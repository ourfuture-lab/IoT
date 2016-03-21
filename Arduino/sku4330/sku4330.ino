int bizhangPin = 3;//定义避障传感器接口
int ledPin =  13;  //定义 LED 接口
int buttonState = 0;

void setup() 
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);//定义 LED 为输出模式      
  pinMode(bizhangPin, INPUT);//定义避障传感器为输入模式      
}

void loop()
{
  buttonState = digitalRead(bizhangPin);//读取避障传感器的值并赋给buttonState
  if (buttonState == LOW) 
  {       
    digitalWrite(ledPin, HIGH);//前方有障碍物时，LED亮  
  } 
  else 
  {
    digitalWrite(ledPin, LOW); 
  }  
  delay(2000);
}
