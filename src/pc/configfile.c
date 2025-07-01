// configfile.c - handles loading and saving the configuration options
#include <stdbool.h>
#include "configfile.h"

/*
 *Config options and default values
 */
bool configFullscreen            = false;
// Keyboard mappings (scancode values)
unsigned int configKeyA          = 0x26;
unsigned int configKeyB          = 0x33;
unsigned int configKeyStart      = 0x39;
unsigned int configKeyR          = 0x36;
unsigned int configKeyZ          = 0x25;
unsigned int configKeyCUp        = 0x148;
unsigned int configKeyCDown      = 0x150;
unsigned int configKeyCLeft      = 0x14B;
unsigned int configKeyCRight     = 0x14D;
unsigned int configKeyStickUp    = 0x11;
unsigned int configKeyStickDown  = 0x1F;
unsigned int configKeyStickLeft  = 0x1E;
unsigned int configKeyStickRight = 0x20;

// Loads the config file specified by 'filename'
void configfile_load(const char *filename) {

}

// Writes the config file to 'filename'
void configfile_save(const char *filename) {

}
