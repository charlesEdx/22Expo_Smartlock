
#define LED_ON_LEVEL		HIGH
#define LED_OFF_LEVEL		LOW

#define LED_1				2
#define LED_2				3
#define LED_3				4
#define LED_4				5
#define LED_5				6
#define LED_6				7
#define LED_7				8
#define LED_8				9


void setup() {
	Serial.begin(9600);
	pinMode(LED_BUILTIN, OUTPUT);
	for (int led=LED_1; led < LED_8+1; led++) {
		pinMode(led, OUTPUT);
		digitalWrite(led, LED_ON_LEVEL);
		delay(1000);
		digitalWrite(led, LED_OFF_LEVEL);
	}
}


void flashLed(int msCycle) {
	digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
	delay(msCycle/2);                       // wait for a second
	digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
	delay(msCycle/2);                       //
}


void loop() {
	int led_cycle;
	if (Serial.available() > 0) {  // 檢查是否有資料可供讀取
		int data = Serial.read();  // 讀取進來的 byte
		Serial.print("data= "); Serial.println(data, HEX);
		switch (data) {            // 根據收到的字元決定要打開哪顆 LED
		case 0x10:	// LED#1 Off
			digitalWrite(LED_1, LED_OFF_LEVEL);
			Serial.println("LED-1 OFF");
			break;
		case 0x11:	// LED#1 On
			digitalWrite(LED_1, LED_ON_LEVEL);
			Serial.println("LED-1 ON");
			break;
		case 0x20:	// LED#2 Off
			digitalWrite(LED_2, LED_OFF_LEVEL);
			Serial.println("LED-2 OFF");
			break;
		case 0x21:	// LED#2 On
			digitalWrite(LED_2, LED_ON_LEVEL);
			Serial.println("LED-2 ON");
			break;
		case 0x30:	// LED#3 Off
			digitalWrite(LED_3, LED_OFF_LEVEL);
			Serial.println("LED-3 OFF");
			break;
		case 0x31:	// LED#3 On
			digitalWrite(LED_3, LED_ON_LEVEL);
			Serial.println("LED-3 ON");
			break;
		case 0x40:	// LED#4 Off
			digitalWrite(LED_4, LED_OFF_LEVEL);
			Serial.println("LED-4 OFF");
			break;
		case 0x41:	// LED#4 On
			digitalWrite(LED_4, LED_ON_LEVEL);
			Serial.println("LED-4 ON");
			break;
		case 0x50:	// LED#5 Off
			digitalWrite(LED_5, LED_OFF_LEVEL);
			Serial.println("LED-5 OFF");
			break;
		case 0x51:	// LED#5 On
			digitalWrite(LED_5, LED_ON_LEVEL);
			Serial.println("LED-5 ON");
			break;
		case 0x60:	// LED#6 Off
			digitalWrite(LED_6, LED_OFF_LEVEL);
			Serial.println("LED-6 OFF");
			break;
		case 0x61:	// LED#6 On
			digitalWrite(LED_6, LED_ON_LEVEL);
			Serial.println("LED-6 ON");
			break;
		case 0x70:	// LED#7 Off
			digitalWrite(LED_7, LED_OFF_LEVEL);
			Serial.println("LED-7 OFF");
			break;
		case 0x71:	// LED#7 On
			digitalWrite(LED_7, LED_ON_LEVEL);
			Serial.println("LED-7 ON");
			break;
		case 0x80:	// LED#8 Off
			digitalWrite(LED_8, LED_OFF_LEVEL);
			Serial.println("LED-8 OFF");
			break;
		case 0x81:	// LED#8 On
			digitalWrite(LED_8, LED_ON_LEVEL);
			Serial.println("LED-8 ON");
			break;
		case 0x99:	// LED#8 On
			Serial.println("LED-ALL OFF");
			for (int led=LED_1; led < LED_8+1; led++) {
				digitalWrite(led, LED_OFF_LEVEL);
			}
			break;
		default:
			break;
		}
	}

	// flashLed(led_cycle);
	flashLed(100);
}
