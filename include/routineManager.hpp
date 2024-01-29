#pragma once

#include "event.hpp"
#include "pump.hpp"
#include "flowManager.hpp"

class RoutineManager {
    public:
        void init(bool test);
        Event* buildTestRoutine();
        void run(Event* head);
        void deleteRoutine(Event* head);

        // Callback functions to be used by ModbusMaster
        static void postTransmission();
        static void preTransmission();

    private:
        // Receive and transmit pins for the MAX485
        const int MODBUS_RX = 16;
        const int MODBUS_TX = 17;
        static const int MAX485_DE = 18;
        static const int MAX485_RE_NEG = 19;

        FlowManager* f;
        Pump* p;
        ModbusMaster controller;
};