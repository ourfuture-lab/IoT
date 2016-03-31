/*
* Getting Started example sketch for nRF24L01+ radios
* This is a very basic example of how to send data from one node to another
* Updated: Dec 2014 by TMRh20
*/

#include <SPI.h>
#include "RF24.h"

/****************** User Config ***************************/
/***      Set this radio as radio number 0 or 1         ***/
bool radioNumber = 1;

/* Hardware configuration: Set up nRF24L01 radio on SPI bus plus pins 7 & 8 */
RF24 radio(7,8);
/**********************************************************/

byte addresses[][6] = {"1Node","2Node"};

// Used to control whether this node is sending or receiving
bool role = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println(F("RF24/examples/recive"));

  radio.begin();

  // Set the PA Level low to prevent power supply related issues since this is a
  // getting_started sketch, and the likelihood of close proximity of the devices. RF24_PA_MAX is default.
  radio.setPALevel(RF24_PA_LOW);

  // Open a writing and reading pipe on each radio, with opposite addresses
  // recive
  radio.openWritingPipe(addresses[1]);
  radio.openReadingPipe(1, addresses[0]);


  // Start the radio listening for data
  radio.startListening();
}


void loop() {
  // put your main code here, to run repeatedly:
 unsigned long got_time;
    
    if( radio.available()){                                         // Variable for the received timestamp
      while (radio.available()) {                                   // While there is data ready
        radio.read( &got_time, sizeof(unsigned long) );             // Get the payload
      }
     
     // radio.stopListening();                                        // First, stop listening so we can talk   
     // radio.write( &got_time, sizeof(unsigned long) );              // Send the final one back.      
     // radio.startListening();                                       // Now, resume listening so we catch the next packets.     
      Serial.print(F("recive "));
      Serial.println(got_time);  
   }
}
