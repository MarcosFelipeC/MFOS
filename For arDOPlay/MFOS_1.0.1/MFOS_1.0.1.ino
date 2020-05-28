/*
 * MFOS 1.0.1 by Marcos Felipe 
 * e-mail: felipe-marcos10@hotmail.com
 * 
 * OBS: 
 * 1. O arquivo menu_modelo contém a função que desenha o menu_selecao();
 * 2. O arquivo onboard contém as funções light_on_off (que controla a luz de fundo do display) e a bt (que controla o estado dos botões);
 * 3. Todos os outros arquivos são referentes à softwares executáveis pelo dispositivo.
 * 
 * Funções úteis:
 * 
 * menu_seleção(String Nome, byte Caracteres, String Itens[], boolean Selecionado[], byte Tamanho):
 *  É uma função usada para desenhar telas com um menu de seleção 
 *  Sintaxe:
 *    menu_selecao(String Nome, byte número_de_caracteres_da_String_Nome, String Itens[], boolean Selecionado[], byte quantidade_de_elementos_da_String_Itens)
 * 
 * bt():
 *  Função usada para ler modificações nos botões do teclado do dispositivo;
 *  Também controla o feedback sonoro ao pressionar das teclas;
 *  Modifica a variável booleana press_bt[], inserindo 1 na posição referente ao botão pressionado;
 *    //a, start, right, down, left, up.
 *    ex: boolean press_bt[] = {1,0,0,0,0,0}; - botão "a" foi pressionado
 * 
 * light_on_off():
 *  Função que controla a luz de fundo da tela;
 *  Depende da variável tempo_light, onde o valor é atribuido a partir do valor escrito na EEPROM.
 *  
 * 
 */


// +++ Bibliotecas +++
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <SoftwareSerial.h>
#include <EEPROM.h>
//#include <SPI.h>
//#include <SdFat.h>

/* +++ Pinos do display: +++
 * pino 13 - Serial clock out (SCLK)
 * pino 11 - Serial data out (DIN)
 * pino 12 - Data/Command select (D/C)
 * pino 10 - LCD chip select (CS)
 * pino A1 - LCD reset (RST)
*/

Adafruit_PCD8544 display = Adafruit_PCD8544(13, 11, 12, 10, A1);

// +++ KeyMaping +++
#define   bt_up     8
#define   bt_down   6
#define   bt_left   7
#define   bt_right  5
#define   bt_start  4
#define   bt_a      3

#define   spk       9 //speaker
#define   light     A0 //luz de fundo

// ----------- Variáveis Globais ----------------
boolean cfgbuzzer, light_on = 1;
boolean mostra = 1, selecao = 1; //Parâmetros do Menu

// +++ Tempo da luz de Fundo +++
int tempo_light = 0;

//Botões:
//a, start, right, down, left, up.
boolean press_bt[] = {0,0,0,0,0,0};
boolean ue_bt[] = {1,1,1,1,1,1};
unsigned long utlight = millis();

void setup() {
  //  +++ Mapeamento dos Botões, spk e light +++
  byte i;
  //botão
  for (i=2; i<= 8; i++) pinMode (i, INPUT_PULLUP);
  //spk e light
  for (i=14; i<=15; i++) pinMode  (i, OUTPUT);
  //  -----------------------------------------------
  boot();//Splashscreen e leitura da EEPROM
}

void loop() {
  bt();//Função que lê e escreve no arrey press_bt
  light_on_off();//Acende ou apaga a luz de fundo
  menu_principal();//Vai pro menu principal
}
