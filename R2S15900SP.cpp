#include <Arduino.h>
#include <Wire.h>
#include "R2S15900SP.h"

R2S15900SP::R2S15900SP(){
	Wire.begin();
}

void R2S15900SP::setVol_l(int vol_l){
      byte vol_l10 = vol_l/10;
      byte vol_l1 = vol_l%10;
  writeWire(R2S15900SP_VOL_L, (vol_l10 << 4) + vol_l1);
}

void R2S15900SP::setVol_r(int vol_r){
      byte vol_r10 = vol_r/10;
      byte vol_r1 = vol_r%10;
  writeWire(R2S15900SP_VOL_R, (vol_r10 << 4) + vol_r1);
}

void R2S15900SP::setInput(int in, int gain, int mute){
      switch(in){
       case 0: in = 0b00011;break;
       case 1: in = 0b00111;break;
       case 2: in = 0b01011;break;
       case 3: in = 0b01111;break;
       case 4: in = 0b10011;break;
       case 5: in = 0b10111;break;
}
  writeWire(R2S15900SP_INPUT, (in << 3) + (gain << 2) + mute);
}

void R2S15900SP::set_Bass(int surr, int mode, int bass){
       if(bass >= 0){bass = bass + 0b10000;}
  writeWire(R2S15900SP_BASS, mode + (surr << 2) + (bass << 3));
}

void R2S15900SP::set_Treb(int treb){
       if(treb >= 0){treb = treb + 0b10000;}
  writeWire(R2S15900SP_TREB, (treb << 3));
}

void R2S15900SP::writeWire(char a, char b){
  Wire.beginTransmission(R2S15900SP_address);
  Wire.write (a);
  Wire.write (b);
  Wire.endTransmission();
}
