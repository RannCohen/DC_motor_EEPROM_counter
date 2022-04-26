#include <EEPROM.h>
#define Erase 0
uint16_t cnt;
int ddelay = 30000;
int sec = 1000;

void setup()
{
  Serial.begin(9600);
  DDRB |= B00100111;
  cnt = 0;
  if (Erase)
    EEPROM.put(0, cnt);
  EEPROM.get(0, cnt);
  Serial.print("counter value at startup: "); Serial.println(cnt);
}

void loop()
{
  PORTB |= B00100101;
  delay(ddelay);
  PORTB |= B00100101;
  delay(sec);
  PORTB |= B00000110;
  delay(ddelay);
  PORTB &= B00000110;
  cnt++;
  EEPROM.put(0, cnt);
  Serial.print("counter: ");
  Serial.println(cnt);
  delay(sec);
}
