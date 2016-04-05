#include "gpio.h"
#include "system.h"
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "odometry.h"
#include "actuators.h"
#include "sides.h"

int main()
{
	system_init();
	
	while(1)
	{
		purpleside();
	}
}