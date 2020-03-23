// Demo setup
// monitoring using serial communication with android phone

const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor

const int max_deapth = 130 // max deapth of my tank (achieved when empty)
const int min_deapth = 20 // min deapth of my tank (achieved when full)
 
void setup() {
   Serial.begin(9600); // Starting Serial Terminal
}

void loop() {
   float duration;
   int cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);

   cm = microsecondsToCentimeters(duration);

   Serial.print("Filled:");
   Serial.print(max_deapth-cm);
   Serial.print("cm, ");
   Serial.print("Left:");
   Serial.print(cm-min_deapth);
   Serial.print("cm");
   Serial.println();
   delay(10000);
}

// the duration of echo to cm
int microsecondsToCentimeters(long microseconds) {
   return microseconds / 29.0 / 2.0;
}
