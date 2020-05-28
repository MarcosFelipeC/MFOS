void configuracoes(){
  String itensConfig[] = {"Luz da Tela","Som da Tecla","Zerar EEPROM", "USB"};
  boolean itenSelecionadoConfig[] = {1,0,0,0}; 
  boolean boot_config = 1;
  while(boot_config == 1){
    bt();
    light_on_off();
    mostra = 1;
    // +++ Strings de Configuração +++
    String Sim_Nao [] = {"Sim","Nao"};
    boolean Alternativa [] = {1,0};
    if(press_bt[1]){
      press_bt[1] = 0;
      if(itenSelecionadoConfig[0] == 1){
        boolean cfg_backlight = 1;
        String Tempo_da_tela [] = {"3 seg.", "10 seg.", "1 min.", "Desligada"};
        boolean AlternativaTela [] = {1,0,0,0};
        while(cfg_backlight == 1){
          bt();
          light_on_off();
          menu_selecao("Luz da Tela", 11, Tempo_da_tela, AlternativaTela, 4);
          if(press_bt[1]){
            if(AlternativaTela[0]){
              EEPROM.write(0,3);
              light_on = 1;
              tempo_light = EEPROM.read(0)*1000;
              cfg_backlight = 0;
              light_on_off();
            }
            else if(AlternativaTela[1]){
              EEPROM.write(0,10);
              light_on = 1;
              tempo_light = EEPROM.read(0)*1000;
              cfg_backlight = 0;
              light_on_off();
            }
            else if(AlternativaTela[2]){
              EEPROM.write(0,60);
              light_on = 1;
              tempo_light = EEPROM.read(0)*1000;
              cfg_backlight = 0;
              light_on_off();
            }
            else if(AlternativaTela[3]){
              EEPROM.write(0,0);
              
              tempo_light = EEPROM.read(0)*1000;
              cfg_backlight = 0;
              light_on_off();
            }
            press_bt[1] = 0;
          }
          if(press_bt[0]){
            mostra = 1;
            press_bt[0] = 0;
            cfg_backlight = 0;
          }
        }
      }
      if(itenSelecionadoConfig[1] == 1){
        boolean cfg_som = 1;
        while(cfg_som == 1){
          bt();
          light_on_off();
          mostra = 1;
          menu_selecao("Som da Tecla", 12, Sim_Nao, Alternativa, 2);
          if(press_bt[1]){
            if(Alternativa[0] == 1){
              EEPROM.write(1, 1);
              cfgbuzzer = EEPROM.read(1);
              cfg_som = 0;
            }
            else if(Alternativa[1] == 1){
              EEPROM.write(1, 0);
              cfgbuzzer = EEPROM.read(1);
              cfg_som = 0;
            }
            press_bt[1] = 0;
          }
          if(press_bt[0]){
            mostra = 1;
            press_bt[0] = 0;
            cfg_som = 0;
          }
        }
      }
      if(itenSelecionadoConfig[2] == 1){
        boolean cfg_apaga = 1;
        while(cfg_apaga == 1){
          bt();
          light_on_off();
          mostra = 1;
          menu_selecao("Certeza?", 8, Sim_Nao, Alternativa, 2);
          if(press_bt[1]){
            if(Alternativa[0] == 1){
              display.clearDisplay();
              display.setTextSize(1);
              display.setCursor(18,20);
              display.print("Apagando");
              display.display();
              for(byte e = 0; e<=1; e++) EEPROM.write(e, 1);
              display.clearDisplay();
              display.setTextSize(1);
              display.setCursor(18,20);
              display.print("Apagando!");
              display.display();
              asm volatile ("  jmp 0");
              cfg_apaga = 0;
            }
            else if(Alternativa[1] == 1){
              cfg_apaga = 0;
            }
            press_bt[1] = 0;
          }
          if(press_bt[0]){
            mostra = 1;
            press_bt[0] = 0;
            cfg_apaga = 0;
          }
        }
      }
      if(itenSelecionadoConfig[3] == 1){
        boolean carregando = 1;
        display.clearDisplay();
        display.setContrast(0);
        display.display();
        while(carregando){  
          bt();
          light_on_off();
          if(press_bt[0]){
            mostra = 1;
            press_bt[0] = 0;
            carregando = 0;
            display.setContrast(60);
          }
        }
      }
    }
    menu_selecao("Config.", 7, itensConfig, itenSelecionadoConfig, 4);
    if(press_bt[0]){
      mostra = 1;
      press_bt[0] = 0;
      boot_config = 0;
    }
  }
}
