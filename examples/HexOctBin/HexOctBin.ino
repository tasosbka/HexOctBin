/*
  example for HexOctBin - Library for Hex/Oct/Bin code.
  Created by tasos.bka
  Released into the public domain.
*/

#include <HexOctBin.h>

HexOctBin hob;

void setup() {
  Serial.begin(9600);
  String Bin, Oct, Hex;
  hob.toHOB(pow(2, 32) - 1, Bin, 1);
  hob.toHOB(pow(2, 32) - 1, Oct, 2);
  hob.toHOB(pow(2, 32) - 1, Hex);
  Serial.println("2^32 - 1 = 4294967295 = Bin = " + Bin);
  Serial.println("2^32 - 1 = 4294967295 = Oct = " + Oct);
  Serial.println("2^32 - 1 = 4294967295 = Hex = " + Hex);
  Serial.println();

  hob.Bin2Oct("B11111111", Oct);
  hob.Bin2Hex("11111111", Hex);
  Serial.print("\t"   + Oct);
  Serial.println("\t" + Hex);
  
  hob.Oct2Bin("34567", Bin);
  hob.Oct2Hex("O34567", Hex);
  Serial.print("\t"   + Bin);
  Serial.println("\t" + Hex);
  
  hob.Hex2Bin("0x4000", Bin);
  hob.Hex2Oct("4000", Oct);
  Serial.print("\t"   + Bin);
  Serial.println("\t" + Oct);
  Serial.println();
    
  uint32_t dec = hob.toDec("10011010010", 1); // hob.toDec("B0000010011010010", 1);
  Serial.print( dec );         // 1234
  hob.toHOB(dec, Bin, 1);
  Serial.println("\t" + Bin );  // B0000010011010010

  Serial.print( hob.toDec("2322", 2) ); //  hob.toDec("O002322", 2) );
  hob.toHOB(1234, Oct, 2);
  Serial.println("\t" + Oct );  // O002322

  Serial.print( hob.toDec("4D2") );   // hob.toDec("0x04D2",3) );
  hob.toHOB( hob.toDec("4D2"), Hex );
  Serial.println("\t" + Hex );        // 0x04D2
  Serial.println();

  // convert float decimal to hex/oct/bin maximum is  = 9999999
  // otherwise convert decimal maximum (2^32) - 1  = 4294967295
  hob.toHOB(9999999.1234567, Bin, 1 );
  hob.toHOB(9999999.1234567, Oct, 2 );
  hob.toHOB(9999999.1234567, Hex, 3);

  Serial.println("float: \t" + Bin );  // B100110001001011001111111
  Serial.println("float: \t" + Oct );  // O046113177
  Serial.println("float: \t" + Hex );  // 0x0098967F
}

void loop() {
}
