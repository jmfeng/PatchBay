//4 Different Sequences that correspond to each codename/color
//Each player must input their sequence to be cleared from the alarm system
//Once each player has entered their sequence, system resets, hackerman gives them the go
//Game is complete.

int ledPins[] = {8, 9, 10, 11};

int buttons[] = {4, 5, 6, 7};
int previousState[] = {HIGH, HIGH, HIGH, HIGH};

int pattern[12];
int userPattern[12];
int userIndex = 0;    // which digit in the pattern the user is currently entering

int totalRounds = 3;
int currentRound = 0;
int gameState = 0;

/* 0 = create pattern
   1 = flash LED pattern
   2 = user input

*/

void setup() {
  Serial.begin(9600);
  Serial.println("System Online");

  //applies to all outputs of 'ledPins'
  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
    pinMode(buttons[i], INPUT_PULLUP);
  }
}

void loop() {

  if (gameState == 0) {
    // setup, create pattern

    //Prevents same sequence from occurring each game
    randomSeed(analogRead(4));

    // create pattern
    for (int i = 0; i < 4; i++) {
      pattern[i] = random(4);
      Serial.print(pattern[i]);
    }
    Serial.println("");

    gameState++;
    Serial.println("ggame state = " + gameState);
  }

  if (gameState == 1) {
    // flash LEDs

    //all LEDs start as off
    for (int i = 0; i < 4; i++) {
      digitalWrite(ledPins[i], LOW);
    }

    //Pattern begins for Puzzle
    //1st LED turns on for 1 second
    for (int i = 0; i < 4; i++) {
      digitalWrite(ledPins[pattern[i]], HIGH);
      delay(1000);
      digitalWrite(ledPins[pattern[i]], LOW);
      delay(1000);
    }

    gameState++;
    Serial.println(gameState);
    Serial.println("game state = " + String(gameState));
  }


  if (gameState == 2) {
    // enter puzzle answer

    // as the user presses buttons, append the button ID to the user answer array
    for (int i = 0; i < 5; i++) {
      if (digitalRead(buttons[i]) == LOW && previousState[i] == HIGH) {
        userPattern[userIndex] = i;
        userIndex++;

        Serial.println("down");
        // previous state for this button is now "pressed" or LOW (or 0 or false)
        previousState[i] = LOW;
      }

      // reset button when user no longer pressing it
      if (digitalRead(buttons[i]) == HIGH && previousState[i] == LOW) {
        Serial.println("up");
        previousState[i] = HIGH;
      }
    }

    if (userIndex == 4) {
      // was it true?
      bool patternCorrect = true;

      // for loop that registers if pattern is false
      // if loop is false must revert to previous gameState
      for (int i = 0; i < 4; i++) {
        if (userPattern[i] != pattern[i]) {
          patternCorrect = false;
        }
      }
      // if patternCorrect is true then LEDs blink
      // all LED's should blink
      if (patternCorrect == true) {
        for (int i = 0; i < 4; i++) {
          digitalWrite(ledPins[8], HIGH);
          delay(1000);
          digitalWrite(ledPins[pattern[i]], LOW);
          delay(1000);

        }
        gameState = 3;
        Serial.println("game state = " + String(gameState));
        userIndex = 0;
      }
      else {
        Serial.println("game state = " + String(gameState));
        gameState = 2;
        
      }
    }
  }
  if (gameState == 3) {
    // check user code
    // print out entire user code after they enter it
    for (int i = 0; i < 4; i++) {
      Serial.print(userPattern[i]);
    }
    Serial.println("");
    gameState = 4;
  }



}
