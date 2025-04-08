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

Elegoo_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

//debug main 
void draw_debugMain(int page);      //multiple pages tracked by int variable
void setUserCursor(char Direction); //always from selection knob
                                      //left(L), right(R), or push(P)
int UserCursor_pos;   //global variable tracks y1 variable for drawing shapes

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void draw_debugMain(int page){
  //print names of each effect
  tft.fillScreen(BLACK)
  tft.setTextColor(WHITE);
  tft.setTextSize(2);     //edit needed
  tft.setCursor(0,0);

  switch(page)
  case 1:         //page 1
  tft.println("Distortion");
  //continue using tft.println for remaining effects
  case 2:         //page 2
}

void setUserCursor(char Direction){
  //if statements that check the current UserCursor_pos value and decides
  //whether to increment or decrement
  //if Direction is R, then UserCursor_pos++
    //overflow to next page
  //if Direction is L, then UserCursor_pos--
    //if underflow then previous page
  tft.drawRect(0,UserCursor_pos,320,20);  //width of screen is 320, height is 240

  //set color (red maybe?)


}
