// C++ code
//
int diody[]={9,10,11,12};

unsigned long zapCzas=0;

void setup()
{
  for(int i=0; i<4; i++){
  pinMode(diody[i], OUTPUT);
  }
}

void loop()
{
  unsigned long czas = millis();
  
  if(czas-zapCzas<4000){
    digitalWrite(10, LOW);
  	digitalWrite(11,LOW);
  	digitalWrite(9, HIGH);
  	digitalWrite(12,HIGH);
  }
  else if(czas-zapCzas<8000){
    digitalWrite(9, LOW);
  	digitalWrite(12,LOW);
    digitalWrite(10, HIGH);
  	digitalWrite(11,HIGH);
    czas= millis();
  }
  else{
  zapCzas=czas;
  }
}