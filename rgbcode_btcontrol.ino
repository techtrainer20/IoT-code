int color=0;
 
//define the RGB pind
int red = 9;
int green = 10;
int blue = 11;
 
char received;
 
void setup()  { 
  Serial.begin(9600);     //Start the serial comunication for the bluetooth module
  pinMode(red, OUTPUT);   //Red color pwm pin defined as output
  pinMode(green, OUTPUT); //Green color pwm pin defined as output
  pinMode(blue, OUTPUT);  //Blue color pwm pin defined as output
  
  //Give first value of the PWM 0, we start with the RGB LEDs off
  analogWrite(red,0);
  analogWrite(green,0);
  analogWrite(blue,0);
 
 } 
 
void loop()  { 
  
  while(Serial.available()>0){
    // read the bluetoot data and store it
     String color = Serial.readString();
   // String Rec = String(color);
   // if (Rec != "colors")
    //{
    Serial.println(color); //This is to visualise the received character on the serial monitor
   // }  
 // }
 
  //LEDs off
  if (color == "OFF")
  {
    analogWrite(red,0);
    analogWrite(green,0);
    analogWrite(blue,0);
  }
  //White
  if (color == "White")
  {
    analogWrite(red,255);
    analogWrite(green,255);
    analogWrite(blue,255);
  }
  //Red
  if (color == "red")
  {
    analogWrite(red,255);
    analogWrite(green,0);
    analogWrite(blue,0);
  }
  //Green
  if (color == "green")
  {
    analogWrite(red,0);
    analogWrite(green,255);
    analogWrite(blue,0);
  }
  //Blue
  if (color == "blue")
  {
    analogWrite(red,0);
    analogWrite(green,0);
    analogWrite(blue,255);
  }
  //Orange
  if (color == "orange")
  {
    analogWrite(red,255);
    analogWrite(green,153);
    analogWrite(blue,0);
  }
  //Violet
  if (color == "violet")
  {
    analogWrite(red,102);
    analogWrite(green,0);
    analogWrite(blue,153);
  }
  //Cyan
  if (color == "yan")
  {
    analogWrite(red,0);
    analogWrite(green,255);
    analogWrite(blue,255);
  }
  //Yellow 
  if (color == "yellow")
  {
    analogWrite(red,255);
    analogWrite(green,204);
    analogWrite(blue,0);
  }  
  if(color == "glow")
  {
    
    while(1){glow(color);};
    Serial.print(color);
    //break;
   
   }
   
  }
}
  
  
 
void glow(String str)
{

  for(int i=0;i<=255;i++)
  {
    analogWrite(red,i);
    analogWrite(blue,0);
       analogWrite(green,0);
    Serial.println("red ");
    Serial.print(i);
    if(i>=255)
    {
      for(int j=0;j<=i;j++)
     {
      analogWrite(red,0);
    analogWrite(blue,j);
    analogWrite(green,0);
    Serial.println("blue ");
    Serial.print(j);
    if(j>=255)
    {
      for(int k=0;k<=j;k++)
    {
    analogWrite(red,0);
    analogWrite(green,k);
    analogWrite(blue,0);
    Serial.println(k);
    if(k>=255)
    {
      for(int m=0;m<=k;m++)
    {
    analogWrite(red,m);
    analogWrite(green,0);
    analogWrite(blue,m);
    Serial.println(m);
    
    if(m>=255)
    {
      for(int v=0;v<=m;v++)
    {
    analogWrite(red,0);
    analogWrite(green,v);
    analogWrite(blue,v);
    Serial.println(v);
    if(v>=255)
    {
      for(int y=0;y<=v;y++)
    {
    analogWrite(red,y);
    analogWrite(green,y);
    analogWrite(blue,0);
    Serial.println(y);
    if(y>=255)
    {
      for(int x=0;x<=y;x++)
    {
    analogWrite(red,128);
    analogWrite(green,0);
    analogWrite(blue,128);
    Serial.println(y);
   // return str;
   // String str =Serial.readString();
    }}}}}}}}}}}}}}
    
/*/Serial.println("green ");
   // 
    Serial.print("color");
    Serial.print(color);
    //delay(1);
    //return str=Serial.readString(); 
    }/* 
  }}/*/
        
    
    
    
    
    
   
    
