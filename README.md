# Bebop

This project use the [FireBeetle 2 ESP32-E](https://www.dfrobot.com/product-2195.html) and [ESP32-A2DP](https://github.com/pschatzmann/ESP32-A2DP) "A Simple Arduino Bluetooth Music Receiver and Sender for the ESP32".

The ESP32 act as a signal receiver (either from BLE or WiFi) and the output the send through the I2S bus protocol to be amplified.

A2DP protocol is a bluetooth protocol which only provides audio streaming.
I²S (Inter IC Sound): is a protocol dedicated to transfer sound between pcb with a better resolution than most DAC/ADC signals.