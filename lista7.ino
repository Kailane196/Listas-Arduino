#define ex3

#ifdef ex1
//7.1– Acrescente um buzzer a montagem. 
//Modifique o programa para o led acender e o buzzer apitar. 
int lm = A0; 
int buzzer = 7;
float temperatura; 
int led = 13; 

void setup() { 
pinMode(led,OUTPUT);
pinMode(buzzer,OUTPUT);
Serial.begin(9600); 
}

void loop() { 
temperatura = (float(analogRead(lm))*5.0/(1023))/0.01; 
Serial.print("Temperatura: "); 
Serial.println(temperatura); 
  
if (temperatura >= 27){      
digitalWrite(led,HIGH);
tone(buzzer,264);
}
else {     
digitalWrite(led,LOW); 
noTone(buzzer);
}
delay(100); 
} 
#endif //ex1

#ifdef ex2 
//7.2– Acrescente mais 2 leds a montagem. 
//Conforme a temperatura aumenta os leds vão acendendo progressivamente. 
//O buzzer deve apitar quando o último led acender.
int lm = A0; 
int buzzer = 7;
float temperatura; 
int led = 13;
int led2 = 10;
int led3 = 9;

void setup() { 
pinMode(led,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(buzzer,OUTPUT);
Serial.begin(9600); 
}

void loop() { 
temperatura = (float(analogRead(lm))*5.0/(1023))/0.01; 
Serial.print("Temperatura: "); 
Serial.println(temperatura); 

if (temperatura >= 30){
digitalWrite(led,HIGH);
noTone(buzzer);
}  
else{
digitalWrite(led,LOW);
noTone(buzzer);
}

if (temperatura >= 80){
digitalWrite(led2,HIGH);
noTone(buzzer);
}  
else{
digitalWrite(led2,LOW);
noTone(buzzer);
}
  
if (temperatura >= 130){      
digitalWrite(led3,HIGH);
tone(buzzer,264);
}
else {     
digitalWrite(led3,LOW); 
noTone(buzzer);
}
delay(100); 
}
#endif //ex2

#ifdef ex3
//7.3- Transforme a leitura do sensor de temperatura em uma função que retorna o valor lido.
int lm = A0; 
int buzzer = 7;
float temperatura; 
int led = 13;
int led2 = 10;
int led3 = 9;
int tempvalor = 0;

void setup() { 
pinMode(led,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(buzzer,OUTPUT);
Serial.begin(9600); 
}

int leitura(float temperatura)
{
tempvalor=analogRead(temperatura);
temperatura = (float(analogRead(lm))*5.0/(1023))/0.01; 
Serial.print("Temperatura: "); 
Serial.println(temperatura);   
return temperatura;
}

void loop() { 
tempvalor = leitura(temperatura);

if (tempvalor >= 30){
digitalWrite(led,HIGH);
noTone(buzzer);
}  
else{
digitalWrite(led,LOW);
noTone(buzzer);
}

if (tempvalor >= 80){
digitalWrite(led2,HIGH);
noTone(buzzer);
}  
else{
digitalWrite(led2,LOW);
noTone(buzzer);
}
  
if (tempvalor >= 130){      
digitalWrite(led3,HIGH);
tone(buzzer,264);
}
else {     
digitalWrite(led3,LOW); 
noTone(buzzer);
}
delay(100); 
}
#endif //ex3

#ifdef ex4
//7.4– Transforme o controle de cada led em uma função. 
int lm = A0; 
int buzzer = 7;
float temperatura; 
int led = 13;
int led2 = 10;
int led3 = 9;
int tempvalor = 0;

void setup() { 
pinMode(led,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(buzzer,OUTPUT);
Serial.begin(9600); 
}

int leitura(float temperatura)
{
tempvalor=analogRead(temperatura);
temperatura = (float(analogRead(lm))*5.0/(1023))/0.01; 
Serial.print("Temperatura: "); 
Serial.println(temperatura);   
return temperatura;
}

void controled(){
if (tempvalor >= 30){
digitalWrite(led,HIGH);
noTone(buzzer);
}  
else{
digitalWrite(led,LOW);
noTone(buzzer);
}
}

void controled2(){
if (tempvalor >= 80){
digitalWrite(led2,HIGH);
noTone(buzzer);
}  
else{
digitalWrite(led2,LOW);
noTone(buzzer);
}
}

void controled3(){
if (tempvalor >= 130){      
digitalWrite(led3,HIGH);
tone(buzzer,264);
}
else {     
digitalWrite(led3,LOW); 
noTone(buzzer);
}
}

void loop() { 
tempvalor = leitura(temperatura);
controled();
controled2();
controled3();
delay(100); 
}
#endif //ex4

#ifdef ex5
//7.5– Transforme o controle do buzzer em uma função.
int lm = A0; 
int buzzer = 7;
float temperatura; 
int led = 13;
int led2 = 10;
int led3 = 9;
int tempvalor = 0;

void setup() { 
pinMode(led,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(buzzer,OUTPUT);
Serial.begin(9600); 
}

int leitura(float temperatura)
{
tempvalor=analogRead(temperatura);
temperatura = (float(analogRead(lm))*5.0/(1023))/0.01; 
Serial.print("Temperatura: "); 
Serial.println(temperatura);   
return temperatura;
}

void controled(){
if (tempvalor >= 30)
digitalWrite(led,HIGH); 
else
digitalWrite(led,LOW);
}

void controled2(){
if (tempvalor >= 80)
digitalWrite(led2,HIGH); 
else
digitalWrite(led2,LOW);
}

void controled3(){
if (tempvalor >= 130)      
digitalWrite(led3,HIGH);
else    
digitalWrite(led3,LOW); 
}

void controlebuzzer(int tempvalor) {
  if (tempvalor>130)
  {
  tone(buzzer, 264);
  }
  else
  {
  noTone (buzzer);
  } 
} 

void loop() { 
tempvalor = leitura(temperatura);
controled();
controled2();
controled3();
controlebuzzer(tempvalor);
delay(100); 
}
#endif //ex5