void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(12, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.write(random(10));

  if (Serial.available() > 0) {
    
    int inByte = Serial.read();

    if (inByte == 1) {
      digitalWrite(12, HIGH);
    } else {
      digitalWrite(12, LOW);
    }
  }
  delay(100);
}
