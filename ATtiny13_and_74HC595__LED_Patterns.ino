// Pin definitions for ATtiny13
#define DATA_PIN 0 // PB0
#define CLOCK_PIN 1 // PB1
#define LATCH_PIN 2 // PB2

// Delay time in milliseconds
#define DELAY_TIME 100

void setup() {
  // Set pin modes
  pinMode(DATA_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(LATCH_PIN, OUTPUT);
}

void shiftOutData(uint8_t data) {
  for (int i = 0; i < 8; i++) {
    // Write each bit to the data pin
    digitalWrite(DATA_PIN, (data & (1 << (7 - i))) ? HIGH : LOW);

    // Pulse the clock pin
    digitalWrite(CLOCK_PIN, HIGH);
    delayMicroseconds(1);
    digitalWrite(CLOCK_PIN, LOW);
    delayMicroseconds(1);
  }
}

void latchData() {
  // Pulse the latch pin
  digitalWrite(LATCH_PIN, HIGH);
  delayMicroseconds(1);
  digitalWrite(LATCH_PIN, LOW);
  delayMicroseconds(1);
}

void loop() {
  uint8_t patterns[] = {

   //we can creat pattern like that
    0b00000001,
    0b00000010,
    0b00000100,
    0b00001000,
    0b00010000,
    0b00100000,
    0b01000000,
    0b10000000,
    
  };

  for (int i = 0; i < sizeof(patterns); i++) {
    shiftOutData(patterns[i]);
    latchData();
    delay(DELAY_TIME);
  }
}
