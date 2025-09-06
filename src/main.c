#include <stdbool.h>

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

#include "demo.h"



LOG_MODULE_DECLARE(ST25R);

const struct gpio_dt_spec ledspec = GPIO_DT_SPEC_GET(DT_NODELABEL(led0), gpios);

int main()
{

    int err = gpio_is_ready_dt(&ledspec);
	if (!err) {
		LOG_ERR("Error: GPIO device is not ready, err: %d", err);
		return 0;
	}

    bool rv = demoIni();
    if (!rv) {
        LOG_ERR("failed to initialize");
    } 

    gpio_pin_configure_dt(&ledspec, GPIO_OUTPUT_ACTIVE);

        while (1) {
             gpio_pin_toggle_dt(&ledspec);
             
            demoCycle();

            LOG_INF("failed to initialize");

             k_sleep(K_MSEC(1000));


        }
    

    return 0;
}
