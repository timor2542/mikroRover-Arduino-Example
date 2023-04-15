void setup() {
  // put your setup code here, to run once:
  while (digitalRead(8));
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(10) && digitalRead(11)) {
    fd(60);
  }
  else if (!digitalRead(10) && digitalRead(11)) {
    sl(70);
  }
  else if (digitalRead(10) && !digitalRead(11)) {
    sr(70);
  }
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
