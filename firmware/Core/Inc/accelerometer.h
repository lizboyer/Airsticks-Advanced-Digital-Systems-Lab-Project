/*
 * accelerometer.h
 */

#ifndef INC_ACCELEROMETER_H_
#define INC_ACCELEROMETER_H_

/************************** DEVICE ADDRESSES **************************/
#define ACC0_W_ADDR			0xd4
#define ACC0_R_ADDR			0xd5
#define ACC1_W_ADDR			0xd6
#define ACC1_R_ADDR			0xd7


/************************** DEVICE REGISTERS **************************/
#define REG_CTRL1_XL		0x10
#define REG_CTRL2_G			0x11
#define REG_INT1_CTRL 		0x0d
#define REG_INT2_CTRL 		0x0e


/************************** REGISTER CONFIGS **************************/
#define ACC_104HZ_2G		0x40
#define GYRO_OFF			0x00
#define DATA_RDY			0x01

#define OUTX_L_A			0x28
#define OUTX_H_A			0x29
#define OUTY_L_A			0x2a
#define OUTY_H_A			0x2b
#define OUTZ_L_A			0x2c
#define OUTZ_H_A			0x2d

#include <stdint.h>

/**************************** TYPEDEFS ********************************/
typedef enum axis {
	X_AXIS,
	Y_AXIS,
	Z_AXIS,
	ALL_AXIS
} axis_t;

typedef struct accelerometer_t {
	  int16_t x_measurement;
	  int16_t y_measurement;
	  int16_t z_measurement;
	  int8_t  slave_r_addr;
	  int8_t  slave_w_addr;
} accelerometer_t;


/*********************** FUNCTION PROTOTYPES ***************************/

/*
 * acc_init
 * inputs:
 * 		- accelerometer_t acc: pointer to the accelerometer to initialize
 * returns:
 * 		- none
 * side effects:
 * 		- configure the accelerometer to 100Hz polling, and turn off gyro
 */
extern void acc_init			(accelerometer_t* acc);

/*
 * read_axis
 * inputs:
 * 		- accelerometer_t acc: pointer the the accelerometer struct from
 * 				which to read the acceleration values
 * 		- axis_t axis: enumerator representing the axis to read
 * returns:
 * 		- none
 * 	side effects:
 * 		- updates the acceleration values inside the accelerometer struct
 **/
extern void read_axis			(accelerometer_t* acc, axis_t axis);


/*
 * read_axis
 * inputs:
 * 	    - accelerometer_t acc: pointer the the accelerometer struct to
 * 	    		which to write data to
 * 		- int8_t reg: the register within the accelerometer to write to
 * 		- int8_t data: the data to write
 * returns:
 * 		- none
 * 	side effects:
 * 		- performs and I2C write to the passed in accelerometer
 **/
extern void accelerometer_write(accelerometer_t* acc, int8_t reg, int8_t data);


#endif /* INC_ACCELEROMETER_H_ */
