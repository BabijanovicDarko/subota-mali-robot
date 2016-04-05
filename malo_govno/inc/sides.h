#ifndef SIDES_H_
#define SIDES_H_

#define TACTIC_ONE_POSITION_COUNT 9

struct goto_fields
{
	struct odometry_position point;
	uint8_t					 speed;
	uint8_t					 direction;
	uint8_t					 (*callback)(uint32_t start_time);
};




void purpleside(void);
void greenside(void);
#endif /* SIDES_H_ */