void setup()
{
    pinMode(13,OUTPUT);
    pinMode(12,OUTPUT);
    pinMode(11,OUTPUT);
    pinMode(10,OUTPUT);
    pinMode(9,OUTPUT);
    pinMode(8,OUTPUT);
    pinMode(7,OUTPUT);
    pinMode(6,OUTPUT);
    pinMode(5,OUTPUT);
    pinMode(4,OUTPUT);
    pinMode(3,OUTPUT);
    Serial.begin(9600);
    pinMode(2, INPUT_PULLUP);
    tone(8,200,500);
    delay(250);
    tone(8,400,100);
}

int light =3;
int count=1;
int timedelay=100;//เวลาดีเลย์
void loop()
{
    for (int light=3; light<=13; light++)//ไฟขึ้น 
    {
    if (light==8) 
    {
        digitalWrite(light,0);
        continue;
    }
    digitalWrite(light,1);
    delay(timedelay);
    digitalWrite(light,0);
    if(digitalRead(2)==0)//เร่ง
    {
        count=count*2;
        timedelay=timedelay/2;
        Serial.println("Faster X 2 (Current Speed : X" + String(count) + ")");
        tone(8,400,100);
    }
    }


    for (int light=13; light>=3; light--) //ไฟลง
    {
    if (light==8) 
    {
        digitalWrite(light,0);
        continue;
    }
    digitalWrite(light,1);
    delay(timedelay);
    digitalWrite(light,0);
    if(digitalRead(2)==0)//เร่ง
    {
        count=count*2;
        timedelay=timedelay/2;
        Serial.println("Faster X 2 (Current Speed : X" + String(count) + ")");
        tone(8,400,100);
    }
    }
}
