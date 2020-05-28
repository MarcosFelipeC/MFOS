void snake(){
  boolean boot_snake = 1;
  display.setTextSize(2);
  display.setTextColor(BLACK, WHITE);
  for(int x = -54; x <= 13; x++){
    bt();
    light_on_off();
    if (press_bt[0] || press_bt[1]) x = 13;
    display.clearDisplay();
    display.setCursor(x,16);
    //x final 15
    display.println("Snake");
    display.display();
    delay(2);
  }
  for (int i = 80; i >= 0; i--){
    bt();
    light_on_off();
    if (press_bt[0] || press_bt[1]) i = 0;
    display.drawLine(16-i, 8, 80-i, 8, BLACK);
    display.drawLine(16-i, 9, 80-i, 9, BLACK);
    display.display();
    delay(2);
  }
  for (int i = 32; i >= 0; i--){
    bt();
    light_on_off();
    if (press_bt[0] || press_bt[1]) i = 0;
    display.drawLine(80, 8, 80, 40-i, BLACK);
    display.drawLine(79, 8, 79, 40-i, BLACK);
    display.display();
    delay(2);
  }
  delay(50);
  display.setTextColor(WHITE, BLACK);
  display.setTextSize(1);
  display.setCursor(27,35);
  display.println("Start");
  display.display();
  display.setTextColor(BLACK, WHITE);
  boolean start_snake=0;
  boolean pause_game = 0;
  while(boot_snake == 1){
    bt();
    light_on_off();
    display.clearDisplay();
    display.setCursor(0,0);
    display.println("Em desenvolvimento...");
    display.display();
    if(press_bt[0]){
      press_bt[0] = 0;
      boot_snake = 0;
    }
    mostra = 1;
  }  
}
