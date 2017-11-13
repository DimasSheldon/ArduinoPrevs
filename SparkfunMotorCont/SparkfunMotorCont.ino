int pwmFL = 6;
int pwmBL = 9;
int pwmFR = 3;
int pwmBR = 5;
int dirFL = 7;
int dirBL = 8;
int dirFR = 2;
int dirBR = 4;
int spd = 255;
int dly = 3000;
void setup() {
  Serial.begin(9600);
  pinMode(pwmFL, OUTPUT);
  pinMode(pwmFR, OUTPUT);
  pinMode(pwmBL, OUTPUT);
  pinMode(pwmBR, OUTPUT);
  pinMode(dirFL, OUTPUT);
  pinMode(dirFR, OUTPUT);
  pinMode(dirBL, OUTPUT);
  pinMode(dirBR, OUTPUT);
}

void loop() {
  //Forward
  Serial.println("Forward");
  digitalWrite(dirFR, HIGH);
  analogWrite(pwmFR, spd);
  digitalWrite(dirFL, HIGH);
  analogWrite(pwmFL, spd);
  digitalWrite(dirBR, HIGH);
  analogWrite(pwmBR, spd);
  digitalWrite(dirBL, HIGH);
  analogWrite(pwmBL, spd);
  delay(dly);
  //stop
  analogWrite(pwmFR, 0);
  analogWrite(pwmFL, 0);
  analogWrite(pwmBR, 0);
  analogWrite(pwmBL, 0);
  delay(dly);

  //Backward
  Serial.println("Backward");
  digitalWrite(dirFR, LOW);
  analogWrite(pwmFR, spd);
  digitalWrite(dirFL, LOW);
  analogWrite(pwmFL, spd);
  digitalWrite(dirBR, LOW);
  analogWrite(pwmBR, spd);
  digitalWrite(dirBL, LOW);
  analogWrite(pwmBL, spd);
  delay(dly);
  //stop
  analogWrite(pwmFR, 0);
  analogWrite(pwmFL, 0);
  analogWrite(pwmBR, 0);
  analogWrite(pwmBL, 0);
  delay(dly);

  //Left
  Serial.println("Left");
  digitalWrite(dirFR, HIGH);
  analogWrite(pwmFR, spd);
  digitalWrite(dirFL, LOW);
  analogWrite(pwmFL, spd);
  digitalWrite(dirBR, HIGH);
  analogWrite(pwmBR, spd);
  digitalWrite(dirBL, LOW);
  analogWrite(pwmBL, spd);
  delay(dly);
  //stop
  analogWrite(pwmFR, 0);
  analogWrite(pwmFL, 0);
  analogWrite(pwmBR, 0);
  analogWrite(pwmBL, 0);
  delay(dly);

  //Right
  Serial.println("Right");
  digitalWrite(dirFR, LOW);
  analogWrite(pwmFR, spd);
  digitalWrite(dirFL, HIGH);
  analogWrite(pwmFL, spd);
  digitalWrite(dirBR, LOW);
  analogWrite(pwmBR, spd);
  digitalWrite(dirBL, HIGH);
  analogWrite(pwmBL, spd);
  delay(dly);
  //stop
  analogWrite(pwmFR, 0);
  analogWrite(pwmFL, 0);
  analogWrite(pwmBR, 0);
  analogWrite(pwmBL, 0);
  delay(dly);

  for (int i = 0; i <= 255; i++) {
    Serial.print("PWM up; ");
    Serial.println(i);
    digitalWrite(dirFR, HIGH);
    analogWrite(pwmFR, i);
    digitalWrite(dirFL, HIGH);
    analogWrite(pwmFL, i);
    digitalWrite(dirBR, HIGH);
    analogWrite(pwmBR, i);
    digitalWrite(dirBL, HIGH);
    analogWrite(pwmBL, i);
    delay(20);
  }

  for (int i = 255; i >= 0; i--) {
    Serial.print("PWM down; ");
    Serial.println(i);
    digitalWrite(dirFR, HIGH);
    analogWrite(pwmFR, i);
    digitalWrite(dirFL, HIGH);
    analogWrite(pwmFL, i);
    digitalWrite(dirBR, HIGH);
    analogWrite(pwmBR, i);
    digitalWrite(dirBL, HIGH);
    analogWrite(pwmBL, i);
    delay(20);
  }
  delay(2000);
}
