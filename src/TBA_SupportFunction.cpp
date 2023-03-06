/*
  TBA_SupportFunction.cpp - Library for TBA_SupportFunction code.
  Created by Mr Q, December 2, 2022.
  Released into the public domain.
*/
#pragma once

#include "Arduino.h"
#include "TBA_SupportFunction.h"

TBA_SupportFunction::TBA_SupportFunction()
{
  this->lastHeap = getHeapSize();
  this->lastFreeHeap = getFreeHeap();
  this->lastMinFreeHeap = getMinFreeHeap();
  this->lastMaxAllocHeap = getMaxAllocHeap();

  int64_t thisSize = getHeapSize();
  String sizeVal = humanReadableSize(thisSize);
  String diffVal = humanReadableSize(thisSize - this->lastHeap);
  Serial.printf("HEAP Size    : %s diff: %s\n", sizeVal, diffVal);
  this->lastHeap = thisSize;

  thisSize = getFreeHeap();
  sizeVal = humanReadableSize(thisSize);
  diffVal = humanReadableSize((thisSize - this->lastFreeHeap));
  Serial.printf("HEAP Free    : %s diff: %s\n", sizeVal, diffVal);
  this->lastFreeHeap = thisSize;

  thisSize = getMinFreeHeap();
  sizeVal = humanReadableSize(thisSize);
  diffVal = humanReadableSize((thisSize - this->lastMinFreeHeap));
  Serial.printf("HEAP Min Free: %s diff: %s\n", sizeVal, diffVal);
  this->lastMinFreeHeap = thisSize;

  thisSize = getMaxAllocHeap();
  sizeVal = humanReadableSize(thisSize);
  diffVal = humanReadableSize((thisSize - this->lastMaxAllocHeap));
  Serial.printf("HEAP Max Allo: %s diff: %s\n", sizeVal, diffVal);
  this->lastMaxAllocHeap = thisSize;
}


String TBA_SupportFunction::humanReadableSize(int64_t bytes)
{

  int8_t sign = 1;
  if (bytes != abs(bytes))
//  if (bytes < 0)
  {
    sign = -1;
    bytes *= sign;
  }

  char buf[12];
  int bufSize = sizeof(buf) / sizeof(char);
  memset(buf, 0, sizeof(buf));

  double dSize = 0.0;

  if (bytes < 1024)
  {
    dSize = (double)bytes / 1.0;
    sprintf(buf, "%3.0f B", dSize * sign);
  }
  else if (bytes < (1024 * 1024))
  {
    dSize = bytes / 1024.0;
    sprintf(buf, "%3.3f KB", dSize * sign);
  }
  else if (bytes < (1024 * 1024 * 1024))
  {
    dSize = bytes / 1024.0 / 1024.0;
    sprintf(buf, "%3.3f MB", dSize * sign);
  }
  else
  {
    dSize = bytes / 1024.0 / 1024.0 / 1024.0;
    sprintf(buf, "%3.3f GB", dSize * sign);
  }

  String bytesStg = convertToString(buf, bufSize);

  return bytesStg;
}

void TBA_SupportFunction::initTBA_SupportFunction()
{
}

void TBA_SupportFunction::showChipID()
{
  int64_t chipId = 0;
  for (int i = 0; i < 17; i = i + 8)
  {
    chipId |= ((ESP.getEfuseMac() >> (40 - i)) & 0xff) << i;
  }

  Serial.printf("ESP32 Chip model = %s Rev %d\n", ESP.getChipModel(), ESP.getChipRevision());
  Serial.printf("This chip has %d cores\n", ESP.getChipCores());
  Serial.printf("Chip ID: %d", chipId);
}

String TBA_SupportFunction::convertToString(char *buff, int sizeOf)
{
  // converts character array to string and returns it
  int i;
  String rtnString = "";
  for (i = 0; i < sizeOf; i++)
  {
    rtnString = rtnString + buff[i];
  }
  return rtnString;
}

int64_t TBA_SupportFunction::getHeapSize()
{
  return(int64_t) ESP.getHeapSize();
}
int64_t TBA_SupportFunction::getFreeHeap()
{
  return (int64_t)ESP.getFreeHeap();
}
int64_t TBA_SupportFunction::getMinFreeHeap()
{
  return (int64_t)ESP.getMinFreeHeap();
}
int64_t TBA_SupportFunction::getMaxAllocHeap()
{
  return (int64_t)ESP.getMaxAllocHeap();
}

void TBA_SupportFunction::memoryInfo()
{
  Serial.println();

  int64_t thisSize = getHeapSize();
  String sizeVal = humanReadableSize(thisSize);
  String diffVal = humanReadableSize((thisSize - this->lastHeap));
  Serial.printf("HEAP Size    : %s diff: %s\n", sizeVal, diffVal);
  this->lastHeap = thisSize;

  thisSize = getFreeHeap();
  sizeVal = humanReadableSize(thisSize);
  diffVal = humanReadableSize((thisSize - this->lastFreeHeap));
  Serial.printf("HEAP Free    : %s diff: %s\n", sizeVal, diffVal);
  this->lastFreeHeap = thisSize;

  thisSize = getMinFreeHeap();
  sizeVal = humanReadableSize(thisSize);
  diffVal = humanReadableSize((thisSize - this->lastMinFreeHeap));
  Serial.printf("HEAP Min Free: %s diff: %s\n", sizeVal, diffVal);
  this->lastMinFreeHeap = thisSize;

  thisSize = getMaxAllocHeap();
  sizeVal = humanReadableSize(thisSize);
  diffVal = humanReadableSize((thisSize - this->lastMaxAllocHeap));
  Serial.printf("HEAP Max Allo: %s diff: %s\n", sizeVal, diffVal);
  this->lastMaxAllocHeap = thisSize;
}
