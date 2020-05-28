void boot(){
  // +++ boot +++
  // Acende a luz:
  digitalWrite(light, 1);
  // SOM:
  tone(spk, 500);
  delay(100);
  tone(spk, 1000);
  delay(100);
  //tone(spk, 300);
  //delay(100);
  noTone(spk);
  // DISPLAY:
  display.begin();
  display.setContrast(60);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(1);
  display.setCursor(20,16);
  display.println("MFos");
  display.setCursor(9,33);
  display.setTextSize(1);
  display.println("by Marcos F.");
  display.display();
  delay(1000);
  display.setCursor(0,0);
  display.print("booting.");
  display.display();
  delay(300);

  // +++ Leitura da EEPROM +++
  /*for (byte k = 0; k<= 1; k++){
    if (EEPROM.read(k) > 1) EEPROM.write(k, 1);
  }
  */
  tempo_light = EEPROM.read(0)*1000;

  cfgbuzzer = EEPROM.read(1);

  
  display.setCursor(0,0);
  display.print("booting..");
  display.display();
  delay(300);
  display.setCursor(0,0);
  display.print("booting...");
  display.display();
  delay(1000);
}
