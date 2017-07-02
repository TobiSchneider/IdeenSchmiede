#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#include <Wire.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
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
static const int hourSECHS[4]       = {0,1,4,0};
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
  char auth[] = "YourAuthToken";
  int trigger = 0;
   
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(11, 11, 5,
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
  NEO_MATRIX_ROWS + NEO_MATRIX_ZIGZAG,
  NEO_GRB            + NEO_KHZ800);

void displayWords() {
  for (int i = 0; i<11; i++) {
    matrix.drawLine(0,i,10,i,0);
  }
  //Always on
  matrix.drawLine(phraseES[1],phraseES[3],phraseES[2],phraseES[3],WHITE);
  matrix.drawLine(phraseIST[1],phraseIST[3],phraseIST[2],phraseIST[3],WHITE);
    // define the dots
    if((minutes%10)==1 || (minutes%10)==6 ){
      matrix.drawLine(0,10,0,10,WHITE);
    }
    if((minutes%10)==2 || (minutes%10)==7 ){
      matrix.drawLine(0,10,0,10,WHITE);
      matrix.drawLine(1,10,1,10,WHITE);
    }
    if((minutes%10)==3 || (minutes%10)==8){
      matrix.drawLine(0,10,0,10,WHITE);
      matrix.drawLine(1,10,1,10,WHITE);
      matrix.drawLine(2,10,2,10,WHITE);
    }
    if((minutes%10)==4 || (minutes%10)==9){
      matrix.drawLine(0,10,0,10,WHITE);
      matrix.drawLine(1,10,1,10,WHITE);
      matrix.drawLine(2,10,2,10,WHITE);
      matrix.drawLine(3,10,3,10,WHITE);
    }
  //calculate minutes on the hour
    if(minutes<5){
    matrix.drawLine(phraseUHR[1],phraseUHR[3],phraseUHR[2],phraseUHR[3],WHITE);
    trigger=1;
    }    
    if(minutes>4 && minutes<10){
    matrix.drawLine(hourFUENFm[1],hourFUENFm[3],hourFUENFm[2],hourFUENFm[3],WHITE);
    matrix.drawLine(phraseNACH[1],phraseNACH[3],phraseNACH[2],phraseNACH[3],WHITE);
    }
    if(minutes>9 && minutes<15){
    matrix.drawLine(hourZEHNm[1],hourZEHNm[3],hourZEHNm[2],hourZEHNm[3],WHITE);
    matrix.drawLine(phraseNACH[1],phraseNACH[3],phraseNACH[2],phraseNACH[3],WHITE);
    }
    if(minutes>14 && minutes<20){
    matrix.drawLine(phraseVIERTEL[1],phraseVIERTEL[3],phraseVIERTEL[2],phraseVIERTEL[3],WHITE);
    matrix.drawLine(phraseNACH[1],phraseNACH[3],phraseNACH[2],phraseNACH[3],WHITE);
    }
    if(minutes>19 && minutes<25){
    matrix.drawLine(hourZWANZIG[1],hourZWANZIG[3],hourZWANZIG[2],hourZWANZIG[3],WHITE);
    matrix.drawLine(phraseNACH[1],phraseNACH[3],phraseNACH[2],phraseNACH[3],WHITE);
    }
    if(minutes>24 && minutes<30){
    matrix.drawLine(hourFUENFm[1],hourFUENFm[3],hourFUENFm[2],hourFUENFm[3],WHITE);
    matrix.drawLine(phraseVor[1],phraseVor[3],phraseVor[2],phraseVor[3],WHITE);
    matrix.drawLine(phraseHALB[1],phraseHALB[3],phraseHALB[2],phraseHALB[3],WHITE);
    }
    if(minutes>29 && minutes<35){
    matrix.drawLine(phraseHALB[1],phraseHALB[3],phraseHALB[2],phraseHALB[3],WHITE);  
    }
    if(minutes>34 && minutes<40){
    matrix.drawLine(hourFUENFm[1],hourFUENFm[3],hourFUENFm[2],hourFUENFm[3],WHITE);
    matrix.drawLine(phraseNACH[1],phraseNACH[3],phraseNACH[2],phraseNACH[3],WHITE);
    matrix.drawLine(phraseHALB[1],phraseHALB[3],phraseHALB[2],phraseHALB[3],WHITE);  
    }
    if(minutes>39 && minutes<45){
    matrix.drawLine(hourZWANZIG[1],hourZWANZIG[3],hourZWANZIG[2],hourZWANZIG[3],WHITE);
    matrix.drawLine(phraseVor[1],phraseVor[3],phraseVor[2],phraseVor[3],WHITE);
    }
    if(minutes>44 && minutes<50){
    matrix.drawLine(phraseVIERTEL[1],phraseVIERTEL[3],phraseVIERTEL[2],phraseVIERTEL[3],WHITE);
    matrix.drawLine(phraseVor[1],phraseVor[3],phraseVor[2],phraseVor[3],WHITE);
    }    
    if(minutes>49 && minutes<55){
    matrix.drawLine(hourZEHNm[1],hourZEHNm[3],hourZEHNm[2],hourZEHNm[3],WHITE);
    matrix.drawLine(phraseVor[1],phraseVor[3],phraseVor[2],phraseVor[3],WHITE);
    }
    if(minutes>54 && minutes<60){
    matrix.drawLine(hourFUENFm[1],hourFUENFm[3],hourFUENFm[2],hourFUENFm[3],WHITE);
    matrix.drawLine(phraseVor[1],phraseVor[3],phraseVor[2],phraseVor[3],WHITE);
    }
  if(minutes<25){
    // Calculate hour 
    if(hours==1 || hours==13 ){
      if(trigger==1){
        matrix.drawLine(hourEIN[1],hourEIN[3],hourEIN[2],hourEIN[3],WHITE);
      }else{
        matrix.drawLine(hourEINS[1],hourEINS[3],hourEINS[2],hourEINS[3],WHITE);
      }
    }
    if(hours==2 || hours==14 ){
     matrix.drawLine(hourZwei[1],hourZwei[3],hourZwei[2],hourZwei[3],WHITE);
    }
    if(hours==3 || hours==15 ){
    matrix.drawLine(hourDREI[1],hourDREI[3],hourDREI[2],hourDREI[3],WHITE);
    }
    if(hours==4 || hours==16 ){
     matrix.drawLine(hourVIER[1],hourVIER[3],hourVIER[2],hourVIER[3],WHITE);
    }
    if(hours==5 || hours==17 ){
     matrix.drawLine(hourFUENFs[1],hourFUENFs[3],hourFUENFs[2],hourFUENFs[3],WHITE);
    }
    if(hours==6 || hours==18 ){
     matrix.drawLine(hourSECHS[1],hourSECHS[3],hourSECHS[2],hourSECHS[3],WHITE);
    }
    if(hours==7 || hours==19 ){
     matrix.drawLine(hourSIEBEN[1],hourSIEBEN[3],hourSIEBEN[2],hourSIEBEN[3],WHITE);
    }
    if(hours==8 || hours==20 ){
     matrix.drawLine(hourACHT[1],hourACHT[3],hourACHT[2],hourACHT[3],WHITE);
    }
    if(hours==9 || hours==21 ){
     matrix.drawLine(hourNEUN[1],hourNEUN[3],hourNEUN[2],hourNEUN[3],WHITE);
    }
    if(hours==10 || hours==22 ){
     matrix.drawLine(hourZEHNs[1],hourZEHNs[3],hourZEHNs[2],hourZEHNs[3],WHITE);
    }
    if(hours==11 || hours==23 ){
     matrix.drawLine(hourELF[1],hourELF[3],hourELF[2],hourELF[3],WHITE);
    }
    if(hours==12 || hours==0 ){
    matrix.drawLine(hourZWOELF[1],hourZWOELF[3],hourZWOELF[2],hourZWOELF[3],WHITE);
    }
  }
  if(minutes>24){
    // Calculate hour 
    if(hours==1 || hours==13 ){
     matrix.drawLine(hourZwei[1],hourZwei[3],hourZwei[2],hourZwei[3],WHITE);
    }
    if(hours==2 || hours==14 ){
    matrix.drawLine(hourDREI[1],hourDREI[3],hourDREI[2],hourDREI[3],WHITE);
    }
    if(hours==3 || hours==15 ){
     matrix.drawLine(hourVIER[1],hourVIER[3],hourVIER[2],hourVIER[3],WHITE);
    }
    if(hours==4 || hours==16 ){
     matrix.drawLine(hourFUENFs[1],hourFUENFs[3],hourFUENFs[2],hourFUENFs[3],WHITE);
    }
    if(hours==5 || hours==17 ){
     matrix.drawLine(hourSECHS[1],hourSECHS[3],hourSECHS[2],hourSECHS[3],WHITE);
    }
    if(hours==6 || hours==18 ){
     matrix.drawLine(hourSIEBEN[1],hourSIEBEN[3],hourSIEBEN[2],hourSIEBEN[3],WHITE);
    }
    if(hours==7 || hours==19 ){
     matrix.drawLine(hourACHT[1],hourACHT[3],hourACHT[2],hourACHT[3],WHITE);
    }
    if(hours==8 || hours==20 ){
     matrix.drawLine(hourNEUN[1],hourNEUN[3],hourNEUN[2],hourNEUN[3],WHITE);
    }
    if(hours==9 || hours==21 ){
     matrix.drawLine(hourZEHNs[1],hourZEHNs[3],hourZEHNs[2],hourZEHNs[3],WHITE);
    }
    if(hours==10 || hours==22 ){
     matrix.drawLine(hourELF[1],hourELF[3],hourELF[2],hourELF[3],WHITE);
    }
    if(hours==11 || hours==23 ){
    matrix.drawLine(hourZWOELF[1],hourZWOELF[3],hourZWOELF[2],hourZWOELF[3],WHITE);
    }
    if(hours==12 || hours==0 ){
    matrix.drawLine(hourEINS[1],hourEINS[3],hourEINS[2],hourEINS[3],WHITE);
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
  while(!!!client.available()) {
     yield();
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
                Serial.println(theDate);
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
   Serial.print("Connecting to ");
   Serial.print(ssid);
   WiFi.begin(ssid, password);
  
   while (WiFi.status() != WL_CONNECTED) {
      matrix.drawLine(phraseWLAN[1],phraseWLAN[3],phraseWLAN[2],phraseWLAN[3],RED);
      matrix.show();
      delay(1000);
      Serial.print(".");
   }
  Serial.print("\nWiFi connected, IP address: ");
  Serial.println(WiFi.localIP());
}

void hourMIN() {
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
}
void setup() {
    // Debug console
  Serial.begin(9600);
  //Blynk.begin(auth, ssid, pass);
  matrix.begin();
  matrix.setBrightness (128);
  matrix.show();
  initWifi();
}
void loop() {
 Serial.println("Still Alive");

//Blynk.run();
// Wlan Verbindung aufbauen und testen
  if (WiFi.status() != WL_CONNECTED) {
      initWifi();
      Serial.println("Wifi connection lost, reconnecting ...");
   }
   else{
// Mode selection 
// Request current time
    hourMIN();
    Serial.println(hours);
    Serial.println(minutes);
    delay(5000);
// Draw
    displayWords();
   }
  matrix.show();
}
