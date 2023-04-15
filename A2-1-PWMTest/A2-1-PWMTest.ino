void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  if (!digitalRead(8) && digitalRead(9)) {
    analogWrite(13, 0);
    analogWrite(14, 100);
    analogWrite(16, 0);
    analogWrite(17, 100);
    delay(2000);
  }
  else if (digitalRead(8) && !digitalRead(9)) {
    analogWrite(13, 100);
    analogWrite(14, 0);
    analogWrite(16, 100);
    analogWrite(17, 0);
    delay(2000);
  }
  analogWrite(13, 0);
  analogWrite(14, 0);
  analogWrite(16, 0);
  analogWrite(17, 0);
}
