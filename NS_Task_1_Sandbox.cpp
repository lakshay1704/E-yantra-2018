#include "NS_Task_1_Sandbox.h"

/*
*
* Function Name: forward_wls
* Input: node
* Output: void
* Logic: Uses white line sensors to go forward by the number of nodes specified
* Example Call: forward_wls(2); //Goes forward by two nodes
*
*/
void forward_wls(unsigned char node)
{
	/*
	while (1) {
		if (ADC_Conversion(1) == 0 && ADC_Conversion(2) > 200 && ADC_Conversion(3) == 0) {
			forward();
			velocity(127, 127);
		}

		if (ADC_Conversion(1) > 0 && ADC_Conversion(2) > 200 && ADC_Conversion(3) > 200) {
			forward();
			velocity(127, 127);
			_delay_ms(300);
			stop();
			break;
		}
	}
	*/
	unsigned char left_sensor, centre_sensor, right_sensor;
	while (1) {
		left_sensor = ADC_Conversion(1);
		centre_sensor = ADC_Conversion(2);
		right_sensor = ADC_Conversion(3);
		_delay_ms(500);
		printf("\n %d %d %d", left_sensor, centre_sensor, right_sensor);
		if (left_sensor < 200 && centre_sensor > 200 && right_sensor < 200) {
			forward();
			velocity(50, 50);
		}
		if (left_sensor > 200 && centre_sensor > 200 && right_sensor > 200) {
			stop();
			printf(" \n exiting forward  \n");
			break;
		}
	}
	forward();
	velocity(127, 127);
	_delay_ms(300);
	stop();
	printf(" \n exited forward \n");

}
/*
*
* Function Name: left_turn_wls
* Input: void
* Output: void
* Logic: Uses white line sensors to turn left until black line is encountered
* Example Call: left_turn_wls(); //Turns right until black line is encountered
*
*/
void left_turn_wls(void)
{
	/*
	left();
	velocity(127, 127);
	while (ADC_Conversion(2) < 200);
	stop();
	*/
	printf(" \n Entered left_turn_wls \n");
	unsigned char left_sensor, centre_sensor, right_sensor;
	while (1) {
		left_sensor = ADC_Conversion(1);
		centre_sensor = ADC_Conversion(2);
		right_sensor = ADC_Conversion(3);
		left();
		velocity(127, 127);
		_delay_ms(150);
		if (left_sensor < 200 && centre_sensor > 200 && right_sensor < 200) {
			stop();
			break;
		}
		else {
			continue;
		}
		//while (ADC_Conversion(2) < 200);
		//stop();
	}
	printf("\n exited left turn wls \n");
}

/*
*
* Function Name: right_turn_wls
* Input: void
* Output: void
* Logic: Uses white line sensors to turn right until black line is encountered
* Example Call: right_turn_wls(); //Turns right until black line is encountered
*/
void right_turn_wls(void)
{
	printf(" \n Entered right_turn_wls \n");
	unsigned char left_sensor, centre_sensor, right_sensor;
	while (1) {
		left_sensor = ADC_Conversion(1);
		centre_sensor = ADC_Conversion(2);
		right_sensor = ADC_Conversion(3);
		right();
		velocity(127, 127);
		_delay_ms(150);
		if (left_sensor < 200 && centre_sensor > 200 && right_sensor < 200) {
			stop();
			break;
		}
		else {
			continue;
		}
		//while (ADC_Conversion(2) < 200);
		//stop();
	}
	printf("\n exited right turn wls \n");
}

/*
*
* Function Name: Square
* Input: void
* Output: void
* Logic: Use this function to make the robot trace a square path on the arena
* Example Call: Square();
*/
void Square(void)
{
	forward();
	velocity(127, 127);
	_delay_ms(1500);
	stop();
	right();
	velocity(127, 127);
	_delay_ms(925);
	stop();
	forward();
	velocity(127, 127);
	_delay_ms(1500);
	stop();
	right();
	velocity(127, 127);
	_delay_ms(925);
	stop();
	forward();
	velocity(127, 127);
	_delay_ms(1500);
	stop();
	right();
	velocity(127, 127);
	_delay_ms(925);
	stop();
	forward();
	velocity(127, 127);
	_delay_ms(1500);
	stop();
	right();
	velocity(127, 127);
	_delay_ms(925);
	stop();
}

/*
*
* Function Name: line_follow
* Input: void
* Output: void
* Logic: using predef functions we trace the given path in the arena
* Example Call: line_follow();
*/
void line_follow() {
	unsigned char left_sensor, centre_sensor, right_sensor;
	while (1) {
		left_sensor = ADC_Conversion(1);
		centre_sensor = ADC_Conversion(2);
		right_sensor = ADC_Conversion(3);
		printf("\n %d %d %d", left_sensor, centre_sensor, right_sensor);
		if (left_sensor == 0 && centre_sensor > 200 && right_sensor == 0) {
			printf("etered in if \n");
			forward();
			velocity(50, 50);
			_delay_ms(50);
			stop();
		}
		else if ((left_sensor > 200 && right_sensor == 0 && centre_sensor == 0) || (left_sensor > 200 && centre_sensor > 200 && right_sensor == 0)) {
			soft_left();
			velocity(50, 50);
			_delay_ms(50);
			stop();
		}
		else if ((right_sensor > 200 && left_sensor == 0 && centre_sensor == 0) || (right_sensor > 200 && centre_sensor > 200 && left_sensor == 0)) {
			soft_right();
			velocity(50, 50);
			_delay_ms(50);
			stop();
		}
		else {
			printf("\n Error");
			stop();
		}
	}
}


/*
*
* Function Name: Task_1_1
* Input: void
* Output: void
* Logic: Use this function to encapsulate your Task 1.1 logic
* Example Call: Task_1_1();
*/
void Task_1_1(void)
{
	
	_delay_ms(1);
	//unsigned char left_sensor, centre_sensor, right_sensor;
	/*
	while (1) {
		left_sensor = ADC_Conversion(1);
		centre_sensor = ADC_Conversion(2);
		right_sensor = ADC_Conversion(3);
		printf("\n %d %d %d", left_sensor, centre_sensor, right_sensor);
	}
	*/
	
	int total_nodes = 13;
	int n = 0;
	while (n <= 13) {
		if (n == 0 || n == 3) {
			printf("%d \n", n);
			printf("\n Entering forward function \n");
			forward_wls(0);
			n += 1;
			printf("%d \n", n);
		}
		if (n == 1) {
			printf("%d \n", n);
			printf("\n entering right turn wls function");
			right_turn_wls();
			forward_wls(0);
			n += 1;
			printf("%d \n", n);
		}
		if (n == 2 || n == 10) {
			printf("%d \n", n);
			//left_turn_wls();
			//soft_left();
			//forward_wls(0);
			n += 1;
		}
		if (n == 4) {
			printf("%d \n", n);
			//left_turn_wls();
			//forward_wls(0);
			n += 1;
		}
		if (n == 5) {
			printf("%d \n", n);
			//right_turn_wls();
			//soft_right();
			n += 1;
		}
		if (n == 6 || n == 7) {
			printf("%d \n", n);
			//soft_right();
			n += 1;
		}
		if (n == 8) {
			printf("%d \n", n);
			//right_turn_wls();
			//forward_wls(0);
			n += 1;
		}
		if (n == 9) {
			printf("%d \n", n);
			//left_turn_wls();
			//forward_wls(0);
			n += 1;
		}
		if (n == 11) {
			printf("%d \n", n);
			//left_turn_wls();
			//forward_wls(0);
			n += 1;
		}
		if (n == 12) {
			printf("%d \n", n);
			//right_turn_wls();
			//forward_wls(0);
			n += 1;
		}
		if (n == 13) {
			printf("%d \n", n);
			stop();
			right();
			velocity(127, 127);
			_delay_ms(3700);
			stop();
		}
	}
	
	/*
	unsigned char left_sensor, centre_sensor, right_sensor;
	while (1) {
		left_sensor = ADC_Conversion(1);
		centre_sensor = ADC_Conversion(2);
		right_sensor = ADC_Conversion(3);
		printf("\n %d %d %d", left_sensor, centre_sensor, right_sensor);
		if (left_sensor == 0 && centre_sensor > 200 && right_sensor == 0) {
			forward();
			velocity(127, 127);
		}
		else  if (left_sensor > 200 && centre_sensor > 200 && right_sensor > 200) {
			forward();
			velocity(127, 127);
			_delay_ms(300);
			stop();
			
		}
	}
	*/
	
	//right()
	//soft_right()
	//left()
	//soft_left()
}
/*
*
* Function Name: Task_1_2
* Input: void
* Output: void
* Logic: Use this function to encapsulate your Task 1.2 logic
* Example Call: Task_1_2();
*/
void Task_1_2(void)
{
	//_delay_ms(1);
	//unsigned int red_pulse_count, green_pulse_count, blue_pulse_count, filter_clear_pulse_count;
	//while (1) {
		//filter_red();
		//red_pulse_count = color_sensor_pulse_count;
		//filter_green();
		//green_pulse_count = color_sensor_pulse_count;
		//filter_blue();
		//blue_pulse_count = color_sensor_pulse_count;
		//filter_clear();
		//filter_clear_pulse_count = color_sensor_pulse_count;
		//printf("\n red: %d	green: %d	blue:  %d	%d \n", red_pulse_count, green_pulse_count, blue_pulse_count, filter_clear_pulse_count);
		//_delay_ms(1000);
	//}
	pick();
	left_turn_wls();
	forward_wls(0);
	right_turn_wls();
	place();
	_delay_ms(5000);
}
