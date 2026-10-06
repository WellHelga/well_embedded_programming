const int button_pin = 2;
const int led_1_pin = 11;
const int led_2_pin = 10;

const unsigned long t_debounce = 100;
const unsigned long t_short_max = 500;
const unsigned long t_long_min = 1000;
const unsigned long t_led2_on = 2000;

int last_button_state = LOW;
int current_button_state = LOW;
unsigned long last_debounce_time = 0;

bool button_pressed = false;
unsigned long press_start_time = 0;
bool led_2_active = false;
unsigned long led_2_start_time = 0;
bool led_1_state = false;

void setup() {
  
  pinMode(button_pin, INPUT);
  pinMode(led_1_pin, OUTPUT);
  pinMode(led_2_pin, OUTPUT);
  
  Serial.begin(9600);
}
void loop() {

  unsigned long current_millis = millis();
  int reading = digitalRead(button_pin);
  
  if (reading != last_button_state) {
    last_debounce_time = current_millis;
  }
  if (current_millis - last_debounce_time > t_debounce) {

    if (reading != current_button_state) {
      current_button_state = reading;

      if (current_button_state == HIGH && !button_pressed) {
        button_pressed = true;
        press_start_time = current_millis;
      }
      if (current_button_state == LOW && button_pressed) {
        button_pressed = false;
        unsigned long press_duration = current_millis - press_start_time;
        
        if (press_duration < t_short_max) {
          led_1_state = !led_1_state;
          digitalWrite(led_1_pin, led_1_state);
          Serial.println("короткое нажатие");
        }
        else if (press_duration > t_long_min) {
          led_2_active = true;
          led_2_start_time = current_millis;
          digitalWrite(led_2_pin, HIGH);
          Serial.println("длинное нажатие");
        }
      }
    }
  }
  last_button_state = reading;
  
  if (led_2_active && (current_millis - led_2_start_time >= t_led2_on)) {
    led_2_active = false;
    digitalWrite(led_2_pin, LOW);
  }
}
