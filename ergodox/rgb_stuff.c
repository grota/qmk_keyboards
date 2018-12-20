#include "grota.h"

#ifdef RGB_MATRIX_ENABLE
extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

bool process_record_user_rgb(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      case RGB_SLD:
        if (record->event.pressed) {
          rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
        }
        return false;

      case KC_RGB_LYR_IND:
        if (record->event.pressed) {
          userspace_config.rgb_layer_change ^= 1;
          eeconfig_update_user(userspace_config.raw);
          if (userspace_config.rgb_layer_change) {
            layer_state_set(layer_state); // This is needed to immediately set the layer color (looks better)
          }
        }
        return false;

      //This disables layer indication, as it's assumed that if you're changing this ... you want that disabled
      case RGB_MODE_FORWARD:
      case RGB_MODE_REVERSE:
      case RGB_MODE_PLAIN ... RGB_MODE_GRADIENT:
        if (record->event.pressed) {
          if (userspace_config.rgb_layer_change) {
            userspace_config.rgb_layer_change = false;
            eeconfig_update_user(userspace_config.raw);
          }
        }
        return true;
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
  if (g_suspend_state || !rgb_matrix_config.enable || !userspace_config.rgb_layer_change) return;

  switch (biton32(layer_state)) {
    case _BASE:
      rgb_matrix_set_color_all(0xFF, 0x80, 0x00);
      rgb_matrix_set_color(32, 0x00, 0xFF, 0x00);
      rgb_matrix_set_color(31, 0x00, 0xFF, 0xFF);
      rgb_matrix_set_color(30, 0xFF, 0x00, 0x00);
      rgb_matrix_set_color(29, 0xFF, 0x80, 0x00);
      rgb_matrix_set_color(37, 0x00, 0xFF, 0xFF);
      rgb_matrix_set_color(36, 0x00, 0xFF, 0xFF);
      rgb_matrix_set_color(35, 0x00, 0xFF, 0xFF);
      rgb_matrix_set_color(34, 0x7A, 0x00, 0xFF);
      break;

    case _FN_AND_MOUSE:
      rgb_matrix_set_color_all(0x76, 0xEE, 0xC6);
      break;
  }
}
#endif //RGB_MATRIX_ENABLE
