#ifndef NixieDisplay_h
#define NixieDisplay_h

#include "Arduino.h" // TODO Remove Arduino dependency
#include "Globals.h"

// Location of each segment in each tube the 64 bit shift register
const byte leftDot       = 30;
const byte rightDot      = 62;
const byte hourTens[]    = {9,6,0,1,2,3,4,5,7,8};
const byte hourUnits[]   = {19,16,10,11,12,13,14,15,17,18};
const byte minuteTens[]  = {29,26,20,21,22,23,24,25,27,28};
const byte minuteUnits[] = {41,38,32,33,34,35,36,37,39,40};
const byte secondTens[]  = {51,48,42,43,44,45,46,47,49,50};
const byte secondUnits[] = {61,58,52,53,54,55,56,57,59,60};
// Not in use: positions 31 and 63

class NixieDisplay {
  public:
    NixieDisplay();
    void begin();
    void enableSegment(byte segment);
    void disableSegments(const byte segments[], int count);
    void disableAllSegments();
    void disableSegment(byte segment);
    void updateDisplay();
    void runSlotMachine();
  private: 
    // Frame of data to be shifted into 64 bit HV shift register
    byte _frame[8]; // 8 bytes = 64 bits = 6 digits @ 10 bits + 2 dots @ 1 bit + 2 unused bits
};

#endif
