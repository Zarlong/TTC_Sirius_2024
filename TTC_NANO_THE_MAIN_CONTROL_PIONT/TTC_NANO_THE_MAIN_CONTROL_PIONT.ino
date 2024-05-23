#include <LiquidCrystal.h>

// #include "DHT.h"

// #define DHTPIN 2
// Задаём имя пинов дисплея
constexpr uint8_t PIN_RS = 6;
constexpr uint8_t PIN_EN = 7;
constexpr uint8_t PIN_DB4 = 8;
constexpr uint8_t PIN_DB5 = 9;
constexpr uint8_t PIN_DB6 = 10;
constexpr uint8_t PIN_DB7 = 11;

boolean buttonWasUp = true;
boolean ledEnabled = false;

// #define PIN_LED 5
#define PIN_PHOTO_SENSOR A0

// #define DHTTYPE DHT11
// DHT dht(DHTPIN, DHTTYPE);

int objectDetect = 0;

#define PIN_TRIG 13
#define PIN_ECHO A3

long duration, cm;

int dhtold = 0;

int longDHT = 0;
int longPHOTO = 0;

bool dhtflag = 0;
bool photoflag = 0;

int countDHT = 0;
int countPHOTO = 0;

int arr[2][16] = { { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16}, { 180, 170, 160, 150, 140, 130, 120, 110, 100, 90, 80, 70, 60, 50, 40, 30 } };
// int delsec[16] = {170, 165, 170, 175, 180, 185, 180, 180, 180, 180, 180, 180, 180, 180, 180, 190};
/*
 * Создаём объект для работы с текстовым дисплеем
 * LiquidCrystal lcd(RS, EN, DB4, DB5, DB6, DB7);
 * Подробности подключения:
 * http://wiki.amperka.ru/products:display-lcd-text-16x2
*/
LiquidCrystal lcd(PIN_RS, PIN_EN, PIN_DB4, PIN_DB5, PIN_DB6, PIN_DB7);

void setup() {
  // Устанавливаем размер экрана
  // Количество столбцов и строк
  lcd.begin(16, 2);
  Serial.begin(9600);
  // pinMode(PIN_LED, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  // Serial.println(F("DHTxx test!"));

  // dht.begin();
  pinMode(5, OUTPUT);  // define LED as output interface
  pinMode(4, OUTPUT);
  pinMode(A3, INPUT);
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  // Устанавливаем курсор в колонку 0 и строку 0
  //

  // int val = analogRead(PIN_PHOTO_SENSOR);
  // Serial.println(val);
  // if (val < 750) {
  //   digitalWrite(PIN_LED, LOW);
  // } else {
  //   digitalWrite(PIN_LED, HIGH);
  // }
  // Serial.println(val);
  delay(2000);
  // dhtold = dhty();
  for (int i = 0; i < 16; ++i) {
    // if (i <= 15) {
    fan();
    // long long j = millis() + delsec[i];
    digitalWrite(3, HIGH);
    delay(5);
    // dhtold = dhty();
    while (analogRead(A4) > 840) {  // ----------------------------------------ТЕСТ-----------------------------------------------
      fan();
      // Serial.println(analogRead(A2));
    }
    digitalWrite(3, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(i);
    lcd.setCursor(8, 1);
    lcd.print(analogRead(PIN_PHOTO_SENSOR));
    // Serial.println(i);
    lcd.setCursor(0, 1);
    lcd.print(analogRead(A2));
    
    // // Печатаем первую строку
    long long j = millis() + 2000;
    while (j > millis()) {
      fan();
      int eeeeeeee = analogRead(A2);
      int qqqqqqq = analogRead(PIN_PHOTO_SENSOR);
    }
    if ((analogRead(A2) < 120) and (dhtflag == 0)) {
      longDHT = i;
      dhtflag = 1;
      countDHT = analogRead(A2);
    }
    int valPHOTO = analogRead(PIN_PHOTO_SENSOR);
    if ((valPHOTO > 1000) and (photoflag == 0)) {
      longPHOTO = i;
      photoflag = 1;
      countPHOTO = valPHOTO;
    }
    fan();
    // }
  }
  // countPHOTO = analogRead(PIN_PHOTO_SENSOR);
  // countDHT = dhty();
  lcd.clear();
  lcd.setCursor(0, 0);
  longPHOTO += 1;
  for (int i = 0; i < 16; ++i) {
    if (arr[0][i] == longPHOTO) {
      longPHOTO = arr[1][i];
    }
  }
  // // Печатаем первую строку
  lcd.print(longPHOTO);


  lcd.setCursor(8, 0);
  // // Печатаем первую строку

  longDHT += 1;
  for (int i = 0; i < 16; ++i) {
    if (arr[0][i] == longDHT) {
      longDHT = arr[1][i];
    }
  }
  lcd.print(countPHOTO);
  // Устанавливаем курсор в колонку 0 и строку 1
  // lcd.setCursor(0, 1);
  lcd.setCursor(0, 1);
  // // Печатаем первую строку
  lcd.print(longDHT);
  // Печатаем вторую строку
  lcd.setCursor(8, 1);
  // // Печатаем первую строку
  lcd.print(countDHT);
}

void loop() {

  // delay(500);
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
}