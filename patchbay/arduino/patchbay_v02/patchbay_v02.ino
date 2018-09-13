//RGB LEDs - Top Row
const int led01R_pin = 22;
const int led01G_pin = 23;
const int led01B_pin = 24;

const int led02R_pin = 25;
const int led02G_pin = 26;
const int led02B_pin = 27;

const int led03R_pin = 28;
const int led03G_pin = 29;
const int led03B_pin = 30;

const int led04R_pin = 31;
const int led04G_pin = 32;
const int led04B_pin = 33;

//RGB LEDs - Bottom Row
const int led05R_pin = 34;
const int led05G_pin = 35;
const int led05B_pin = 36;

const int led06R_pin = 37;
const int led06G_pin = 38;
const int led06B_pin = 39;

const int led07R_pin = 40;
const int led07G_pin = 41;
const int led07B_pin = 42;

const int led08R_pin = 43;
const int led08G_pin = 44;
const int led08B_pin = 45;

//OUTPUT JACKS - Top Row
const int jackOut01_pin = A0;
const int jackOut02_pin = A1;
const int jackOut03_pin = A2;
const int jackOut04_pin = A3;

//INPUT JACKS - Bottom Row
const int jackIn01_pin = A4;
const int jackIn02_pin = A5;
const int jackIn03_pin = A6;
const int jackIn04_pin = A7;

const int button01_pin = 10;

bool buttonState = 0;

int jackIn01_state = 0;
int jackIn02_state = 0;
int jackIn03_state = 0;
int jackIn04_state = 0;

bool combo01 = 0;     //will return true when 
bool combo02 = 0;
bool combo03 = 0;
bool combo04 = 0;

int sequence = 0;     //for tracking progress through puzzle

bool solve = 0;       //true when puzzle solved

void setup()
{
  pinMode(led01R_pin, OUTPUT);
  pinMode(led01G_pin, OUTPUT);
  pinMode(led01B_pin, OUTPUT);

  pinMode(led02R_pin, OUTPUT);
  pinMode(led02G_pin, OUTPUT);
  pinMode(led02B_pin, OUTPUT);

  pinMode(led03R_pin, OUTPUT);
  pinMode(led03G_pin, OUTPUT);
  pinMode(led03B_pin, OUTPUT);

  pinMode(led04R_pin, OUTPUT);
  pinMode(led04G_pin, OUTPUT);
  pinMode(led04B_pin, OUTPUT);

  pinMode(led05R_pin, OUTPUT);
  pinMode(led05G_pin, OUTPUT);
  pinMode(led05B_pin, OUTPUT);

  pinMode(led06R_pin, OUTPUT);
  pinMode(led06G_pin, OUTPUT);
  pinMode(led06B_pin, OUTPUT);

  pinMode(led07R_pin, OUTPUT);
  pinMode(led07G_pin, OUTPUT);
  pinMode(led07B_pin, OUTPUT);

  pinMode(led08R_pin, OUTPUT);
  pinMode(led08G_pin, OUTPUT);
  pinMode(led08B_pin, OUTPUT);

  pinMode(jackOut01_pin, OUTPUT);
  pinMode(jackOut02_pin, OUTPUT);
  pinMode(jackOut03_pin, OUTPUT);
  pinMode(jackOut04_pin, OUTPUT);

  pinMode(jackIn01_pin, INPUT);
  pinMode(jackIn02_pin, INPUT);
  pinMode(jackIn03_pin, INPUT);
  pinMode(jackIn04_pin, INPUT);

  pinMode(button01_pin, INPUT);

  Serial.begin(19200);
}

void loop()
{
  analogWrite(jackOut01_pin, 1023);
  analogWrite(jackOut02_pin, 768);
  analogWrite(jackOut03_pin, 512);
  analogWrite(jackOut04_pin, 256);
  
  jackIn01_state = analogRead(jackIn01_pin);
  jackIn02_state = analogRead(jackIn02_pin);
  jackIn03_state = analogRead(jackIn03_pin);
  jackIn04_state = analogRead(jackIn04_pin);

  jackRead(jackIn01_state);
  
}

void jackRead(int j)   //function for analog values at input jacks
{
  if (j > 768)                      //768 to 1023
  {
    Serial.println("01");
    
    digitalWrite(led01R_pin, HIGH);
    digitalWrite(led01G_pin, HIGH);
    digitalWrite(led01B_pin, HIGH);
  }
  else if (j > 512)                 //512 to 768
  {
    Serial.println("02");

    digitalWrite(led02R_pin, HIGH);
    digitalWrite(led02G_pin, HIGH);
    digitalWrite(led02B_pin, HIGH);
  }
  else if (j > 256)                 //256 to 512
  {
    Serial.println("03");

    digitalWrite(led03R_pin, HIGH);
    digitalWrite(led03G_pin, HIGH);
    digitalWrite(led03B_pin, HIGH);
  }
  else                              //0 to 256
  {
    Serial.println("04");

    digitalWrite(led04R_pin, HIGH);
    digitalWrite(led04G_pin, HIGH);
    digitalWrite(led04B_pin, HIGH);
  }
}
