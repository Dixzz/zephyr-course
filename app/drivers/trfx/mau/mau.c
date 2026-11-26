#include "zephyr/drivers/sensor.h"
#include "zephyr/drivers/gpio.h"
#include "zephyr/sys/printk.h"

#define DT_DRV_COMPAT mau

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

static DEVICE_API(sensor, phew) = {
	.sample_fetch = sensor_sample_fetch_impl,
	.channel_get = sensor_channel_get_impl,
};

static int init(const struct device *dev)
{
	printk("Device initiated\n");
	return 0;
}

DEVICE_DT_INST_DEFINE(0, init, NULL, NULL, NULL, POST_KERNEL, 80, &phew);
