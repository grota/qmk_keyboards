#include "grota.h"
#include "rgb_stuff.h"
#include "eeprom.h"

#ifdef RGB_MATRIX_ENABLE
extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

bool process_record_user_rgb(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      case CUSTOM_RGB_CYCLE:
        if (record->event.pressed) {
          uint8_t shifted = get_mods() & (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT));
          if(shifted) {
            rgb_matrix_config.mode--;
            if (rgb_matrix_config.mode < 1)
              rgb_matrix_config.mode = RGB_MATRIX_EFFECT_MAX_NEW - 1;
            eeconfig_update_rgb_matrix(rgb_matrix_config.raw);
          }
          else {
            rgb_matrix_config.mode++;
            if (rgb_matrix_config.mode >= RGB_MATRIX_EFFECT_MAX_NEW)
              rgb_matrix_config.mode = 1;
            eeconfig_update_rgb_matrix(rgb_matrix_config.raw);
          }
#ifdef SPLIT_KEYBOARD
          RGB_DIRTY = true;
#endif
        }
        return false;

    }
    return true;
}

void shutdown_user (void) {
    uint16_t timer_start = timer_read();
    rgb_matrix_set_color_all( 0xFF, 0x00, 0x00 );
    while(timer_elapsed(timer_start) < 250) { wait_ms(1); }
}

void suspend_power_down_user(void) {
    rgb_matrix_set_suspend_state(true);
    rgb_matrix_config.enable = false;
}

void suspend_wakeup_init_user(void) {
    rgb_matrix_config.enable = true;
    rgb_matrix_set_suspend_state(false);
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || !rgb_matrix_config.enable) return;

  switch (rgb_matrix_config.mode) {
    case RGB_MATRIX_LAYER_INDICATOR:
      rgb_matrix_layer_indicator_custom();
      break;
  }

}
void rgb_matrix_layer_indicator_custom(void) {
  uint8_t modifiers = get_mods();
  uint8_t one_shot = get_oneshot_mods();
  uint8_t weak_mods = get_weak_mods();
  RGB background1 = hsv_to_rgb( (HSV) { .h = rgb_matrix_config.hue, .s = rgb_matrix_config.sat, .v = (rgb_matrix_config.val >> 2)});
  RGB background2 = hsv_to_rgb( (HSV) { .h = ((rgb_matrix_config.hue + 40) % 0xFF ), .s = rgb_matrix_config.sat, .v = (rgb_matrix_config.val >> 2)});

  RGB rgb1 = hsv_to_rgb( (HSV) { .h = (rgb_matrix_config.hue +  80) % 0xFF, .s = rgb_matrix_config.sat, .v = rgb_matrix_config.val} );
  RGB rgb2 = hsv_to_rgb( (HSV) { .h = (rgb_matrix_config.hue + 120) % 0xFF, .s = rgb_matrix_config.sat, .v = rgb_matrix_config.val} );
  RGB rgb3 = hsv_to_rgb( (HSV) { .h = (rgb_matrix_config.hue + 160) % 0xFF, .s = rgb_matrix_config.sat, .v = rgb_matrix_config.val} );

  switch (biton32(layer_state)) {
    case _BASE:
      (RALT_IS_PRESSED) ?
        rgb_matrix_set_color_all(background2.r, background2.g, background2.b) :
        rgb_matrix_set_color_all(background1.r, background1.g, background1.b);
      rgb_matrix_set_color(18, rgb1.r, rgb1.g, rgb1.b); // .
      rgb_matrix_set_color(10, rgb1.r, rgb1.g, rgb1.b); // ,
      rgb_matrix_set_color(41, rgb1.r, rgb1.g, rgb1.b); // M
      rgb_matrix_set_color(40, rgb2.r, rgb2.g, rgb2.b); // B
      rgb_matrix_set_color(35, rgb3.r, rgb3.g, rgb3.b); // G
      rgb_matrix_set_color(14, rgb2.r, rgb2.g, rgb2.b); // O
      rgb_matrix_set_color(17, rgb3.r, rgb3.g, rgb3.b); // P
      break;

    case _FN_AND_MOUSE:
      rgb_matrix_set_color_all(background2.r, background2.g, background2.b);
      rgb_matrix_set_color( 7, rgb1.r, rgb1.g, rgb1.b); // M_UP
      rgb_matrix_set_color(11, rgb1.r, rgb1.g, rgb1.b); // M_RIGHT
      rgb_matrix_set_color(12, rgb1.r, rgb1.g, rgb1.b); // M_DOWN
      rgb_matrix_set_color(13, rgb1.r, rgb1.g, rgb1.b); // M_LEFT
      rgb_matrix_set_color(9,  rgb2.r, rgb2.g, rgb2.b); // M_WHLUP
      rgb_matrix_set_color(14, rgb2.r, rgb2.g, rgb2.b); // M_WHLDN
      rgb_matrix_set_color(20, rgb3.r, rgb3.g, rgb3.b); // Mouse middle click
      rgb_matrix_set_color(21, rgb3.r, rgb3.g, rgb3.b); // Mouse right click
      rgb_matrix_set_color(22, rgb3.r, rgb3.g, rgb3.b); // Mouse left click
      break;
  }
}
#endif //RGB_MATRIX_ENABLE
