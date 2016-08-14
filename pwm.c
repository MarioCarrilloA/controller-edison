#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mraa.h>

#define PWM_PORT 3
#define SLEEP_TIME 1000
#define PERIOD 200
#define ENABLE 1
#define DISABLE 0
#define UP 1
#define DOWN 2

int main()
{

	float percentage;
	float current_percentage;
	unsigned int way_flag;
	mraa_pwm_context pwm;

	/* Initialise pwm_context, uses board mapping */
	pwm = mraa_pwm_init(PWM_PORT);

	if (pwm == NULL)
		return EXIT_FAILURE;

	/* Set period, microseconds */
	mraa_pwm_period_us(pwm, PERIOD);

	/* Set the enable status of the PWM pin.
	None zero will assume on with output being 
	driven. and 0 will disable the output.*/
	mraa_pwm_enable(pwm, ENABLE);

	percentage = 0.0f;
	way_flag = DOWN;
	
	while (1) {

		mraa_pwm_write(pwm, percentage);
		if (percentage <= 0.0f) {
			way_flag = UP;
		}

		if (percentage >= 1.0f) {
			way_flag = DOWN;
		}

		if (way_flag == UP)
			percentage = percentage + 0.01f;
		else
			percentage = percentage - 0.01f;

		current_percentage = mraa_pwm_read(pwm);
		system("clear");
		printf("%.0f%\n", current_percentage * 100);
		usleep(SLEEP_TIME);
    	}

	mraa_pwm_enable(pwm, DISABLE);
	mraa_pwm_close(pwm);

	return MRAA_SUCCESS;
}
