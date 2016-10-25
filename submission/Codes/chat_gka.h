/*
 *  Off-the-Record Messaging library
 *  Copyright (C) 2015-2016  Dimitrios Kolotouros <dim.kolotouros@gmail.com>,
 *							 Konstantinos Andrikopoulos <el11151@mail.ntua.gr>
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of version 2.1 of the GNU Lesser General
 *  Public License as published by the Free Software Foundation.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef CHAT_GKA_H_
#define CHAT_GKA_H_

#include "chat_types.h"

typedef enum {
        CHAT_GKASTATE_NONE,
        CHAT_GKASTATE_AWAITING_UPFLOW,
        CHAT_GKASTATE_AWAITING_DOWNFLOW,
        CHAT_GKASTATE_FINISHED
} ChatGKAState;

struct OtrlListOpsStruct interKeyOps;

unsigned int chat_gka_info_get_position(ChatGKAInfoPtr gka_info);
ChatGKAState chat_gka_info_get_state(ChatGKAInfoPtr gka_info);

void chat_gka_info_free(ChatGKAInfoPtr gka_info);

int chat_gka_init(ChatContextPtr ctx, ChatMessage **msgToSend);

int chat_gka_is_my_message(const ChatMessage *msg);

int chat_gka_handle_message(ChatContextPtr ctx, ChatMessage *msg,
		ChatMessage **msgToSend);

#endif /* CHAT_GKA_H_ */
