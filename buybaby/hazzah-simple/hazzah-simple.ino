
/*

ACCESS POINT - HTTP
http://192.168.4.1

*/

#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

const char *ssid = "unconference";
const char *password = "thereisnospoon";

ESP8266WebServer server(80);

void handleRoot() {
	server.send(200, "text/html", "<h1>YAY! You are here</h1>");
}

void ledOn() {
  server.send(200, "text/html", "<h1>Led ON</h1> <br> <a href='http://192.168.4.1/led/0'> Click </a>");
  digitalWrite(12, HIGH);
}
void ledOff() {
  server.send(200, "text/html", "<h1>Led OFF</h1> <br> <a href='http://192.168.4.1/led/1'> Click </a>");
  digitalWrite(12, LOW);
}
void setup() {
	delay(1000);
	Serial.begin(115200);
	
	WiFi.softAP(ssid, password);
	IPAddress myIP = WiFi.softAPIP();

        server.on("/", handleRoot);
        server.on("/led/1", ledOn);
        server.on("/led/0", ledOff);

  pinMode(12, OUTPUT);
	server.begin();
}

void loop() {
	server.handleClient();
}
