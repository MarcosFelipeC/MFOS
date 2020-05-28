// +++ Parâmetros de Menu +++
//menu_selecao(Nome, Caracteres, Itens, Selecionado, Tamanho)

void menu_selecao(String Nome, byte Caracteres, String Itens[], boolean Selecionado[], byte Tamanho){
  display.setTextSize(1);
  byte n, pagina_atual, paginas = Tamanho/4;
  if (Tamanho%4){
    paginas ++;
  }
  for(n = 0; n <= (Tamanho-1); n++){
    if (Selecionado[n]==1){
      if ((n+1)%4){
        pagina_atual = (n+1)/4;
        pagina_atual++;
      }
      else pagina_atual = (n+1)/4;
    }
  }
  Tamanho = Tamanho - 1;
  if (mostra){
    if (!pagina_atual) pagina_atual = 1; 
    display.clearDisplay();
    display.fillRect(0,0,84,8,BLACK);
    int x = (84-((Caracteres*5)+(Caracteres-1)))/2;
    display.setCursor(x,0);
    display.setTextColor(WHITE);
    display.print(Nome);
    display.setCursor(66,8);
    display.setTextColor(BLACK);
    display.print(String(pagina_atual) + "/" + String(paginas));
    display.setCursor(0,16);
    for(byte k = 0+(4*(pagina_atual-1)); k <= Tamanho; k++){
      if(Selecionado[k] == 1) display.setTextColor(WHITE, BLACK);
      else display.setTextColor(BLACK, WHITE);
      display.println(Itens[k]);
      }
    display.display();
    selecao = 1;
    mostra = 0;    
  }  
  if(press_bt[5] || press_bt[4]){  //volta
    for(n = 1; n <= Tamanho; n++){
      if(Selecionado[n] == 1 && selecao == 1){
        if (n > 0) Selecionado[n-1] = 1;
        Selecionado[n] = 0;
        mostra = 1;
        press_bt[5] = 0;
        press_bt[4] = 0;
        selecao = 0;
      }
    }
    mostra = 1;
    press_bt[5] = 0;
    press_bt[4] = 0;
    //selecao = 0;
  }
  
  if(press_bt[3] || press_bt[2]){  //avança
    for(n = 0; n <= (Tamanho -1); n++){
      if(Selecionado[n] == 1 && selecao == 1){
        Selecionado[n+1] = 1;
        Selecionado[n] = 0;
        mostra = 1;
        press_bt[3] = 0;
        press_bt[2] = 0;
        selecao = 0;
      }
    }
    mostra = 1;
    press_bt[3] = 0;
    press_bt[2] = 0;
    //selecao = 0;
  }
}
