#ifndef CONFIGURATION_H
#define CONFIGURATION_H

//this is it!

// BASIC SETTINGS: select your board type, thermistor type, axis scaling, and endstop configuration

//// The following define selects which electronics board you have. Please choose the one that matches your setup
// MEGA/RAMPS up to 1.2  = 3,
// RAMPS 1.3 = 33
// Gen6 = 5, 
// Sanguinololu up to 1.1 = 6
// Sanguinololu 1.2 and above = 62
#define MOTHERBOARD 62 

//// Thermistor settings:
// 1 is 100k thermistor
// 2 is 200k thermistor
// 3 is mendel-parts thermistor
// 4 is 10k thermistor
#define THERMISTORHEATER 1
#define THERMISTORBED 2

//// Calibration variables
// X, Y, Z, E steps per unit - Metric Prusa Mendel with Wade extruder:
float axis_steps_per_unit[] = {91.4286, 91.4286,4000,910};

//// Endstop Settings
#define ENDSTOPPULLUPS 1 // Comment this out (using // at the start of the line) to disable the endstop pullup resistors
// The pullups are needed if you directly connect a mechanical endswitch between the signal and ground pins.
const bool ENDSTOPS_INVERTING = false; //set to true to invert the logic of the endstops
//If your axes are only moving in one direction, make sure the endstops are connected properly.
//If your axes move in one direction ONLY when the endstops are triggered, set ENDSTOPS_INVERTING to true here

// This determines the communication speed of the printer
#define BAUDRATE 115200

// Comment out (using // at the start of the line) to disable SD support:
//#define SDSUPPORT 1


//// ADVANCED SETTINGS - to tweak parameters

//#include "thermistortables.h"

// For Inverting Stepper Enable Pins (Active Low) use 0, Non Inverting (Active High) use 1
#define X_ENABLE_ON 0
#define Y_ENABLE_ON 0
#define Z_ENABLE_ON 0
#define E_ENABLE_ON 0

// Disables axis when it's not being used.
const bool DISABLE_X = false;
const bool DISABLE_Y = false;
const bool DISABLE_Z = true;
const bool DISABLE_E = false;

// Inverting axis direction
const bool INVERT_X_DIR = true;
const bool INVERT_Y_DIR = false;
const bool INVERT_Z_DIR = false;
const bool INVERT_E_DIR = true;

//// ENDSTOP SETTINGS:
// Sets direction of endstops when homing; 1=MAX, -1=MIN
#define X_HOME_DIR -1
#define Y_HOME_DIR -1
#define Z_HOME_DIR -1

const bool min_software_endstops = false; //If true, axis won't move to coordinates less than zero.
const bool max_software_endstops = true;  //If true, axis won't move to coordinates greater than the defined lengths below.
const int X_MAX_LENGTH = 150;
const int Y_MAX_LENGTH = 148;
const int Z_MAX_LENGTH = 100;

//// MOVEMENT SETTINGS
const int NUM_AXIS = 4; // The axis order in all axis related arrays is X, Y, Z, E
float max_feedrate[] = {30000, 30000, 500, 30000};
float homing_feedrate[] = {1500,1500,120};
bool axis_relative_modes[] = {false, false, false, false};

// Min step delay in microseconds. If you are experiencing missing steps, try to raise the delay microseconds, but be aware this
// If you enable this, make sure STEP_DELAY_RATIO is disabled.
//#define STEP_DELAY_MICROS 1

// Step delay over interval ratio. If you are still experiencing missing steps, try to uncomment the following line, but be aware this
// If you enable this, make sure STEP_DELAY_MICROS is disabled. (except for Gen6: both need to be enabled.)
//#define STEP_DELAY_RATIO 0.25

// Comment this to disable ramp acceleration
#define RAMP_ACCELERATION 1

//// Acceleration settings
#ifdef RAMP_ACCELERATION
// X, Y, Z, E maximum start speed for accelerated moves. E default values are good for skeinforge 40+, for older versions raise them a lot.
float max_start_speed_units_per_second[] = {25.0,25.0,0.2,10.0};
long max_acceleration_units_per_sq_second[] = {1000,1000,50,250}; // X, Y, Z and E max acceleration in mm/s^2 for printing moves or retracts
long max_travel_acceleration_units_per_sq_second[] = {500,500,50,500}; // X, Y, Z max acceleration in mm/s^2 for travel moves
#endif

// Machine UUID
// This may be useful if you have multiple machines and wish to identify them by using the M115 command. 
// By default we set it to zeros.
char uuid[] = "00000000-0000-0000-0000-000000000000";


//// AD595 THERMOCOUPLE SUPPORT UNTESTED... USE WITH CAUTION!!!!

//// PID settings:
// Uncomment the following line to enable PID support. This is untested and could be disastrous. Be careful.
#define PIDTEMP 1
#ifdef PIDTEMP
int pid_max = 255; // limits current to nozzle
int pid_i_max = 130;//125;
double Kp = 1.10; //100 is 1.0
double Ki = 0.01; //100 is 1.0
double Kd = 0.01; //100 is 1.0
#endif

//M109 target window - machine will deem to have reached target temperature when nozzle reaches Temp = target - NZONE.
int nzone = 5;//2;

#define DEBUG_PID

// How often should the heater check for new temp readings, in milliseconds
#define HEATER_CHECK_INTERVAL 112
#define BED_CHECK_INTERVAL 5000
// Comment the following line to enable heat management during acceleration
//#define DISABLE_CHECK_DURING_ACC
#ifndef DISABLE_CHECK_DURING_ACC
  // Uncomment the following line to disable heat management during moves
  //#define DISABLE_CHECK_DURING_MOVE
#endif
// Uncomment the following line to disable heat management during travel moves (and extruder-only moves, eg: retracts), strongly recommended if you are missing steps mid print.
// Probably this should remain commented if are using PID.
// It also defines the max milliseconds interval after which a travel move is not considered so for the sake of this feature.
//#define DISABLE_CHECK_DURING_TRAVEL 1000

//// Temperature smoothing - only uncomment this if your temp readings are noisy (Gen6 without EvdZ's 5V hack)
//#define SMOOTHING 1
//#define SMOOTHFACTOR 16 //best to use a power of two here - determines how many values are averaged together by the smoothing algorithm

//// Experimental watchdog and minimal temp
// The watchdog waits for the watchperiod in milliseconds whenever an M104 or M109 increases the target temperature
// If the temperature has not increased at the end of that period, the target temperature is set to zero. It can be reset with another M104/M109
//#define WATCHPERIOD 5000 //5 seconds

//// The minimal temperature defines the temperature below which the heater will not be enabled
#define MINTEMP 5

//// Experimental max temp
// When temperature exceeds max temp, your heater will be switched off.
// This feature exists to protect your hotend from overheating accidentally, but *NOT* from thermistor short/failure!
// You should use MINTEMP for thermistor short/failure protection.
#define MAXTEMP 300

// Select one of these only to define how the nozzle temp is read.
#define HEATER_USES_THERMISTOR
//#define HEATER_USES_AD595
//#define HEATER_USES_MAX6675

// Select one of these only to define how the bed temp is read.
#define BED_USES_THERMISTOR
//#define BED_USES_AD595

// Uncomment the following line to enable debugging. You can better control debugging below the following line
//#define DEBUG
#ifdef DEBUG
  //#define DEBUG_PREPARE_MOVE //Enable this to debug prepare_move() function
  //#define DEBUG_BRESENHAM //Enable this to debug the Bresenham algorithm
  //#define DEBUG_RAMP_ACCELERATION //Enable this to debug all constant acceleration info
  //#define DEBUG_MOVE_TIME //Enable this to time each move and print the result
  //#define DEBUG_HEAT_MGMT //Enable this to debug heat management. WARNING, this will cause axes to jitter!
  //#define DEBUG_DISABLE_CHECK_DURING_TRAVEL //Debug the namesake feature, see above in this file
#endif

//nozzle temp table, 100k EPCOS G540
#define NUMTEMPS 58
const short temptable[NUMTEMPS][2] = {
{	15	,	286	},
{	16	,	282	},
{	17	,	278	},
{	18	,	274	},
{	19	,	270	},
{	20	,	266	},
{	21	,	262	},
{	22	,	258	},
{	23	,	254	},
{	25	,	250	},
{	27	,	246	},
{	28	,	242	},
{	31	,	238	},
{	33	,	234	},
{	35	,	230	},
{	38	,	226	},
{	41	,	222	},
{	44	,	218	},
{	48	,	214	},
{	52	,	210	},
{	56	,	206	},
{	61	,	202	},
{	66	,	198	},
{	71	,	194	},
{	78	,	190	},
{	84	,	186	},
{	92	,	182	},
{	100	,	178	},
{	109	,	174	},
{	120	,	170	},
{	131	,	166	},
{	143	,	162	},
{	156	,	158	},
{	171	,	154	},
{	187	,	150	},
{	205	,	146	},
{	224	,	142	},
{	224	,	160	},
{	245	,	155	},
{	268	,	150	},
{	293	,	145	},
{	320	,	140	},
{	348	,	135	},
{	379	,	130	},
{	411	,	125	},
{	480	,	115	},
{	553	,	105	},
{	628	,	95	},
{	702	,	85	},
{	770	,	75	},
{	830	,	65	},
{	881	,	55	},
{	922	,	45	},
{	954	,	35	},
{	977	,	25	},
{	993	,	15	},
{	999	,	10	},
{	1008	,	0	},
};

//bed temp table, 100k EPCOS
#define BNUMTEMPS 34
const short bedtemptable[BNUMTEMPS][2] = {
   {1, 628},
   {32, 254},
   {63, 213},
   {94, 191},
   {125, 176},
   {156, 165},
   {187, 156},
   {218, 148},
   {249, 141},
   {280, 135},
   {311, 129},
   {342, 124},
   {373, 120},
   {404, 115},
   {435, 111},
   {466, 107},
   {497, 103},
   {528, 99},
   {559, 96},
   {590, 92},
   {621, 88},
   {652, 84},
   {683, 81},
   {714, 77},
   {745, 73},
   {776, 68},
   {807, 64},
   {838, 59},
   {869, 54},
   {900, 48},
   {931, 40},
   {962, 31},
   {993, 17},
   {1008,0}
};

/****************************************************************************************
* Sanguinololu pin assignment
*
****************************************************************************************/
#if MOTHERBOARD == 62
#define MOTHERBOARD 6
#define SANGUINOLOLU_V_1_2 
#endif
#if MOTHERBOARD == 6
#define KNOWN_BOARD 1
#ifndef __AVR_ATmega32U4__
#error Oops!  Make sure you have 'Sanguino' selected from the 'Tools -> Boards' menu.
#endif

#define X_STEP_PIN         20//15
#define X_DIR_PIN          21
#define X_MIN_PIN          3//18
#define X_MAX_PIN           -2

#define Y_STEP_PIN         22
#define Y_DIR_PIN          23
#define Y_MIN_PIN          2//19
#define Y_MAX_PIN          -1

#define Z_STEP_PIN         24//3
#define Z_DIR_PIN          25//2
#define Z_MIN_PIN          0//20
#define Z_MAX_PIN          -1

#define E_STEP_PIN         4//1
#define E_DIR_PIN          1//0

#define LED_PIN            -1

#define FAN_PIN            -1 

#define PS_ON_PIN          -1
#define KILL_PIN           -1

#define HEATER_0_PIN       10//13 // (extruder)

#define HEATER_1_PIN       9//12 // (bed)
#define X_ENABLE_PIN       13//14
#define Y_ENABLE_PIN       13//14
#define Z_ENABLE_PIN       26
#define E_ENABLE_PIN       13//14

#define TEMP_0_PIN          8//7   // MUST USE ANALOG INPUT NUMBERING NOT DIGITAL OUTPUT NUMBERING!!!!!!!!! (pin 33 extruder)
#define TEMP_1_PIN          9//6   // MUST USE ANALOG INPUT NUMBERING NOT DIGITAL OUTPUT NUMBERING!!!!!!!!! (pin 34 bed)
#define SDPOWER          -1
#define SDSS          14//31

#ifndef KNOWN_BOARD
#error Unknown MOTHERBOARD value in configuration.h
#endif

#endif
#endif
