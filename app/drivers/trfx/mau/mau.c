#include "zephyr/drivers/sensor.h"
#include "zephyr/sys/printk.h"
#include "trfx_mau.h"

#define DT_DRV_COMPAT mau


/* Dynamic runtime data */
struct trfx_mau_data {
    int counter;
};

/* Driver's dynamic data instance */
static struct trfx_mau_data mau_data = {
    .counter = 0,
};

static int sensor_channel_get_impl(const struct device *dev, enum sensor_channel chan,
				   struct sensor_value *sensor_value)
{
	printk("Got channel %d\n", chan);
	return 0;
}

static int sensor_sample_fetch_impl(const struct device *dev, enum sensor_channel chan)
{
    printk("Got fetch %d\n", chan);
	return 0;
}


int trfx_mau_set_counter(const struct device *dev, int value)
{
    struct trfx_mau_data *data = dev->data;

    if (dev == NULL) {
        return -EINVAL;
    }
    int prev_v = data->counter;

    data->counter = value;

    printk("New counter: %d from: %d\n", data->counter, prev_v);

    return 0;
}

static DEVICE_API(sensor, phew) = {
	.sample_fetch = sensor_sample_fetch_impl,
	.channel_get = sensor_channel_get_impl,
};

static int init(const struct device *dev)
{
	printk("Device initiated\n");
	return 0;
}

DEVICE_DT_INST_DEFINE(0, init, NULL, &mau_data, NULL, POST_KERNEL, 80, &phew);
