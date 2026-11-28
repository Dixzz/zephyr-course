#include <zephyr/shell/shell.h>
#include "zephyr/drivers/sensor.h"

const struct device *dev_shell = DEVICE_DT_GET_ANY(mau);
static int info(const struct shell *sh, size_t argc, char **argv)
{
	shell_print(sh, "App version: 1.0.0; ESP32 WROOM DEVKITC");
	return 0;
};
struct sensor_value svv;
static int fetch(const struct shell *sh, size_t argc, char **argv)
{
	shell_print(sh, "App version: 1.0.0");

	if (!(device_is_ready(dev_shell))) {
		shell_error(sh, "fetch: failed to get device: %s", dev_shell->name);
		return -1;
	}
	shell_info(sh, "Got value from sensor_sample_fetch: %d", sensor_sample_fetch(dev_shell));
	return 0;
};
static int get(const struct shell *sh, size_t argc, char **argv)
{
	shell_print(sh, "App version: 1.0.0");


	if (!(device_is_ready(dev_shell))) {
		shell_error(sh, "get: failed to get device: %s", dev_shell->name);
		return -1;
	}
	shell_info(sh, "Got value from sensor_channel_get: %d", sensor_channel_get(dev_shell, SENSOR_CHAN_GAUGE_STATE_OF_HEALTH, &svv));
	return 0;
};
SHELL_CMD_REGISTER(info, NULL, "Show app version", info);
SHELL_CMD_REGISTER(fetch, NULL, "Show app version", fetch);
SHELL_CMD_ARG_REGISTER(get, NULL, "Fetch with arg", get, 1, 0);
