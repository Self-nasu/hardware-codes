int l1 = 2;
int l2 = 7;
int frame = 41.6666666667;

void setup()
{
  pinMode(l1,OUTPUT);
  pinMode(l2,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  
  delay(14*frame);
  
  digitalWrite(l1,HIGH);
  delay(2*frame);
  digitalWrite(l1,LOW);
  
  delay(50*frame);
  
  digitalWrite(l1,HIGH);
  delay(2*frame);
  digitalWrite(l1,LOW);
  
  delay(35*frame);
  
  digitalWrite(l2,HIGH);
  delay(2*frame);
  digitalWrite(l2,LOW);
  
  delay(2*frame);
  
  digitalWrite(l2,HIGH);
  delay(2*frame);
  digitalWrite(l2,LOW);
  
  delay(4*frame);
  
  digitalWrite(l2,HIGH);
  delay(2*frame);
  digitalWrite(l2,LOW);
  
  delay(5*frame);
  
  digitalWrite(l2,HIGH);
  delay(2*frame);
  digitalWrite(l2,LOW);
  
  delay(5*frame);
  
  digitalWrite(l2,HIGH);
  delay(2*frame);
  digitalWrite(l2,LOW);
  
  delay(11*frame);
  
  digitalWrite(l1,HIGH);
  delay(2*frame);
  digitalWrite(l1,LOW);
  
  delay(12*frame);
  
  digitalWrite(l1,HIGH);
  delay(2*frame);
  digitalWrite(l1,LOW);
  
  delay(15*frame);
  
  digitalWrite(l1,HIGH);
  delay(2*frame);
  digitalWrite(l1,LOW);
  
  delay(9*frame);
  
  digitalWrite(l1,HIGH);
  delay(2*frame);
  digitalWrite(l1,LOW);
  
  delay(8*frame);
  
  digitalWrite(l1,HIGH);
  delay(2*frame);
  digitalWrite(l1,LOW);
  
  delay(10*frame);
  
  digitalWrite(l1,HIGH);
  delay(2*frame);
  digitalWrite(l1,LOW);
  
  delay(8*frame);
  
  digitalWrite(l1,HIGH);
  delay(2*frame);
  digitalWrite(l1,LOW);
}