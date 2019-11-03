#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#include <Servo.h>

#ifndef STASSID
#define STASSID "AlticeForumBraga"
#define STAPSK  ""
#endif

const char* ssid = STASSID;
const char* password = STAPSK;

ESP8266WebServer server(80);

Servo servo;

void handleRoda() {
    servo.write(0);
    delay(3000);
    servo.write(90);
    delay(3000);
    servo.write(180);
    delay(3000);
}

void handleTurnOFF() {
  digitalWrite(2, HIGH);
  server.send(200, "text/html", "Luz: OFF \
  <form action='turnON' method='get'> \
         <button type='submit'>ON</button> \
  </form> \
  ");
}

void handleTurnON() {
  digitalWrite(2, LOW);
  server.send(200, "text/html", "Luz: ON \
  <form action='turnOFF' method='get'> \
         <button type='submit'>OFF</button> \
  </form> \
  ");
}

void handleRoot() {
  server.send(200, "text/html", "Olá");
}

void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}

void setup(void) {
  pinMode(2, OUTPUT);

  servo.attach(D1);
  servo.write(0);

  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", handleRoot);
  server.on("/turnOFF", handleTurnOFF);
  server.on("/turnON", handleTurnON);
  server.on("/roda", handleRoda);

  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
  server.handleClient();
  MDNS.update();
}
