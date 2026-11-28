#include <zephyr/shell/shell.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

static int info(const struct shell *sh, size_t argc, char **argv)
{
	shell_print(sh, "App version: 1.0.0; ESP32 WROOM DEVKIT-1");
	return 0;
};
static int get(const struct shell *sh, size_t argc, char **argv)
{
	shell_print(sh, "App version: 1.0.0");
	return 0;
};
// SHELL_CMD_REGISTER(info, NULL, "Show app version", info);
static int sensor_set_value(const struct shell *sh, size_t argc, char **argv)
{

    // argv[0] = "set"
    // argv[1] = "<value>"

	if (argc != 2) {
		shell_error(sh, "Usage: set <value>  must have exactly 1 argument");
		return -EINVAL;
	}

	char *endptr;
    errno = 0;

    long value = strtol(argv[1], &endptr, 10);

    if (errno == ERANGE || *argv[1] == '\0' ||
        *endptr != '\0' ||
        value < INT_MIN || value > INT_MAX) {
        shell_error(sh, "Argument must be an integer");
        return -EINVAL;
    }

    int number = (int)value;

	shell_print(sh, "WTF???? %d", number);
	return 0;
};
SHELL_STATIC_SUBCMD_SET_CREATE(sub_sensor_set,
    SHELL_CMD_ARG(set, NULL, "Set sensor value", sensor_set_value, 2, 0),
    SHELL_SUBCMD_SET_END,
);

SHELL_CMD_REGISTER(sensor, &sub_sensor_set, "Sensor commands", NULL);
