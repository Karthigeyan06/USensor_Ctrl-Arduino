#define TRIGGER_PIN  7  
#define ECHO_PIN     6  
#define LED_PIN      13 

long duration;
int distance;
bool objectDetected = false;

void setup() {
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  
  
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  
  duration = pulseIn(ECHO_PIN, HIGH);

  
  distance = duration * 0.034 / 2;


  if (distance < 15) {
    objectDetected = true;
  } else {
    objectDetected = false;
    digitalWrite(12, HIGH);
  }

 
  if (objectDetected) {
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(12, LOW);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    delay(500);
    
  }
}
