
#include "Arduino.h"

/*
 * 0 - LOG_LEVEL_SILENT     no output
 * 1 - fatal     LOG_LEVEL_FATAL      fatal errors
 * 2 - errorln   LOG_LEVEL_ERROR      all errors
 * 3 - warning   LOG_LEVEL_WARNING    errors, and warnings
 * 4 - notice    LOG_LEVEL_NOTICE     errors, warnings and notices
 * 5 - trace     LOG_LEVEL_TRACE      errors, warnings, notices & traces
 * 6 - verboseln LOG_LEVEL_VERBOSE    all
 */

#include "RandomMemoryPig.h"

#include "TBA_SupportFunction.h"
TBA_SupportFunction supportFunction = TBA_SupportFunction();

void setupSerial()
{
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  while (!Serial)
  {
    ; // wait for serial port to connect. Needed for native USB
  }
}

void setupCPU()
{
  char buffer[100];
  setCpuFrequencyMhz(240);
  sprintf(buffer, "CPU running at:  %i Mhz", xPortGetCoreID());
  Serial.println(buffer);
}

void setup()
{
  char buffer[100];

  setupSerial();

  Serial.println();

  supportFunction.memoryInfo();

  Serial.println("- - - - - - - - - - - - - - - - - - - - -");
  Serial.println("Booting...");
  Serial.println("Support Fuction test");
  Serial.println("- - - - - - - - - - - - - - - - - - - - -");

  sprintf(buffer, "Setup() running on core:  %i", xPortGetCoreID());
  Serial.println(buffer);

  supportFunction.initTBA_SupportFunction();
  supportFunction.showChipID();

  Serial.print("loop() Core: ");
  Serial.println(xPortGetCoreID());

  setupCPU();

  // char str[]="1776ad";
  char str[] = {'1', '7', '7', '6', ' ', 'A', 'D'};
  String tempString = supportFunction.convertToString(str, sizeof(str));
  Serial.println(tempString);

  Serial.println();
  supportFunction.memoryInfo();
  Serial.println("Setup complete.\n\n");
}

int cnt = 0;

void loop()
{
  // intro
  Serial.println("========================================");
  Serial.println("========================================");
  Serial.println("========================================");
  Serial.print("Loop cnt: ");
  Serial.println(cnt++);

  Serial.println("");
  Serial.println("(-) negative number indicates memory allocated");
  Serial.println("(+) positive number indicates memory delete/free");
  Serial.println("");

  // base state
  Serial.println("----------------------------------------");
  Serial.println("");
  Serial.println("Pre allocate usage S/B  0 byte difference");
  supportFunction.memoryInfo();
  Serial.println();

  // allocate state
  Serial.println("----------------------------------------");
  Serial.println("Post allocated usage");
  RandomMemoryPig *randomMemoryPig = new RandomMemoryPig();
  supportFunction.memoryInfo();
  Serial.println();
  Serial.print("Memory allocate size: ");
  Serial.println(randomMemoryPig->getAllocationSize());
  Serial.print("Human readable size : ");
  Serial.println(supportFunction.humanReadableSize(randomMemoryPig->getAllocationSize()));
  Serial.println();

  // free/delete state
  Serial.println("----------------------------------------");
  Serial.println("Post free/delete memory usage, s/b positive of allocated usage");
  delete (randomMemoryPig);
  supportFunction.memoryInfo();
  Serial.println();

  delay(5000);
  yield();
}
