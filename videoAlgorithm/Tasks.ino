// 0-Dal
// 1-İleri
// 2-Geri
// 3-Sağ-yatay
// 4-Sol-yatay
// 5-Sağ dönüş
// 6-Sol dönüş
// 7-Yüksel

void moveTasks()
{
  switch (state)
  {
    case 1:
      y_onSol.writeMicroseconds(onsol-150);
      y_onSag.writeMicroseconds(onsagcontrol-150);
      y_arkaSol.writeMicroseconds(arkasolcontrol-150);
      y_arkaSag.writeMicroseconds(arkasagcontrol-150);
      Serial.println("Dalıyor");
      
    break;
    case 2:
    for(int control=1500;control<=1850;control++)
     {
      int controlTers=(MAX_PWM-control)+MIN_PWM;
      m_onSol.writeMicroseconds(controlTers);
      m_onSag.writeMicroseconds(control);
      m_arkaSol.writeMicroseconds(control);
      m_arkaSag.writeMicroseconds(control);
      Serial.println("İleri Hareket");
     }
           m_onSol.writeMicroseconds(DUR_PWM);
      m_onSag.writeMicroseconds(DUR_PWM);
      m_arkaSol.writeMicroseconds(DUR_PWM);
      m_arkaSag.writeMicroseconds(DUR_PWM);
    break;
    case 3:
     for(int control=1500;control>=1150;control--)
     {
      int controlTers=(MAX_PWM-control)+MIN_PWM;
      m_onSol.writeMicroseconds(controlTers);
      m_onSag.writeMicroseconds(control);
      m_arkaSol.writeMicroseconds(control);
      m_arkaSag.writeMicroseconds(control);
      Serial.println("Geri hareket");
     }
                m_onSol.writeMicroseconds(DUR_PWM);
      m_onSag.writeMicroseconds(DUR_PWM);
      m_arkaSol.writeMicroseconds(DUR_PWM);
      m_arkaSag.writeMicroseconds(DUR_PWM);
    break;
    case 4:
      for(int control=1500;control<=1850;control++)
      {
        m_onSag.writeMicroseconds(control);
        m_arkaSag.writeMicroseconds(control);
        Serial.println("sağa dönüş");
      }
                 
      m_onSag.writeMicroseconds(DUR_PWM);
      
      m_arkaSag.writeMicroseconds(DUR_PWM);
      break;
    case 5:
      for(int control=1500;control<=1850;control++)
      {
        m_onSol.writeMicroseconds(control);
        m_arkaSol.writeMicroseconds(control);
        Serial.println("sola-yatay dönüş");
      }
    break;
    case 6:
      for(int control=1500;control<=1850;control++)
      {
        int controlTers=(MAX_PWM-control)+MIN_PWM;
        m_onSol.writeMicroseconds(controlTers);
        m_arkaSol.writeMicroseconds(control);
        Serial.println("sağa dönüş");
      }
                 m_onSol.writeMicroseconds(DUR_PWM);
     
      m_arkaSol.writeMicroseconds(DUR_PWM);
     
    break;
    case 7:
      for(int control=1500;control<=1850;control++)
      {
        m_onSag.writeMicroseconds(control);
        m_arkaSag.writeMicroseconds(control);
        Serial.println("sola dönüş");
      }
                 
      m_onSag.writeMicroseconds(DUR_PWM);
      
      m_arkaSag.writeMicroseconds(DUR_PWM);
    break;
    case 8:
      y_onSol.writeMicroseconds(onsol-150);
      y_onSag.writeMicroseconds(onsagcontrol+150);
      y_arkaSol.writeMicroseconds(arkasolcontrol+150);
      y_arkaSag.writeMicroseconds(arkasagcontrol+150);
      Serial.println("yükseliyor");
    break;
    default:
      pidBalance(); // !!! BURADA LOOP İÇİNDE DE TABIMLANDIĞI İÇİN SIKINTI ÇIKABİLİR !!!
            y_onSol.writeMicroseconds(DUR_PWM);
      y_onSag.writeMicroseconds(DUR_PWM);
      y_arkaSol.writeMicroseconds(DUR_PWM);
      y_arkaSag.writeMicroseconds(DUR_PWM);
    break;
  }
}
