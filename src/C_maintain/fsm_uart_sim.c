#include <stdio.h>
#include <stdint.h>
#include <string.h>

// FSM states
typedef enum {
    STATE_WAIT,
    STATE_VALID,
    STATE_ERROR
} FSMState;

FSMState current_state = STATE_WAIT;

// ✅ Checksum calculation
uint8_t calc_checksum(const char* text) {
    uint16_t sum = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        sum += (uint8_t)text[i];
    }
    return sum % 256;
}

// ✅ Validate and print result
void validate_uart_packet(const char* line) {
    char payload[64];
    int recv_checksum;
    
    if (sscanf(line, "%[^*]*%d", payload, &recv_checksum) == 2) {
        uint8_t calculated = calc_checksum(payload);
        if (calculated == recv_checksum) {
            current_state = STATE_VALID;
            printf("[%s] %s\n", "VALID", payload);
        } else {
            current_state = STATE_ERROR;
            printf("[%s] MISMATCH (expected %d)\n", "ERROR", calculated);
        }
    } else {
        current_state = STATE_ERROR;
        printf("[%s] FORMAT ERROR\n", "ERROR");
    }
}

int main() {
    const char* uart_lines[] = {
        "TEMP:24.3;HUM:55.2*247",
        "TEMP:28.1;HUM:61.0*BAD",
        "BROKENLINE",
        "TEMP:30.5;HUM:50.0*234"
    };

    int count = sizeof(uart_lines) / sizeof(uart_lines[0]);

    for (int i = 0; i < count; i++) {
        current_state = STATE_WAIT;
        printf("[%s] Waiting...\n", "WAIT");
        validate_uart_packet(uart_lines[i]);
        printf("\n");
    }

    return 0;
}
