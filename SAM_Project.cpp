const int pir1 = 8; 
const int pir2 = 10; 
const int pir3 = 12; 
const int led1 = 2;    
const int led2 = 4;
const int led3 = 6;
const int ldrPin = A0; 

void setup() {
  pinMode(pir1, INPUT);
  pinMode(pir2, INPUT);
  pinMode(pir3, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  Serial.begin(9600); 
}

void loop() {
  int pir1val = digitalRead(pir1);
  int pir2val = digitalRead(pir2);
  int pir3val = digitalRead(pir3);
  int ldrValue = analogRead(ldrPin); 

  if (ldrValue > 750) { 
    if (pir1val == LOW && pir2val == HIGH && pir3val == HIGH) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
      Serial.println("Motion detected by PIR 1!");
    } 
    else if (pir1val == HIGH && pir2val == LOW && pir3val == HIGH) {
      digitalWrite(led2, HIGH);
      digitalWrite(led1, LOW);
      digitalWrite(led3, LOW);
      Serial.println("Motion detected by PIR 2!");
    } 
    else if (pir1val == HIGH && pir2val == HIGH && pir3val == LOW) {
      digitalWrite(led3, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led1, LOW);
      Serial.println("Motion detected by PIR 3!");
    } 
    else if (pir1val == LOW && pir2val == LOW && pir3val == LOW) {
      digitalWrite(led3, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led1, HIGH);
      Serial.println("Motion detected by all PIRs!");
    }
  } 
  else {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    //Serial.println("No motion detected or it's too bright.");
  }

  delay(200); 
}
