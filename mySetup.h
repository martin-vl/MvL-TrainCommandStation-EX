// set enable pins of turnout low/off
IODevice::write(168, 0);
IODevice::write(169, 0);

// Set DC for track A, loc 1
SETUP("<= A DC 1>");
SETUP("<S 20 170 pullup>");

Sensor::create(5000, 5000, 0);