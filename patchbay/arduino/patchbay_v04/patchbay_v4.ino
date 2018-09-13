const int jackIn01_pin = A0;
const int jackIn02_pin = A1;
const int jackIn03_pin = A2;
const int jackIn04_pin = A3;

int lastJackNumber;
int jackIn01_state = 0;
int jackIn02_state = 0;
int jackIn03_state = 0;
int jackIn04_state = 0;

String jackin_01 = "Jackin_1:";
String jackin_02 = "Jackin_2:";
String jackin_03 = "Jackin_3:";
String jackin_04 = "Jackin_4:";
long lastDebounceTime = 0;


int debounce(int jackValue, long debounceDelay, int comparedTime){
  int lastValue = jackValue; 
  int newJackValue;
  
  
  if (jackValue != lastValue) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    

    // if the button state has changed:
    if (jackValue == newJackValue) {
      newJackValue = jackValue;
      lastDebounceTime = millis();

      return newJackValue;
    }
    
  }

  return 0;
}

void setup() {
  
    pinMode(jackIn01_pin, INPUT);
    pinMode(jackIn02_pin, INPUT);
    pinMode(jackIn03_pin, INPUT);
    pinMode(jackIn04_pin, INPUT);

    
    Serial.begin(9600);
}

void loop() {
  
 // jackIn01_state = analogRead(jackIn01_pin);
 //jackIn02_state = analogRead(jackIn02_pin);
 // jackIn03_state = analogRead(jackIn03_pin);
// jackIn04_state = analogRead(jackIn04_pin);

  //Serial.println(jackin_01 + jackIn01_state);
  // Serial.println(jackin_02 + jackIn02_state);
   // Serial.println(jackin_03 + jackIn03_state);
   //Serial.println(jackin_04 + jackIn04_state);
   delay(100);
    lastJack = debounce(lastJack)
    
    int val01 = jackRead(jackIn01_pin);
    int val02 = jackRead(jackIn02_pin);
    int val03 = jackRead(jackIn03_pin);
    int val04 = jackRead(jackIn04_pin);

  Serial.println(debounce(val01, 1000, 666));
}

int jackRead(int jack) 
{
  int value = analogRead(jack);
  return value;
}

