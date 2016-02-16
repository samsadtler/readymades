
/*

ACCESS POINT - HTTP
http://192.168.4.1

*/

#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#define stp 12
#define dir 13
#define MS1 14
#define MS2 5
#define EN  16

//Declare variables for functions
char user_input;
int x;
int y;
int state;

const char *ssid = "babies";
const char *password = "thereisnospoon";

ESP8266WebServer server(80);
void handleRoot() {
	server.send(200, "text/html", "<h1>YAY! You are here</h1>");
}

void ledOn() {
  server.send(200, "text/html", "<h1>Led ON</h1> <br> <a href='http://192.168.4.1/led/0'> Click </a>");
  SmallStepMode();
//  digitalWrite(12, HIGH);
}
void ledOff() {
  server.send(200, "text/html", "<h1>Led OFF</h1> <br> <a href='http://192.168.4.1/led/1'> Click </a>");
//  digitalWrite(12, LOW);
  resetEDPins();
}
void setup() {
        pinMode(stp, OUTPUT);
        pinMode(dir, OUTPUT);
        pinMode(MS1, OUTPUT);
        pinMode(MS2, OUTPUT);
        pinMode(EN, OUTPUT);
        resetEDPins(); //Set step, direction, microstep and enable pins to default states
//        Serial.begin(9600); //Open Serial connection for debugging
//       

//        Serial.println("3. Turn at 1/8th microstep mode.");

//        Serial.println();
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

//Reset Easy Driver pins to default states
void resetEDPins()
{
  digitalWrite(stp, LOW);
  digitalWrite(dir, LOW);
  digitalWrite(MS1, LOW);
  digitalWrite(MS2, LOW);
  digitalWrite(EN, HIGH);
}


// 1/8th microstep foward mode function
void SmallStepMode()
{
  Serial.println("Stepping at 1/8th microstep mode.");
  digitalWrite(dir, HIGH); //Pull direction pin low to move "forward"
  digitalWrite(MS1, HIGH); //Pull MS1, and MS2 high to set logic to 1/8th microstep resolution
  digitalWrite(MS2, HIGH);
  for(x= 1; x<1500; x++)  //Loop the forward stepping enough times for motion to be visible
  {
    digitalWrite(stp,HIGH); //Trigger one step forward
    delay(1);
    digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
    delay(1);
  }
  Serial.println("Enter new option");
  Serial.println();
}

