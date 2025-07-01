#ifndef _PS2_MEMCARD_H
#define _PS2_MEMCARD_H

#include <stdbool.h>
#include <stdint.h>

#define PS2_SAVE_PATH "SM64" // the 0 is replaced later

bool ps2_memcard_init(void);
bool ps2_memcard_save(const void *data, const int ofs, const uint32_t size);
bool ps2_memcard_load(void *data, const int ofs, const uint32_t size);

#endif // _PS2_MEMCARD_H
