#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>

SoftwareSerial NodeMCU(D2, D3);//D2 = Rx, D3 = Tx
int pin = D6;

WiFiClient client;
WiFiServer server(80);

const char* ssid1 = "MAI-TINH";//your wifi
const char* ssid2 = "MaiTinh";
const char* password = "123456mt"; //your wifi's password
String  data = "";

void setup() {
  server.begin();
  Serial.begin(9600);
  NodeMCU.begin(4800);
  pinMode(D2, INPUT);
  pinMode(pin, OUTPUT);
  pinMode(D3, OUTPUT);
  Serial.print ("Wifi connecting to \n");
  Serial.print (ssid2);
  WiFi.begin(ssid2, password);
  Serial.print("\nConnecting\n");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("NodeMCU Local IP is : ");
  Serial.print((WiFi.localIP()));
  Serial.print("\n");
}
void LEDon() {
  client.println("Led pin is now: on ");
    
  digitalWrite(pin, HIGH);
  NodeMCU.print(9);
  NodeMCU.println("\n");
  delay(30);
}
void LEDoff() {
  client.println("Led pin is now: off ");
  
  digitalWrite(pin, LOW);
  NodeMCU.print(8);
  NodeMCU.println("\n");
  delay(30);
}
String checkClient ()
{
  while (!client.available()) delay(10);   // Wait until the client sends some data
  String request = client.readStringUntil('\r');
  request.remove(0, 5);
  request.remove(request.length() - 9, 9);
  Serial.print(request);
  Serial.print("\n");
  return request;
}

void loop() {
  client = server.available();// Check if a client has connected
  if (!client) return;// Check if a client has connected
  data = checkClient ();
  client.println("HTTP/1.1 200 OK");//respond code: 200
  client.println("Content-Type: text/html");//respond type: text/html 
 // use header like HTTP/1.1 or Content-Type to transfer different- 
 //kind of information
  client.println("");
  
  if (data == "LEDon") LEDon();
  else if (data == "LEDoff") LEDoff();
  else if (data == "distance"){
     int distance = NodeMCU.parseFloat();
    Serial.print(distance);
    Serial.print("cm");
    Serial.print("\n");    
    client.println(distance);
    }
  delay(200);
}
