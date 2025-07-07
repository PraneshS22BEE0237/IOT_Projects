int pirPin = 12;        // PIR sensor connected to digital pin 12
int ldrPin = 13;        // LDR connected to analog pin A0
int ledPin = 2;         // LED connected to digital pin 2
int threshold = 500;    // Light threshold (adjust based on testing)

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ldrPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int ldrValue = analogRead(ldrPin);   // Read ambient light
  int pirValue = digitalRead(pirPin);  // Read motion status

  Serial.print("LDR: ");
  Serial.print(ldrValue);
  Serial.print(" | PIR: ");
  Serial.println(pirValue);

  if (ldrValue < threshold && pirValue == HIGH) {
    digitalWrite(ledPin, HIGH);  // Turn on light
    Serial.println("Motion detected in dark! Sending alert...");
  } else {
    digitalWrite(ledPin, LOW);   // Turn off light
  }

  delay(200);  // Stability delay
}
