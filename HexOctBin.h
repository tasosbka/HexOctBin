/*
  HexOctBin.h - Library for Hex/Oct/Bin code.
  Created by tasos.bka
  Released into the public domain.
*/

#ifndef HexOctBin_H
#define HexOctBin_H

#include <Arduino.h>

class HexOctBin {
  protected:
    void to2(String &s);
    void to8(String &s);
    void to16(String &s);
    void toBin(uint32_t dec, String &rslt);
    void toOct(uint32_t dec, String &rslt);
    void toHex(uint32_t dec, String &rslt);
    uint32_t Bin2Dec(String Bin);
    uint32_t Oct2Dec(String Oct);
    uint32_t Hex2Dec(String Hex);
  public:
    uint32_t toDec(String HOB, byte tp = 3);
    void toHOB(uint32_t dec, String &rslt, byte tp = 3);

};

#endif
