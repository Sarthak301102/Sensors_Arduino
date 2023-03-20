#include "DHT.h"


#define MoisturePin PA0
#define dht22Pin PA1
#define MQ5 PA2
#define MQ3 PA3
/*#define MQ6 PA4
#define pHpin PA5
#define ldrPin PA6*/

#define DHTTYPE DHT22 
DHT dht22(dht22Pin, DHTTYPE);


/*float calibration_value = 21.34;
int phval = 0; 
unsigned long int avgval; 
int buffer_arr[10],temp;*/

void setup() {
  // put your setup code here, to run once:
  pinMode(MoisturePin, INPUT); // soil moisture reader pin
  pinMode(dht22Pin, INPUT); //DHT22 Sensor 
  pinMode(MQ5, INPUT); //Gas Sensor MQ5
  pinMode(MQ3, INPUT); //Gas Sensor MQ3
  /*pinMode(MQ6, INPUT); //Gas Sensor MQ6
  pinMode(pHpin, INPUT);//pH sensor
  pinMode(ldrPin, INPUT); //ldr Sensor*/

  Serial.begin(19200);
  dht22.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
   float MoistureValue= analogRead(MoisturePin); 
   int MQ5val= analogRead(MQ5);
   int MQ3val= analogRead(MQ3);
   //int MQ6val= analogRead(MQ6);
   //float ldr = analogRead(ldrPin);
float t=dht22.readTemperature();
float h1=dht22.readHumidity();
 /*for(int i=0;i<10;i++){ 
  buffer_arr[i]=analogRead(pHpin);
  delay(30);
  }
 for(int i=0;i<9;i++){
  for(int j=i+1;j<10;j++){
  if(buffer_arr[i]>buffer_arr[j]){
  temp=buffer_arr[i];
  buffer_arr[i]=buffer_arr[j];
  buffer_arr[j]=temp;
      }
    }
  }
 avgval=0;
 for(int i=2;i<8;i++)
 avgval+=buffer_arr[i];
 float volt=(float)avgval*5.0/1024/6;
 float ph_act = -5.70 * volt + calibration_value-3.7;*/
  Serial.print("Soil Moisture Reading in %: ");
  Serial.println(100-(MoistureValue*100/4095));//reading moisture value
  Serial.print("MQ3 Reading: ");
  Serial.println(MQ3val);//reading gas sensor MQ3 value
  Serial.print("MQ5 Reading: ");
  Serial.println(MQ5val);//reading gas sensor MQ5 value
  /*Serial.print("MQ6 Reading: ");
  Serial.println(MQ6val);//reading gas sensor MQ6 value*/
   
  Serial.print("Temperature Reading dht22: ");
  Serial.println(t);//reading dht22 temperature reading 
  Serial.print("Humidity Reading dht22: ");
  Serial.println(h1);//reading dht22 humidity reading   
  /*Serial.print("pH Sensor Reading: ");//pH Sensor reading
  Serial.println(ph_act);
  Serial.print("Ldr reading in percentage: ");
  Serial.println((ldr/1023)*100);*/

  Serial.println();

   delay(500);// 1 sec delay
}
