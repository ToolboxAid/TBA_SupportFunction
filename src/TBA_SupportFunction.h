/*
  TBA_SupportFunction.h - Library for flashing TBA_SupportFunction code.
  Created by Mr Q, December 2, 2022.
  Released into the public domain.
*/

#pragma once

#ifndef TBA_SupportFunction_h
#define TBA_SupportFunction_h

#include "Arduino.h"

class TBA_SupportFunction
{
private:
  int64_t lastHeap;
  int64_t lastFreeHeap;
  int64_t lastMinFreeHeap;
  int64_t lastMaxAllocHeap;

protected:
public:
  TBA_SupportFunction();
  String convertToString(char *buff, int size);
  String humanReadableSize(int64_t bytes);
  int64_t getHeapSize();
  int64_t getFreeHeap();
  int64_t getMinFreeHeap();
  int64_t getMaxAllocHeap();
  void memoryInfo();
  void showChipID();
  void initTBA_SupportFunction();
};

#endif // end TBA_SupportFunction_h
