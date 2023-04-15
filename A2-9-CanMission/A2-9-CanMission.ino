#include <Servo.h>
Servo sv_keep, sv_pick;
void setup() {
  // put your setup code here, to run once:
  while(digitalRead(8));

  sv_keep.attach(18);
  sv_pick.attach(19);
  
  cross_left();
  cross_stop();
  
  sKeep();

  UTURN();

  cross_left();
  cross_stop();

  sDrop();
}

void loop() {
  // put your main code here, to run repeatedly:
}
void fd(unsigned int speed) {
  unsigned int pwm = map(constrain(speed, 0, 100), 0, 100, 0, 255);
  analogWrite(13, 0);
  analogWrite(14, pwm);
  analogWrite(16, 0);
  analogWrite(17, pwm);
}
void bk(unsigned int speed) {
  unsigned int pwm = map(constrain(speed, 0, 100), 0, 100, 0, 255);
  analogWrite(13, pwm);
  analogWrite(14, 0);
  analogWrite(16, pwm);
  analogWrite(17, 0);
}
void sl(unsigned int speed) {
  unsigned int pwm = map(constrain(speed, 0, 100), 0, 100, 0, 255);
  analogWrite(13, pwm);
  analogWrite(14, 0);
  analogWrite(16, 0);
  analogWrite(17, pwm);
}
void sr(unsigned int speed) {
  unsigned int pwm = map(constrain(speed, 0, 100), 0, 100, 0, 255);
  analogWrite(13, 0);
  analogWrite(14, pwm);
  analogWrite(16, pwm);
  analogWrite(17, 0);
}
void tl(unsigned int speed) {
  unsigned int pwm = map(constrain(speed, 0, 100), 0, 100, 0, 255);
  analogWrite(13, 0);
  analogWrite(14, 0);
  analogWrite(16, 0);
  analogWrite(17, pwm);
}
void tr(unsigned int speed) {
  unsigned int pwm = map(constrain(speed, 0, 100), 0, 100, 0, 255);
  analogWrite(13, 0);
  analogWrite(14, pwm);
  analogWrite(16, 0);
  analogWrite(17, 0);
}
void fd2(unsigned int speed1, unsigned int speed2) {
  unsigned int pwm1 = map(constrain(speed1, 0, 100), 0, 100, 0, 255);
  unsigned int pwm2 = map(constrain(speed2, 0, 100), 0, 100, 0, 255);
  analogWrite(13, 0);
  analogWrite(14, pwm1);
  analogWrite(16, 0);
  analogWrite(17, pwm2);
}
void bk2(unsigned int speed1, unsigned int speed2) {
  unsigned int pwm1 = map(constrain(speed1, 0, 100), 0, 100, 0, 255);
  unsigned int pwm2 = map(constrain(speed2, 0, 100), 0, 100, 0, 255);
  analogWrite(13, 0);
  analogWrite(14, pwm1);
  analogWrite(16, 0);
  analogWrite(17, pwm2);
}
void ao() {
  analogWrite(13, 0);
  analogWrite(14, 0);
  analogWrite(16, 0);
  analogWrite(17, 0);
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
void cross_pass() {
  while (1) {
    if (digitalRead(10) && digitalRead(11)) {
      fd(60);
    }
    else if (!digitalRead(10) && digitalRead(11)) {
      sl(70);
    }
    else if (digitalRead(10) && !digitalRead(11)) {
      sr(70);
    }
    else if (!digitalRead(10) && !digitalRead(11)) {
      fd(60);
      delay(200);
      break;
    }
  }
}
void cross_stop() {
  while (1) {
    if (digitalRead(10) && digitalRead(11)) {
      fd(60);
    }
    else if (!digitalRead(10) && digitalRead(11)) {
      sl(70);
    }
    else if (digitalRead(10) && !digitalRead(11)) {
      sr(70);
    }
    else if (!digitalRead(10) && !digitalRead(11)) {
      ao();
      break;
    }
  }
}
void cross_left() {
  while (1) {
    if (digitalRead(10) && digitalRead(11)) {
      fd(60);
    }
    else if (!digitalRead(10) && digitalRead(11)) {
      sl(70);
    }
    else if (digitalRead(10) && !digitalRead(11)) {
      sr(70);
    }
    else if (!digitalRead(10) && !digitalRead(11)) {
      fd(60);
      delay(150);
      L90();
      break;
    }
  }
}
void cross_right() {
  while (1) {
    if (digitalRead(10) && digitalRead(11)) {
      fd(60);
    }
    else if (!digitalRead(10) && digitalRead(11)) {
      sl(70);
    }
    else if (digitalRead(10) && !digitalRead(11)) {
      sr(70);
    }
    else if (!digitalRead(10) && !digitalRead(11)) {
      fd(60);
      delay(150);
      R90();
      break;
    }
  }
}
void R90(){
  sr(70);
  while(digitalRead(11));
  while(!digitalRead(11));
  ao();
}
void L90(){
  sl(70);
  while(digitalRead(11));
  while(!digitalRead(11));
  ao();
}
void UTURN(){
  bk(70);
  delay(300);
  R90();
}
