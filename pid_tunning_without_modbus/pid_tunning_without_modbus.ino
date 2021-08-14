#include <Wire.h>
#include <Servo.h>

#define MPU9250_ADDRESS 0x68
#define ACC_FULL_SCALE_2_G 0x00
#define ACC_FULL_SCALE_4_G 0x08
#define ACC_FULL_SCALE_8_G 0x10
#define ACC_FULL_SCALE_16_G 0x18
#define MAX_PWM 1900 // ESC Maksimum PWM Değeri
#define MIN_PWM 1100 // ESC Minimum PWM Değeri
#define DUR_PWM 1500 // ESC'lerin durmasını sağlayan PWM Değeri

#define KP 30
#define KI 0
#define KD 2.25

Servo m_onSol,m_onSag,m_arkaSol,m_arkaSag,y_onSol,y_onSag,y_arkaSol,y_arkaSag;
 // rs modülü için gerekli olan değişkenler
const int slave=10; //Receiver RS-485, DE,RE pinlerinin bağlandığı pin 
int degerGelenX;  //Manevra joy, X için transmitterdan gelen değer (0-180)
int pwmX; //Manevra joy, X için degerGelenX değişkeninin maplenmiş hali (1100-1900)
int degerGelenY;  //Manevra joy, Y için transmitterdan gelen değer (0-180)
int pwmY; //Manevra joy, Y için degerGelenY değişkeninin maplenmiş hali (1100-1900)
int degerGelenYukseklikY;  //Yukseklik joy, Y için transmitterdan gelen değer (0-180) 
int yukseklik_pwmY; //Yükseklik joy, Y için degerGelenYukseklik değişkeninin maplenmiş hali (1100-1900)
int degerGelenYatayX;
int yatay_pwmX;

int joypin=A6;
int joydeger;



//mpu için gerekli değişkenler mpu sekmesinde kullanılıyor
double xAci1,yAci1,zAci1,x,x1,roll,y,y1,pitch,z,z1,z2;

//calculatestpeed fonksiyonunun çıktıları için tanımlanana değişkenler
int onsolcontrol, onsagcontrol, arkasolcontrol, arkasagcontrol;
int onsol;

void setup(){
  Serial.begin(9600);
  Wire.begin();
  pinMode(slave,OUTPUT);
  pinMode(joypin,INPUT);
  digitalWrite(slave,LOW);

  y_onSol.attach(6, MIN_PWM, MAX_PWM);
  y_onSag.attach(7, MIN_PWM, MAX_PWM);
  y_arkaSol.attach(8, MIN_PWM, MAX_PWM);
  y_arkaSag.attach(9, MIN_PWM, MAX_PWM);


    y_onSol.writeMicroseconds(MAX_PWM);
  y_onSag.writeMicroseconds(MAX_PWM);
  y_arkaSol.writeMicroseconds(MAX_PWM);
  y_arkaSag.writeMicroseconds(MAX_PWM);
  delay(2000);
    y_onSol.writeMicroseconds(DUR_PWM);
  y_onSag.writeMicroseconds(DUR_PWM);
  y_arkaSol.writeMicroseconds(DUR_PWM);
  y_arkaSag.writeMicroseconds(DUR_PWM);
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  
calculateSpeed();

Serial.print(roll);
Serial.print(" pitch: ");
Serial.println(pitch);
delay(100);
}
