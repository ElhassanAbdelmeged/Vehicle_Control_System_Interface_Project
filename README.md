# Vehicle_Control_System_Interface_Project

This C programming project implements a basic vehicle control system with the following features:

Ask the user to:

Turn on the vehicle engine
Turn off the vehicle engine
Quit the system
If "Quit the system" is chosen, the program exits.

If "Turn off the vehicle engine" is chosen, the program returns to the main menu.

After each choice, the program displays the current system state.

Choosing "Turn on the vehicle engine" presents a menu to:

Turn off the engine
Set the traffic light color
Set the room temperature
Set the engine temperature
While the engine is ON, the menu is continuously displayed and awaits user input.

Based on user input:
a. Vehicle speed is adjusted based on the traffic light color.
b. The AC is controlled based on room temperature.
c. The "Engine Temperature Controller" is managed based on engine temperature.
d. Special actions are taken if the vehicle speed is 30 km/hr.

The program shows the current vehicle state, including engine status, AC, speed, room temperature, engine temperature controller, and engine temperature.

Choosing "Turn off the engine" from the menu returns to the main menu.

Bonus Requirement: Define WITH_ENGINE_TEMP_CONTROLLER as 1 to compile and run code related to the "Engine Temperature Controller." Set it to 0 to exclude that code.

