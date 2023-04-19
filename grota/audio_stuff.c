#include "audio_stuff.h"
#include "grota/config.h"
#include "grota/grota.h"
#include "qmk_firmware/quantum/audio/audio.h"
#include "qmk_firmware/quantum/audio/musical_notes.h"

#define STARTUP_SONG SONG(WORKMAN_SOUND)
static float shift_pressed_song[][2] = SONG(ED_NOTE(_E4), ED_NOTE(_F4));
static float ctrl_pressed_song[][2] = SONG(ED_NOTE(_C4), ED_NOTE(_D4));
static float lalt_pressed_song[][2] = SONG(ED_NOTE(_A3));
static float gui_pressed_song[][2] = SONG(ED_NOTE(_G3));
static float ralt_pressed_song[][2] = SONG(E__NOTE(_G3));

#define SONG_LAYER_BASE ED_NOTE(_A3), ED_NOTE(_B3)
#define SONG_LAYER_MOUSE ED_NOTE(_C4), ED_NOTE(_D4)
#define SONG_LAYER_SYM ED_NOTE(_F4), ED_NOTE(_G4)
#define SONG_LAYER_NUMBERS ED_NOTE(_A4), ED_NOTE(_B4)
#define SONG_LAYER_MEDIA ED_NOTE(_C5), ED_NOTE(_D5)
#define GROTA_X(LAYER_NAME, LAYER_ID, DESC)                                    \
  float layer_song_##LAYER_ID[2][2] = SONG(SONG##LAYER_ID);
REPEAT_GROTA_X_FOR_LAYERS
#undef GROTA_X

#ifdef SPACE_CADET_ENABLE
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
#endif

void matrix_scan_play_audio_when_mods_are_hold(void) {
#ifdef SPACE_CADET_ENABLE
  // Bail out if a space cadet key has been pressed but not enough time has
  // passed to trigger a hold.
  if (tapping_term_for_space_cadet_key != 0 &&
      timer_elapsed(timer_sc) < tapping_term_for_space_cadet_key) {
    return;
  }
#endif

  uint8_t modifiers = get_mods();
  uint8_t weak_mods = get_weak_mods();
#ifndef NO_ACTION_ONESHOT
  uint8_t one_shot = get_oneshot_mods();
#endif

  static bool detected_shift_pressed = false;
  if (!detected_shift_pressed && (SHIFT_IS_PRESSED)) {
    detected_shift_pressed = true;
    PLAY_SONG(shift_pressed_song);
  }
  if (detected_shift_pressed && !(SHIFT_IS_PRESSED)) {
    detected_shift_pressed = false;
  }

  static bool detected_ctrl_pressed = false;
  if (!detected_ctrl_pressed && (CTRL_IS_PRESSED)) {
    detected_ctrl_pressed = true;
    PLAY_SONG(ctrl_pressed_song);
  }
  if (detected_ctrl_pressed && !(CTRL_IS_PRESSED)) {
    detected_ctrl_pressed = false;
  }

  static bool detected_lalt_pressed = false;
  if (!detected_lalt_pressed && (LALT_IS_PRESSED)) {
    detected_lalt_pressed = true;
    PLAY_SONG(lalt_pressed_song);
  }
  if (detected_lalt_pressed && !(LALT_IS_PRESSED)) {
    detected_lalt_pressed = false;
  }

  static bool detected_gui_pressed = false;
  if (!detected_gui_pressed && (GUI_IS_PRESSED)) {
    detected_gui_pressed = true;
    PLAY_SONG(gui_pressed_song);
  }
  if (detected_gui_pressed && !(GUI_IS_PRESSED)) {
    detected_gui_pressed = false;
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
#define GROTA_X(LAYER_NAME, LAYER_ID, DESC)                                    \
  case LAYER_ID:                                                               \
    PLAY_SONG(layer_song_##LAYER_ID);                                          \
    break;
    REPEAT_GROTA_X_FOR_LAYERS
#undef GROTA_X

  default:
    break;
  }
}
