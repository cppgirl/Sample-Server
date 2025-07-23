#include <stdint.h>
#include <stddef.h>

// Put the following define in exactly one of your c/cpp files before including.
#define TINYCSOCKET_IMPLEMENTATION
#include "tinycsocket.h"

int main() {
    tcs_lib_init();

    TcsSocket client_socket = TCS_NULLSOCKET;
    tcs_create(&client_socket, TCS_TYPE_TCP_IP4);
    tcs_connect(client_socket, "example.com", 80);

    uint8_t send_buffer[] = "GET / HTTP/1.1\nHost: example.com\n\n";
    tcs_send(client_socket, send_buffer, sizeof(send_buffer), TCS_MSG_SENDALL, NULL);

    uint8_t recv_buffer[8192] = {0};
    size_t bytes_received = 0;
    tcs_receive(client_socket, recv_buffer, 8192, TCS_NO_FLAGS, &bytes_received);

    tcs_shutdown(client_socket, TCS_SD_BOTH);
    tcs_destroy(&client_socket);

    tcs_lib_free();
}
