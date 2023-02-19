#include <Wire.h>
uint8_t ret1,ret2;
uint16_t ret;
const int RELAY_PIN = 3;
char serialData;

void setup()
{
Serial.begin(9600);
Wire.begin();
pinMode(RELAY_PIN,OUTPUT);
digitalWrite(RELAY_PIN, HIGH)
}
void loop()
{
Wire.beginTransmission(0x5A);
Wire.write(0x07);
Wire.endTransmission(false);
Wire.requestFrom(0x5A,3);
ret1 = Wire.read();
ret2 = Wire.read();
ret = ret1 | ret2 << 8;
float TempC = ( (ret * 0.02) -273.15 )+2;
Serial.println(TempC);

ข-18

delay(500);
serialData=Serial.read();
if(serialData=='1')
{
digitalWrite(RELAY_PIN, LOW);
delay(500);
}
digitalWrite(RELAY_PIN, HIGH);
}
