int IR1 = 8;
int IR2 = 12;
int IR3 = 13;
int LDR = 7;
int led1 = 3;
int led2 = 5;
int led3 = 6;
int val1;
int val2;
int val3;
int val4;

void setup()
{
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  pinMode(LDR, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  val1 = digitalRead(IR1);
  val2 = digitalRead(IR2);
  val3 = digitalRead(IR3);
  val4 = digitalRead(LDR);

  if (val1 == 1 && val4 == 0 && val2 == 1 && val3 == 1)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
  else if (val1 == 1 && val4 == 1 && val2 == 1 && val3 == 1)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
  }
  else if (val1 == 0 && val4 == 1 && val2 == 1 && val3 == 1)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
  }
  else if (val1 == 1 && val4 == 1 && val2 == 0 && val3 == 1)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
  }
  else if (val1 == 1 && val4 == 1 && val2 == 1 && val3 == 0)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
  }
}
