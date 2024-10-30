#define SPEAKER_PIN 2
#define LED_PIN_1 3
#define LED_PIN_2 4

void setup() {
  pinMode(SPEAKER_PIN, OUTPUT);
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
}

void loop() {
  int notes[] = {800, 1200, 1400, 1600, 00000, 2000, 2200, 2400,800, 1200, 1400, 1600, 00000, 2000, 2200, 2400,800, 1200, 1400, 1600, 00000, 2000, 2200, 2400,800, 1200, 1400, 1600, 00000, 2000, 2200, 2400};
  int durations[] = {10, 10, 10, 10, 80, 10, 12,10,10, 10, 10, 10, 80, 10, 12,10,10, 10, 10, 10, 800, 10, 12,10,10, 10, 10, 10, 80, 10, 12,10,10, 10, 10, 10, 80, 10, 12,10};

  for (int i = 0; i < sizeof(notes) / sizeof(notes[0]); i++) {
    // Play the tone
    tone(SPEAKER_PIN, notes[i]);
    
    // Toggle LEDs
    if (i % 2 == 0) {
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, LOW);
    } else {
      digitalWrite(LED_PIN_1, LOW);
      digitalWrite(LED_PIN_2, HIGH);
    }

    // Delay for the duration
    delay(durations[i]);

    // Turn off tone and LEDs
    noTone(SPEAKER_PIN);
    digitalWrite(LED_PIN_1, LOW);
    digitalWrite(LED_PIN_2, LOW);

    // Pause between tones
    delay(100);
  }
}
