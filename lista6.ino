#define ex1

#ifdef ex1
//6.1- Acrescente um buzzer a montagem. Modifique o programa para o led acender e o buzzer apitar.
int led = 13; 
int ldr = 0; 
int ldrvalor = 0; 
int buzzer = 7;

void setup() {
pinMode(led,OUTPUT);
pinMode(buzzer,OUTPUT);
Serial.begin(9600); 
}

void loop() {
ldrvalor = analogRead(ldr); 
Serial.println(ldrvalor);
if (ldrvalor>= 500){
digitalWrite(led,HIGH);
tone(buzzer, 264);}
else{
digitalWrite(led,LOW);
noTone(buzzer);}
delay(100);
}
#endif //ex1

#ifdef ex2
//6.2- Acrescente mais 2 leds a montagem. Conforme a luminosidade diminui os leds vão acendendo progressivamente. O buzzer deve apitar quando o último led acender.
int led = 13; 
int led2 = 12;
int led3 = 11;
int ldr = 0;
int ldrvalor = 0; 
int buzzer = 7;

void setup() {
pinMode(led,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(buzzer,OUTPUT);
Serial.begin(9600); 
}

void loop() {
  ldrvalor = analogRead(ldr);
  Serial.println(ldrvalor);
  if (ldrvalor>=500)
  {
  digitalWrite(led,HIGH);
  	noTone(buzzer);
  }
  else
  {
  digitalWrite(led,LOW);
  noTone(buzzer);
  }
  if (ldrvalor>=700)
  {
  digitalWrite(led2,HIGH);
    noTone(buzzer);
  }
  else
  {
  digitalWrite(led2,LOW);
  noTone(buzzer);
  }
  if (ldrvalor>=900)
  {
  digitalWrite(led3,HIGH);
    tone(buzzer, 264);
  }
  else
  {
  digitalWrite(led3,LOW);
  noTone(buzzer);
  }
  delay(100);
}

#endif //ex2



#ifdef ex3
//6.3- Transforme a leitura do sensor de luminosidade em uma função que retorna o valor lido.
int led = 13; 
int led2 = 12;
int led3 = 11;
int ldr = 0;
int ldrvalor = 0; 
int buzzer = 7;
int valor;

void setup() {
pinMode(led,OUTPUT); 
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(buzzer,OUTPUT);
Serial.begin(9600); 
}

int leitura(int ldr)
{
  ldrvalor=analogRead(ldr);
  Serial.print("Luminosidade: "); 
  Serial.println(ldrvalor);  
  return ldrvalor;
}

void loop() {
  
  valor = leitura(ldr);
  
  if (ldrvalor>=500)
  {
  digitalWrite(led,HIGH);
  	noTone(buzzer);
  }
  else
  {
  digitalWrite(led,LOW);
  noTone(buzzer);
  }
  if (ldrvalor>=700)
  {
  digitalWrite(led2,HIGH);
    noTone(buzzer);
  }
  else
  {
  digitalWrite(led2,LOW);
  noTone(buzzer);
  }
  if (ldrvalor>=900)
  {
  digitalWrite(led3,HIGH);
  tone(buzzer, 264);
  }
  else
  {
  digitalWrite(led3,LOW);
  noTone(buzzer);
  }
  delay(100);
}

#endif //ex3

#ifdef ex4

//6.4- Transforme o controle de cada dos led em uma função.
int led = 13; 
int led2 = 12;
int led3 = 11;
int ldr = 0;
int ldrvalor = 0; 
int buzzer = 7;
int valor;

void setup() {
pinMode(led,OUTPUT); 
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(buzzer,OUTPUT);
Serial.begin(9600);  
}

int leitura(int ldr)
{
  ldrvalor=analogRead(ldr);
  Serial.print("Luminosidade: "); 
  Serial.println(ldrvalor);
  return ldrvalor;
}

void controled() {
if (ldrvalor>=500)
  {
  digitalWrite(led,HIGH);
  }
  else
  {
  digitalWrite(led,LOW);
  }
}

void controled2() {
if (ldrvalor>=700)
  {
  digitalWrite(led2,HIGH);
  }
  else
  {
  digitalWrite(led2,LOW);
  }
}

void controled3() {
if (ldrvalor>=900)
  {
  digitalWrite(led3,HIGH);
  }
  else
  {
  digitalWrite(led3,LOW);
  }
}

void loop() {
  
  valor = leitura(ldr);
  controled();
  controled2();
  controled3();
  
  if (ldrvalor>900)
  {
  tone(buzzer, 264);
  }
  else
  {
  noTone (buzzer);
  }
  
  delay(100);
}

#endif //ex4


#ifdef ex5
//6.5- Transforme o controle do buzzer em uma função. 
int led = 13; 
int led2 = 12;
int led3 = 11;
int ldr = 0;
int ldrvalor = 0; 
int buzzer = 7;
int valor;

void setup() {
pinMode(led,OUTPUT); 
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(buzzer,OUTPUT);
Serial.begin(9600);  
}

int leitura(int ldr)
{
  ldrvalor=analogRead(ldr);
  Serial.print("Luminosidade: "); 
  Serial.println(ldrvalor);
  return ldrvalor;
}

void controled() {
if (ldrvalor>=500)
  {
  digitalWrite(led,HIGH);
  }
  else
  {
  digitalWrite(led,LOW);
  }
}

void controled2() {
if (ldrvalor>=700)
  {
  digitalWrite(led2,HIGH);
  }
  else
  {
  digitalWrite(led2,LOW);
  }
}

void controled3() {
if (ldrvalor>=900)
  {
  digitalWrite(led3,HIGH);
  }
  else
  {
  digitalWrite(led3,LOW);
  }
}

void controlebuzzer(int ldrvalor) {
  if (ldrvalor>900)
  {
  tone(buzzer, 264);
  }
  else
  {
  noTone (buzzer);
  }
  
}

void loop() {
  
  valor = leitura(ldr);
  controled();
  controled2();
  controled3();
  controlebuzzer(ldrvalor);
  
  delay(100);
}

#endif //ex5