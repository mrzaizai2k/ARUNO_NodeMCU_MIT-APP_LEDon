# ARUNO_NodeMCU_MIT-APP_LEDon
Check out my 2 YOUTUBE channels for more:
1. [Mrzaizai2k - AI](https://www.youtube.com/channel/UCFGCVG0P2eLS5jkDaE0vSfA) (NEW)
2. [Mrzaizai2k](https://www.youtube.com/channel/UCCq3lQ1W437euT9eq2_26HQ) (old)

LED Control with Android app via Wifi to NodeMCU and Arduino Uno then send data back to the app.

[**YOUTUBE LINK: IOT with Arduino Uno, NodeMCU, MIT app _ Mrzaizai2k**](https://www.youtube.com/watch?v=3IDCPlOG418&list=PLwPBf6q2CQ-btTIgsZXhBJY6vKkSxBtxv&index=2)

My Arduino code, circut diagram & apk. file (MIT App): https://drive.google.com/open?id=1pGBlIQ7Rhmqb2475-qOyBZvDtrR75e32

References:
1. How To Build Custom Android App for your Arduino Project using MIT App Inventor: https://www.youtube.com/watch?time_continue=69&v=o-YVvxYiSuk&feature=emb_logo
2. MIT App Inventor: http://appinventor.mit.edu/
3. How to make SoftwareSerial Communication between Arduino Uno and NodeMCU: https://www.youtube.com/watch?v=BfUtpScdQ9Y
4. Dự án xe điều khiển từ xa qua Internet với iNut Cảm biến kết nối với wifi trong nhà hoặc USB Wifi 3G: http://arduino.vn/tutorial/5781-du-xe-dieu-khien-tu-xa-qua-internet-voi-inut-cam-bien-ket-noi-voi-wifi-trong-nha-hoac
5. MIT APP INVENTOR 2 -nodemcu wifi car control app: https://www.youtube.com/watch?v=nVYCTKWcq24&t=25s
6. NodeMCU Server | Control via WebBrowser | RoboShala Hindi: https://www.youtube.com/watch?v=rs2CwV8ilPI&t=12s
</br>

## Table of Contents
1. [Ledon_Uno](#1-ledon_uno)
   1.1 [Overview](#11-overview-ledon_uno)
   1.2 [How It Works](#12-how-it-works-ledon_uno)
2. [Ledonwifi](#2-ledonwifi)
   2.1 [Overview](#21-overview-ledonwifi)
   2.2 [How It Works](#22-how-it-works-ledonwifi)

---

## 1. Ledon_Uno <a name="1-ledon_uno"></a>

### 1.1 Overview <a name="11-overview-ledon_uno"></a>

The `Ledon_Uno` Arduino sketch integrates an ultrasonic sensor (HC-SR04) and an LED controlled by an Arduino Uno. It communicates with a NodeMCU (ESP8266) via SoftwareSerial. The ultrasonic sensor measures distance, and the LED is controlled based on commands received from `Ledonwifi`.

### 1.2 How It Works <a name="12-how-it-works-ledon_uno"></a>

1. **Setup:** 
   - The HC-SR04 ultrasonic sensor is connected to pins 8 (trig) and 7 (echo).
   - An LED is connected to pin 12.
   - Communication between Arduino Uno and NodeMCU is established using SoftwareSerial on pins 3 (RX) and 2 (TX).
   - OpenAI API credentials are set up.
   
2. **Distance Measurement:**
   - The `distance()` function measures the distance using the HC-SR04 sensor and returns the result in centimeters.

3. **Communication with NodeMCU:**
   - The Arduino Uno sends the distance data to NodeMCU via SoftwareSerial.
   - NodeMCU processes the data and controls the LED based on specific commands.

4. **Data Transmission:**
   - The Arduino Uno continuously measures and sends the distance data to NodeMCU.
   - NodeMCU toggles the LED on or off based on commands received from `Ledonwifi`.

## 2. Ledonwifi <a name="2-ledonwifi"></a>

### 2.1 Overview <a name="21-overview-ledonwifi"></a>

The `Ledonwifi` Arduino sketch runs on a NodeMCU (ESP8266) and serves as a web server. It receives commands via HTTP requests to control the LED on `Ledon_Uno` and obtain distance information.

### 2.2 How It Works <a name="22-how-it-works-ledonwifi"></a>

1. **Setup:**
   - NodeMCU is connected to a Wi-Fi network.
   - A web server is set up on NodeMCU.

2. **LED Control:**
   - Commands like "LEDon" and "LEDoff" are received via HTTP requests.
   - The corresponding functions (`LEDon()` and `LEDoff()`) are executed to control the LED on `Ledon_Uno`.

3. **Distance Information:**
   - The "distance" command is processed to obtain distance data from `Ledon_Uno`.
   - The data is sent back to the client (browser) that made the HTTP request.

4. **HTTP Server Handling:**
   - The server continuously listens for client connections and responds to requests.

**Note:** Ensure that the Wi-Fi credentials in `Ledonwifi` match your network settings, and the OpenAI API key in `Ledon_Uno` is secure and not publicly shared.
