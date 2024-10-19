// Define Buttons
ALIAS(BTN1)
ALIAS(BT1_SW, 170)
ALIAS(BT1_LED, 171)
//SIGNALH(BT1_LED, 0, 0)


// Define Turnouts
#define PULSE 200    // Set the duration of the pulse to 10ms

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

DUAL_COIL_TURNOUT(1, 47, 39, 41, "Wissel A")
DUAL_COIL_TURNOUT(2, 49, 43, 45, "Wissel B")



AUTOSTART

START(BTN1)

DONE

// Turn on BT LEDs
SEQUENCE(BTN1)
    IF(-BT1_SW)
        SET(BT1_LED)
    ELSE
        RESET(BT1_LED)
    ENDIF
    DELAY(100) 
    FOLLOW(BTN1)


