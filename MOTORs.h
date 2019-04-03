#ifndef MOTORS_H_
#define MOTORS_H_ 

//Definición de parámetros del motor
#define MOTOR_STOP 	0
#define MOTOR_BACKWARD	1
#define MOTOR_FORWARD	2
#define ROBO_SPEED 150 //0-255

void init_timer1();
void motor_right(uint8_t dir,uint8_t speed);
void motor_left(uint8_t dir,uint8_t speed);


#endif /* MOTORS_H_ */