#include "SD.h"
#include "TMRpcm.h"
#define SD_ChipSelectPin 10

TMRpcm tmrpcm;

int buttonState = 0;
int lastButtonState = 0; 

void setup(){ 
tmrpcm.speakerPin=9;
tmrpcm.quality(1);
tmrpcm.setVolume(5);
randomSeed(analogRead(0));
if(!SD.begin(SD_ChipSelectPin)){
  Serial.println("SD fail");
  return;}
Serial.begin(9600);
}

void LetTheMusicPlay(){
  char filename[7];
  sprintf(filename, "%02d.wav", random(51));
  Serial.println(filename);
  Serial.println("---");
  tmrpcm.play(filename);
  delay(1000);
  
}

void loop(){
  buttonState = digitalRead(4);
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      Serial.println("on");
      LetTheMusicPlay();
    } else {
      Serial.println("off");
    }
    delay(50);
  }
  lastButtonState = buttonState;
}
