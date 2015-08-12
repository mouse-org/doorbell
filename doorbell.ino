/* melodyPlayer !
 
 Plays a melody when a button is pressed.
 
 circuit:
 * 8-ohm speaker on digital pin 5
 * Button connected to digital pin 12
 
 based on an example by by Tom Igoe
 http://arduino.cc/en/Tutorial/Tone */

int speakerPin = 5;
int buttonPin = 12;

int buttonState = 0;


//
// notes in the melody - these numbers actually control the pitches.
// if you are interested in making music with this circuit, check out:
// http://arduino.cc/en/Tutorial/Tone or go to
// File > Examples > 2.Digital > ToneMelody to learn how!
int melody[] = {131, 131, 131, 196, 131, 131, 131, 196, 784, 831, 932, 988, 1047, 1109, 523};

// note durations: 4 = quarter note, 8 = eighth note, etc.
// you only need to understand if you are interested in rhythm:
int noteDurations[] = {16,16,16,16,16,16,16,16,2,2,2,2,2,2,2};

void setup() {
  //declaring pins as inputs and outputs
  pinMode(speakerPin, OUTPUT); //speaker attached to pin 5
  pinMode(buttonPin, INPUT);  //button attached to pin 12
}

void loop() {  
  //check the current state of the button
  buttonState = digitalRead(buttonPin);
 
  //if the button IS pressed
  if(buttonState == HIGH){  // HIGH = pressed
	playMelody();
  }
 
  //if the button IS NOT pressed
  else if(buttonState == LOW){ // LOW = NOT pressed
   //do nothing
  }
}

// Again, this section is important to understand
// only if you are interested in making music w/Arduino...
void playMelody(){
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 15; thisNote++) {

	// to calculate the note duration, take one second
	// divided by the note type.
	//e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
	int noteDuration = 1000/noteDurations[thisNote];
	tone(speakerPin, melody[thisNote],noteDuration);

	// Space between each note
	delay(150);
  }
}