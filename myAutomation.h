// Define Buttons
ALIAS(BTN1)
ALIAS(BT1_SW, 170)
ALIAS(BT1_LED, 171)
//SIGNALH(BT1_LED, 0, 0)

// Define Turnouts (Wissels)
ALIAS(WS1)
ALIAS(WS2)

// Define Routes
ALIAS(RT1)
ALIAS(RT2)


// Define Turnouts
#define PULSE 1000    // Set the duration of the pulse to 10ms

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

DUAL_COIL_TURNOUT(WS1, 47, 39, 41, "Wissel A")
DUAL_COIL_TURNOUT(WS2, 49, 43, 45, "Wissel B")

// Define Routes
ROUTE(RT1,"Station Platform 1")
    THROW(WS1)
    THROW(WS2)
    DONE

ROUTE(RT2,"Station Platform 2")
    CLOSE(WS1)
    CLOSE(WS2)
    DONE



AUTOSTART

RESET(BT1_LED)

START(BTN1)

DONE

// Turn on BT LEDs
SEQUENCE(BTN1)
    IFCLOSED(WS1)
        CALL(RT1)
    ELSE
        CALL(RT2)
    ENDIF
    DELAY(100) 
    FOLLOW(BTN1)


