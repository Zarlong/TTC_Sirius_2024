#include <AFMotor.h>   // подключаем библиотеку для шилда
AF_DCMotor motor1(1);  // подключаем мотор к клеммникам M1
AF_DCMotor motor2(2);  // подключаем мотор к клеммникам M2
#include <Servo.h>

Servo myservo;
void setup() {
  // motor1.setSpeed(255); // задаем максимальную скорость мотора
  // motor1.run(RELEASE);   // останавливаем мотор
  // motor2.setSpeed(255); // задаем максимальную скорость мотора
  // motor2.run(RELEASE);   // останавливаем мотор
  myservo.attach(10);
  // myservo.write(0);
  // delay(1000);
  // myservo.write(180);
  // Serial.begin(9600);
}

void loop() {
  // Serial.println(digitalRead(A0));
  if (digitalRead(A0) == 1) {
    motor1.run(FORWARD);   // задаем движение вперед
    motor2.run(BACKWARD);  // задаем движение вперед
    motor1.setSpeed(90);   // задаем скорость движения
    motor2.setSpeed(90);   // задаем скорость движения
  } else {
    motor1.run(RELEASE);  // останавливаем мотор M1
    motor2.run(RELEASE);  // останавливаем мотор M2
    for (int i = 0; i < 60; ++i) {
      motor1.setSpeed(0);  // задаем скорость движения
      motor2.setSpeed(0);
      motor1.run(FORWARD);  // задаем движение вперед
      motor2.run(BACKWARD);
      motor1.setSpeed(255);  // задаем скорость движения
      motor2.setSpeed(255);
      delay(4);
      motor2.run(FORWARD);  // задаем движение вперед
      motor1.run(BACKWARD);
      motor1.setSpeed(255);  // задаем скорость движения
      motor2.setSpeed(255);
      delay(4);
    }
    motor1.run(RELEASE);  // останавливаем мотор M1
    motor2.run(RELEASE);
    motor1.setSpeed(0);  // задаем скорость движения
    motor2.setSpeed(0);
  }
  if (digitalRead(A1) == 1) {
    myservo.write(0);
  } else {
    myservo.write(180);
  }
  // delay(2000);          // указываем время движения

  // motor1.run(RELEASE);  // останавливаем мотор M1
  // motor2.run(RELEASE);  // останавливаем мотор M2

  // motor1.run(BACKWARD); // задаем движение назад
  // motor2.run(BACKWARD); // задаем движение назад
  // motor1.setSpeed(255);   // задаем скорость движения
  // motor2.setSpeed(255);   // задаем скорость движения

  // delay(2000);          // указываем время движения

  // motor1.run(RELEASE);  // останавливаем мотор M1
  // motor2.run(RELEASE);  // останавливаем мотор M2
}