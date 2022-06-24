# 22Expo_Smartlock
2022 Edimax Expo - Smartlock

## PC UART

PC Host 透過 UART 與 Arduino UNO 板通訊，UNO 依據 Host 指令控制對應的 LED 燈開關。

UART baud rate 固定為 9600。

### 控制程式

Windows UART 控制程式是參考 [15.6. Example serial code for Windows in C](https://www.pololu.com/docs/0J73/15.6) 這一篇改的。

在 Windows 下用 MINGW64 編譯：
> `gcc -o uart_ledctrl uart_led_ctrl.c`

### 使用方式
```
uart_ledctrl.exe comport ledcmd

comport : COM port number, e.g., comport=12 for COM12
ledcmd  : One byte hex value (0xXY).
          where X is the LED number (1~8) and Y controls ON/OFF (1:ON, 0:OFF)
          ** 0x99 will turn all LEDs off.

Example
uart_ledctrl.exe  13  0x20		<-- Use COM13 to set LED#2 OFF
uart_ledctrl.exe  13  0x21		<-- Use COM13 to set LED#2 ON
uart_ledctrl.exe  13  0x99		<-- Use COM13 to turn all LEDs OFF
```

## Arduino UNO LED Control

