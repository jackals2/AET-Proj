const int trigPin = 9;
const int echoPin = 10;
int ledPin1 = 13;
int ledPin2 = 12;
int ledPin3 = 7;
long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication// put your setup code here, to run once:

}
void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  
  //Checks distance to see which LEDs to turn on
  if (distance <= 5){
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    Serial.print("CLOSE");
  }else if (distance <= 15){
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    Serial.print("closer...");
  }else if (distance <= 30){
    digitalWrite(ledPin3, HIGH);
    Serial.print("approaching");
  }else{
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
  }
}
