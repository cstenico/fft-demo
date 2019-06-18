
//=== Pin Assignment ===//

const int DO = 6; // Digital PIN 2 of Arduino

// Digital PIN 3 to 11 of Arduino
const int led_01 = 7;
const int led_02 = 8;
const int led_03 = 9;
const int led_04 = 10;
const int led_05 = 11;
const int led_06 = 12;
const int led_07 = 13;


/** 
 * Corresponding Sensor Values (Sensor Threshold)
 * The values has 4 gap values, you can make how many gaps you like.
 */
 
int sVal_01 = 500; // Initial Threshold
int sVal_02 = 510;
int sVal_03 = 510;
int sVal_04 = 520;
int sVal_05 = 520;
int sVal_06 = 530;
int sVal_07 = 530;


int lastPin = 13; // last digital PIN number
int totalLED = 7; // total LEDs

/**
 * Additional Settings
 */
 
int debugSwitch = true; // Switch for Debugging: true or false (ctrl+shift+M or ctrl+shift+L)
int ledTest = true; // If true it will test the LEDs first before use (you can press reset to check LEDs if running correctly

/**
 * Please keep out don't modify the codes below.
 * Just edit the variables above, thanks!
 */

int sensorvalue = 0; // storage for recording sensor values
 
void setup() {
  Serial.begin(9600);
  for (int i = 6; i <= lastPin; i++) {
    pinMode(i, OUTPUT);
  }

  if (ledTest == true) {
    initTest(); // Initial testing for LED's
  }
}

void loop() {
  //sensorvalue = analogRead(DA); // getting sensor values from analog A0
  if (debugSwitch == true) {
    debug();
  } else {
    Serial.println("The debugging mode is set to false!");
  }

  // Lights Animation
  music();
}

void debug() {
  Serial.print("Sound Value: ");

  if (sensorvalue >= sVal_01) {
    Serial.print(sensorvalue);
    Serial.println(" - LED ON!");
  } else {
    Serial.println(sensorvalue);
  }
}

void initTest() {
  digitalWrite(led_05, HIGH);
  delay(1000);
  digitalWrite(led_04, HIGH);
  digitalWrite(led_06, HIGH);
  delay(1000);
  digitalWrite(led_03, HIGH);
  digitalWrite(led_07, HIGH);
  delay(1000);
  digitalWrite(led_02, HIGH);
  digitalWrite(led_08, HIGH);
  delay(1000);
  digitalWrite(led_01, HIGH);
  digitalWrite(led_09, HIGH);
  delay(2000);
  digitalWrite(led_01, LOW);
  digitalWrite(led_09, LOW);
  delay(500);
  digitalWrite(led_02, LOW);
  digitalWrite(led_08, LOW);
  delay(500);
  digitalWrite(led_03, LOW);
  digitalWrite(led_07, LOW);
  delay(500);
  digitalWrite(led_04, LOW);
  digitalWrite(led_06, LOW);
  delay(500);
  digitalWrite(led_05, LOW);
}

void music() {
  
  // Basically the LED will turn on if the sensorvalue reach the threshold
  
  if(sensorvalue >= sVal_01) {
    digitalWrite(led_05, HIGH);
  } else {
    digitalWrite(led_05, LOW);
  }

  if(sensorvalue >= sVal_02) {
    digitalWrite(led_04, HIGH);
  } else {
    digitalWrite(led_04, LOW);
  }

  if(sensorvalue >= sVal_03) {
    digitalWrite(led_06, HIGH);
  } else {
    digitalWrite(led_06, LOW);
  }

  if(sensorvalue >= sVal_04) {
    digitalWrite(led_03, HIGH);
  } else {
    digitalWrite(led_03, LOW);
  }

  if(sensorvalue >= sVal_05) {
    digitalWrite(led_07, HIGH);
  } else {
    digitalWrite(led_07, LOW);
  }

  if(sensorvalue >= sVal_06) {
    digitalWrite(led_02, HIGH);
  } else {
    digitalWrite(led_02, LOW);
  }



  if(sensorvalue >= sVal_08) {
    digitalWrite(led_01, HIGH);
  } else {
    digitalWrite(led_01, LOW);
  }
