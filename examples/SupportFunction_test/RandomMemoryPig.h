#include "Arduino.h"

class RandomMemoryPig
{
private:
    void *pointer;
    uint64_t allocationSize;

public:
    RandomMemoryPig()
    {
        Serial.println("RandomMemoryPig(construtor)");

        allocationSize = (uint64_t)random(10, 20000);
        pointer = malloc(allocationSize);
    }
    ~RandomMemoryPig()
    {
        Serial.println("~RandomMemoryPig(destructor)");
        free(pointer);
    }
    uint64_t getAllocationSize()
    {
        return this->allocationSize;
    }
};