#ifndef TRFX_MAU_H
#define TRFX_MAU_H

#include <zephyr/device.h>

#ifdef __cplusplus
extern "C" {
#endif

int trfx_mau_set_counter(const struct device *dev, int value);

#ifdef __cplusplus
}
#endif

#endif
