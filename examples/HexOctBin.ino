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

  uint32_t dec = hob.toDec("10011010010", 1); // hob.toDec("0B0000010011010010", 1);
  Serial.print( dec );         // 1234
  hob.toHOB(dec, Bin, 1);
  Serial.println("\t" + Bin );  // 0B0000010011010010

  Serial.print( hob.toDec("2322", 2) ); //  hob.toDec("0o002322", 2) );
  hob.toHOB(1234, Oct, 2);
  Serial.println("\t" + Oct );  // 0o002322

  Serial.print( hob.toDec("4D2") );   // hob.toDec("0x04D2",3) );
  hob.toHOB( hob.toDec("4D2"), Hex );
  Serial.println("\t" + Hex );        // 0x04D2
  Serial.println();

  // convert float to hex/oct/bin maximum = 9999999
  hob.toHOB(9999999.1234567, Bin, 1 );
  hob.toHOB(9999999.1234567, Oct, 2 );
  hob.toHOB(9999999.1234567, Hex, 3);

  Serial.println("float: \t" + Bin );  // 0B100110001001011001111111
  Serial.println("float: \t" + Oct );  // 0oâ€¬046113177
  Serial.println("float: \t" + Hex );  // 0x0098967F
}

void loop() {}
