#include <FS.h>
#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#include <Wire.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <ESP8266mDNS.h>
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
static const int phraseES[4]        = {0,0,1,10};
static const int phraseIST[4]       = {0,3,5,10};
static const int phraseWLAN[4]      = {0,7,10,10};
static const int hourFUENFm[4]      = {0,1,4,9};
static const int hourZEHNm[4]       = {0,5,8,9};

static const int phraseVIERTEL[4]   = {0,1,8,9};
static const int hourZWANZIG[4]     = {0,2,8,8};
static const int phraseMINUTEN[4]   = {0,1,7,7};
static const int phraseNACH[4]      = {0,1,4,6};
static const int phraseVor[4]       = {0,6,8,6};

static const int phraseHALB[4]      = {0,0,3,5};
static const int hourZWOELF[4]      = {0,5,9,5};
static const int hourZwei[4]        = {0,0,3,4};
static const int hourEIN[4]        = {0,2,4,4};
static const int hourEINS[4]        = {0,2,5,4};

static const int hourSIEBEN[4]      = {0,5,10,4};
static const int hourDREI[4]        = {0,1,4,3};
static const int hourFUENFs[4]      = {0,7,10,3};
static const int hourELF[4]         = {0,0,2,2};
static const int hourNEUN[4]        = {0,3,6,2};

static const int hourVIER[4]        = {0,7,10,2};
static const int hourACHT[4]        = {0,1,4,1};
static const int hourZEHNs[4]       = {0,6,9,1};
static const int hourSECHS[4]       = {0,1,5,0};
static const int phraseUHR[4]       = {0,8,10,0};
//------------------------------------------------
  int hours;
  int minutes;
  int i = 1;
  int offset=242;
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
  char auth[] = "";
  int trigger = 0;
  String Ntime;
  int color=WHITE;
  String regg[55];
  String theDate;
  String BORN="Fri, 14 Jul 2017 0:0:0 GMT";
  boolean extended_1 = 1;
  boolean extended_2 = 0;
  boolean initiateTransition = 0;
  int timeBuffer = 0;
  int numbersC = 128;
  char *serverPayload;
  boolean transFade = 0;
  boolean transHart = 0;
  boolean transEinschieben = 1;
  int array_i;
  int array[20][3];
  boolean Mode_autoHelligkeit = 1;
  //------------------------------------------------


Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(11, 12, 5,
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
  matrix.setBrightness (0);
  for (int i = 0; i<100; i++){
    matrix.drawPixel(2,1,WHITE);
    matrix.drawPixel(2,2,WHITE);
    matrix.drawPixel(2,2,WHITE);
    matrix.drawPixel(2,3,WHITE);
    matrix.drawPixel(2,4,WHITE);
    matrix.drawPixel(2,5,WHITE);
    matrix.drawPixel(2,6,WHITE);
    matrix.drawPixel(2,7,WHITE);
    matrix.drawPixel(2,8,WHITE);
    matrix.drawPixel(3,1,WHITE);
    matrix.drawPixel(3,2,WHITE);
    matrix.drawPixel(3,3,WHITE);
    matrix.drawPixel(3,4,WHITE);
    matrix.drawPixel(3,5,WHITE);
    matrix.drawPixel(3,6,WHITE);
    matrix.drawPixel(3,7,WHITE);
    matrix.drawPixel(3,8,WHITE);
    matrix.drawPixel(4,7,WHITE);
    matrix.drawPixel(4,8,WHITE);
    matrix.drawPixel(5,7,WHITE);
    matrix.drawPixel(5,8,WHITE);
    matrix.drawPixel(6,7,WHITE);
    matrix.drawPixel(6,8,WHITE);
    matrix.drawPixel(7,5,WHITE);
    matrix.drawPixel(7,6,WHITE);
    matrix.drawPixel(7,7,WHITE);
    matrix.drawPixel(6,4,WHITE);
    matrix.drawPixel(6,5,WHITE);
    matrix.drawPixel(5,4,WHITE);
    matrix.drawPixel(5,5,WHITE);
    matrix.drawPixel(4,4,WHITE);
    matrix.drawPixel(4,5,WHITE);
    matrix.setBrightness (i);
    matrix.show();
    delay(100);
  }
}

void displayWords() {
  array_i=0;
  for (int i = 0; i<12; i++) {
    matrix.drawLine(0,i,10,i,0);
  }
  //Always on
  if(extended_1){
    array_i=array_i + 1;
    array[array_i][0] =phraseES[1];
    array[array_i][1] =phraseES[2];
    array[array_i][2] =phraseES[3];
      matrix.drawLine(phraseES[1],phraseES[3],phraseES[2],phraseES[3],color);
          array_i=array_i + 1;
    array[array_i][0] =phraseIST[1];
    array[array_i][1] =phraseIST[2];
    array[array_i][2] =phraseIST[3];
      matrix.drawLine(phraseIST[1],phraseIST[3],phraseIST[2],phraseIST[3],color);
    }
    // define the dots
    if((minutes%10)==1 || (minutes%10)==6 ){
      matrix.drawLine(9,11,9,11,color);
    }
    if((minutes%10)==2 || (minutes%10)==7 ){
      matrix.drawLine(9,11,10,11,color);
    }
    if((minutes%10)==3 || (minutes%10)==8){
      matrix.drawLine(8,11,10,11,color);
    }
    if((minutes%10)==4 || (minutes%10)==9){
      matrix.drawLine(7,11,10,11,color);
    }
  //calculate minutes on the hour
    if(minutes<5){
      array_i=array_i + 1;
  array[array_i][0] =phraseUHR[1];
  array[array_i][1] = phraseUHR[2];
  array[array_i][2] = phraseUHR[3];
  matrix.drawLine(phraseUHR[1],phraseUHR[3],phraseUHR[2],phraseUHR[3],color);
    trigger=1;
    }
    if(((minutes>5 && minutes<25) || minutes>35) && extended_2){
      array_i=array_i + 1;
      array[array_i][0] =phraseUHR[1];
      array[array_i][1] = phraseUHR[2];
      array[array_i][2] = phraseUHR[3];
    matrix.drawLine(phraseUHR[1],phraseUHR[3],phraseUHR[2],phraseUHR[3],color);
    }
    if((minutes<30 || minutes>34) && minutes>4){
      array_i=array_i + 1;
      array[array_i][0] = phraseMINUTEN[1];
      array[array_i][1] = phraseMINUTEN[2];
      array[array_i][2] = phraseMINUTEN[3];
      matrix.drawLine(phraseMINUTEN[1],phraseMINUTEN[3],phraseMINUTEN[2],phraseMINUTEN[3],color);
    }
    if(minutes>4 && minutes<10){
      array_i=array_i + 1;
      array[array_i][0] =hourFUENFm[1];
      array[array_i][1] = hourFUENFm[2];
      array[array_i][2] = hourFUENFm[3];
    matrix.drawLine(hourFUENFm[1],hourFUENFm[3],hourFUENFm[2],hourFUENFm[3],color);
    array_i=array_i + 1;
    array[array_i][0] =phraseNACH[1];
    array[array_i][1] = phraseNACH[2];
    array[array_i][2] = phraseNACH[3];
    matrix.drawLine(phraseNACH[1],phraseNACH[3],phraseNACH[2],phraseNACH[3],color);
    }
    if(minutes>9 && minutes<15){
      array_i=array_i + 1;
      array[array_i][0] =hourZEHNm[1];
      array[array_i][1] = hourZEHNm[2];
      array[array_i][2] = hourZEHNm[3];
    matrix.drawLine(hourZEHNm[1],hourZEHNm[3],hourZEHNm[2],hourZEHNm[3],color);
    array_i=array_i + 1;
    array[array_i][0] =phraseNACH[1];
    array[array_i][1] = phraseNACH[2];
    array[array_i][2] = phraseNACH[3];
    matrix.drawLine(phraseNACH[1],phraseNACH[3],phraseNACH[2],phraseNACH[3],color);
    }
    if(minutes>14 && minutes<20){
      array_i=array_i + 1;
      array[array_i][0] =phraseVIERTEL[1];
      array[array_i][1] = phraseVIERTEL[2];
      array[array_i][2] = phraseVIERTEL[3];
    matrix.drawLine(phraseVIERTEL[1],phraseVIERTEL[3],phraseVIERTEL[2],phraseVIERTEL[3],color);
    array_i=array_i + 1;
    array[array_i][0] =phraseNACH[1];
    array[array_i][1] = phraseNACH[2];
    array[array_i][2] = phraseNACH[3];
    matrix.drawLine(phraseNACH[1],phraseNACH[3],phraseNACH[2],phraseNACH[3],color);
    }
    if(minutes>19 && minutes<25){
      array_i=array_i + 1;
      array[array_i][0] =hourZWANZIG[1];
      array[array_i][1] = hourZWANZIG[2];
      array[array_i][2] = hourZWANZIG[3];
    matrix.drawLine(hourZWANZIG[1],hourZWANZIG[3],hourZWANZIG[2],hourZWANZIG[3],color);
    array_i=array_i + 1;
    array[array_i][0] =phraseNACH[1];
    array[array_i][1] = phraseNACH[2];
    array[array_i][2] = phraseNACH[3];
    matrix.drawLine(phraseNACH[1],phraseNACH[3],phraseNACH[2],phraseNACH[3],color);
    }
    if(minutes>24 && minutes<30){
      array_i=array_i + 1;
      array[array_i][0] =hourFUENFm[1];
      array[array_i][1] = hourFUENFm[2];
      array[array_i][2] = hourFUENFm[3];
    matrix.drawLine(hourFUENFm[1],hourFUENFm[3],hourFUENFm[2],hourFUENFm[3],color);
    array_i=array_i + 1;
    array[array_i][0] =phraseVor[1];
    array[array_i][1] = phraseVor[2];
    array[array_i][2] = phraseVor[3];
    matrix.drawLine(phraseVor[1],phraseVor[3],phraseVor[2],phraseVor[3],color);
    array_i=array_i + 1;
    array[array_i][0] =phraseHALB[1];
    array[array_i][1] = phraseHALB[2];
    array[array_i][2] = phraseHALB[3];
    matrix.drawLine(phraseHALB[1],phraseHALB[3],phraseHALB[2],phraseHALB[3],color);
    }
    if(minutes>29 && minutes<35){
      array_i=array_i + 1;
      array[array_i][0]=phraseHALB[1];
      array[array_i][1] = phraseHALB[2];
      array[array_i][2] = phraseHALB[3];
    matrix.drawLine(phraseHALB[1],phraseHALB[3],phraseHALB[2],phraseHALB[3],color);
    }
    if(minutes>34 && minutes<40){
      array_i=array_i + 1;
      array[array_i][0] =hourFUENFm[1];
      array[array_i][1] = hourFUENFm[2];
      array[array_i][2] = hourFUENFm[3];
    matrix.drawLine(hourFUENFm[1],hourFUENFm[3],hourFUENFm[2],hourFUENFm[3],color);
    array_i=array_i + 1;
    array[array_i][0] =phraseNACH[1];
    array[array_i][1] = phraseNACH[2];
    array[array_i][2] = phraseNACH[3];
    matrix.drawLine(phraseNACH[1],phraseNACH[3],phraseNACH[2],phraseNACH[3],color);
    array_i=array_i + 1;
    array[array_i][0] =phraseHALB[1];
    array[array_i][1] = phraseHALB[2];
    array[array_i][2] = phraseHALB[3];
    matrix.drawLine(phraseHALB[1],phraseHALB[3],phraseHALB[2],phraseHALB[3],color);
    }
    if(minutes>39 && minutes<45){
      array_i=array_i + 1;
      array[array_i][0] =hourZWANZIG[1];
      array[array_i][1] = hourZWANZIG[2];
      array[array_i][2] = hourZWANZIG[3];
    matrix.drawLine(hourZWANZIG[1],hourZWANZIG[3],hourZWANZIG[2],hourZWANZIG[3],color);
    array_i=array_i + 1;
    array[array_i][0] =phraseVor[1];
    array[array_i][1] = phraseVor[2];
    array[array_i][2] = phraseVor[3];
    matrix.drawLine(phraseVor[1],phraseVor[3],phraseVor[2],phraseVor[3],color);
    }
    if(minutes>44 && minutes<50){
      array_i=array_i + 1;
      array[array_i][0] =phraseVIERTEL[1];
      array[array_i][1] = phraseVIERTEL[2];
      array[array_i][2] = phraseVIERTEL[3];
    matrix.drawLine(phraseVIERTEL[1],phraseVIERTEL[3],phraseVIERTEL[2],phraseVIERTEL[3],color);
    array_i=array_i + 1;
    array[array_i][0] =phraseVor[1];
    array[array_i][1] = phraseVor[2];
    array[array_i][2] = phraseVor[3];
    matrix.drawLine(phraseVor[1],phraseVor[3],phraseVor[2],phraseVor[3],color);
    }
    if(minutes>49 && minutes<55){
      array_i=array_i + 1;
      array[array_i][0] =hourZEHNm[1];
      array[array_i][1] = hourZEHNm[2];
      array[array_i][2] = hourZEHNm[3];
    matrix.drawLine(hourZEHNm[1],hourZEHNm[3],hourZEHNm[2],hourZEHNm[3],color);
    array_i=array_i + 1;
    array[array_i][0] =phraseVor[1];
    array[array_i][1] = phraseVor[2];
    array[array_i][2] = phraseVor[3];
    matrix.drawLine(phraseVor[1],phraseVor[3],phraseVor[2],phraseVor[3],color);
    }
    if(minutes>54 && minutes<60){
      array_i=array_i + 1;
      array[array_i][0] =hourFUENFm[1];
      array[array_i][1] = hourFUENFm[2];
      array[array_i][2] = hourFUENFm[3];
    matrix.drawLine(hourFUENFm[1],hourFUENFm[3],hourFUENFm[2],hourFUENFm[3],color);
    array_i=array_i + 1;
    array[array_i][0] =phraseVor[1];
    array[array_i][1] = phraseVor[2];
    array[array_i][2] = phraseVor[3];
    matrix.drawLine(phraseVor[1],phraseVor[3],phraseVor[2],phraseVor[3],color);
    }
  if(minutes<25){
    // Calculate hour
    if((hours%12)==1){
      if(trigger==1){
        array_i=array_i + 1;
        array[array_i][0] =hourEIN[1];
        array[array_i][1] =hourEIN[2];
        array[array_i][2] =hourEIN[3];
        matrix.drawLine(hourEIN[1],hourEIN[3],hourEIN[2],hourEIN[3],color);
      }else{
        array_i=array_i + 1;
        array[array_i][0] =hourEINS[1];
        array[array_i][1] =hourEINS[2];
        array[array_i][2] =hourEINS[3];
        matrix.drawLine(hourEINS[1],hourEINS[3],hourEINS[2],hourEINS[3],color);
      }
    }
    if((hours%12)==2){
      array_i=array_i + 1;
      array[array_i][0] =hourZwei[1];
      array[array_i][1] = hourZwei[2];
      array[array_i][2] = hourZwei[3];
     matrix.drawLine(hourZwei[1],hourZwei[3],hourZwei[2],hourZwei[3],color);
    }
    if((hours%12)==3){
      array_i=array_i + 1;
      array[array_i][0] =hourDREI[1];
      array[array_i][1] = hourDREI[2];
      array[array_i][2] = hourDREI[3];
    matrix.drawLine(hourDREI[1],hourDREI[3],hourDREI[2],hourDREI[3],color);
    }
    if((hours%12)==4){
      array_i=array_i + 1;
      array[array_i][0] =hourVIER[1];
      array[array_i][1] = hourVIER[2];
      array[array_i][2] = hourVIER[3];
     matrix.drawLine(hourVIER[1],hourVIER[3],hourVIER[2],hourVIER[3],color);
    }
    if((hours%12)==5){
      array_i=array_i + 1;
      array[array_i][0] =hourFUENFs[1];
      array[array_i][1] = hourFUENFs[2];
      array[array_i][2] = hourFUENFs[3];
     matrix.drawLine(hourFUENFs[1],hourFUENFs[3],hourFUENFs[2],hourFUENFs[3],color);
    }
    if((hours%12)==6){
      array_i=array_i + 1;
      array[array_i][0] =hourSECHS[1];
      array[array_i][1] = hourSECHS[2];
      array[array_i][2] = hourSECHS[3];
     matrix.drawLine(hourSECHS[1],hourSECHS[3],hourSECHS[2],hourSECHS[3],color);
    }
    if((hours%12)==7){
      array_i=array_i + 1;
      array[array_i][0] =hourSIEBEN[1];
      array[array_i][1] = hourSIEBEN[2];
      array[array_i][2] = hourSIEBEN[3];
     matrix.drawLine(hourSIEBEN[1],hourSIEBEN[3],hourSIEBEN[2],hourSIEBEN[3],color);
    }
    if((hours%12)==8){
      array_i=array_i + 1;
      array[array_i][0] =hourACHT[1];
      array[array_i][1] = hourACHT[2];
      array[array_i][2] = hourACHT[3];
     matrix.drawLine(hourACHT[1],hourACHT[3],hourACHT[2],hourACHT[3],color);
    }
    if((hours%12)==9){
      array_i=array_i + 1;
      array[array_i][0] =hourNEUN[1];
      array[array_i][1] = hourNEUN[2];
      array[array_i][2] = hourNEUN[3];
     matrix.drawLine(hourNEUN[1],hourNEUN[3],hourNEUN[2],hourNEUN[3],color);
    }
    if((hours%12)==10){
      array_i=array_i + 1;
      array[array_i][0] =hourZEHNs[1];
      array[array_i][2] = hourZEHNs[3];
      array[array_i][1] = hourZEHNs[2];
     matrix.drawLine(hourZEHNs[1],hourZEHNs[3],hourZEHNs[2],hourZEHNs[3],color);
    }
    if((hours%12)==11){
      array_i=array_i + 1;
      array[array_i][0] =hourELF[1];
      array[array_i][1] = hourELF[2];
      array[array_i][2] = hourELF[3];
     matrix.drawLine(hourELF[1],hourELF[3],hourELF[2],hourELF[3],color);
    }
    if((hours%12)==0){
      array_i=array_i + 1;
      array[array_i][0] =hourZWOELF[1];
      array[array_i][1] = hourZWOELF[2];
      array[array_i][2] = hourZWOELF[3];
    matrix.drawLine(hourZWOELF[1],hourZWOELF[3],hourZWOELF[2],hourZWOELF[3],color);
    }
  }
  if(minutes>24){
    // Calculate hour
    if((hours%12)==1){
      array_i=array_i + 1;
      array[array_i][0] =hourZwei[1];
      array[array_i][1] = hourZwei[2];
      array[array_i][2] = hourZwei[3];
     matrix.drawLine(hourZwei[1],hourZwei[3],hourZwei[2],hourZwei[3],color);
    }
    if((hours%12)==2){
      array_i=array_i + 1;
      array[array_i][0] =hourDREI[1];
      array[array_i][1] = hourDREI[2];
      array[array_i][2] = hourDREI[3];
    matrix.drawLine(hourDREI[1],hourDREI[3],hourDREI[2],hourDREI[3],color);
    }
    if((hours%12)==3){
      array_i=array_i + 1;
      array[array_i][0] =hourVIER[1];
      array[array_i][1] = hourVIER[2];
      array[array_i][2] = hourVIER[3];
     matrix.drawLine(hourVIER[1],hourVIER[3],hourVIER[2],hourVIER[3],color);
    }
    if((hours%12)==4){
      array_i=array_i + 1;
      array[array_i][0] =hourFUENFs[1];
      array[array_i][1] = hourFUENFs[2];
      array[array_i][2] = hourFUENFs[3];
     matrix.drawLine(hourFUENFs[1],hourFUENFs[3],hourFUENFs[2],hourFUENFs[3],color);
    }
    if((hours%12)==5){
      array_i=array_i + 1;
      array[array_i][0] =hourSECHS[1];
      array[array_i][1] = hourSECHS[2];
      array[array_i][2] = hourSECHS[3];
     matrix.drawLine(hourSECHS[1],hourSECHS[3],hourSECHS[2],hourSECHS[3],color);
    }
    if((hours%12)==6){
      array_i=array_i + 1;
      array[array_i][0] =hourSIEBEN[1];
      array[array_i][1] = hourSIEBEN[2];
      array[array_i][2] = hourSIEBEN[3];
     matrix.drawLine(hourSIEBEN[1],hourSIEBEN[3],hourSIEBEN[2],hourSIEBEN[3],color);
    }
    if((hours%12)==7){
      array_i=array_i + 1;
      array[array_i][0] =hourACHT[1];
      array[array_i][1] = hourACHT[2];
      array[array_i][2] = hourACHT[3];
     matrix.drawLine(hourACHT[1],hourACHT[3],hourACHT[2],hourACHT[3],color);
    }
    if((hours%12)==8){
      array_i=array_i + 1;
      array[array_i][0] =hourNEUN[1];
      array[array_i][1] = hourNEUN[2];
      array[array_i][2] = hourNEUN[3];
     matrix.drawLine(hourNEUN[1],hourNEUN[3],hourNEUN[2],hourNEUN[3],color);
    }
    if((hours%12)==9){
      array_i=array_i + 1;
      array[array_i][0] =hourZEHNs[1];
      array[array_i][2] = hourZEHNs[3];
      array[array_i][1] = hourZEHNs[2];
     matrix.drawLine(hourZEHNs[1],hourZEHNs[3],hourZEHNs[2],hourZEHNs[3],color);
    }
    if((hours%12)==10){
      array_i=array_i + 1;
      array[array_i][0] =hourELF[1];
      array[array_i][1] = hourELF[2];
      array[array_i][2] = hourELF[3];
     matrix.drawLine(hourELF[1],hourELF[3],hourELF[2],hourELF[3],color);
    }
    if((hours%12)==11){
      array_i=array_i + 1;
      array[array_i][0] =hourZWOELF[1];
      array[array_i][1] = hourZWOELF[2];
      array[array_i][2] = hourZWOELF[3];
    matrix.drawLine(hourZWOELF[1],hourZWOELF[3],hourZWOELF[2],hourZWOELF[3],color);
    }
    if((hours%12)==0){
      array_i=array_i + 1;
      array[array_i][0] =hourEINS[1];
      array[array_i][1] =hourEINS[2];
      array[array_i][2] =hourEINS[3];
    matrix.drawLine(hourEINS[1],hourEINS[3],hourEINS[2],hourEINS[3],color);
    }
  }
  if(Mode_autoHelligkeit){
    if(hours%24 >= 22 || hours%24 < 6){
      matrix.setBrightness (25);
    }
    else{
      matrix.setBrightness (numbersC);
    }
  }
  trigger=0;
  matrix.show();
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
            Serial.println("Jesus Christ it's Jason Bourne! -----------------------------------------------------------------");
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
//  wifiManager.setAPStaticIPConfig(IPAddress(10,0,1,1), IPAddress(10,0,1,1), IPAddress(255,255,255,0));
//  wifiManager.setSTAStaticIPConfig(IPAddress(192,168,2,104), IPAddress(192,168,2,1), IPAddress(255,255,255,0));
  wifiManager.autoConnect("Wordclock");      //Log In zum Wifimanager
  Serial.println();
  Serial.print("Connecting to ");
  Serial.print(ssid);
// -----------------------------------------------------------------------
  Serial.print("\nWiFi connected, IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
//    if (!MDNS.begin("esp8266")) {
//    Serial.println("Error setting up MDNS responder!");
//    while(1) {
//      delay(1000);
//    }}else{
//        Serial.println("mDNS responder started");
//        server.begin();
//        MDNS.addService("http", "tcp", 80);
//        Serial.println("TCP server started and service added");
//    }

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
  hours=atoi( hourTIME)+offset;
  minutes=atoi( minTIME);
  initiateTransition=0;
 if((minutes!=timeBuffer) && minutes%5==0){
    initiateTransition=1;
  }
  timeBuffer = minutes;
  return TIME;
}

void MyServer() {
  WiFiClient client = server.available();

  if (!client) {
    return;
  }

  if (client.available()){
    String req = client.readStringUntil('\r');
    Serial.println(req );
    if (req.indexOf("favicon") == -1){
      Serial.println(req);
        int newCounter = 1;
        for(int f=0;f<40;f++){
        TIMEC[f]=req[f];
        }
        char * pch;
        pch = strtok (TIMEC," ,.-/");
        while (pch != NULL)
        {
          pch = strtok (NULL, " ,.-/");
          if(newCounter==2){
           serverPayload =pch;
          }
          newCounter ++;
        }

      Serial.println(Ntime);
      client.flush();
      delay(100);
      char copy[30];
      req.toCharArray(copy, 30);
      // Match the request
      Serial.println(copy );
      switch (copy[5]){
          case 'c':{
                color = strtol (serverPayload,NULL,16);
                Serial.println (color);
                }
                   break;

          case 'b':{
                char numbers[3];
                numbers[0] = copy[16];
                numbers[1] = copy[17];
                numbers[2] = copy[18];
                numbers[3] = '\0';
                numbersC = atoi(numbers);
                matrix.setBrightness (numbersC);
                Serial.println("set brightness to: " );
                Serial.println(numbersC);
                break;
            }

          case 't':
             switch (copy[11]){
                case 'p':
                      offset++;
                      Serial.println(hours);
                      Serial.println(offset );
                      break;
                case 'm':
                      offset--;
                      Serial.println(hours);
                      Serial.println(offset );
                      break;
                case 'r':
                      offset=242;
                      Serial.println(hours);
                      Serial.println(offset );
                      break;
                  }
                   break;

          case 'm':
             switch (copy[11]){
                case 'e':
                      Serial.println(extended_1 );
                      extended_1 = !extended_1;
                      Serial.println(extended_1 );
                      break;
                case 'u':
                      Serial.println(extended_2 );
                      extended_2 = !extended_2;
                      Serial.println(extended_2 );
                      break;
                }
                   break;

          case 'f':
             switch (copy[11]){
                case 'a':
                      transFade = 1;
                      transHart = 0;
                      transEinschieben = 0;
                      break;
                case 'b':
                      transFade = 0;
                      transHart = 0;
                      transEinschieben = 1;
                      break;
                case 'c':
                      transFade = 0;
                      transHart = 1;
                      transEinschieben = 0;
                      Serial.println("hart:");
                      Serial.println(transHart );

                      break;
                }
                   break;
            }

      client.flush();
      // response
//      String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\n ";
      String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
      s += WiFi.localIP().toString();
     // s += "</html>\n";
      client.print(s);
      delay(1);
    }
  }
}

void setup() {
  Serial.begin(9600);
  matrix.begin();
  matrix.setBrightness (numbersC);
  matrix.show();
  initClock(); //Aufrufen der Initialisierung
  initWifi();
  Serial.println(WiFi.localIP());
}

void loop() {
  int fadeDelay = 10;
  int fadeDelay2= 100;
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
      if(initiateTransition && transFade){
        for (int i = numbersC; i>0; i--){
          matrix.setBrightness (i);
          delay(fadeDelay);
          matrix.show();
        }
      }
// -----------------------------------------------------------------------
      displayWords();
      if(initiateTransition && transEinschieben){
        for (int i = 0; i<11; i++) {
          matrix.drawLine(0,i,10,i,0);
        }
        for (int j = 0; j<11; j++){
          for (int i = 1; i<=array_i; i++){
            if((array[i][2]-10+j)>=0){
              matrix.drawLine(array[i][0],array[i][2]-10+j,array[i][1],array[i][2]-10+j,color);
            }
          }
          delay(fadeDelay2);
          matrix.show();
           for (int i = 0; i<11; i++) {
          matrix.drawLine(0,i,10,i,0);
        }
        }
    }
// -----------------------------------------------------------------------
      if(initiateTransition && transFade){
        for (int i = 1; i<numbersC; i++){
          matrix.setBrightness (i);
          delay(fadeDelay);
          matrix.show();
        }
      }
// -----------------------------------------------------------------------
   }
}
