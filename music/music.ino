
int incomingByte = 0;  

//=== Pin Assignment ===//

char payload[150];

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
 
int sVal_01 = 50; // Initial Threshold
int sVal_02 = 70;
int sVal_03 = 80;
int sVal_04 = 90;
int sVal_05 = 100;
int sVal_06 = 120;
int sVal_07 = 155;


int lastPin = 13; // last digital PIN number
int totalLED = 7; // total LEDs

/**
 * Additional Settings
 */
 
int debugSwitch = false; // Switch for Debugging: true or false (ctrl+shift+M or ctrl+shift+L)
int ledTest = true; // If true it will test the LEDs first before use (you can press reset to check LEDs if running correctly

/**
 * Please keep out don't modify the codes below.
 * Just edit the variables above, thanks!
 */

int sensorvalue = 0; // storage for recording sensor values
void setup() {
  Serial.begin(115200); // use the same baud-rate as the python side

  if (ledTest == true) {
    initTest(); // Initial testing for LED's
  }
}

void loop() {
  //sensorvalue = analogRead(DA); // getting sensor values from analog A0

  char data[2];
  if (debugSwitch == true) {
    debug();
  } else {
    //Serial.println("The debugging mode is set to false!");
  }

  if (Serial.available() >0) {
    //char c = Serial.read();
    //data[0] = c;
    //data[1] = '\0';
    //Serial.println(data);
    incomingByte = Serial.read(); 
    sensorvalue = incomingByte ;

                // say what you got:
                Serial.print("I received: ");
                Serial.println(incomingByte);
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
  delay(1000);
  digitalWrite(led_01, HIGH);
  delay(2000);
  digitalWrite(led_01, LOW);
  delay(500);
  digitalWrite(led_02, LOW);
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
  
  if(sensorvalue == 0) {
    digitalWrite(led_01, LOW);
    digitalWrite(led_02, LOW);
    digitalWrite(led_03, LOW);
    digitalWrite(led_04, LOW);
    digitalWrite(led_05, LOW);
    digitalWrite(led_06, LOW);
    digitalWrite(led_07, LOW);
  }else

    if(sensorvalue == 1) {
    digitalWrite(led_01, HIGH);
    digitalWrite(led_02, LOW);
    digitalWrite(led_03, LOW);
    digitalWrite(led_04, LOW);
    digitalWrite(led_05, LOW);
    digitalWrite(led_06, LOW);
    digitalWrite(led_07, LOW);
    }else
    if(sensorvalue == 2) {
    digitalWrite(led_01, HIGH);
    digitalWrite(led_02, HIGH);
    digitalWrite(led_03, LOW);
    digitalWrite(led_04, LOW);
    digitalWrite(led_05, LOW);
    digitalWrite(led_06, LOW);
    digitalWrite(led_07, LOW);
    }else
    if(sensorvalue == 3) {
    digitalWrite(led_01, HIGH);
    digitalWrite(led_02, HIGH);
    digitalWrite(led_03, HIGH);
    digitalWrite(led_04, LOW);
    digitalWrite(led_05, LOW);
    digitalWrite(led_06, LOW);
    digitalWrite(led_07, LOW);
    }else
    if(sensorvalue == 4) {
    digitalWrite(led_01, HIGH);
    digitalWrite(led_02, HIGH);
    digitalWrite(led_03, HIGH);
    digitalWrite(led_04, HIGH);
    digitalWrite(led_05, LOW);
    digitalWrite(led_06, LOW);
    digitalWrite(led_07, LOW);
    }else
    if(sensorvalue == 5) {
    digitalWrite(led_01, HIGH);
    digitalWrite(led_02, HIGH);
    digitalWrite(led_03, HIGH);
    digitalWrite(led_04, HIGH);
    digitalWrite(led_05, HIGH);
    digitalWrite(led_06, LOW);
    digitalWrite(led_07, LOW);
    }else
    if(sensorvalue == 6) {
    digitalWrite(led_01, HIGH);
    digitalWrite(led_02, HIGH);
    digitalWrite(led_03, HIGH);
    digitalWrite(led_04, HIGH);
    digitalWrite(led_05, HIGH);
    digitalWrite(led_06, HIGH);
    digitalWrite(led_07, LOW);
    }
    if(sensorvalue == 7) {
    digitalWrite(led_01, HIGH);
    digitalWrite(led_02, HIGH);
    digitalWrite(led_03, HIGH);
    digitalWrite(led_04, HIGH);
    digitalWrite(led_05, HIGH);
    digitalWrite(led_06, HIGH);
    digitalWrite(led_07, HIGH);
    }

}
