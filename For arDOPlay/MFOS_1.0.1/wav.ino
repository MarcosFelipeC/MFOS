
//#define SS A2
void SD_Card(){
  boolean boot_sd = 1;
  while (boot_sd) SD_Card_boot();
}

//Need a future implementation

void SD_Card_boot(){/*
  digitalWrite (A2,1);
  digitalWrite (A1,0);
  SdFat sd;
  SysCall::yield();
  
  if (!sd.begin(SS)) {  // SPI_FULL_SPEED
    digitalWrite (A2,0);
    digitalWrite (A1,1);
    display.clearDisplay();
    display.println("error");
    display.display();
  }
  else {
    digitalWrite (A2,0);
    digitalWrite (A1,1);
    display.clearDisplay();
    display.println("OK!");
    display.display();
  }*/
}
