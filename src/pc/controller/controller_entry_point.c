#include "macros.h"

#include "lib/src/libultra_internal.h"
#include "lib/src/osContInternal.h"


#include "controller_recorded_tas.h"
#if !defined(TARGET_PSP) && !defined(TARGET_DC)
#include "controller_keyboard.h"
#endif

#if defined(_WIN32) || defined(_WIN64)
#include "controller_xinput.h"
#elif defined(TARGET_PSP)
#include "controller_psp.h"
#elif defined(TARGET_DC)
#include "controller_dc.h"
#else
#include "controller_sdl.h"
#endif

#ifdef __linux__
#include "controller_wup.h"
#endif

static struct ControllerAPI *controller_implementations[] = {
#if !defined(TARGET_PSP) && !defined(TARGET_DC)
    &controller_recorded_tas,
    &controller_keyboard,
#endif
#if defined(_WIN32) || defined(_WIN64)
    &controller_xinput,
#elif defined(TARGET_PSP)
    &controller_psp,
#elif defined(TARGET_DC)
    &controller_dc,
#else
    &controller_sdl,
#endif
#ifdef __linux__
    &controller_wup,
#endif
};

s32 osContInit(UNUSED OSMesgQueue *mq, u8 *controllerBits, UNUSED OSContStatus *status) {
    size_t i;

    for (i = 0; i < sizeof(controller_implementations) / sizeof(struct ControllerAPI *); i++) {
        controller_implementations[i]->init();
    }
    *controllerBits = 1;
    return 0;
}

s32 osContStartReadData(UNUSED OSMesgQueue *mesg) {
    return 0;
}

void osContGetReadData(OSContPad *pad) {
    size_t i;

    pad->button = 0;
    pad->stick_x = 0;
    pad->stick_y = 0;
    pad->errnum = 0;

    for (i = 0; i < sizeof(controller_implementations) / sizeof(struct ControllerAPI *); i++) {
        controller_implementations[i]->read(pad);
    }
}
