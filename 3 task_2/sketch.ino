const int button_pin = 2;
const int led_pin = 11;
const int t_debounce = 50;

int  last_button = LOW;
int current_button = LOW;
unsigned long last_debounce = 0;

bool led_state = false;
int count = 0;

void setup() {

  pinMode(button_pin, INPUT);
  pinMode(led_pin, OUTPUT);
  
  Serial.begin(9600);
  
  digitalWrite(led_pin, led_state);
}
void loop() {

  int reading = digitalRead(button_pin);

  if (reading != last_button) {
    last_debounce = millis();
  }
  if (millis() - last_debounce > t_debounce) {

    if (reading != current_button) {
      current_button = reading;

      if (current_button == HIGH) {
        led_state = !led_state;
        digitalWrite(led_pin, led_state);
        
        count++;
        Serial.print("нажатий: ");
        Serial.println(count);
      }
    }
  }
  last_button = reading;
}
