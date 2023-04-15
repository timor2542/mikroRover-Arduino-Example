#include <Servo.h>
Servo sv_keep, sv_pick;
void setup() {
  // put your setup code here, to run once:
  sv_keep.attach(18);
  sv_pick.attach(19);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (!digitalRead(8) && digitalRead(9)) {
    sKeep();
  }
  else if (digitalRead(8) && !digitalRead(9)) {
    sDrop();
  }
}
void sKeep()
{
  sv_keep.write(50); delay(300);
  sv_pick.write(45); delay(300);
  sv_keep.write(112); delay(300);
  sv_pick.write(165); delay(300);
}
void sDrop()
{
  sv_pick.write(45); delay(300);
  sv_keep.write(50); delay(300);
  sv_pick.write(165); delay(300);
  sv_keep.write(112); delay(300);
}
