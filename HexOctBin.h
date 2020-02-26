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
    // tp: 1 = Bin,  2 = Oct,  3 = Hex (default)
    uint32_t toDec(String HOB, byte tp = 3);
    // tp: 1 = Bin,  2 = Oct,  3 = Hex (default)
    void toHOB(uint32_t dec, String &rslt, byte tp = 3);
    void Bin2Oct(String Bin, String &rslt) {
    void Bin2Hex(String Bin, String &rslt) {
    void Oct2Bin(String Oct, String &rslt) {
    void Oct2Hex(String Oct, String &rslt) {
    void Hex2Bin(String Hex, String &rslt) {
    void Hex2Oct(String Hex, String &rslt) {

};

#endif
