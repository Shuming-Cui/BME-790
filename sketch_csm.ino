int sensorPin1 = A1;
int sensorPin2 = A2;
float ValT1 = 0;
float ValT2 = 0;
int doorPin = A3;
int doorVal = 0;
const float thresh = 512;
const float hys = 20;
int AlarmPin = 12;
int HeatPin = 10;
bool Alert = false;

void Comparison(float T1,float T2){
if (abs(T1 - T2) < 0.2*T1){
  Alert = false;
} else {
  Alert = true;
}
}

void setup() {
  // put your setup code here, to run once:
 pinMode(doorPin,INPUT_PULLUP);
 pinMode(HeatPin,OUTPUT);
 pinMode(AlarmPin,OUTPUT);
 Serial.begin(9600);
}

void loop() {

// put your main code here, to run repeatedly:
ValT1 = analogRead(sensorPin1);
ValT2 = analogRead(sensorPin2);
doorVal = digitalRead(doorPin);

Serial.print (ValT1);
Serial.print (" ");
Serial.print (ValT2);
Serial.print (" ");
Serial.print (doorVal);
Serial.print (" ");
Serial.println (Alert);


if (ValT1 > thresh + hys){
  digitalWrite(HeatPin, HIGH);
  Alert = false;
}else if (ValT1 < thresh - hys) {
  digitalWrite(HeatPin, LOW);
  Alert = true;
} else {
  Alert = false;
}

if(doorVal == LOW){
  Alert = true;
}

if(Alert == false){
Comparison(ValT1,ValT2);
}

if(Alert == true){
  digitalWrite(AlarmPin, HIGH);
  digitalWrite(HeatPin,LOW);
}else{
  digitalWrite(AlarmPin,LOW);
}

}
