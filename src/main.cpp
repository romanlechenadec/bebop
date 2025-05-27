#include <btAudio.h>
#include "Arduino.h"
#include "WiFi.h"
#include "Audio.h"

#define I2S_DOUT      22  // connect to DAC pin DIN
#define I2S_BCLK      26  // connect to DAC pin BCK
#define I2S_LRC       25  // connect to DAC pin LCK

Audio audio;
const char* ssid =     "SFR-d778";
const char* password = "DV3F72QMW7CX";
// Sets the name of the audio device
btAudio bt_handle = btAudio("Bebop");

void setup() {
 
//  // Streams audio data to the ESP32   
//  bt_handle.volume(0.05);
//  bt_handle.begin();
 
//  // Re-connects to last connected device
//  bt_handle.reconnect();
 
//  // Outputs the received data to an I2S DAC, e.g. https://www.adafruit.com/product/3678
//  int bck = 26; 
//  int ws = 25;
//  int dout = 22;
//  bt_handle.I2S(bck, dout, ws);
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) 
    {
        Serial.printf("Wifi state: %d\r\n", WiFi.status());
        delay(1500);
    }
    audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);
    audio.setVolume(5);
    audio.connecttohost("http://direct.fipradio.fr/live/fipjazz-hifi.aac"); // 64 kbp/s aac+
}

void loop() {
    audio.loop();
    if(Serial.available()){ // put streamURL in serial monitor
        audio.stopSong();
        String r=Serial.readString(); r.trim();
        if(r.length()>5) audio.connecttohost(r.c_str());
        log_i("free heap=%i", ESP.getFreeHeap());
    }
}

void audio_info(const char *info){
    Serial.print("info        "); Serial.println(info);
}