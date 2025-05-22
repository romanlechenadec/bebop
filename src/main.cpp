#include <btAudio.h>

// Sets the name of the audio device
btAudio audio = btAudio("Bebop");

void setup() {
 
 // Streams audio data to the ESP32   
 audio.volume(0.05);
 audio.begin();
 
 // Re-connects to last connected device
 audio.reconnect();
 
 // Outputs the received data to an I2S DAC, e.g. https://www.adafruit.com/product/3678
 int bck = 26; 
 int ws = 25;
 int dout = 22;
 audio.I2S(bck, dout, ws);
}

void loop() {

}