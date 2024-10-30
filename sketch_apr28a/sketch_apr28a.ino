#define SPEAKER_PIN 2

void setup() {
  pinMode(SPEAKER_PIN, OUTPUT);
}

void loop() {
  // Play a tone sequence representing "hello"
  tone(SPEAKER_PIN, 1000); // Sound for 'h'
  delay(200);
  noTone(SPEAKER_PIN);
  delay(50);
  
  tone(SPEAKER_PIN, 1500); // Sound for 'e'
  delay(200);
  noTone(SPEAKER_PIN);
  delay(50);
  
  tone(SPEAKER_PIN, 2000); // Sound for 'l'
  delay(200);
  noTone(SPEAKER_PIN);
  delay(50);
  
  tone(SPEAKER_PIN, 2000); // Sound for the second 'l'
  delay(200);
  noTone(SPEAKER_PIN);
  delay(50);
  
  tone(SPEAKER_PIN, 1500); // Sound for 'o'
  delay(200);
  noTone(SPEAKER_PIN);
  delay(50);
  
  // Pause before repeating
  delay(1000);
}
