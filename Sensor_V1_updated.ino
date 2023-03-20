#include "SparkFun_AS7265X.h" 
#include <DFRobot_DHT11.h>
#include <Wire.h>   



DFRobot_DHT11 DHT;
#define MoisturePin A0
#define dhtPin A1
#define GasSensor A4
#define pHpin A8

float calibration_value = 21.34;// FOR pH Sensor
int phval = 0; 
unsigned long int avgval; 
int buffer_arr[10],temp;



AS7265X spectral;
 
void setup() {
  Serial.begin(19200);
  Wire.begin();
  pinMode(MoisturePin, INPUT); // soil moisture reader pin
  pinMode(dhtPin, INPUT); //DHT11 Sensor 
  pinMode(GasSensor, INPUT); //Gas Sensor 
  pinMode(pHpin, INPUT); //pH Sensor 

  
}
 
void loop() {
  spectral.takeMeasurements(); //This is a hard wait while all 18 channels are measured
  int MoistureValue= analogRead(MoisturePin); 
  int GasSensorVal= analogRead(GasSensor);
  DHT.read(dhtPin);

  for(int i=0;i<10;i++){ 
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
  float ph_act = -5.70 * volt + calibration_value-3.3;
  Serial.print("Moisture Reading: ");
  Serial.println(MoistureValue);//reading moisture value
  Serial.print("Gas Sensor Reading: ");
  Serial.println(GasSensorVal);//reading gas sensor value
  Serial.print("Temperature Reading: ");
  Serial.println(DHT.temperature);//reading dht11 temperature reading
  Serial.print("Humidity Reading: ");
  Serial.println(DHT.humidity);//reading dht11 humidity reading
  
  Serial.print("Spectral Sensor Reading: ");//AS7265x SPECTRAL SENSOR READING
  Serial.print(spectral.getCalibratedA());
  Serial.print(",");
  Serial.print(spectral.getCalibratedB());
  Serial.print(",");
  Serial.print(spectral.getCalibratedC());
  Serial.print(",");
  Serial.print(spectral.getCalibratedD());
  Serial.print(",");
  Serial.print(spectral.getCalibratedE());
  Serial.print(",");
  Serial.print(spectral.getCalibratedF());
  Serial.print(",");
 
  Serial.print(spectral.getCalibratedG());
  Serial.print(",");
  Serial.print(spectral.getCalibratedH());
  Serial.print(",");
  Serial.print(spectral.getCalibratedI());
  Serial.print(",");
  Serial.print(spectral.getCalibratedJ());
  Serial.print(",");
  Serial.print(spectral.getCalibratedK());
  Serial.print(",");
  Serial.print(spectral.getCalibratedL());
  Serial.print(",");
 
  Serial.print(spectral.getCalibratedR());
  Serial.print(",");
  Serial.print(spectral.getCalibratedS());
  Serial.print(",");
  Serial.print(spectral.getCalibratedT());
  Serial.print(",");
  Serial.print(spectral.getCalibratedU());
  Serial.print(",");
  Serial.print(spectral.getCalibratedV());
  Serial.print(",");
  Serial.println(spectral.getCalibratedW()); 
  
  Serial.print("pH Sensor Reading: ");// pH Sensor Reading
  Serial.println(ph_act);
  
  delay(1000);// 1 sec delay

}