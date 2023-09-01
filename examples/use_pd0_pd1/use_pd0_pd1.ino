// Use as Public domain
// Original author: Mitsumine Suzu 2023

// HIGHで点灯するように、PD0, PD1にそれぞれLEDを接続してください。

/** PD0, PD1 ピンについて

PD0, PD1は外部発振に利用されていて、デフォルトではGPIOとして利用できません。
コードで初期化する必要があります。

また現在、ボード定義でのピン数の宣言の問題で、PD**のピンが取り扱えません。

2つの実装例を紹介します。
*/


// WCH社のライブラリ関数を利用する例
#define USE_SPL

// ボード定義を書き換えて、ArduinoのpinMode(), digitalWrite()を利用する例
// #define MODIFY_BOARD_DEFINITION


#ifdef USE_SPL

void setup() {

  pinMode(PA5, OUTPUT);

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
  GPIO_PinRemapConfig(GPIO_Remap_PD01, ENABLE);

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
  GPIO_InitTypeDef gpio_init_st;
  gpio_init_st.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
  gpio_init_st.GPIO_Mode = GPIO_Mode_Out_PP;
  gpio_init_st.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOD, &gpio_init_st);
}

void loop() {
  digitalWrite(PA5, HIGH);
  // PD0ピンをHIGHにします
  GPIO_WriteBit(GPIOD, GPIO_Pin_0, Bit_SET);
  // PD1ピンをLOWにします
  GPIO_WriteBit(GPIOD, GPIO_Pin_1, Bit_RESET);
  delay(100);

  digitalWrite(PA5, LOW);
  GPIO_WriteBit(GPIOD, GPIO_Pin_0, Bit_RESET);
  GPIO_WriteBit(GPIOD, GPIO_Pin_1, Bit_SET);
  delay(100);
}

#endif

#ifdef MODIFY_BOARD_DEFINITION

// ボードの定義ファイル "WCH/hardware/ch32v/1.0.3/variants/CH32V20x/CH32V203G8/variant_CH32V203G8.h"
// の83行目を編集して、
// NUM_DIGITAL_PINSを37に設定してください
#if NUM_DIGITAL_PINS == 37
#else
#error NUM_DIGITAL_PINS must be 37
#endif

void setup() {
  // PD0, PD1をGPIOとして利用するよう、機能を切り替えます  
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
  GPIO_PinRemapConfig(GPIO_Remap_PD01, ENABLE);

  pinMode(PA5, OUTPUT);
  pinMode(PD0, OUTPUT);
  pinMode(PD1, OUTPUT);
}

void loop() {
  digitalWrite(PA5, HIGH);
  digitalWrite(PD0, HIGH);
  digitalWrite(PD1, LOW);
  delay(500);
  
  digitalWrite(PA5, LOW);
  digitalWrite(PD0, LOW);
  digitalWrite(PD1, HIGH);
  delay(500);
  
}
#endif
