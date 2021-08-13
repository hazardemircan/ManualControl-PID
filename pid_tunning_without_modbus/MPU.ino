int i=0;

//Veri okuyan fonksiyon
void I2Cread(uint8_t Adres, uint8_t Kayit, uint8_t Nbytes, uint8_t* Veri)
{
Wire.beginTransmission(Adres);
Wire.write(Kayit);
Wire.endTransmission();

Wire.requestFrom(Adres, Nbytes);
uint8_t j = 0;
while (Wire.available())
Veri[j++] = Wire.read();
}

// Verileri yazan fonksiyon
void I2CwriteByte(uint8_t Adres, uint8_t Kayit, uint8_t Veri)
{
Wire.beginTransmission(Adres);
Wire.write(Kayit);
Wire.write(Veri);
Wire.endTransmission();
}

double imuDeger()
{
  // — İvme Ölçer ve Jiroskop verilerini okuma —
uint8_t Buf[14];
I2Cread(MPU9250_ADDRESS, 0x3B, 14, Buf);

// Veri dönüşümü
int16_t ax = -(Buf[0] << 8 | Buf[1]);
int16_t ay = -(Buf[2] << 8 | Buf[3]);
int16_t az = Buf[4] << 8 | Buf[5];

double xAci = atan( ax / (sqrt(square(ay) + square(az))));
double yAci = atan( ay / (sqrt(square(ax) + square(az))));
double zAci = atan( sqrt(square(ax) + square(ay)) / az);

//Radyan cinsi verinin dereceye dönüşümü
xAci *= 180.00;
yAci *= 180.00;
zAci *= 180.00;
xAci /= PI;
yAci /= PI;
zAci /= PI;

// Kalibrasyon ve Filtrasyon İşlemleri

while(i<2){
  xAci1=xAci;
  yAci1=yAci;
  zAci1=zAci;
  i++;
  delay(1000);
  }

  x=xAci-xAci1;
  x1=((xAci-xAci1)+x)/2;
  roll=(x+x1+(xAci-xAci1))/3;
  
  
  y=yAci-yAci1;
  y1=((yAci-yAci1)+y)/2;
  pitch=(y+y1+(yAci-yAci1))/3;
  
  z=zAci-zAci1;
  z1=((zAci-zAci1)+z)/2;
  z2=(z+z1+(zAci-zAci1))/3;
  
return roll,pitch;
}
