#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiClient.h>

#include <Servo.h>

#include "index.h"

#ifndef STASSID
#define STASSID "AlticeForumBraga"
#define STAPSK ""
#endif

const char *ssid = STASSID;
const char *password = STAPSK;

ESP8266WebServer server(80);
Servo servo;
int IN1 = D5;
int IN2 = D6;
int IN3 = D7;
int IN4 = D8;

void handleRotate() {
  String page = MAIN_PAGE;
  for (uint8_t i = 0; i < server.args(); i++) {
    servo.write(server.arg(i).toInt());
  }
  server.send(200, "text/html", page);
}

void handleTurn() {
  String page = MAIN_PAGE;
  for (uint8_t i = 0; i < server.args(); i++) {
    if (server.arg(i) == "left") {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN3, HIGH);
      delay(2000);
      digitalWrite(IN1, LOW);
      digitalWrite(IN3, LOW);
    } else {
      digitalWrite(IN2, HIGH);
      digitalWrite(IN4, HIGH);
      delay(2000);
      digitalWrite(IN2, LOW);
      digitalWrite(IN4, LOW);
    }
  }
  server.send(200, "text/html", page);
}

void handleWalk() {
  String page = MAIN_PAGE;
  for (uint8_t i = 0; i < server.args(); i++) {
    if (server.arg(i) == "foward") {
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      delay(2000);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
    } else {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN4, HIGH);
      delay(2000);
      digitalWrite(IN1, LOW);
      digitalWrite(IN4, LOW);
    }
  }
  server.send(200, "text/html", page);
}

void handleTurnOFF() {
  String page = MAIN_PAGE;
  digitalWrite(LED_BUILTIN, HIGH);
  server.send(200, "text/html", page);
}

void handleTurnON() {
  String page = MAIN_PAGE;
  digitalWrite(LED_BUILTIN, LOW);
  server.send(200, "text/html", page);
}

void handleRoot() {
  String page = MAIN_PAGE;
  server.send(200, "text/html", page);
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
  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

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

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  servo.write(0);
  digitalWrite(LED_BUILTIN, LOW);

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", handleRoot);
  server.on("/off", handleTurnOFF);
  server.on("/on", handleTurnON);
  server.on("/rotate", handleRotate);
  server.on("/turn", handleTurn);
  server.on("/walk", handleWalk);

  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
  server.handleClient();
  MDNS.update();
}
