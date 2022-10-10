#pragma once

#include "quantum.h"
#include "solenoid.h"
#include "transactions.h"
#include <stdio.h>
#include <string.h>

#define SPLIT_TRANSACTION_IDS_KB SYNC_SLAVE_MSG
#define RPC_S2M_BUFFER_SIZE 96

typedef struct _slave_to_master_t {
    char str1[32];
    char str2[32];
    char str3[32];
} slave_to_master_t;


void receive_msg_from_slave_cb(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data);
void receive_msg_from_slave(void);
