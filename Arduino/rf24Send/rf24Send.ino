/*
* Getting Started example sketch for nRF24L01+ radios
* This is a very basic example of how to send data from one node to another
* Updated: Dec 2014 by TMRh20
*/

#include <SPI.h>
#include "RF24.h"



/* Hardware configuration: Set up nRF24L01 radio on SPI bus plus pins 7 & 8 */
RF24 radio(7,8);
/**********************************************************/

byte addresses[][6] = {"1Node","2Node"};

// Used to control whether this node is sending or receiving

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println(F("RF24/examples/send"));

  radio.begin();

  // Set the PA Level low to prevent power supply related issues since this is a
  // getting_started sketch, and the likelihood of close proximity of the devices. RF24_PA_MAX is default.
  radio.setPALevel(RF24_PA_LOW);

  // Open a writing and reading pipe on each radio, with opposite addresses
  // send
  radio.openWritingPipe(addresses[0]);
  radio.openReadingPipe(1, addresses[1]);


  // Start the radio listening for data
  radio.stopListening();
}
unsigned long start_time = 1; 

void loop() {
  // put your main code here, to run repeatedly:
  /****************** Ping Out Role ***************************/


    //Serial.println(F("Now sending"));
                        // Take the time, and send it.  This will block until complete
        
    bool iswirte= radio.write( &start_time, sizeof(unsigned long) );
     Serial.print(iswirte);
    if (!iswirte) {
      Serial.println(F("failed"));
    }
     Serial.print(";start_time=");
     Serial.println(start_time);
    start_time++;

    // Try again 1s later
    delay(1000);
 
}
