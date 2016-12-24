// transmitter.pde
//
// Simple example of how to use VirtualWire to transmit messages
// Implements a simplex (one-way) transmitter with an TX-C1 module


#include <VirtualWire.h>

void setup() {
    Serial.begin(9600);			// Debugging only
    Serial.println("setup");	// Prints "Setup to the serial monitor"

    vw_set_tx_pin(4);			// Sets pin D12 as the TX pin
    vw_set_ptt_inverted(true);	// Required for DR3100
    vw_setup(4000);				// Bits per sec
}

void loop() {
    const char *msg = "hello";	// Message to be sent
	
    digitalWrite(13, true);		// Flash a light to show transmitting
    vw_send((uint8_t *)msg, strlen(msg)); //Sending the message
    vw_wait_tx();				// Wait until the whole message is gone

    Serial.println(*msg);
    digitalWrite(13, false);	// Turn the LED off.
    delay(200);					// A short gap.
} 
