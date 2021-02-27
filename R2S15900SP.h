// Алксандр Лиман
// liman324@yandex.ru

#ifndef R2S15900SP_H
#define R2S15900SP_H
#define R2S15900SP_address 0b1000001 

#define R2S15900SP_VOL_L   0x00
#define R2S15900SP_VOL_R   0x01
#define R2S15900SP_INPUT   0x02
#define R2S15900SP_BASS    0x03
#define R2S15900SP_TREB    0x04

#include <Arduino.h>
class R2S15900SP
{
  public:
    R2S15900SP();
              
        void setVol_l(int vol_l);  // volume left >> int 84...0 === -84...0 dB
        void setVol_r(int vol_r);  // volume_right >> int 84...0 === -84...0 dB
        void setInput(int in, int gain, int mute);     
             // input >> int 0 === all off | int 1...5 === input 1...5 
             // gain >> int 0...1 === 0 dB...+4.5 dB
             // mute >> int 0...1 === mute off...mute on
        void set_Bass(int surr, int mode, int bass);
             // surround mode >> int 0...1 === low level...high level
             // mode selector >> int 0...3 === bypass tone tone&Pseudo_stereo tone&Surround
             // tone control bass >> int -15...15 === -15dB...+15dB
        void set_Treb(int treb);   // tone control treble >> int -15...15 === -15dB...+15dB

  private:
	void writeWire(char a, char b);
};
	
#endif //R2S15900SP_H
