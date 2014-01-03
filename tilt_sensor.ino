/* Tilt Sensor
 * 
 * Modified by Nahid Alam
 * Baseline from Arduino/AdaFruit
 */
 
int inPin = 5;         // the number of the input pin
int outPin = 3;       // the number of the output pin. Avoided using the default led pin 13
 
int LEDstate = HIGH;      // the current state of the output pin
int reading;           // the current reading from the input pin
int previous = LOW;    // the previous reading from the input pin
 
// the follow variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long time = 0;         // the last time the output pin was toggled
long debounce = 50;   // the debounce time, increase if the output flickers
 
void setup()
{
  Serial.begin(9600); 
  pinMode(inPin, INPUT);
  digitalWrite(inPin, HIGH);   // turn on the built in pull-up resistor
  pinMode(outPin, OUTPUT);

}
 
void loop()
{
  int switchstate;
  reading = digitalRead(inPin);
 
  // If the switch changed, due to bounce or pressing...
  if (reading != previous) {
    // reset the debouncing timer
    time = millis();
  } 
 
  if ((millis() - time) > debounce) {
     // whatever the switch is at, its been there for a long time
     // so lets settle on it!
     switchstate = reading;
 
     // Now invert the output on the pin13 LED
    if (switchstate == HIGH){
      LEDstate = LOW;
      Serial.print("Not Tilted\n "); 
  }
    else{
      LEDstate = HIGH;
      Serial.print("Tilted\n"); 
  }
  }
  digitalWrite(outPin, LEDstate);
 
  // Save the last reading so we keep a running tally
  previous = reading;
}
