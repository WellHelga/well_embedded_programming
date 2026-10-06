const int d_red = 11;
const int d_yellow = 10;
const int d_green = 9;

const int w_red = 5;
const int w_green = 6;

const int button = 2;

const int t_yellow = 1000;
const int t_red = 5000;
const int t_flash = 500;
const int t_block = 50;

void setup() {
  pinMode(d_red, OUTPUT);
  pinMode(d_yellow, OUTPUT);
  pinMode(d_green, OUTPUT);
  pinMode(w_red, OUTPUT);
  pinMode(w_green, OUTPUT);
  
  pinMode(button, INPUT);
  
  digitalWrite(d_green, HIGH);
  digitalWrite(w_red, HIGH);
}

void loop() {
  if (digitalRead(button) == HIGH) {
    delay(t_block);
    if (digitalRead(button) == HIGH) {
      run();
    }
  }
}

void run() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(d_green, HIGH);
    delay(t_flash);
    digitalWrite(d_green, LOW);
    delay(t_flash);
  }
  
  digitalWrite(d_yellow, HIGH);
  delay(t_yellow);
  digitalWrite(d_yellow, LOW);
  
  digitalWrite(d_red, HIGH);
  digitalWrite(w_red, LOW);
  digitalWrite(w_green, HIGH);
  delay(t_red);
 
  for (int i = 0; i < 3; i++) {
    digitalWrite(w_green, HIGH);
    delay(t_flash);
    digitalWrite(w_green, LOW);
    delay(t_flash);
  }
  
  digitalWrite(d_red, LOW);
  digitalWrite(w_green, LOW);
  digitalWrite(w_red, HIGH);
  digitalWrite(d_green, HIGH);
}
