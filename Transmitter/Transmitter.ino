//transmitter
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);      // set LED pin as output
  digitalWrite(LED_BUILTIN, LOW);    // switch off LED pin

  Serial.begin(9600);               // initialize serial communication at 9600 bits per second
  Serial1.begin(9600);              // initialize UART with baud rate of 9600
}

void loop() {
  while (Serial1.available() >= 0) {
    char receivedData = Serial1.read();   // read one byte from serial buffer and save to receivedData
    if (receivedData == '1') {
      digitalWrite(LED_BUILTIN, HIGH); // switch LED On
    }
    else if (receivedData == '0') {
      digitalWrite(LED_BUILTIN, LOW);  // switch LED Off
    }
  }
  if (Serial.available() > 0) {
    char receivedData = Serial.read();   // read one byte from serial buffer and save to receivedData
    if (receivedData == '1') {
      Serial1.println('1');
      digitalWrite(LED_BUILTIN, HIGH);   // switch LED On
      Serial.println("LEDs ON");
    }
    else if (receivedData == '0') {
      Serial1.println('0');
      digitalWrite(LED_BUILTIN, LOW);    // switch LED Off
      Serial.println("LEDs OFF");
    }
  }
}