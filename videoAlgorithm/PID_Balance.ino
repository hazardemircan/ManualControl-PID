double setpoint=0;
double lasttime, lastroll, lastpitch;
double error, errorpitch;
double pid_i,pid_i_p;

double control_signal()
{
  joydeger=analogRead(joypin);
  yukseklik_pwmY=map(joydeger,0,1023,1100,1900);
  
  imuDeger();
  
  double deltatime=(millis()-lasttime)/1000;
  lasttime=millis();

  double error_roll=roll-setpoint;
  double error_pitch=pitch-setpoint;

  //PID proportional
  double p=error_roll*KP;
  double p_p=error_pitch*KP;

  //PID integral
  if(-3<error<3)
  {
    pid_i+=(error_roll*deltatime)*KI;
  }

    if(-3<error_pitch<3)
  {
    pid_i_p+=(error_pitch*deltatime)*KI;
  }  

  double d=((error_roll-lastroll)/deltatime)*KD;
  double d_p=((error_pitch-lastpitch)/deltatime)*KD;

  double control_signal=p+pid_i+d;
  double control_signal_p=p_p+pid_i_p+d_p;

//  if(control_signal<-1500)
//  {
//    control_signal=-1500;
//  }
//  if(control_signal>1500)
//  {
//    control_signal=1500;
//  }

  // yÜKSELİRKEN GERÇEKLEŞEN PWM HESAPLAMASI
if(state==7)
{
  onsolcontrol=1500-control_signal+control_signal_p;
  onsagcontrol=1500+control_signal+control_signal_p;
  arkasolcontrol=1500-control_signal-control_signal_p;
  arkasagcontrol=1500+control_signal-control_signal_p;
//   onsolcontrol=0-control_signal+control_signal_p;
//  onsagcontrol=0+control_signal+control_signal_p;
//  arkasolcontrol=0-control_signal-control_signal_p;
//  arkasagcontrol=0+control_signal-control_signal_p;

  if(onsolcontrol<1500)
  {
    onsolcontrol=1500;
  }
  if(onsolcontrol>1900)
  {
    onsolcontrol=1900;
  }
    if(onsagcontrol<1500)
  {
    onsagcontrol=1500;
  }
  if(onsagcontrol>1900)
  {
    onsagcontrol=1900;
  }
    if(arkasolcontrol<1500)
  {
    arkasolcontrol=1500;
  }
  if(arkasolcontrol>1900)
  {
    arkasolcontrol=1900;
  }
    if(arkasagcontrol<1500)
  {
     arkasagcontrol=1500;
  }
  if(arkasagcontrol>1900)
  {
    arkasagcontrol=1900;
  }    
}


// DALARKEN GERÇEKLEŞECEK PWM HESAPLAMASI
else if(state==0)
{
  onsolcontrol=1500+control_signal-control_signal_p;
  onsagcontrol=1500-control_signal-control_signal_p;
  arkasolcontrol=1500+control_signal+control_signal_p;
  arkasagcontrol=1500-control_signal+control_signal_p;

//  onsolcontrol=0+control_signal-control_signal_p;
//  onsagcontrol=0-control_signal-control_signal_p;
//  arkasolcontrol=0+control_signal+control_signal_p;
//  arkasagcontrol=0-control_signal+control_signal_p;

  if(onsolcontrol>1500)
  {
    onsolcontrol=1500;
  }
  if(onsolcontrol<1100)
  {
    onsolcontrol=1100;
  }
    if(onsagcontrol>1500)
  {
    onsagcontrol=1500;
  }
  if(onsagcontrol<1100)
  {
    onsagcontrol=1100;
  }
    if(arkasolcontrol>1500)
  {
    arkasolcontrol=1500;
  }
  if(arkasolcontrol<1100)
  {
    arkasolcontrol=1100;
  }
    if(arkasagcontrol>1500)
  {
     arkasagcontrol=1500;
  }
  if(arkasagcontrol<1100)
  {
    arkasagcontrol=1100;
  }    
}
else
{
  onsolcontrol=1500+control_signal-control_signal_p;
  onsagcontrol=1500-control_signal-control_signal_p;
  arkasolcontrol=1500+control_signal+control_signal_p;
  arkasagcontrol=1500-control_signal+control_signal_p;

  if(onsolcontrol<1100)
  {
    onsolcontrol=1100;
  }
  if(onsolcontrol>1900)
  {
    onsolcontrol=1900;
  }

  if(onsagcontrol<1100)
  {
    onsagcontrol=1100;
  }
    if(onsagcontrol>1900)
  {
    onsagcontrol=1900;
  }

  if(arkasolcontrol<1100)
  {
    arkasolcontrol=1100;
  }
    if(arkasolcontrol>1900)
  {
    arkasolcontrol=1900;
  }

  if(arkasagcontrol<1100)
  {
    arkasagcontrol=1100;
  }    
    if(arkasagcontrol>1900)
  {
    arkasagcontrol=1900;
  }
}
  onsol=(MAX_PWM-onsolcontrol)+MIN_PWM;

  lastroll=error;
  lastpitch=errorpitch;

 return onsolcontrol, onsagcontrol, arkasolcontrol, arkasagcontrol, onsol;
}
