
#include "Arduino.h"

/* https://github.com/thijse/Arduino-Log
#include "ArduinoLog.h"
 * 0 - LOG_LEVEL_SILENT     no output 
 * 1 - fatal     LOG_LEVEL_FATAL      fatal errors 
 * 2 - errorln   LOG_LEVEL_ERROR      all errors  
 * 3 - warning   LOG_LEVEL_WARNING    errors, and warnings 
 * 4 - notice    LOG_LEVEL_NOTICE     errors, warnings and notices 
 * 5 - trace     LOG_LEVEL_TRACE      errors, warnings, notices & traces 
 * 6 - verboseln LOG_LEVEL_VERBOSE    all 
 */

#include "TBA_SupportFunction.h"
TBA_SupportFunction supportFunction = TBA_SupportFunction();

void setupSerial() {
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }
}

void setupCPU() {
  char buffer[100];
  setCpuFrequencyMhz(240);
  sprintf(buffer, "CPU running at:  %i Mhz", xPortGetCoreID());
  Serial.println(buffer);
}

void setup() {
  char buffer[100];

  setupSerial();

  Serial.println("- - - - - - - - - - - - - - - - - - - - -" );    
  Serial.println("Booting..." );
  Serial.println("Support Fuction test" );
  Serial.println("- - - - - - - - - - - - - - - - - - - - -"  );

  sprintf(buffer, "Setup() running on core:  %i", xPortGetCoreID());
  Serial.println(buffer);

  supportFunction.initTBA_SupportFunction();
  supportFunction.showChipID();

  Serial.print  ("loop() Core: ");
  Serial.println(xPortGetCoreID());

  setupCPU();

  supportFunction.memoryInfo();


// not tested (only compiled)
  char str[]="1776ad";
  String stg = supportFunction.convertToString(str,sizeof(str));

  Serial.println("Done." );
}

int maxCnt  =   100;
int sendCnt =  maxCnt - 1;

void loop() {
  sendCnt++;
  if (sendCnt >= maxCnt){
      Serial.print(".");
      sendCnt = 0;

      supportFunction.memoryInfo();      
  }

  delay(10);
  yield();
}
