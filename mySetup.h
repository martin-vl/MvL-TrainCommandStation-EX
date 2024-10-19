// set enable pins of turnout low/off
IODevice::write(168, 0);
IODevice::write(169, 0);

// Set DC for track A, loc 1
SETUP("<= A DC 1>");
// Create input buttons
SETUP("<S 20 170 pullup>");
// Create output LEDs for buttons iflag=011 inverted reset at power up
SETUP("<Z 21 171 3>");
// Setup time of flight sensor
//SETUP("<S 5000 5000 0>");
Sensor::create(5000, 5000, 0);