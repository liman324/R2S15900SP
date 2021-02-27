#include <Wire.h>
#include <R2S15900SP.h>
  R2S15900SP r2s;

void setup() {
  audio();
}

void loop() {
  
}

void audio(){             
  r2s.setVol_l(0);  // volume left >> int 84...0 === -84...0 dB
  r2s.setVol_r(0);  // volume_right >> int 84...0 === -84...0 dB
  r2s.setInput(1, 0, 0);     
             // input >> int 0 === all off | int 1...5 === input 1...5 
             // gain >> int 0...1 === 0 dB...+4.5 dB
             // mute >> int 0...1 === mute off...mute on
  r2s.set_Bass(0, 0, 0);
             // surround mode >> int 0...1 === low level...high level
             // mode selector >> int 0...3 === bypass tone tone&Pseudo_stereo tone&Surround
             // tone control bass >> int -15...15 === -15dB...+15dB
  r2s.set_Treb(0);   // tone control treble >> int -15...15 === -15dB...+15dB
}
