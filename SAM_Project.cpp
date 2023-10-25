const int ir1 = 8; 
const int ir2 = 10; 
const int ir3 = 12; 
const int led1 = 2;    
const int led2 = 4;
const int led3 = 6;
const int ldrPin = A0; 

void setup() {
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  Serial.begin(9600); 
}

void loop() {
  int ir1val = digitalRead(ir1);
  int ir2val = digitalRead(ir2);
  int ir3val = digitalRead(ir3);
  int ldrValue = analogRead(ldrPin); 

  if (ldrValue > 750) { 
    if (ir1val == LOW && ir2val == HIGH && ir3val == HIGH) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
      Serial.println("Motion detected by IR 1!");
    } 
    else if (ir1val == HIGH && ir2val == LOW && ir3val == HIGH) {
      digitalWrite(led2, HIGH);
      digitalWrite(led1, LOW);
      digitalWrite(led3, LOW);
      Serial.println("Motion detected by IR 2!");
    } 
    else if (ir1val == HIGH && ir2val == HIGH && ir3val == LOW) {
      digitalWrite(led3, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led1, LOW);
      Serial.println("Motion detected by IR 3!");
    } 
    else if (ir1val == LOW && ir2val == LOW && ir3val == LOW) {
      digitalWrite(led3, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led1, HIGH);
      Serial.println("Motion detected by all IRs!");
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
