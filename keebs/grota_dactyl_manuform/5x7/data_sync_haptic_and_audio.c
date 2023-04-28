
#include "data_sync_haptic_and_audio.h"

// not sure if the calls to eeconfig_update_audio/eeconfig_update_haptic are
// necessary, probably not... I'm currently debugging an hardware issue.
void haptic_and_audio_slave_handler(uint8_t in_buflen, const void *in_data,
                                    uint8_t out_buflen, void *out_data) {
  const master_to_slave_t *m2s = (const master_to_slave_t *)in_data;
  haptic_config.raw = m2s->hapticraw;
  audio_config.raw = m2s->audioraw;
#if 0
  if (haptic_config.raw != m2s->hapticraw) {
    haptic_config.raw = m2s->hapticraw;
    eeconfig_update_haptic(haptic_config.raw);
  }
  if (audio_config.raw != m2s->audioraw) {
    audio_config.raw = m2s->audioraw;
    eeconfig_update_audio(audio_config.raw);
  }
#endif
}

void send_to_slave_haptic_and_audio_state(void) {
  static uint32_t last_sync = 0;
  if (timer_elapsed32(last_sync) <= TAPPING_TERM) {
    return;
  }
  static master_to_slave_t last_state_synced = {0, 0};
  if (audio_config.raw == last_state_synced.audioraw &&
      haptic_config.raw == last_state_synced.hapticraw) {
    return;
  }
  master_to_slave_t m2s = {audio_config.raw, haptic_config.raw};
  if (transaction_rpc_send(SYNC_HAPTIC_AND_AUDIO, sizeof(m2s), &m2s)) {
    last_sync = timer_read32();
    last_state_synced = m2s;
  }
}
