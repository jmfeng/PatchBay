const int led01R = 22;
const int led01G = 23;
const int led01B = 24;

const int led02R = 25;
const int led02G = 26;
const int led02B = 27;

const int led03R = 28;
const int led03G = 29;
const int led03B = 30;

const int led04R = 31;
const int led04G = 32;
const int led04B = 33;

const int led05R = 34;
const int led05G = 35;
const int led05B = 36;

const int led06R = 37;
const int led06G = 38;
const int led06B = 39;

const int led07R = 40;
const int led07G = 41;
const int led07B = 42;

const int led08R = 43;
const int led08G = 44;
const int led08B = 45;

const int jackOut01 = 6;
const int jackOut02 = 7;
const int jackOut03 = 8;
const int jackOut04 = 9;

const int jackIn01 = 2;
const int jackIn02 = 3;
const int jackIn03 = 4;
const int jackIn04 = 5;

const int b01 = 10;

int bState = 0;

int jackIn01_state = 0;
int jackIn02_state = 0;
int jackIn03_state = 0;
int jackIn04_state = 0;

int combo01 = 0;
int combo02 = 0;
int combo03 = 0;
int combo04 = 0;

int sequence = 0;

void setup()
{
  pinMode(led01R, OUTPUT);
  pinMode(led01G, OUTPUT);
  pinMode(led01B, OUTPUT);

  pinMode(led02R, OUTPUT);
  pinMode(led02G, OUTPUT);
  pinMode(led02B, OUTPUT);

  pinMode(led03R, OUTPUT);
  pinMode(led03G, OUTPUT);
  pinMode(led03B, OUTPUT);

  pinMode(led04R, OUTPUT);
  pinMode(led04G, OUTPUT);
  pinMode(led04B, OUTPUT);

  pinMode(led05R, OUTPUT);
  pinMode(led05G, OUTPUT);
  pinMode(led05B, OUTPUT);

  pinMode(led06R, OUTPUT);
  pinMode(led06G, OUTPUT);
  pinMode(led06B, OUTPUT);

  pinMode(led07R, OUTPUT);
  pinMode(led07G, OUTPUT);
  pinMode(led07B, OUTPUT);

  pinMode(led08R, OUTPUT);
  pinMode(led08G, OUTPUT);
  pinMode(led08B, OUTPUT);

  pinMode(jackOut01, OUTPUT);
  pinMode(jackOut02, OUTPUT);
  pinMode(jackOut03, OUTPUT);
  pinMode(jackOut04, OUTPUT);

  pinMode(jackIn01, INPUT);
  pinMode(jackIn02, INPUT);
  pinMode(jackIn03, INPUT);
  pinMode(jackIn04, INPUT);

  pinMode(b01, INPUT);

  Serial.begin(19200);
}

void loop()
{
    jackIn01_state = digitalRead(jackIn01);
    jackIn02_state = digitalRead(jackIn02);
    jackIn03_state = digitalRead(jackIn03);
    jackIn04_state = digitalRead(jackIn04);
     
    digitalWrite(jackOut01, HIGH);
    digitalWrite(jackOut02, HIGH);
    digitalWrite(jackOut03, HIGH);
    digitalWrite(jackOut04, HIGH);

    digitalWrite(led01R, HIGH);
    digitalWrite(led01G, LOW);
    digitalWrite(led01B, LOW);

    Serial.println(jackIn01_state);

    if (jackIn01_state == HIGH)
    {
      //Serial.println("Y");
      combo01 = 1;
      sequence++;
      digitalWrite(led01R, HIGH); 
    }
 
}
