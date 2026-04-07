//made by will

#include "BetterButton.h"

int button1Pin = 31;
int button2Pin = 32;
int button3Pin = 33;
int button4Pin = 34;

BetterButton button1(button1Pin, 60);
BetterButton button2(button2Pin, 62);
BetterButton button3(button3Pin, 64);
BetterButton button4(button4Pin, 65);

void setup() {
  button1.pressHandler(onPress);
  button1.releaseHandler(onRelease);
  button2.pressHandler(onPress);
  button2.releaseHandler(onRelease);
  button3.pressHandler(onPress);
  button3.releaseHandler(onRelease);
  button4.pressHandler(onPress);
  button4.releaseHandler(onRelease);
}

void loop() {
  button1.process();
  button2.process();
  button3.process();
  button4.process();

  usbMIDI.read();
}

void onPress(int note) {
  usbMIDI.sendNoteOn(note, 99, 1);
}

void onRelease(int note) {
  usbMIDI.sendNoteOff(note, 0, 1);
}