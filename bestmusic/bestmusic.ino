#include "pitches.h"

#define SPEAKER_PIN 2
#define LED1_PIN 3
#define LED2_PIN 4

// Rock beat melody notes and durations
int melody[] = {
  NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_D4,
  NOTE_C4, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_E4,
  NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_D4,
  NOTE_G4, NOTE_E4, NOTE_A4, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_E4, NOTE_E4
};

// Durations: 4 = quarter note, 8 = eighth note, etc.
int noteDurations[] = {
  8, 8, 8, 8, 4, 8, 8, 4,
  8, 8, 8, 8, 4, 8, 8, 4,
  8, 8, 8, 8, 4, 8, 8, 4,
  8, 8, 8, 8, 4, 8, 8, 4
};

void setup() {
  // Initialize the speaker and LEDs
  pinMode(SPEAKER_PIN, OUTPUT);
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
}

void loop() {
  // Iterate over the notes of the melody
  for (int thisNote = 0; thisNote < sizeof(melody)/sizeof(int); thisNote++) {
    // Calculate the note duration
    int noteDuration = 1000 / noteDurations[thisNote];

    // Play the note on pin 2
    tone(SPEAKER_PIN, melody[thisNote], noteDuration);

    // Blink LEDs in sync with the note
    digitalWrite(LED1_PIN, HIGH);
    digitalWrite(LED2_PIN, LOW);
    delay(noteDuration);
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, HIGH);

    // Pause for the note duration + 30% for note spacing
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes - noteDuration); // Adjust delay to account for note duration

    // Stop the tone playing
    noTone(SPEAKER_PIN);
  }

  // Add a delay before repeating the melody
  delay(200);
}
