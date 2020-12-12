#define echoPin 2
#define trigPin 3
#define stopPin 4

long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(stopPin, OUTPUT);
  Serial.begin(9600);//baudrate is 9600
}

void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  if (distance < 75){ //if the drone becomes 2.5 feet away from an object it stops the drone
    Serial.println("Too close, stopping drone");
    digitalWrite(stopPin, HIGH);
  }
  else { //otherwise the drone is free to fly
    Serial.print("Distance 1: ");
    Serial.print(distance);
    Serial.println(" cm");
    digitalWrite(stopPin, LOW);
  }
}
