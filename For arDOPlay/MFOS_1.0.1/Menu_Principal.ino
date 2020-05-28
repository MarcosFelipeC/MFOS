// +++ Programação do Menu Principal +++
String itensMenu[] = {"Programas","Jogos","Config.","Info."};
boolean itenSelecionado[] = {1,0,0,0};

void menu_principal(){
  menu_selecao("Menu Principal", 14, itensMenu, itenSelecionado, 4);
  if(press_bt[1]){ //botão select
    press_bt[1] = 0;
    mostra = 1;
    if(itenSelecionado[0]){
      programas();
    }
    else if(itenSelecionado[1]){
      jogos();
    }
    else if(itenSelecionado[2]){
      configuracoes();
    }
    else if(itenSelecionado[3]){
      boolean info = 1;
      while (info){
        bt();
        light_on_off();
        if (mostra){
          display.clearDisplay();
          display.fillRect(0,0,84,8,BLACK);
          display.setCursor(9,0);
          display.setTextColor(WHITE);
          display.print("Informacoes");
          display.setCursor(0,9);
          display.setTextColor(BLACK);
          display.println("Desenvolvido  por: ");
          display.setCursor(0,27);
          display.println("Marcos Felipe");
          display.println("felipe-marcos10@hotmail.com");
          display.display();
          mostra = 0;
        }
        if(press_bt[0]){
          mostra = 1;
          info = 0;
          press_bt[0] = 0;
        }
      }
    }
  }

  if(press_bt[0]) press_bt[0] = 0;
  
}


void programas(){
  boolean boot_programas = 1;
  String itensProgramas[] = {"Serial Monitor","Ultrassonico", "SD", "Osciloscopio"};
  boolean programaSelecionado[] = {1,0,0,0};
  while(boot_programas){
    bt();
    light_on_off();
    menu_selecao("Programas", 9, itensProgramas, programaSelecionado, 4);
    if(press_bt[1]){
      mostra = 1;
      press_bt[1] = 0;
      if(programaSelecionado[0]) serial_monitor();
      if(programaSelecionado[1]) ulstrassonico();
      if(programaSelecionado[2]) SD_Card();
      if(programaSelecionado[3]) osciloscope();
    }
    if(press_bt[0]){
      mostra = 1;
      boot_programas = 0;
      press_bt[0]=0;
    }
  }
}

void jogos(){
  boolean boot_jogos = 1;
  String itensJogos[] = {"Snake"};
  boolean jogoSelecionado[] = {1};
  while(boot_jogos){
    bt();
    light_on_off();
    menu_selecao("Jogos", 5, itensJogos, jogoSelecionado, 1);
    if(press_bt[1]){
      mostra = 1;
      press_bt[1] = 0;
      if(jogoSelecionado[0]) snake();
    }
    if(press_bt[0]){
      mostra = 1;
      boot_jogos = 0;
      press_bt[0]=0;
    }
  }
}
