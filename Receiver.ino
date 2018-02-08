const int sensorPIN = A0;
const int sampleWindow = 50; // Ancho ventana en mS (50 mS = 20Hz)
String valor="x"; 
int contadorpunto=0; 
int contadorguion=0; 
int contadornada=0; 
int contadormillon=0; 
int foco=2; 
int contadorx=0; 

void setup() 
{
   Serial.begin(9600);
   pinMode(foco,OUTPUT); 
}
 
void loop() 
{
  if(contadormillon<=150){ 
    digitalWrite(foco,HIGH); 
    contadormillon++; 
   unsigned long startMillis= millis();
 
   unsigned int signalMax = 0;
   unsigned int signalMin = 1024;
 
   // Recopilar durante la ventana
   unsigned int sample;
   while (millis() - startMillis < sampleWindow)
   {
      sample = analogRead(sensorPIN);
      if (sample < 1024)
      {
         if (sample > signalMax)
         {
            signalMax = sample;  // Actualizar máximo
         }
         else if (sample < signalMin)
         {
            signalMin = sample;  // Actualizar mínimo
         }
      }
   }
   unsigned int peakToPeak = signalMax - signalMin;  // Amplitud del sonido
   double volts = (peakToPeak * 5.0) / 1024;  // Convertir a tensión

  if(volts>=0&&volts<=0.5){ 
    valor="x"; 
    contadorx++; 
  }
  
  if(volts>0.7&&volts<=1.10){ 
    contadorx=0; 
    valor="." ; 
   
  }
    
  if(volts>=1.5){ 
    valor="-"; 
    contadorx=0; 
  }
    
  Serial.println(valor); 
  }
  else{ 
    Serial.println('y');
    Serial.println(contadormillon); 
    digitalWrite(foco,LOW); 
   Serial.end(); 
  }
}
