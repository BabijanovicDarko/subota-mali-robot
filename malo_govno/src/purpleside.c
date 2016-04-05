#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include "system.h"
#include "odometry.h"
#include "can.h"
#include "sides.h"
#include "uart.h"
#include "actuators.h"
#include "gpio.h"

const struct goto_fields purple_tactic_one_positions[TACTIC_ONE_POSITION_COUNT] = 
{
	//{{85,400},LOW_SPEED,FORWARD,NULL}
	{{230,400},NORMAL_SPEED,FORWARD,NULL},						//ide ispred prve kucice
	{{230,80},NORMAL_SPEED,FORWARD,NULL},						//zatvara vrata
	{{230,400},NORMAL_SPEED,BACKWARD,NULL},						//se vraca nazad
	{{550,300},NORMAL_SPEED,FORWARD,NULL},						//ide ispred druge
	{{550,80},NORMAL_SPEED,FORWARD,NULL},						//zatvara drugu	
	{{550,300},NORMAL_SPEED,BACKWARD,NULL},						//vraca se nazad
	{{250,850},NORMAL_SPEED,FORWARD,NULL},						//priprema za kocke
	{{1100,970},NORMAL_SPEED,FORWARD,NULL},						//gura kocke
	{{100,970},NORMAL_SPEED,FORWARD,NULL}						//zavrsi
		
};

void purpleside(void)
{
	struct odometry_position starting_position;
	uint8_t current_position = 0;
	uint8_t next_position	 = 0;
	uint8_t odometry_status;
	uint8_t active_state = ROBOT_STATE_TACTIC_ONE;
	
	starting_position.x		= 85;
	starting_position.y		= 670;
	starting_position.angle = -90;
	
	odometry_set_position(&starting_position);

	while(1)
	{
		switch(active_state)
		{
			case ROBOT_STATE_TACTIC_ONE:
				for(current_position = next_position;current_position < TACTIC_ONE_POSITION_COUNT; current_position++)
				{
					odometry_status = odometry_move_to_position(&(purple_tactic_one_positions[current_position].point), purple_tactic_one_positions[current_position].speed,
																purple_tactic_one_positions[current_position].direction,purple_tactic_one_positions[current_position].callback); 
					if(odometry_status == ODOMETRY_FAIL)
					{
						break;
					}
					if(current_position == 8 )
					{
						while(1);
					}
				}//end for
		}//end switch
	}//end while
}//end void
