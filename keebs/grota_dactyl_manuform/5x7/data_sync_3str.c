#include "data_sync_3str.h"

char str1[32];
char str2[32];
char str3[32];

void receive_msg_from_slave_cb(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data) {
  slave_to_master_t *s2m = (slave_to_master_t*)out_data;
  strcpy(s2m->str1, str1);
  strcpy(s2m->str2, str2);
  strcpy(s2m->str3, str3);
}

void receive_msg_from_slave(void) {
  if (is_keyboard_master()) {
    static uint32_t last_sync = 0;
    static slave_to_master_t last_rcvd = {0};
    /*static bool print_comm_failure = true;*/
    if (timer_elapsed32(last_sync) > 100) {
      last_sync = timer_read32();
      slave_to_master_t s2m = {0};
      if(transaction_rpc_recv(SYNC_SLAVE_MSG, sizeof(s2m), &s2m)) {
        /*print_comm_failure = true;*/
        if (strcmp(last_rcvd.str1, s2m.str1) != 0 || strcmp(last_rcvd.str2, s2m.str2) != 0 || strcmp(last_rcvd.str3, s2m.str3) != 0) {
          uprintf("Slave str1: %s\n", s2m.str1);
          uprintf("Slave str2: %s\n", s2m.str2);
          uprintf("Slave str3: %s\n", s2m.str3);
          memcpy(&last_rcvd, &s2m, sizeof(s2m));
        }
      } else {
        /*if (print_comm_failure) {*/
          uprint("Slave sync failed!\n");
          /*print_comm_failure = false;*/
        }
      }
    }
  }
}
