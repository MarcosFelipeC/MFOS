byte tempo = 10;
int grafico1[]={0,0,0,0};
int x_g = 0;

void osciloscope(){
  pinMode (A2, INPUT);
  boolean boot_osc = 1;
  String ondas[] = {"Quadrada","Flutuante"};
  boolean ondasSelecionado[] = {1,0};
  display.clearDisplay();
  while (boot_osc){
    menu_selecao("Osciloscopio", 12, ondas, ondasSelecionado, 2);
    bt();
    light_on_off();
    if (press_bt[1]){
      if (ondasSelecionado[0])graph_osc_sqr();
      else if (ondasSelecionado[1])graph_osc(); 
    }
    else if(press_bt[0]){
      mostra = 1;
      boot_osc = 0;
      press_bt[0]=0;
    }
  }
}

void graph_osc(){
  boolean g_os = 1;
  display.clearDisplay();
  while (g_os){
    //gerar_grafico(arrey de coordenadas, posição x0, posição y0, posição x1, posição y1, valor mínimo do gráfico, valor mmáximo do gráfico, input de dados)
    gerar_grafico(grafico1,0,7,83,47,7,20,map(analogRead(A2), 0, 1023, 7, 47));
    x_g ++;

    light_on_off();
    bt();
    light_on_off();
    if(press_bt[0]){
      mostra = 1;
      g_os = 0;
      press_bt[0]=0;
    }
    
  }
}

void graph_osc_sqr(){
  boolean g_os = 1;
  display.clearDisplay();
  while (g_os){
    //gerar_grafico(arrey de coordenadas, posição x0, posição y0, posição x1, posição y1, valor mínimo do gráfico, valor mmáximo do gráfico, input de dados)
    gerar_grafico(grafico1,0,7,83,47,0,1,digitalRead(A2));
    x_g ++;

    bt();
    light_on_off();
    if(press_bt[0]){
      mostra = 1;
      g_os = 0;
      press_bt[0]=0;
    }
    
  }
}

void gerar_grafico(int coordenadas[], int posx0, int posy0, int posx1, int posy1, int valmin, int valmax, int datain){
  
  display.fillRect(70, 0, 84, 7, WHITE);
  display.setCursor(70,0);
  display.setTextColor(BLACK);
  display.setTextSize(1);
  display.print(datain);
  
  if (coordenadas[0] == 0) coordenadas[0] = posx0; 
  if (coordenadas[1] == 0) coordenadas[1] = posy0;
  if (coordenadas[2] == 0) coordenadas[2] = posx0;
  
  if (coordenadas[2] >= posx1){
    coordenadas[0] = posx0;
    coordenadas[2] = posx0;
  }
  
  cursor_deleta(coordenadas[2], posy0, posy1,3);
  
  coordenadas[3] = map(datain, valmin, valmax, posy1, posy0);
  
  coordenadas[2]++;

  eixo_y(posx0,posy0,posy1,valmin,valmax);
  
  display.drawLine(coordenadas[0], coordenadas[1], coordenadas[2], coordenadas[3], 1);
  
  coordenadas[0] = coordenadas[2];
  coordenadas[1] = coordenadas[3];
  timer(posx1-posx0);
  display.display();
}

void timer(int fatorx){
  
  delay(tempo*1000/fatorx);
}

void cursor_deleta(int x_g, int y0, int y1, byte espessura){
  for (byte i = 1; i <= espessura; i++) display.drawLine (x_g+i, y0, x_g+i, y1+4 ,WHITE);
}

void eixo_y(int x0, int y0, int y1, int valmin, int valmax){
  display.drawLine(x0, y0, x0, y1, 1);
}
