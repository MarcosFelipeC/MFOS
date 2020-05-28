void light_on_off(){
  //Apaga/acende display
  if (light_on == 1){
    digitalWrite(light,1);
    utlight = millis();
    light_on = 0;
  }
  if (millis() - utlight >= tempo_light){
    digitalWrite(light,0);
    light_on = 0;
  }   
}

void bt(){
  // +++ Botão Pressionado +++
  for (byte i = 0; i <= 5; i++){
    if (press_bt[i] == 1) press_bt[i] = 0;
  }
  for (byte k=3; k<=8; k++){
    if (!digitalRead(k) && ue_bt[k-3]){
      delay(3);
      mostra = 1;
      press_bt[k-3] = 1;
      light_on = 1;
      if(cfgbuzzer==1) tone(spk, 1000, 50);
      ue_bt[k-3] = 0;
    }
    if (digitalRead(k) && !ue_bt[k-3]){
      delay(3);
      ue_bt[k-3] = 1;
    }
  }
}
