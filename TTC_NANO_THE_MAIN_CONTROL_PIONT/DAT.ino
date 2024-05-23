// int dhty() {
//   float h = dht.readHumidity();
//   // Read temperature as Celsius (the default)
//   float t = dht.readTemperature();
//   // Read temperature as Fahrenheit (isFahrenheit = true)
//   float f = dht.readTemperature(true);

//   // // Check if any reads failed and exit early (to try again).
//   if (isnan(h) || isnan(t) || isnan(f)) {
//     Serial.println(F("Failed to read from DHT sensor!"));
//     return;
//   }
//   return t;
// }
void fan() {
  digitalWrite(13, HIGH);  // Enable the internal 38kHz signal.
  delayMicroseconds(210);
  // int Led = 13;       // define LED Interface
  // int buttonpin = 3;  // define the obstacle avoidance sensor interface
  // int val;
  // val = digitalRead(A3);  // digital interface will be assigned a value of 3 to read val
  // boolean buttonIsUp = digitalRead(A3);

  // // если кнопка была отпущена и не отпущена сейчас
  // if (buttonWasUp && !buttonIsUp) {

  //   // исключаем дребезг контактов тактовой кнопки
  //   delay(100);

  //   // и считываем сигнал с кнопки снова
  //   buttonIsUp = digitalRead(A3);

  //   // если кнопка нажата, то переворачиваем сигнал светодиода
  //   if (buttonIsUp == 1)  // When the obstacle avoidance sensor detects a signal, LED flashes
  //   {
  //     digitalWrite(12, HIGH);
  //     digitalWrite(5, LOW);
  //     digitalWrite(4, HIGH);
  //   } else {
  //     digitalWrite(12, LOW);
  //     digitalWrite(5, HIGH);
  //     digitalWrite(4, LOW);
  //   }
  //   // if (!buttonIsUp) {
  //   //   ledEnabled = !ledEnabled;
  //   //   digitalWrite(10, ledEnabled);
  //   // }
  // }
  // digitalWrite(13, LOW);

  // // запоминаем состояние кнопки для новой итерации
  // buttonWasUp = buttonIsUp;
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(5);
  digitalWrite(PIN_TRIG, HIGH);

  // Выставив высокий уровень сигнала, ждем около 10 микросекунд. В этот момент датчик будет посылать сигналы с частотой 40 КГц.
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  //  Время задержки акустического сигнала на эхолокаторе.
  duration = pulseIn(PIN_ECHO, HIGH);

  // Теперь осталось преобразовать время в расстояние
  cm = (duration / 2) / 29.1;
  if (cm > 4) {
    digitalWrite(12, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);
  } else {
    digitalWrite(12, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
  }
}