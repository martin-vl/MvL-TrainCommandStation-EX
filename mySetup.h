// set enable pins of turnout low/off
IODevice::write(168, 0);
IODevice::write(169, 0);

// Set DC for track A, loc 1
SETUP("<= A DC 1>");
// Create input buttons
SETUP("<S 20 170 pullup>");
// Create output LEDs for buttons
SETUP("<Z 21 171 100>");

Sensor::create(5000, 5000, 0);