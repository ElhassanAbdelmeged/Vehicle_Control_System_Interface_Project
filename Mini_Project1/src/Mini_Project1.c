/*
 ============================================================================
 Name        : MMini_Project1.c
 Author      : Hassan Abd El maged
 Version     :
 Copyright   : Your copyright notice
 Description : Mini project 1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define WITH_ENGINE_TEMP_CONTROLLER 1   		//using {#if... #end if} --> true then execute  the whole code
//#define WITH_ENGINE_TEMP_CONTROLLER 0 		//using {#if... #end if} -->false then execute  the  code  except the mentioned part in point 9

// Declaring the  types and the variables
typedef enum{off,on}state;
typedef struct
{
	state EngineState;
	state AC;
	int VehicleSpeed;
	float RoomTemperature;
	state EngineTemperatureController;
	float EngineTemperature;
}vehicle_state;


vehicle_state stateInfo={off,off,50,44,off,100}; 	//Defining A variable of type structure to get informations of the vehicle

/*================================================================================================================================================================*/
// Forming the functions.

/*1- Function that setting the Vehicle speed based on the Traffic Light that some sensor will read  */

void trafficLight(char color){


	printf("enter the color of the traffic light\n {g:green}\n {o:orange}\n {r:red}\n ");
	scanf(" %c",&color);
	switch(color){

	case'g':
		stateInfo.VehicleSpeed=100;
		break;

	case'r':
		stateInfo.VehicleSpeed=0;
		break;

	case'o':
		stateInfo.VehicleSpeed=30;
		break;
	default:
		printf("invalid input\n\n");
		break;
	}

	return ;
}

/*2- Function that takes the value of current room temperature and based on that it will decide to Turn on the AC or not and make the Room Temp. change */

void RoomTemp(vehicle_state *stateInfo ) //pointer to structure
{
	printf("enter the temperature of the Room\n");
	scanf(" %f",&stateInfo->RoomTemperature);

	if( stateInfo->RoomTemperature < 10.0 )
	{
		stateInfo->AC=on;
		stateInfo->RoomTemperature=20.0;
	}

	else if( stateInfo->RoomTemperature>30.0 )

	{
		stateInfo->AC=on;
		stateInfo->RoomTemperature=20.0;


	}
	else  {
		stateInfo->AC=off;

	}

	return ;
}

/*3- Function that Turn (on/off) the Engine Temperature Controller according to the value of Engine Temperature  */

void EngineTemperatureData(vehicle_state *stateInfo ) //pointer to structure
{


	printf("enter the temperature of the Engine\n");
	scanf(" %f",&stateInfo->EngineTemperature);

	if(stateInfo->EngineTemperature<100){

		stateInfo->EngineTemperatureController= on;
		stateInfo->EngineTemperature=125;
	}


	else if(stateInfo->EngineTemperature>150){

		stateInfo->EngineTemperatureController= on;
		stateInfo->EngineTemperature=125;
	}

	else{
		stateInfo->EngineTemperatureController= off;
	}



	return ;
}

/*4-Function to  Turn on Engine Temperature Controller&AC and setting new values of room&engine temperatures   by   checking the speed of the vehicle equal to 30   */

void CheckVehicleSpeed (vehicle_state *stateInfo){

	if(30==stateInfo->VehicleSpeed)
	{
		stateInfo->AC=on;
		stateInfo->RoomTemperature=stateInfo->RoomTemperature*((float)5/4) + 1.0  ;

#if(  WITH_ENGINE_TEMP_CONTROLLER)
		stateInfo->EngineTemperatureController= on;
		stateInfo->EngineTemperature=stateInfo->EngineTemperature*(5.0/4) + 1.0 ;
#endif

	}

	return ;
}

/*5-Function to display the data of the system based on the user choices*/

void DisplayData(void)
{
	CheckVehicleSpeed(&stateInfo);

	if(stateInfo.EngineState==1)
		printf("i.Engine state: ON \n");
	else
		printf("i.Engine state: OFF \n");
	if(stateInfo.AC==1)
		printf("ii.AC state: ON \n");
	else
		printf("ii.AC state: OFF \n");

	printf("iii.Vehicle speed: %d km/h \n",stateInfo.VehicleSpeed);
	printf("iv.Room Temperature: %.3f C \n",stateInfo.RoomTemperature);

#if( WITH_ENGINE_TEMP_CONTROLLER)

	if(stateInfo.EngineTemperatureController==1)
		printf("v.engine  Temperature controller state: ON \n");
	else
		printf("v.engine  Temperature controller state: OFF \n");

	printf("iv.Engine Temperature: %.3f C \n\n",stateInfo.EngineTemperature);
#endif
	return ;
}

/*==================================================================================================================================================================================*/
/*==================================================================================================================================================================================*/

int main(void) {

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);


	char choice1;
	char choice2;
	char choice3='r';

	while(stateInfo.EngineState ==off) //while loop to make sure that the the control flow(choices that determine the system)  is achieved
	{

		printf("enter your choice of:\n");
		printf(" a. Turn on the vehicle engine\n b. Turn off the vehicle engine\n c. Quit the system\n");

		scanf(" %c",&choice1);

		switch(choice1)			//the first choice determine the system case
		{

		case 'a':

			printf("Turn on the vehicle engine\n \n");
			stateInfo.EngineState = on;

			/*Displaying sensor set menu*/


			do  //DO....while loop to make sure that the the control flow(choices of the sensor set menu)  is achieved
			{

				printf(" a. Turn off the engine\n b. Set the traffic light color\n c. Set the room temperature (Temperature Sensor)\n");

#if(  WITH_ENGINE_TEMP_CONTROLLER)  			// if it is true print else pass that line
				printf(" d. Set the engine temperature (Engine Temperature Sensor)\n" );
#endif
				scanf(" %c",&choice2);			//To choose from the sensor set menu

				switch(choice2){

				case 'a':   					//turning the engine off
					stateInfo.EngineState =off;
					printf("Turn off the vehicle engine\n \n");
					break;

				case 'b': 						//setting the traffic light color to set the speed
					trafficLight(choice3);
					DisplayData();
					break;

				case'c': 					 	//setting the room temperature
					RoomTemp(&stateInfo );		//passing the address of the structure to the fun.
					DisplayData();
					break;

#if(  WITH_ENGINE_TEMP_CONTROLLER)
				case'd':						//setting the engine temperatuer

					EngineTemperatureData(&stateInfo );
					DisplayData();
					break;
#endif
				}
			}while(stateInfo.EngineState ==on);
			break;

		case 'b':
			printf("Turn off the vehicle engine\n \n");
			break;

		case 'c':
			printf("Quit from the system \n");
			return 0;
			break;
		}

	}
	return 0;
}
