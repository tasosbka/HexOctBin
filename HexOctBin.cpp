/*
  HexOctBin.cpp - Library for Hex/Oct/Bin code.
  Created by tasos.bka
  Released into the public domain.
*/

#include "HexOctBin.h"

// public functions
// convert Hex/Oct/Bin to decimal
// tp 1 = Bin, 2 = Oct, 3 = Hex (default)
uint32_t HexOctBin::toDec(String HOB, byte tp = 3) {
  uint32_t rslt = 0;
  if (tp == 1) rslt = Bin2Dec(HOB);
  else if (tp == 2) rslt = Oct2Dec(HOB);
  else if (tp == 3) rslt = Hex2Dec(HOB);
  return rslt;
}

// convert decimal to Hex/Oct/Bin
// tp 1 = Bin, 2 = Oct, 3 = Hex (default)
void HexOctBin::toHOB(uint32_t dec, String &rslt, byte tp = 3) {
  String s = "";
  if (tp == 1) toBin(dec, s);
  else if (tp == 2) toOct(dec, s);
  else if (tp == 3) toHex(dec, s);
  rslt = s;
}

// convert Bin to Oct
void HexOctBin::Bin2Oct(String Bin, String &rslt) {
  double dec = Bin2Dec(Bin);
  toOct(dec, rslt);
}

// convert Bin to Hex
void HexOctBin::Bin2Hex(String Bin, String &rslt) {
  double dec = Bin2Dec(Bin);
  toHex(dec, rslt);
}

// convert Oct to Bin
void HexOctBin::Oct2Bin(String Oct, String &rslt) {
  double dec = Oct2Dec(Oct);
  toBin(dec, rslt);
}

// convert Oct to Hex
void HexOctBin::Oct2Hex(String Oct, String &rslt) {
  double dec = Oct2Dec(Oct);
  toHex(dec, rslt);
}

// convert Hex to Bin
void HexOctBin::Hex2Bin(String Hex, String &rslt) {
  double dec = Hex2Dec(Hex);
  toBin(dec, rslt);
}

// convert Hex to Oct
void HexOctBin::Hex2Oct(String Hex, String &rslt) {
  double dec = Hex2Dec(Hex);
  toOct(dec, rslt);
}

// protected function
// leading zeros if necessary
void HexOctBin::to2(String &s) {
  byte zero = s.length() % 8;
  if (zero != 0)
    for (int i = zero; i < 8; i++) s = "0" + s;
  s = "B" + s;
}

void HexOctBin::to8(String &s) {
  byte zero = s.length() % 3;
  if (zero != 0)
    for (int i = zero; i < 3; i++) s = "0" + s;
  if (s != "") s = "O" + s;
}

void HexOctBin::to16(String &s) {
  byte zero = s.length() % 4;
  if (zero != 0)
    for (int i = zero; i < 4; i++) s = "0" + s;
  if (s != "") s = "0x" + s;
}

// convert decimal to binary
void HexOctBin::toBin(uint32_t dec, String &rslt) {
  rslt = "";
  while (dec > 0) {
    rslt = String(dec & 0x01) + rslt;
    dec >>= 1;
  }
  if (rslt == "") rslt = "0";
  to2(rslt);
}

// convert decimal to Oct
void HexOctBin::toOct(uint32_t dec, String &rslt) {
  rslt = "";
  char Digit[] = "01234567" ;
  while (dec > 0) {
    rslt = Digit[dec & 0x07] + rslt;
    dec >>= 3;
  }
  to8(rslt);
}

// convert decimal to hex
void HexOctBin::toHex(uint32_t dec, String &rslt) {
  char Digit[] = "0123456789ABCDEF" ;
  rslt = "";
  while (dec > 0) {
    rslt = Digit[dec & 0x0F]  + rslt;
    dec >>= 4;
  }
  to16(rslt);
}

// convert Bin to decimal
uint32_t HexOctBin::Bin2Dec(String Bin) {
  uint64_t multiply = 1, tmp;
  uint32_t rslt = 0;
  Bin = "." + Bin;
  for (int i = Bin.length() - 1; i; i--) {
    tmp = 0;
    if (Bin[i] >= '0' && Bin[i] <= '1') {
      tmp = ( (int) Bin[i] - 48 ) * multiply;
      multiply <<= 1;
    }
    rslt += tmp;
  }
  return rslt;
}

// convert Oct to decimal
uint32_t HexOctBin::Oct2Dec(String Oct) {
  uint64_t multiply = 1, tmp;
  uint32_t rslt = 0;
  Oct = "." + Oct;
  for (int i = Oct.length() - 1; i; i--) {
    tmp = 0;
    if (Oct[i] >= '0' && Oct[i] <= '7') {
      tmp = ( (int) Oct[i] - 48 ) * multiply;
      multiply <<= 3;
    }
    rslt += tmp;
  }
  return rslt;
}

// convert Hex to decimal
uint32_t HexOctBin::Hex2Dec(String Hex) {
  uint64_t multiply = 1, tmp;
  uint32_t rslt = 0;
  Hex = "." + Hex;
  Hex.toUpperCase();
  for (int i = Hex.length() - 1; i; i--) {
    tmp = 0;
    if (Hex[i] >= '0' && Hex[i] <= '9') {
      tmp = ( (int) Hex[i] - 48 ) * multiply;
      multiply <<= 4;
    } else if (Hex[i] >= 'A' && Hex[i] <= 'F') {
      tmp = ( (int) Hex[i] - 55 ) * multiply;
      multiply <<= 4;
    }
    rslt += tmp;
  }
  return rslt;
}
