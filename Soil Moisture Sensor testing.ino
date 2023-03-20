#define MoisturePin PA6
void setup() {
  // put your setup code here, to run once:
  pinMode(MoisturePin, INPUT); // soil moisture reader pin
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
   int MoistureValue= analogRead(MoisturePin); 
   Serial.println(100-MoistureValue*100/4095);
  delay(500);// 0.5 sec delay
}
