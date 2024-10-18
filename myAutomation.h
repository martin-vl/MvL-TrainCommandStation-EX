// Define Buttons
ALIAS(BT1_SW, 20)
ALIAS(BT1_LED, 21)
//SIGNALH(BT1_LED, 0, 0)

// Turn on BT LEDs
AT(BT1_SW) \
SET(BT1_LED) \
DONE

AT(-BT1_SW) \
RESET(BT1_LED) \
DONE

// Define Turnouts
#define PULSE 20    // Set the duration of the pulse to 10ms

#define DUAL_COIL_TURNOUT(id, en, in1, in2, desc) \
VIRTUAL_TURNOUT(id, desc) \
DONE \
ONCLOSE(id) \
RESET(in2) SET(in1) \
SET(en) DELAY(PULSE) RESET(en) \
DONE \
ONTHROW(id) \
RESET(in1) SET(in2) \
SET(en) DELAY(PULSE) RESET(en) \
DONE

DUAL_COIL_TURNOUT(1, 168, 164, 165, "Wissel A")
DUAL_COIL_TURNOUT(2, 169, 166, 167, "Wissel B")


