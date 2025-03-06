# ARUNO_NodeMCU_MIT-APP_LEDon

Check out my two YouTube channels for more content:  
1. [Mrzaizai2k - AI](https://www.youtube.com/channel/UCFGCVG0P2eLS5jkDaE0vSfA) (NEW)  
2. [Mrzaizai2k](https://www.youtube.com/channel/UCCq3lQ1W437euT9eq2_26HQ) (Old)  

## LED Control with Android App via Wi-Fi

This project demonstrates controlling an LED using an Android app via Wi-Fi, connecting a NodeMCU and Arduino Uno, and sending data back to the app. Watch the video below for a detailed explanation:  

[<img src="https://img.youtube.com/vi/3IDCPlOG418/maxresdefault.jpg" width="100%">](https://youtu.be/3IDCPlOG418)


- **References:**  
  1. [How to Build a Custom Android App for Your Arduino Project Using MIT App Inventor](https://www.youtube.com/watch?time_continue=69&v=o-YVvxYiSuk&feature=emb_logo)  
  2. [MIT App Inventor](http://appinventor.mit.edu/)  
  3. [SoftwareSerial Communication Between Arduino Uno and NodeMCU](https://www.youtube.com/watch?v=BfUtpScdQ9Y)  
  4. [Remote-Controlled Car Project via Internet with iNut Sensor](http://arduino.vn/tutorial/5781-du-xe-dieu-khien-tu-xa-qua-internet-voi-inut-cam-bien-ket-noi-voi-wifi-trong-nha-hoac)  
  5. [MIT App Inventor 2 - NodeMCU Wi-Fi Car Control App](https://www.youtube.com/watch?v=nVYCTKWcq24&t=25s)  
  6. [NodeMCU Server | Control via Web Browser | RoboShala Hindi](https://www.youtube.com/watch?v=rs2CwV8ilPI&t=12s)  

---

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

The `Ledon_Uno` Arduino sketch integrates an ultrasonic sensor (HC-SR04) and an LED controlled by an Arduino Uno. It communicates with a NodeMCU (ESP8266) via SoftwareSerial. The ultrasonic sensor measures distance, and the LED is controlled based on commands received from the `Ledonwifi` sketch.

### 1.2 How It Works <a name="12-how-it-works-ledon_uno"></a>

1. **Setup:**  
   - The HC-SR04 ultrasonic sensor is connected to pins 8 (trig) and 7 (echo).  
   - An LED is connected to pin 12.  
   - SoftwareSerial communication is established between Arduino Uno and NodeMCU on pins 3 (RX) and 2 (TX).  
   - OpenAI API credentials are configured (if applicable).  

2. **Distance Measurement:**  
   - The `distance()` function uses the HC-SR04 sensor to measure the distance in centimeters.  

3. **Communication with NodeMCU:**  
   - The Arduino Uno sends distance data to the NodeMCU via SoftwareSerial.  
   - The NodeMCU processes this data and sends LED control commands back.  

4. **Data Transmission:**  
   - The Arduino Uno continuously measures and transmits distance data to the NodeMCU.  
   - The NodeMCU toggles the LED on or off based on commands from `Ledonwifi`.  

---

## 2. Ledonwifi <a name="2-ledonwifi"></a>

### 2.1 Overview <a name="21-overview-ledonwifi"></a>

The `Ledonwifi` sketch runs on a NodeMCU (ESP8266) and acts as a web server. It receives HTTP requests to control the LED on `Ledon_Uno` and retrieves distance information from the Arduino Uno.

### 2.2 How It Works <a name="22-how-it-works-ledonwifi"></a>

1. **Setup:**  
   - The NodeMCU connects to a Wi-Fi network.  
   - A web server is initialized on the NodeMCU.  

2. **LED Control:**  
   - HTTP requests like "LEDon" and "LEDoff" trigger the `LEDon()` and `LEDoff()` functions.  
   - These commands are sent to `Ledon_Uno` to control the LED.  

3. **Distance Information:**  
   - The "distance" command retrieves distance data from `Ledon_Uno`.  
   - The data is returned to the client (e.g., a browser or app) making the HTTP request.  

4. **HTTP Server Handling:**  
   - The server listens for client connections and responds to incoming requests.  

**Note:** Ensure Wi-Fi credentials in `Ledonwifi` match your network settings. Keep the OpenAI API key in `Ledon_Uno` secure and avoid sharing it publicly.
