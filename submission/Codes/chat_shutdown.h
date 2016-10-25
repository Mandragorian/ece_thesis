#ifndef CHAT_SHUTDOWN_H
#define CHAT_SHUTDOWN_H

#include "chat_types.h"

typedef enum {
	CHAT_SHUTDOWNSTATE_NONE,
	CHAT_SHUTDOWNSTATE_AWAITING_SHUTDOWNS,
	CHAT_SHUTDOWNSTATE_AWAITING_DIGESTS,
	CHAT_SHUTDOWNSTATE_AWAITING_ENDS,
	CHAT_SHUTDOWNSTATE_FINISHED
} ChatShutdownState;

ChatShutdownState chat_shutdown_info_get_state(ChatShutdownInfoPtr shutdown_info);
void chat_shutdown_info_free(ChatShutdownInfoPtr shutdown_info);

int chat_shutdown_init(ChatContextPtr ctx);

int chat_shutdown_send_shutdown(ChatContextPtr ctx, ChatMessage **msgToSend);

int chat_shutdown_send_digest(ChatContextPtr ctx, ChatMessage **msgToSend);

int chat_shutdown_send_end(ChatContextPtr ctx, ChatMessage **msgToSend);

int chat_shutdown_release_secrets(ChatContextPtr ctx, ChatMessage **msgToSend);

int chat_shutdown_is_my_message(const ChatMessage *msg);

int chat_shutdown_handle_message(ChatContextPtr ctx, ChatMessage *msg,
		                 ChatMessage **msgToSend);

#endif /* CHAT_SHUTDOWN_H */
