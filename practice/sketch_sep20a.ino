int red = 12;
int yellow = 10;
int green = 8;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}
void loop() {
  digitalWrite(green, HIGH);
  delay(5000);
  for (int i = 0; i < 3; i++) {
    digitalWrite(green, HIGH);
    delay(1000);
    digitalWrite(green, LOW);
    delay(1000);
  }
  digitalWrite(yellow, HIGH);
  delay(2000);
  digitalWrite(yellow, LOW);
  digitalWrite(red, HIGH);
  delay(5000);
  digitalWrite(yellow, HIGH);
  delay(2000);
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
}
