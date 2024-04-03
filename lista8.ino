#define ex3

#ifdef ex1
//8.1- Monte mais 1 led e modifique o programa para que os 2 leds sejam controlados pelo potenciômetro. 
int led = 13;
int led2 = 10;
int pwmpin = A0; 
unsigned int valor; 
unsigned int pwm; 

void setup() { 
pinMode(led, OUTPUT);
pinMode(led2, OUTPUT);
Serial.begin(9600); 
} 

void loop() { 
valor = analogRead(pwmpin); 
  
Serial.println(valor);   
pwm = map(valor, 0, 1023, 0, 255);
analogWrite(led,pwm);

analogWrite(led2,pwm);
} 
#endif //ex1

#ifdef ex2
//8.2– Modifique o programa para que os leds funcionem invertidos. 
//Com a variação do potenciômetro 1 led vai acendendo e outro led vai apagando. 
int led = 13;
int led2 = 10;
int pwmpin = A0; 
unsigned int valor; 
unsigned int pwm; 

void setup() { 
pinMode(led, OUTPUT);
pinMode(led2, OUTPUT);
Serial.begin(9600); 
} 

void loop() { 
valor = analogRead(pwmpin); 
  
Serial.println(valor);   
pwm = map(valor, 0, 1023, 0, 255);

  if(valor>500){
analogWrite(led,HIGH);
analogWrite(led2,LOW);
  }
  else{
analogWrite(led2,HIGH);
analogWrite(led,LOW);
} 
}
#endif //ex2

#ifdef ex3
//8.3– Monte mais 1 led. Conforme o potenciômetro vai variando, os leds vão acendendo progressivamente. 
int led = 13;
int led2 = 10;
int led3 = 9;
int pwmpin = A0; 
unsigned int valor; 
unsigned int pwm; 

void setup() { 
pinMode(led, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
Serial.begin(9600); 
} 

void loop() { 
valor = analogRead(pwmpin); 
  
Serial.println(valor);   
pwm = map(valor, 0, 1023, 0, 255);

if(valor>300){
analogWrite(led,pwm);
}
if(valor>500){
analogWrite(led2,pwm);
}
if(valor>700){
analogWrite(led3,pwm);
} 
}
#endif //ex3

#ifdef ex4
//8.4– Monte o buzzer e quando o último led acender apite o buzzer junto. 
int led = 13;
int led2 = 10;
int led3 = 9;
int buzzer = 7;
int pwmpin = A0; 
unsigned int valor; 
unsigned int pwm; 

void setup() { 
pinMode(buzzer, OUTPUT);
pinMode(led, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
Serial.begin(9600); 
} 

void loop() { 
valor = analogRead(pwmpin); 
  
Serial.println(valor);   
pwm = map(valor, 0, 1023, 0, 255);

if(valor>300){
analogWrite(led,pwm);
noTone(buzzer);
}
if(valor>500){
analogWrite(led2,pwm);
noTone(buzzer);
}
if(valor>700){
analogWrite(led3,pwm);
tone(buzzer,264);
} 
}
#endif //ex4

#ifdef ex5
//8.5– Transforme a leitura do potenciômetro em uma função. 
int led = 13;
int led2 = 10;
int led3 = 9;
int buzzer = 7;
int pwmpin = A0; 
unsigned int valor; 
unsigned int pwm;
int pwmvalor = 0;

void setup() { 
pinMode(buzzer, OUTPUT);
pinMode(led, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
Serial.begin(9600); 
} 
   
int leitura(int pwmpin)
{
pwmvalor=analogRead(pwmpin);
Serial.print("Potencia: "); 
Serial.println(pwmvalor);
return pwmvalor;
}

void loop() { 
pwm = map(valor, 0, 1023, 0, 255);
valor = leitura(pwmpin);
  
if(valor>300){
analogWrite(led,pwm);
noTone(buzzer);
}
if(valor>500){
analogWrite(led2,pwm);
noTone(buzzer);
}
if(valor>700){
analogWrite(led3,pwm);
tone(buzzer,264);
} 
}
#endif //ex5

#ifdef ex6
//8.6– Transforme a mudança de escala (cálculo) em uma função. 
int led = 13;
int led2 = 10;
int led3 = 9;
int buzzer = 7;
int pwmpin = A0; 
unsigned int valor; 
unsigned int pwm;
int pwmvalor = 0;
int esc;

void setup() { 
pinMode(buzzer, OUTPUT);
pinMode(led, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
Serial.begin(9600); 
} 
   
int leitura(int pwmpin)
{
pwmvalor=analogRead(pwmpin);
Serial.print("Potencia: "); 
Serial.println(pwmvalor);
return pwmvalor;
}

int escala(int pwm){
pwm = map(valor, 0, 1023, 0, 255);
return pwm;
}

void loop() { 
valor = leitura(pwmpin);
esc=escala(pwm);
  
if(valor>300){
analogWrite(led,pwm);
noTone(buzzer);
}
if(valor>500){
analogWrite(led2,pwm);
noTone(buzzer);
}
if(valor>700){
analogWrite(led3,pwm);
tone(buzzer,264);
} 
}
#endif //ex6

#ifdef ex7
//8.7– Transforme o controle de cada dos led em uma função. 
int led = 13;
int led2 = 10;
int led3 = 9;
int buzzer = 7;
int pwmpin = A0; 
unsigned int valor; 
unsigned int pwm;
int pwmvalor = 0;
int esc;

void setup(){ 
pinMode(buzzer, OUTPUT);
pinMode(led, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
Serial.begin(9600); 
} 
   
int leitura(int pwmpin){
pwmvalor=analogRead(pwmpin);
Serial.print("Potencia: "); 
Serial.println(pwmvalor);
return pwmvalor;
}

int escala(int pwm){
pwm = map(valor, 0, 1023, 0, 255);
return pwm;
}

void controled(){
if(valor>300){
analogWrite(led,pwm);
noTone(buzzer);
}
}

void controled2(){
if(valor>500){
analogWrite(led2,pwm);
noTone(buzzer);
}
}

void controled3(){
if(valor>700){
analogWrite(led3,pwm);
tone(buzzer,264);
} 
}

void loop() { 
valor = leitura(pwmpin);
esc=escala(pwm);
controled();
controled2();
controled3();
}
#endif //ex7

#ifdef ex8
//8.8– Transforme o controle do buzzer em uma função. 
int led = 13;
int led2 = 10;
int led3 = 9;
int buzzer = 7;
int pwmpin = A0; 
unsigned int valor; 
unsigned int pwm;
int pwmvalor = 0;
int esc;

void setup() { 
pinMode(buzzer, OUTPUT);
pinMode(led, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
Serial.begin(9600); 
} 
   
int leitura(int pwmpin) {
pwmvalor=analogRead(pwmpin);
Serial.print("Potencia: "); 
Serial.println(pwmvalor);
return pwmvalor;
}

int escala(int pwm) {
pwm = map(valor, 0, 1023, 0, 255);
return pwm;
}

void controled(){
if(valor>300)
analogWrite(led,pwm);
}

void controled2(){
if(valor>500)
analogWrite(led2,pwm);
}

void controled3(){
if(valor>700)
analogWrite(led3,pwm);
}

void controlebuzzer(int pwmvalor) {
if (pwmvalor>700)
tone(buzzer, 264);
else
noTone(buzzer);
}

void loop() { 
valor = leitura(pwmpin);
esc=escala(pwm);
controled();
controled2();
controled3();
controlebuzzer(pwmvalor);
}
#endif //ex8

#ifdef ex9
//8.9– Transforme a escrita no led em uma função.
int led = 13;
int led2 = 10;
int led3 = 9;
int buzzer = 7;
int pwmpin = A0; 
unsigned int valor; 
unsigned int pwm;
int pwmvalor = 0;
int esc;

void setup() { 
pinMode(buzzer, OUTPUT);
pinMode(led, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
Serial.begin(9600); 
} 
   
int leitura(int pwmpin) {
pwmvalor=analogRead(pwmpin);
Serial.print("Potencia: "); 
Serial.println(pwmvalor);
return pwmvalor;
}

int escala(int pwm) {
pwm = map(valor, 0, 1023, 0, 255);
return pwm;
}

void controled(){
analogWrite(led,pwm);
}

void controled2(){
analogWrite(led2,pwm);
}

void controled3(){
analogWrite(led3,pwm);
}

void controledosled(int valor) {
if(valor>300)
controled();
if(valor>500)
controled2();
if(valor>700)
controled3();
}

void controlebuzzer(int pwmvalor) {
if (pwmvalor>700)
tone(buzzer, 264);
else
noTone(buzzer);
}

void loop() { 
valor=leitura(pwmpin);
esc=escala(pwm);
controledosled(valor);
controlebuzzer(pwmvalor);
}
#endif //ex9