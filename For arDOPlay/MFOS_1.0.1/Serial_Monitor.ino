void serial_monitor(){
  SoftwareSerial mySerial(A2, A3); //RX TX
  mySerial.begin(9600);
  display.clearDisplay();
  display.fillRect(0,0,84,8,BLACK);
  display.setCursor(0,0);
  display.setTextColor(WHITE);
  display.print("Serial Monitor");
  display.setTextColor(BLACK);
  display.display();
  boolean boot_serial_monitor = 1;
  while(boot_serial_monitor){
    inicio:
    bt();
    light_on_off();
    if(press_bt[0]){
      press_bt[0] = 0;
      boot_serial_monitor = 0;
    }
    String Recebido="";
    boolean StringPronta = 0;
    while (mySerial.available()){
      Recebido=mySerial.readString();
      StringPronta=1;
      }
    if(StringPronta){
      display.clearDisplay();
      display.fillRect(0,0,84,8,BLACK);
      display.drawRect(0,9,84,39,1);
      display.setCursor(0,0);
      display.setTextColor(WHITE);
      display.print("Serial Monitor");
      display.setTextColor(BLACK);
      display.setCursor(2,10);
      display.setContrast(60);
      display.setTextSize(1);
      display.setTextColor(BLACK);
      display.println(Recebido);
      display.display();
      light_on = 1;
      goto inicio;
    }
  }
}
