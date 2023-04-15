#include "audio_stuff.h"

static float shift_pressed_song[][2] = SONG(NUM_LOCK_ON_SOUND);
static float ralt_pressed_song[][2] = SONG(AG_NORM_SOUND);
static float layer0_song[][2] = SONG(GOODBYE_SOUND);
static float layer1_song[][2] = SONG(STARTUP_SOUND);

static uint16_t timer_sc = 0;
static uint16_t tapping_term_for_space_cadet_key = 0;
bool process_record_prepare_space_cadet_var(uint16_t keycode,
                                            keyrecord_t *record) {
  switch (keycode) {
  case ALL_SPACE_CADET_KEYS:
    if (record->event.pressed) {
      timer_sc = timer_read();
      tapping_term_for_space_cadet_key = GET_TAPPING_TERM(keycode, record);
    } else {
      tapping_term_for_space_cadet_key = 0;
    }
  }
  return true;
}

void matrix_scan_play_audio_when_mods_are_hold(void) {
  // Bail out if a space cadet key has been pressed but not enough time has
  // passed to trigger a hold.
  if (tapping_term_for_space_cadet_key != 0 &&
      timer_elapsed(timer_sc) < tapping_term_for_space_cadet_key) {
    return;
  }

  uint8_t modifiers = get_mods();
  uint8_t one_shot = get_oneshot_mods();
  uint8_t weak_mods = get_weak_mods();

  static bool detected_shift_pressed = false;
  if (!detected_shift_pressed && (SHIFT_IS_PRESSED)) {
    detected_shift_pressed = true;
    PLAY_SONG(shift_pressed_song);
  }
  if (detected_shift_pressed && !(SHIFT_IS_PRESSED)) {
    detected_shift_pressed = false;
  }

  static bool detected_ralt_pressed = false;
  if (!detected_ralt_pressed && (RALT_IS_PRESSED)) {
    detected_ralt_pressed = true;
    PLAY_SONG(ralt_pressed_song);
  }
  if (detected_ralt_pressed && !(RALT_IS_PRESSED)) {
    detected_ralt_pressed = false;
  }
}

void layer_state_set_play_audio_based_on_layer(layer_state_t state) {
  uint8_t layer = biton32(state);
  uprintf("layer_state_set_play_audio_based_on_layer %d\n", layer);
  switch (layer) {
  case _BASE:
    PLAY_SONG(layer0_song);
    break;

  case _LAYER_MOUSE:
    PLAY_SONG(layer1_song);
    break;

  default:
    break;
  }
}
