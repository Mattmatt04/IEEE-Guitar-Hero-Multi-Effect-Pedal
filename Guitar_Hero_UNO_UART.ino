#include <Elegoo_GFX.h>    // Core graphics library
#include <Elegoo_TFTLCD.h> // Hardware-specific library

#define LCD_CS A3 // Chip Select goes to Analog 3
#define LCD_CD A2 // Command/Data goes to Analog 2
#define LCD_WR A1 // LCD Write goes to Analog 1
#define LCD_RD A0 // LCD Read goes to Analog 0

#define LCD_RESET A4 // Can alternately just connect to Arduino's reset pin

#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

//Custom Color Definitions
#define ORANGE 0xFA32

//Serial Communication Input Buffer
String UserInput;

Elegoo_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

void setup(void) {

Serial1.begin(9600);

tft.reset();
uint16_t identifier = 0x9341;
tft.begin(identifier);

tft.fillScreen(BLACK);
tft.setCursor(0,0);

//TFT is 240x320 pixels (Width corresponds to short side by default)
}

void drawMainMenu();
void drawUserSelect();

void loop(void) {
  if (Serial1.available()) {
    if (Serial1.find('/')) {
        UserInput.concat(Serial1.readStringUntil(';'));
    }
  }
  
}


void decodeInput() {
  //Encoder input should be sent as a two character code '1R', '2L'...
  if (UserInput.length()) {
    switch (UserInput[0]) {
      case '1': //Rotary Encoder 1
        //Tell UNO what encoder was used
        break;
      case '2': //Rotary Encoder 2
        //Tell UNO what encoder was used
        break;
      case '3': //Rotary Encoder 3
        //Tell UNO what encoder was used
        break;
    }

    switch (UserInput[1]) {
      case 'L': //Turned Left

        break;
      case 'R': //Turned Right

        break;
      case 'P': //Pushed Button

        break;
      default:  //No Input/Error
        break;
    }
  }
}

void drawMainMenu() {

}

void drawCursor() {

}