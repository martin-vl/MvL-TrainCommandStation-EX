// Disable all four turnout coil drivers on the distribution board.
IODevice::write(44, 0);
IODevice::write(34, 0);
IODevice::write(48, 0);
IODevice::write(46, 0);

// Set DC for track A, loc 1
SETUP("<= A DC 1>");
// Create input buttons
SETUP("<S 20 173 1>"); // BT1 switch: MCP23017 GPB1
SETUP("<S 164 33 1>"); // IR1: Mega D33 (retain sensor ID 164)
SETUP("<S 166 35 1>"); // IR9: Mega D35 (retain sensor ID 166)
// Create output LEDs for buttons iflag=011 inverted reset at power up
SETUP("<Z 21 172 3>"); // BT1 LED: MCP23017 GPB0
// Setup time of flight sensor
//SETUP("<S 5000 5000 0>");
//Sensor::create(5000, 5000, 0);
