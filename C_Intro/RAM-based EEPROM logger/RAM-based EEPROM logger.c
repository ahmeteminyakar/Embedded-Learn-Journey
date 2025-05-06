#include <stdint.h>
#include <stdio.h>

#define MAX_LOGS 64


typedef struct {

    uint32_t timestamp;
    float temperature;
    uint16_t crc;
} LogEntry;


LogEntry log_buffer[MAX_LOGS];
uint8_t write_index = 0;

void update_index(){

    write_index = (write_index + 1) % MAX_LOGS;

}
