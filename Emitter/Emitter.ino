// Name: Giulia Piombo
// Date: June, 2021
// Subject: Emit a differnet sound for a different key

#include <Keypad.h>

// keypad values
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

// frequencies values for each different key
const int frequencies[] = {1000, 1100, 1200, 1300, 1400, 1600, 1700, 1800, 1900, 2000, 2100, 2200, 2300, 2400, 2500, 2600, 2700};

// maping the keys
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

const int buzzer_port = 10;
int incomingByte = 0;

void setup() {

  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  pinMode(buzzer_port, OUTPUT); // Set buzzer - pin 10 as an output
}

void loop() {

    // reading the pressed key
    char key = keypad.getKey();

    // displaying a different frequency for each key
    if (key) {
      Serial.print(key);
      if (key == 'A') {
        tone(buzzer_port, frequencies[10]); 
        delay(1000);        // ...for 1 sec  
      } else if (key == 'B') {
        tone(buzzer_port, frequencies[11]); 
        delay(1000);        // ...for 1 sec  
      } else if (key == 'C') {
        tone(buzzer_port, frequencies[12]); 
        delay(1000);        // ...for 1 sec  
      } else if (key == 'D') {
        tone(buzzer_port, frequencies[13]); 
        delay(1000);        // ...for 1 sec  
      } else if (key == '*') {
        tone(buzzer_port, frequencies[14]); 
        delay(1000);        // ...for 1 sec  
      } else if (key == '#') {
        tone(buzzer_port, frequencies[15]); 
        delay(1000);        // ...for 1 sec  
      } else if (key == '0') {
        tone(buzzer_port, frequencies[0]); 
        delay(1000);        // ...for 1 sec  
      } else if (key == '1') {
        tone(buzzer_port, frequencies[1]); 
        delay(1000);        // ...for 1 sec  
      } else if (key == '2') {
        tone(buzzer_port, frequencies[2]); 
        delay(1000);        // ...for 1 sec  
      } else if (key == '3') {
        tone(buzzer_port, frequencies[3]); 
        delay(1000);        // ...for 1 sec  
      } else if (key == '4') {
        tone(buzzer_port, frequencies[4]); 
        delay(1000);        // ...for 1 sec  
      } else if (key == '5') {
        tone(buzzer_port, frequencies[5]); 
        delay(1000);        // ...for 1 sec  
      } else if (key == '6') {
        tone(buzzer_port, frequencies[6]); 
        delay(1000);        // ...for 1 sec  
      } else if (key == '7') {
        tone(buzzer_port, frequencies[7]); 
        delay(1000);        // ...for 1 sec  
      } else if (key == '8') {
        tone(buzzer_port, frequencies[8]); 
        delay(1000);        // ...for 1 sec  
      } else if (key == '9') {
        tone(buzzer_port, frequencies[9]); 
        delay(1000);        // ...for 1 sec  
      }
      noTone(buzzer_port);     // Stop sound...
      delay(1000);        // ...for 1sec 
    }
}
