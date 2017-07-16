#include <Arduino.h>

#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#include <Wire.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DNSServer.h>            //Local DNS Server used for redirecting all requests to the configuration portal
#include <ESP8266WebServer.h>     //Local WebServer used to serve the configuration portal
#include <WiFiManager.h>          //https://github.com/tzapu/WiFiManager WiFi Configuration Magic
#include <EEPROM.h>
//------------------------------------------------
#define BLYNK_PRINT Serial
//------------------------------------------------
#define BLACK    0x0000
#define BLUE     0x001F
#define RED      0xF800
#define GREEN    0x07E0
#define CYAN     0x07FF
#define MAGENTA  0xF81F
#define YELLOW   0xFFE0
#define WHITE    0xFFFF
#define pause    500
#define initTime 100
//------------------------------------------------
static const int phraseES[4]        = {0,0,1,9};
static const int phraseIST[4]       = {0,3,5,9};
static const int phraseVor[4]       = {0,6,8,6};
static const int phraseNACH[4]      = {0,2,5,6};
static const int phraseHALB[4]      = {0,0,3,5};
static const int phraseVIERTEL[4]   = {0,4,10,7};
static const int phraseUHR[4]       = {0,8,10,0};
static const int phraseOK[4]        = {0,6,7,0};
static const int phraseNO[4]        = {0,0,1,9};
static const int phraseWLAN[4]      = {0,0,3,7};

static const int hourEIN[4]        = {0,2,4,4};
static const int hourEINS[4]        = {0,2,5,4};
static const int hourZwei[4]        = {0,0,3,4};
static const int hourDREI[4]        = {0,1,4,3};
static const int hourVIER[4]        = {0,7,10,2};
static const int hourFUENFm[4]      = {0,7,10,9};
static const int hourFUENFs[4]      = {0,7,10,3};
static const int hourSECHS[4]       = {0,1,5,0};
static const int hourSIEBEN[4]      = {0,5,10,4};
static const int hourACHT[4]        = {0,1,4,1};
static const int hourNEUN[4]        = {0,3,6,2};
static const int hourZEHNm[4]       = {0,0,3,8};
static const int hourZEHNs[4]       = {0,5,8,1};
static const int hourELF[4]         = {0,0,2,2};
static const int hourZWOELF[4]      = {0,5,9,5};
static const int hourZWANZIG[4]     = {0,4,10,8};
//------------------------------------------------
  int hours;
  int minutes;
  int i = 1;
  int mytimemonth;
  int mytimeday;
  int mytimehr;
  int mytimemin;
  int mytimesec;
  const char* ssid = "";
  const char* password = "";
  char TIMEC[40];
  char *hourTIME;
  char *minTIME;
  char *secTIME;
  char auth[] = "7a7d8af34e37437cae1d203c74cb943e";
  int trigger = 0;
  String Ntime;
  int color=WHITE;
  String regg[55];
  String theDate;
  String BORN="Fri, 14 Jul 2017 0:0:0 GMT";

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(11, 11, 5,
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
  NEO_MATRIX_ROWS + NEO_MATRIX_ZIGZAG,
  NEO_GRB            + NEO_KHZ800);
WiFiServer server(80);

//Funktion für Initialisierung der Uhr
void initClock(){
  for(int i = 0; i<11; i++) {
    matrix.drawPixel(i,0,RED);
    matrix.drawPixel(10-i,1,GREEN);
    matrix.drawPixel(i,2,BLUE);
    matrix.drawPixel(10-i,3,RED);
    matrix.drawPixel(i,4,GREEN);
    matrix.drawPixel(10-i,5,BLUE);
    matrix.drawPixel(i,6,RED);
    matrix.drawPixel(10-i,7,GREEN);
    matrix.drawPixel(i,8,BLUE);
    matrix.drawPixel(10-i,9,RED);
    matrix.drawPixel(i,10,GREEN);
    matrix.show();
    delay(initTime);
  }
  for(int j = 0; j<11; j++) {
    matrix.drawPixel(j,0,BLACK);
    matrix.drawPixel(10-j,1,BLACK);
    matrix.drawPixel(j,2,BLACK);
    matrix.drawPixel(10-j,3,BLACK);
    matrix.drawPixel(j,4,BLACK);
    matrix.drawPixel(10-j,5,BLACK);
    matrix.drawPixel(j,6,BLACK);
    matrix.drawPixel(10-j,7,BLACK);
    matrix.drawPixel(j,8,BLACK);
    matrix.drawPixel(10-j,9,BLACK);
    matrix.drawPixel(j,10,BLACK);
    matrix.show();
    delay(initTime);
  }
}

void displayWords() {
  for (int i = 0; i<11; i++) {
    matrix.drawLine(0,i,10,i,0);
  }
  //Always on
  matrix.drawLine(phraseES[1],phraseES[3],phraseES[2],phraseES[3],color);
  matrix.drawLine(phraseIST[1],phraseIST[3],phraseIST[2],phraseIST[3],color);
    // define the dots
    if((minutes%10)==1 || (minutes%10)==6 ){
      matrix.drawLine(0,10,0,10,color);
    }
    if((minutes%10)==2 || (minutes%10)==7 ){
      matrix.drawLine(0,10,0,10,color);
      matrix.drawLine(1,10,1,10,color);
    }
    if((minutes%10)==3 || (minutes%10)==8){
      matrix.drawLine(0,10,0,10,color);
      matrix.drawLine(1,10,1,10,color);
      matrix.drawLine(2,10,2,10,color);
    }
    if((minutes%10)==4 || (minutes%10)==9){
      matrix.drawLine(0,10,0,10,color);
      matrix.drawLine(1,10,1,10,color);
      matrix.drawLine(2,10,2,10,color);
      matrix.drawLine(3,10,3,10,color);
    }
  //calculate minutes on the hour
    if(minutes<30 || minutes>34){
    matrix.drawLine(phraseUHR[1],phraseUHR[3],phraseUHR[2],phraseUHR[3],color);
    trigger=1;
    }
    if(minutes>4 && minutes<10){
    matrix.drawLine(hourFUENFm[1],hourFUENFm[3],hourFUENFm[2],hourFUENFm[3],color);
    matrix.drawLine(phraseNACH[1],phraseNACH[3],phraseNACH[2],phraseNACH[3],color);
    }
    if(minutes>9 && minutes<15){
    matrix.drawLine(hourZEHNm[1],hourZEHNm[3],hourZEHNm[2],hourZEHNm[3],color);
    matrix.drawLine(phraseNACH[1],phraseNACH[3],phraseNACH[2],phraseNACH[3],color);
    }
    if(minutes>14 && minutes<20){
    matrix.drawLine(phraseVIERTEL[1],phraseVIERTEL[3],phraseVIERTEL[2],phraseVIERTEL[3],color);
    matrix.drawLine(phraseNACH[1],phraseNACH[3],phraseNACH[2],phraseNACH[3],color);
    }
    if(minutes>19 && minutes<25){
    matrix.drawLine(hourZWANZIG[1],hourZWANZIG[3],hourZWANZIG[2],hourZWANZIG[3],color);
    matrix.drawLine(phraseNACH[1],phraseNACH[3],phraseNACH[2],phraseNACH[3],color);
    }
    if(minutes>24 && minutes<30){
    matrix.drawLine(hourFUENFm[1],hourFUENFm[3],hourFUENFm[2],hourFUENFm[3],color);
    matrix.drawLine(phraseVor[1],phraseVor[3],phraseVor[2],phraseVor[3],color);
    matrix.drawLine(phraseHALB[1],phraseHALB[3],phraseHALB[2],phraseHALB[3],color);
    }
    if(minutes>29 && minutes<35){
    matrix.drawLine(phraseHALB[1],phraseHALB[3],phraseHALB[2],phraseHALB[3],color);
    }
    if(minutes>34 && minutes<40){
    matrix.drawLine(hourFUENFm[1],hourFUENFm[3],hourFUENFm[2],hourFUENFm[3],color);
    matrix.drawLine(phraseNACH[1],phraseNACH[3],phraseNACH[2],phraseNACH[3],color);
    matrix.drawLine(phraseHALB[1],phraseHALB[3],phraseHALB[2],phraseHALB[3],color);
    }
    if(minutes>39 && minutes<45){
    matrix.drawLine(hourZWANZIG[1],hourZWANZIG[3],hourZWANZIG[2],hourZWANZIG[3],color);
    matrix.drawLine(phraseVor[1],phraseVor[3],phraseVor[2],phraseVor[3],color);
    }
    if(minutes>44 && minutes<50){
    matrix.drawLine(phraseVIERTEL[1],phraseVIERTEL[3],phraseVIERTEL[2],phraseVIERTEL[3],color);
    matrix.drawLine(phraseVor[1],phraseVor[3],phraseVor[2],phraseVor[3],color);
    }
    if(minutes>49 && minutes<55){
    matrix.drawLine(hourZEHNm[1],hourZEHNm[3],hourZEHNm[2],hourZEHNm[3],color);
    matrix.drawLine(phraseVor[1],phraseVor[3],phraseVor[2],phraseVor[3],color);
    }
    if(minutes>54 && minutes<60){
    matrix.drawLine(hourFUENFm[1],hourFUENFm[3],hourFUENFm[2],hourFUENFm[3],color);
    matrix.drawLine(phraseVor[1],phraseVor[3],phraseVor[2],phraseVor[3],color);
    }
  if(minutes<25){
    // Calculate hour
    if(hours==1 || hours==13 ){
      if(trigger==1){
        matrix.drawLine(hourEIN[1],hourEIN[3],hourEIN[2],hourEIN[3],color);
      }else{
        matrix.drawLine(hourEINS[1],hourEINS[3],hourEINS[2],hourEINS[3],color);
      }
    }
    if(hours==2 || hours==14 ){
     matrix.drawLine(hourZwei[1],hourZwei[3],hourZwei[2],hourZwei[3],color);
    }
    if(hours==3 || hours==15 ){
    matrix.drawLine(hourDREI[1],hourDREI[3],hourDREI[2],hourDREI[3],color);
    }
    if(hours==4 || hours==16 ){
     matrix.drawLine(hourVIER[1],hourVIER[3],hourVIER[2],hourVIER[3],color);
    }
    if(hours==5 || hours==17 ){
     matrix.drawLine(hourFUENFs[1],hourFUENFs[3],hourFUENFs[2],hourFUENFs[3],color);
    }
    if(hours==6 || hours==18 ){
     matrix.drawLine(hourSECHS[1],hourSECHS[3],hourSECHS[2],hourSECHS[3],color);
    }
    if(hours==7 || hours==19 ){
     matrix.drawLine(hourSIEBEN[1],hourSIEBEN[3],hourSIEBEN[2],hourSIEBEN[3],color);
    }
    if(hours==8 || hours==20 ){
     matrix.drawLine(hourACHT[1],hourACHT[3],hourACHT[2],hourACHT[3],color);
    }
    if(hours==9 || hours==21 ){
     matrix.drawLine(hourNEUN[1],hourNEUN[3],hourNEUN[2],hourNEUN[3],color);
    }
    if(hours==10 || hours==22 ){
     matrix.drawLine(hourZEHNs[1],hourZEHNs[3],hourZEHNs[2],hourZEHNs[3],color);
    }
    if(hours==11 || hours==23 ){
     matrix.drawLine(hourELF[1],hourELF[3],hourELF[2],hourELF[3],color);
    }
    if(hours==12 || hours==0 ){
    matrix.drawLine(hourZWOELF[1],hourZWOELF[3],hourZWOELF[2],hourZWOELF[3],color);
    }
  }
  if(minutes>24){
    // Calculate hour
    if(hours==25 || hours==13 ){
     matrix.drawLine(hourZwei[1],hourZwei[3],hourZwei[2],hourZwei[3],color);
    }
    if(hours==2 || hours==14 ){
    matrix.drawLine(hourDREI[1],hourDREI[3],hourDREI[2],hourDREI[3],color);
    }
    if(hours==3 || hours==15 ){
     matrix.drawLine(hourVIER[1],hourVIER[3],hourVIER[2],hourVIER[3],color);
    }
    if(hours==4 || hours==16 ){
     matrix.drawLine(hourFUENFs[1],hourFUENFs[3],hourFUENFs[2],hourFUENFs[3],color);
    }
    if(hours==5 || hours==17 ){
     matrix.drawLine(hourSECHS[1],hourSECHS[3],hourSECHS[2],hourSECHS[3],color);
    }
    if(hours==6 || hours==18 ){
     matrix.drawLine(hourSIEBEN[1],hourSIEBEN[3],hourSIEBEN[2],hourSIEBEN[3],color);
    }
    if(hours==7 || hours==19 ){
     matrix.drawLine(hourACHT[1],hourACHT[3],hourACHT[2],hourACHT[3],color);
    }
    if(hours==8 || hours==20 ){
     matrix.drawLine(hourNEUN[1],hourNEUN[3],hourNEUN[2],hourNEUN[3],color);
    }
    if(hours==9 || hours==21 ){
     matrix.drawLine(hourZEHNs[1],hourZEHNs[3],hourZEHNs[2],hourZEHNs[3],color);
    }
    if(hours==10 || hours==22 ){
     matrix.drawLine(hourELF[1],hourELF[3],hourELF[2],hourELF[3],color);
    }
    if(hours==11 || hours==23 ){
    matrix.drawLine(hourZWOELF[1],hourZWOELF[3],hourZWOELF[2],hourZWOELF[3],color);
    }
    if(hours==12 || hours==24 ){
    matrix.drawLine(hourEINS[1],hourEINS[3],hourEINS[2],hourEINS[3],color);
    }
  }
  trigger=0;
}

String getTime() {
  WiFiClient client;
  while (!!!client.connect("google.de", 80)) {
    Serial.println("connection failed, retrying...");
  }
  client.print("HEAD / HTTP/1.1\r\n\r\n");
  int jesus = 1;
  while(!!!client.available()) {
     delay(10);
     yield();
     jesus ++;
     if(jesus>190){
            Serial.println("Jesus Christ it's Jason Born! -----------------------------------------------------------------");
            return BORN;
     }
  }
  while(client.available()){
    if (client.read() == '\n') {
      if (client.read() == 'D') {
        if (client.read() == 'a') {
          if (client.read() == 't') {
            if (client.read() == 'e') {
              if (client.read() == ':') {
                client.read();
                String theDate = client.readStringUntil('\r');
                client.stop();
                //Serial.println(theDate);
                BORN=theDate;
                return theDate;
              }
            }
          }
        }
      }
    }
  }
}

void initWifi() {
  matrix.drawLine(phraseWLAN[1],phraseWLAN[3],phraseWLAN[2],phraseWLAN[3],RED);
  matrix.show();
  delay(1000);
// -----------------------------------------------------------------------
  WiFiManager wifiManager;
  wifiManager.autoConnect("Wordclock", "Batman123");      //Log In zum Wifimanager
  Serial.println();
  Serial.print("Connecting to ");
  Serial.print(ssid);
// -----------------------------------------------------------------------
  Serial.print("\nWiFi connected, IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
  Serial.println();
  Serial.println();
  Serial.println("Server started");
}

String hourMIN() {
  String TIME = getTime();
  for(int f=0;f<40;f++){
      TIMEC[f]=TIME[f];
      }
  char *p = strtok (TIMEC, " ");
  char *wups[50];
  i=0;
  for (int i = 1; i<6; i++) {
    wups[i] = p;
    p = strtok (NULL, " ");
    if (i==4){
      char *g = strtok (p, ":");
      hourTIME =g;
      g = strtok (NULL, ":");
      minTIME =g;
      g = strtok (NULL, ":");
      secTIME =g;
      g = strtok (NULL, ":");
    }
  }
  hours=atoi( hourTIME)+2;
  minutes=atoi( minTIME);
  return TIME;
}

void MyServer() {
  WiFiClient client = server.available();

  if (!client) {
    return;
  }

  if (client.available()){
    String req = client.readStringUntil('\r');
    if (req.indexOf("favicon") == -1){
      Serial.println(req);
      Serial.println(Ntime);
      client.flush();
      delay(100);
      char copy[30];
      req.toCharArray(copy, 30);
      // Match the request
      if (req.indexOf("/color/") != -1){
        switch (copy[11]){
          case 'w':
                Serial.println("set Color: WHITE" );
                color=WHITE;
                break;
          case 'y':
                color=YELLOW;
                break;
          case 'g':
                color=GREEN;
                break;
          case 'b':
                color=BLUE;
                break;
          case 'r':
                color=RED;
                break;
          case 'm':
                color=MAGENTA;
                break;
          case 'c':
                color=CYAN;
                break;
        }
      }
      else if (req.indexOf("/brightness/") != -1){
      char numbers[3];
      numbers[0] = copy[16];
      numbers[1] = copy[17];
      numbers[2] = copy[18];
      numbers[3] = '\0';
      int numbersC = atoi(numbers);
      matrix.setBrightness (numbersC);
      Serial.println("set brightness: " );
      Serial.println(numbersC);
      }
      else {
        Serial.println("invalid request");
        return;
      }
      client.flush();
      // response
      String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\nCOLOR is now ";
      s += (color)?"high":"low";
      s += "</html>\n";
      client.print(s);
      delay(1);
    }
  }
}

void setup() {
    // Debug console
  Serial.begin(9600);
  matrix.begin();
  matrix.setBrightness (128);
  matrix.show();
  initClock(); //Aufrufen der Initialisierung
  initWifi();
  Serial.println(WiFi.localIP());
  //Blynk.begin(auth,  WiFi.SSID().c_str(), WiFi.psk().c_str());
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
// -----------------------------------------------------------------------
      initWifi();
// -----------------------------------------------------------------------
   }
   else{
     // Blynk.run();
// -----------------------------------------------------------------------
      Ntime = hourMIN();
// -----------------------------------------------------------------------
      MyServer();
      delay(500);
// -----------------------------------------------------------------------
      displayWords();
// -----------------------------------------------------------------------
   }
  matrix.show();
}
