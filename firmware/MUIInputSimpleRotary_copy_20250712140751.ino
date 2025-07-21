/*

  MUIInputSimpleRotary.ino

  MUI: https://github.com/olikraus/u8g2/wiki/muimanual
  U8g2 Menu with Rotary Encoder (SimpleRotary library).
  
  Universal 8bit Graphics Library (https://github.com/olikraus/u8g2/)

  Copyright (c) 2022, olikraus@gmail.com
  All rights reserved.

  Redistribution and use in source and binary forms, with or without modification, 
  are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright notice, this list 
    of conditions and the following disclaimer.
    
  * Redistributions in binary form must reproduce the above copyright notice, this 
    list of conditions and the following disclaimer in the documentation and/or other 
    materials provided with the distribution.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND 
  CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, 
  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR 
  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT 
  NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF 
  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  

*/

#include <Arduino.h>
#include <U8g2lib.h>
#include <MUIU8g2.h>
#include <SimpleRotary.h>

// SimpleRotary Library
// https://github.com/mprograms/SimpleRotary
// Pin A, Pin B, Button Pin
SimpleRotary rotary(25,26,27);

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* clock=*/ 22, /* data=*/ 21, /* reset=*/ U8X8_PIN_NONE);   // All Boards without Reset of the Display


MUIU8G2 mui;

/*
  global variables which form the communication gateway between the user interface and the rest of the code
*/
char s[13] = "            ";



uint8_t mui_hrule(mui_t *ui, uint8_t msg) {
  if ( msg == MUIF_MSG_DRAW ) {
      u8g2.drawHLine(0, mui_get_y(ui), u8g2.getDisplayWidth());
  }
  return 0;
}

uint8_t show_my_data(mui_t *ui, uint8_t msg) {
  if ( msg == MUIF_MSG_DRAW ) {
    u8g2_uint_t x = mui_get_x(ui);
    u8g2_uint_t y = mui_get_y(ui);
    u8g2.setCursor(x+5, y);
    u8g2.print("Word:");
    // u8g2.setCursor(x+50, y);
    // u8g2.print(num_value);

    // u8g2.setCursor(x+5, y+12);
    // u8g2.print("Bar:");
    // u8g2.setCursor(x+50, y+12);
    // u8g2.print(bar_value);

    // u8g2.setCursor(x+5, y+24);
    // u8g2.print("Animal:");
    // u8g2.setCursor(x+50, y+24);
    // u8g2.print(animal_idx);  
    // u8g2.print("=");  
    // u8g2.print(animals[animal_idx]);  
  }
  return 0;
}

muif_t muif_list[] = {
  MUIF_U8G2_FONT_STYLE(0, u8g2_font_helvR08_tr),        /* regular font */
  MUIF_U8G2_FONT_STYLE(1, u8g2_font_helvB08_tr),        /* bold font */
  MUIF_U8G2_FONT_STYLE(5, u8g2_font_profont12_mf),        //monospaced also try 'u8g2_font_spleen6x12_mf' or 'u8g2_font_t0_12_mf'

  MUIF_RO("HR", mui_hrule),
  MUIF_U8G2_LABEL(),
  MUIF_RO("GP",mui_u8g2_goto_data),  
  MUIF_BUTTON("GC", mui_u8g2_goto_form_w1_pi),
  
  MUIF_VARIABLE("T0",s+0,mui_u8g2_u8_char_wm_mud_pi),
  MUIF_VARIABLE("T1",s+1,mui_u8g2_u8_char_wm_mud_pi),
  MUIF_VARIABLE("T2",s+2,mui_u8g2_u8_char_wm_mud_pi), 
  MUIF_VARIABLE("T3",s+3,mui_u8g2_u8_char_wm_mud_pi),
  MUIF_VARIABLE("T4",s+4,mui_u8g2_u8_char_wm_mud_pi),
  MUIF_VARIABLE("T5",s+5,mui_u8g2_u8_char_wm_mud_pi),
  MUIF_VARIABLE("T6",s+6,mui_u8g2_u8_char_wm_mud_pi), 
  MUIF_VARIABLE("T7",s+7,mui_u8g2_u8_char_wm_mud_pi),
  MUIF_VARIABLE("T8",s+8,mui_u8g2_u8_char_wm_mud_pi),
  MUIF_VARIABLE("T9",s+9,mui_u8g2_u8_char_wm_mud_pi),
  MUIF_VARIABLE("TA",s+10,mui_u8g2_u8_char_wm_mud_pi), 
  MUIF_VARIABLE("TB",s+11,mui_u8g2_u8_char_wm_mud_pi),

  // MUIF_U8G2_U8_MIN_MAX("NV", &num_value, 0, 99, mui_u8g2_u8_min_max_wm_mud_pi),
  // MUIF_U8G2_U8_MIN_MAX_STEP("NB", &bar_value, 0, 16, 1, MUI_MMS_2X_BAR, mui_u8g2_u8_bar_wm_mud_pf),
  // MUIF_U8G2_U16_LIST("NA", &animal_idx, NULL, animal_name_list_get_str, animal_name_list_get_cnt, mui_u8g2_u16_list_line_wa_mud_pi),

  /* register custom function to show the data */
  MUIF_RO("SH", show_my_data), 

  /* a button for the menu... */
  MUIF_BUTTON("GO", mui_u8g2_btn_goto_wm_fi)  
};


fds_t fds_data[] = 

MUI_FORM(1)
MUI_STYLE(1)
MUI_LABEL(5, 8, "SimpleRotary Lib")
MUI_STYLE(0)
MUI_XY("HR", 0,11)
MUI_DATA("GP", 
    MUI_10 "Enter Data|"
    MUI_12 "Show Data")
MUI_XYA("GC", 5, 24, 0) 
MUI_XYA("GC", 5, 36, 1) 

MUI_FORM(10)
// MUI_STYLE(1)
// MUI_LABEL(5, 8, "Enter Data")
// MUI_XY("HR", 0,11)
// MUI_STYLE(0)
// MUI_LABEL(5,23, "Word:")
// MUI_XYAT("GO", 114, 60, 1, " Ok ") 

// MUI_FORM(61)
MUI_STYLE(0)
MUI_LABEL(5,20, "Text:")
MUI_STYLE(5)                        /* use a monospaced font */
MUI_XY("T0",20, 40)
MUI_XY("T1",28, 40)
MUI_XY("T2",36, 40)
MUI_XY("T3",44, 40)
MUI_XY("T4",52, 40)
MUI_XY("T5",60, 40)
MUI_XY("T6",68, 40)
MUI_XY("T7",76, 40)
MUI_XY("T8",84, 40)
MUI_XY("T9",92, 40)
MUI_XY("TA",100, 40)
MUI_XY("TB",108, 40)
MUI_STYLE(0)
MUI_XYAT("GO", 114, 60, 1, " Ok ") 

MUI_FORM(12)
MUI_STYLE(1)
MUI_LABEL(5, 8, "Show Data")
MUI_XY("HR", 0,11)
MUI_STYLE(0)
MUI_XY("SH", 0, 23)
MUI_XYAT("GO", 114, 60, 1, " Ok ") 

;


void setup(void) {
  u8g2.begin();
  mui.begin(u8g2, fds_data, muif_list, sizeof(muif_list)/sizeof(muif_t));
  mui.gotoForm(/* form_id= */ 1, /* initial_cursor_position= */ 0);
}

uint8_t is_redraw = 1;
uint8_t rotary_event = 0; // 0 = not turning, 1 = CW, 2 = CCW
uint8_t push_event = 0; // 0 = not pushed, 1 = pushed

void detect_events(void) {
  uint8_t tmp;
  
  // 0 = not pushed, 1 = pushed  
  tmp = rotary.push();
  if ( tmp != 0 )         // only assign the push event, never clear the event here
    push_event = tmp;
    
  // 0 = not turning, 1 = CW, 2 = CCW
  tmp = rotary.rotate();
  if ( tmp != 0 )       // only assign the rotation event, never clear the event here
    rotary_event = tmp;    
}

void handle_events(void) {
  // 0 = not pushed, 1 = pushed  
  if ( push_event == 1 ) {
      mui.sendSelect();
      is_redraw = 1;
      push_event = 0;
  }
  
  // 0 = not turning, 1 = CW, 2 = CCW
  if ( rotary_event == 1 ) {
    mui.nextField();
    is_redraw = 1;
    rotary_event = 0;
  }
  
  if ( rotary_event == 2 ) {
    mui.prevField();
    is_redraw = 1;
    rotary_event = 0;
  }    
}


void loop(void) {

  /* check whether the menu is active */
  if ( mui.isFormActive() ) {

    /* update the display content, if the redraw flag is set */
    if ( is_redraw ) {
      u8g2.firstPage();
      do {
          detect_events();
          mui.draw();
          detect_events();
      } while( u8g2.nextPage() );
      is_redraw = 0;                    /* clear the redraw flag */
    }

    detect_events();
    handle_events();
      
  } else {
      /* the menu should never become inactive, but if so, then restart the menu system */
      mui.gotoForm(/* form_id= */ 1, /* initial_cursor_position= */ 0);
  }
}


