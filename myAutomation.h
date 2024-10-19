// Define Buttons
ALIAS(BTN1)
ALIAS(BT1_SW, 20)
//ALIAS(BT1_LED, 21)
//SIGNALH(BT1_LED, 0, 0)


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


ONCHANGE(BT1_SW)
    IF(-170)
        SET(171)
    ELSE
        RESET(171)
    ENDIF
    DONE

AUTOSTART

RESET(168)
RESET(169)

//START(BTN1)

DONE

// Turn on BT LEDs
SEQUENCE(BTN1)
    IF(-170)
        SET(171)
    ELSE
        RESET(171)
    ENDIF
    DELAY(100) 
    FOLLOW(BTN1)


