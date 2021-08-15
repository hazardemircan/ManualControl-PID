void pidBalance()
{
  
  control_signal();
 
      // Manevra joystiğinde -x değerinin motorların ileri çalışabilmesi için yapılan +x dönüşümü
//  int solpwmX=(MAX_PWM-pwmX)+MIN_PWM; 
//
//  int solpwmXyatay=(MAX_PWM-yatay_pwmX)+MIN_PWM; //ileri
//  int sagpwmYatay=(MAX_PWM-yatay_pwmX)+MIN_PWM; //geri


    y_onSol.writeMicroseconds(onsol);
    y_onSag.writeMicroseconds(onsagcontrol);
    y_arkaSol.writeMicroseconds(arkasolcontrol);
    y_arkaSag.writeMicroseconds(arkasagcontrol);
  

//if(onsol<1550 && onsol>1450)
//{
//  y_onSol.writeMicroseconds(DUR_PWM);
//}
//if(onsagcontrol<1550 && onsagcontrol>1450)
//{
//  y_onSag.writeMicroseconds(DUR_PWM);
//}
//if(arkasolcontrol<1550 && arkasolcontrol>1450)
//{
//  y_arkaSol.writeMicroseconds(DUR_PWM);
//}
//if(arkasagcontrol<1550 && arkasagcontrol>1450)
//{
//  y_arkaSag.writeMicroseconds(DUR_PWM);
//}
 
  Serial.print("|| Görev: ");
  Serial.print(state);
    Serial.print("| on sol control: ");
  Serial.print(onsol);
    Serial.print("| on sag control: ");
  Serial.print(onsagcontrol);
    Serial.print("| arka sol control: ");
  Serial.print(arkasolcontrol);
    Serial.print("| arka sag control: ");
  Serial.println(arkasagcontrol);
  
}
