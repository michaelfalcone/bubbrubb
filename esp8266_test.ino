#include<stdlib.h>
#include <SoftwareSerial.h>
#define SSID "FalcoNet"
#define PASS "thisismypassword"
SoftwareSerial wifi(4, 5); // RX, TX

void setup()
{
  Serial.begin(9600);
  wifi.begin(9600);
  wifi.setTimeout(3000);
  Serial.println ("BEGIN");
}

void loop()
{
//  delay(10000);
//  if (connectWiFi()) {
    Serial.println("CONNECTED");
    sendPrintWait("AT+CIPSTATUS");
//    delay(100000000000);
//  }
}

void sendPrintWait(String cmd)
{
  Serial.println("SENDING:");
  Serial.println(cmd);
  wifi.println(cmd);
  for(int i = 0; i<3; i++){
    while (!wifi.available());
    String content = "";
    char character;
    while(wifi.available()) {
        character = wifi.read();
        content.concat(character);
    }
    if (content != "") {
      Serial.println("_________________");
      Serial.println(content);
      Serial.println("^^^^^^^^^^^^^^^^^");
    }
  }
}

boolean connectWiFi()
{
//  sendPrint("AT+CWMODE=1");
  sendPrintWait("AT+CWMODE=1");
  delay(2000);
  String cmd="AT+CWJAP=\"";
  cmd+=SSID;
  cmd+="\",\"";
  cmd+=PASS;
  cmd+="\"";
  delay(5000);
  sendPrintWait(cmd);
//  sendPrint(cmd);
//  delay(5000);
//  if(wifi.find("OK"))
//  {
//    Serial.println("GOT IT");
//    return true;
//  }
//  else
//  {
//    Serial.println("WELL FUCK");
//    return false;
//  }
}
