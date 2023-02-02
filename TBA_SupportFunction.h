/*
  TBA_SupportFunction.h - Library for flashing TBA_SupportFunction code.
  Created by Mr Q, December 2, 2022.
  Released into the public domain.
*/

#pragma once

#ifndef TBA_SupportFunction_h
#define TBA_SupportFunction_h

  #include "Arduino.h"
  
  class TBA_SupportFunction{
    private:

      uint64_t lastHeap;
      uint64_t lastFreeHeap;
      uint64_t lastMinFreeHeap;
      uint64_t lastMaxAllocHeap;

    public:
      TBA_SupportFunction();
      String convertToString(char* buff, int size);
      String humanReadableSize(uint64_t bytes);
      String humanReadableSize(int64_t bytes);
      uint64_t getHeapSize();
      uint64_t getFreeHeap();
      uint64_t getMinFreeHeap();
      uint64_t getMaxAllocHeap();
      void memoryInfo();    
      void showChipID();
      void   initTBA_SupportFunction();

    private:

  };

#endif  // end TBA_SupportFunction_h
