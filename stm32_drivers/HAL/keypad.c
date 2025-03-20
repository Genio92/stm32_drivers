#include "keypad.h"

GPIO_PinConfig_t Key_padRow_pins[4] ; //rows of the keypad
GPIO_PinConfig_t Key_padCol_pins[4]; //columns

char my_keypad[4][4] = {
    {'7', '8', '9', '%'},
    {'4', '5', '6', 'X'},
    {'1', '2', '3', '-'},
    {'A', '0', '=', '+'}
};

void delay_mss(uint32_t time) {
	uint32_t i, j;
	for (i = 0; i < time; i++)
		for (j = 0; j < 255; j++)
			;
}

void Keypad_init() {



	Key_padRow_pins[0].GPIO_PinNumber = R0;
	Key_padRow_pins[0].GPIO_MODE =GPIO_MODE_INPUT_PU;
	Key_padRow_pins[0].GPIO_Output_Speed = GPIO_SPEED_10M;
	Key_padRow_pins[0].PIN_GPIO=KEYPAD_R0_GPIO_PORT;
	MCAL_GPIO_Init(&Key_padRow_pins[0]);

	Key_padRow_pins[1].GPIO_PinNumber = R1;
	Key_padRow_pins[1].GPIO_MODE = GPIO_MODE_INPUT_PU;
	Key_padRow_pins[1].GPIO_Output_Speed = GPIO_SPEED_10M;
	Key_padRow_pins[1].PIN_GPIO=KEYPAD_R1_GPIO_PORT;
	MCAL_GPIO_Init(&Key_padRow_pins[1]);

	Key_padRow_pins[2].GPIO_PinNumber = R2;
	Key_padRow_pins[2].GPIO_MODE = GPIO_MODE_INPUT_PU;
	Key_padRow_pins[2].GPIO_Output_Speed = GPIO_SPEED_10M;
	Key_padRow_pins[2].PIN_GPIO=KEYPAD_R2_GPIO_PORT;
	MCAL_GPIO_Init(&Key_padRow_pins[2]);

	Key_padRow_pins[3].GPIO_PinNumber = R3;
	Key_padRow_pins[3].GPIO_MODE = GPIO_MODE_INPUT_PU;
	Key_padRow_pins[3].GPIO_Output_Speed = GPIO_SPEED_10M;
	Key_padRow_pins[3].PIN_GPIO=KEYPAD_R3_GPIO_PORT;
	MCAL_GPIO_Init(&Key_padRow_pins[3]);
	//         column
	Key_padCol_pins[0].GPIO_PinNumber = C0;
	Key_padCol_pins[0].GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	Key_padCol_pins[0].GPIO_Output_Speed = GPIO_SPEED_10M;
	Key_padCol_pins[0].PIN_GPIO=KEYPAD_C0_GPIO_PORT;
	MCAL_GPIO_Init(&Key_padCol_pins[0]);

	Key_padCol_pins[1].GPIO_PinNumber = C1;
	Key_padCol_pins[1].GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	Key_padCol_pins[1].GPIO_Output_Speed = GPIO_SPEED_10M;
	Key_padCol_pins[1].PIN_GPIO=KEYPAD_C1_GPIO_PORT;
	MCAL_GPIO_Init(&Key_padCol_pins[1]);

	Key_padCol_pins[2].GPIO_PinNumber = C2;
	Key_padCol_pins[2].GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	Key_padCol_pins[2].GPIO_Output_Speed = GPIO_SPEED_10M;
	Key_padCol_pins[2].PIN_GPIO=KEYPAD_C2_GPIO_PORT;
	MCAL_GPIO_Init(&Key_padCol_pins[2]);

	Key_padCol_pins[3].GPIO_PinNumber = C3;
	Key_padCol_pins[3].GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	Key_padCol_pins[3].GPIO_Output_Speed = GPIO_SPEED_10M;
	Key_padCol_pins[3].PIN_GPIO=KEYPAD_C3_GPIO_PORT;
	MCAL_GPIO_Init(&Key_padCol_pins[3]);

	for (int i =0; i<=3;i++){
		MCAL_GPIO_WritePin(&Key_padCol_pins[i], HIGH);

	}

}

char Keypad_getkey() {

	for (int x=0;x<=3;x++){
		MCAL_GPIO_WritePin(&Key_padCol_pins[x], LOW);
		MCAL_GPIO_WritePin(&Key_padCol_pins[(x+1)%4], HIGH);
		MCAL_GPIO_WritePin(&Key_padCol_pins[(x+2)%4], HIGH);
		MCAL_GPIO_WritePin(&Key_padCol_pins[(x+3)%4], HIGH);
		for (int y=0;y<=3;y++){
			if (MCAL_GPIO_ReadPin(&Key_padRow_pins[y])==LOW){
				while(MCAL_GPIO_ReadPin(&Key_padRow_pins[y])==LOW);
				return my_keypad[y][x];

			}

		}

	}
	return '\0';

}
