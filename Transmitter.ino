int state=0;
int buzzer = 3; 
int led = 13; 
unsigned int frecuenciapunto = 950; 
unsigned int frecuenciaguion = 5000; 
unsigned long duracionpunto = 400; 
unsigned long duracionguion= duracionpunto*3;
const int separaciondesimbolo=duracionpunto;
const int separaciondeletra=duracionpunto*3;
const int separaciondepalabra=duracionpunto*7;  



void setup() {
    pinMode(led, OUTPUT); // pin will be used to for output
    Serial.begin(9600); // 
    pinMode(buzzer,OUTPUT); 
}

void punto(){ 
  tone(buzzer,frecuenciapunto,duracionpunto);  
  digitalWrite(led,HIGH); 
  delay(300);
  digitalWrite(led,LOW);
  noTone(buzzer); 
  delay(separaciondesimbolo); 
  }


void guion(){ 
  tone(buzzer,frecuenciaguion,duracionguion);  
  digitalWrite(led,HIGH); 
  delay(900);
  digitalWrite(led,LOW);
  noTone(buzzer); 
    delay(separaciondesimbolo); 
  }

void loop() {
  if (Serial.available() > 0)
  {
    state = Serial.read(); // used to read incoming data
    
    switch(state)// see what was sent to the board
    {
      case '1': // if one was sent
       punto(); 
      break;
      case '0': // if 0 was sent
        guion();
      break;
      case '2': 
      delay(separaciondeletra); 
      default:
      break; 
    }
  }
}
 
