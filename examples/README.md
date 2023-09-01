プログラムの例です。

Example programs.

Arduino IDEは https://github.com/openwch/arduino_core_ch32 を利用しています。


#### LEDの点滅 (Arduino IDE)

[blink_led](blink_led/blink_led.ino)

ボード上のLEDを1秒おきに点滅させます。

#### PD0,PD1ピンの利用 (Arduino IDE)

[use_pd0_pd1](use_pd0_pd1/use_pd0_pd1.ino)

PD0, PD1ピンをGPIOとして利用します。

#### I2C接続のOLEDディスプレイの駆動 (Arduino IDE)

[i2c_oled/i2c_oled.ino]

I2C接続の128x64モノクロOLEDディスプレイを駆動します。Adafruit社製のライブラリを利用します。

#### 液晶パネルの駆動 (Arduino IDE)

(準備中 / Now preparing)

SPI接続の液晶パネルにパターンを表示します。


#### USBシリアル通信 (Arduino IDE)

(準備中 / Now preparing)

USBシリアルとして振舞います。UART2 (PA2, PA3) をUSBへそのまま流します。
