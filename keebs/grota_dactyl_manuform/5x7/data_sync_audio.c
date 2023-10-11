#include "data_sync_audio.h"

void audio_slave_handler(uint8_t in_buflen, const void *in_data,
                                    uint8_t out_buflen, void *out_data) {
  const master_to_slave_t *m2s = (const master_to_slave_t *)in_data;
  audio_config.raw = m2s->audioraw;
}

void send_to_slave_audio_state(void) {
  static uint32_t last_sync = 0;
  if (timer_elapsed32(last_sync) <= TAPPING_TERM) {
    return;
  }
  static master_to_slave_t last_state_synced = {0};
  if (audio_config.raw == last_state_synced.audioraw) {
    return;
  }
  master_to_slave_t m2s = {audio_config.raw};
  if (transaction_rpc_send(SYNC_AUDIO, sizeof(m2s), &m2s)) {
    last_sync = timer_read32();
    last_state_synced = m2s;
  }
}
