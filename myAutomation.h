// Define Buttons
ALIAS(BTN1)
ALIAS(BT1_SW, 173)  // BT1 switch: GPB1 (schematic D109)
ALIAS(BT1_LED, 172) // BT1 LED: GPB0 (schematic D108)
//SIGNALH(BT1_LED, 0, 0)

// Define IrSensors
ALIAS(IR1, 33)     // IR1 connector: Mega D33
ALIAS(IR9, 35)     // IR9 connector: Mega D35
ALIAS(IR15, 29)

// Define Turnouts (Wissels)
ALIAS(WS1)
ALIAS(WS2)

// Define Routes
ALIAS(RT1)
ALIAS(RT2)

// Define Automations
ALIAS(AUTO1)

// Define locs
ROSTER(1,"Loco","DC")


// Define Turnouts
#define PULSE 50    // Pulse duration in milliseconds

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

// Turnout Controller 1: enable, input A, input B.
DUAL_COIL_TURNOUT(WS1, 44, 42, 38, "Wissel A")
DUAL_COIL_TURNOUT(WS2, 34, 36, 40, "Wissel B")

// Define Routes
ROUTE(RT1,"Station Platform 1")
    THROW(WS1)
    DELAY(PULSE)
    CLOSE(WS2)
    RETURN

ROUTE(RT2,"Station Platform 2")
    CLOSE(WS1)
    DELAY(PULSE)
    THROW(WS2)
    RETURN



AUTOSTART

// Set turnouts
CALL(RT1)
DELAY(PULSE)
CALL(RT2)
DELAY(PULSE)

START(BTN1)

RESET(BT1_LED)

DONE

// Turn on BT LEDs
SEQUENCE(BTN1)
    IF(BT1_SW)
        SET(BT1_LED)
        IFCLOSED(WS1)
            CALL(RT1)
        ELSE
            CALL(RT2)
        ENDIF
        DELAY(5000)
        RESET(BT1_LED)
    ENDIF
    DELAY(100) 
    FOLLOW(BTN1)

AUTOMATION(AUTO1, "Test Automation")
    FWD(60)
    AFTER(IR9)
    FWD(90)
    AT(IR15)
    FWD(50)
    AT(IR9)
    STOP
    DELAYRANDOM(3000,10000)
    FOLLOW(AUTO1)
