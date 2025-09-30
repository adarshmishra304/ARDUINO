int irSensor1 = 2;
int irSensor2 = 3;
int irSensor3 = 4;

int ledPin1 = 9;
int ledPin2 = 10;
int ledPin3 = 11;

int ldrPin = A0;       // LDR connected to analog pin A0
int ldrValue = 0;
int ldrThreshold = 100; // Lower value = darker. Adjust as needed.

void setup() {
  pinMode(irSensor1, INPUT);
  pinMode(irSensor2, INPUT);
  pinMode(irSensor3, INPUT);
  
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);

  Serial.begin(9600); // Optional: for debugging
}

void loop() {
  // Read LDR value
  ldrValue = analogRead(ldrPin);
  Serial.print("LDR: ");
  Serial.println(ldrValue);

  if (ldrValue > ldrThreshold) {
    // It's dark — enable street light logic
    
    analogWrite(ledPin1, 100);
    analogWrite(ledPin2, 100);
    analogWrite(ledPin3, 100);

    // Sensor 1
    if (digitalRead(irSensor1) == LOW) {
      analogWrite(ledPin1, 255); // Bright LED
      
    } 
    else {
      analogWrite(ledPin1, 50);   // Turn OFF
    }

    // Sensor 2
    if (digitalRead(irSensor2) == LOW) {
      analogWrite(ledPin2, 255);
     
    } 
    else {
      analogWrite(ledPin2, 50);
    }

    // Sensor 3
    if (digitalRead(irSensor3) == LOW) {
      analogWrite(ledPin3, 255);
     
    } 
    else {
      analogWrite(ledPin3, 50);
    }

  } else {
    // It's daytime — turn all LEDs off
    
    analogWrite(ledPin1, 0);
    analogWrite(ledPin2, 0);
    analogWrite(ledPin3, 0);
  }

  delay(10); // Small delay
}