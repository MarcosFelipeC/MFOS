void ulstrassonico() {
  #define TRIGGER A3  //(DISPARO) - SAIDA: 8 pulso de 40khz
  #define ECHO A2  //RECEBE
  unsigned long tempo;
  int distancia_cm;
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  boolean boot_ultrassonico = 1;
  while (boot_ultrassonico){
    bt();
    light_on_off();
    
    light_on = 1;
    
    if (press_bt[0]){
      boot_ultrassonico = 0;
      press_bt[0] = 0;
    }
    
    display.clearDisplay();
    display.fillRect(0,0,84,8,BLACK);
    display.setCursor(6,0);
    display.setTextColor(WHITE);
    display.print("Ultrassonico");
    display.setTextColor(BLACK);

    
    display.setCursor(2,12);
    display.println("Distancia:");

    
    digitalWrite(TRIGGER, 1);
    delayMicroseconds(10);
    digitalWrite(TRIGGER, 0);
    
    tempo = pulseIn(ECHO, 1);//(qualpino), (tipo do pulso- 1 pra 0, 0 pra um), (tempo que ele aguarda o pulso acontecer)
    distancia_cm = 0.01715*tempo;//velocidade do som divididido por 2
    display.setCursor(2,20);
    display.setTextSize(2);
    display.print (distancia_cm);
    display.setTextSize(1);
    display.println (" cm");
    display.display();
    
    mostra = 1;
    delay(1);
  }

}
