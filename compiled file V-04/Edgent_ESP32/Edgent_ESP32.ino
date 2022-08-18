
//-------------------code----------------------
//THIS WAS MAINLY THE CODE FOR BLYNK, TO ADD REMOTE CONTROL FEATURE , THE CODE FOR
//IR REMOTE CONTROL USING ESP-32 WAS PASTE PART BY PART

//paste this code after opening, file > exmple > blynk> blynk.edgent>ESP32


// same template has been used here, cz, creating another templare requires another new
//device connetion for the same device

// update 03 july:
// now the OLED display will be controlled using the same remote
//AND BLYNK (total six button will be in BLYNK too)
// for this, the the down and enter button will be used W.R.T pin G-12 and G-14
#define BLYNK_TEMPLATE_ID "TMPL4uqmGCRy"
#define BLYNK_DEVICE_NAME "testtt"
#define BLYNK_FIRMWARE_VERSION        "0.1.0"
#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG
#define APP_DEBUG
// Uncomment your board, or configure a custom board in Settings.h
//#define USE_WROVER_BOARD
#include "BlynkEdgent.h"


//--------------------------------------
#include <IRremote.h>
//setup fucntion for IR remote starts here
int IR_Recv = 15; //IR Receiver Pin 15
IRrecv irrecv(IR_Recv,HEX);
decode_results results;
//
void setupForIrRemote(){
    pinMode(16, OUTPUT);
    pinMode(19, OUTPUT);
    pinMode(21, OUTPUT);
    pinMode(22, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(14, OUTPUT);
  Serial.begin(115200); //starts serial communication
  irrecv.enableIRIn(); // Starts the receiver
  }
//setup function for IR remote ends here
//--------------------------------------

BLYNK_WRITE(V16){       // this function is dedicated for pin 16, which will run in loo() function
  int pinValue16 = param.asInt();     //this param.asInt()has been used to store the incoming data
  if(pinValue16 != 1){
    digitalWrite(16,LOW);
    }
  else
  {
    digitalWrite(16,HIGH);
    }
  }



BLYNK_WRITE(V19){       // this function is dedicated for pin 19, which will run in loo() function
  int pinValue19 = param.asInt();     //this param.asInt()has been used to store the incoming data
  if(pinValue19 != 1){
    digitalWrite(19,LOW);
    }
  else
  {
    digitalWrite(19,HIGH);
    }
  }



  BLYNK_WRITE(V21){       // this function is dedicated for pin 21, which will run in loo() function
  int pinValue21 = param.asInt();     //this param.asInt()has been used to store the incoming data
  if(pinValue21 != 1){
    digitalWrite(21,LOW);
    }
  else
  {
    digitalWrite(21,HIGH);
    }
  }


BLYNK_WRITE(V22){        // this function is dedicated for pin 21, which will run in loo() function
  int pinValue22 = param.asInt();         //this param.asInt()has been used to store the incoming data
  if(pinValue22 != 1){
    digitalWrite(22,LOW);
    }
  else
  {
    digitalWrite(22,HIGH);
    }
}


BLYNK_WRITE(V12){        // this function is dedicated for pin 12, which will run in loo() function
  int pinValue12 = param.asInt();         //this param.asInt()has been used to store the incoming data
  if(pinValue12 != 1){
    digitalWrite(12,LOW);
    }
  else
  {
    digitalWrite(12,HIGH);
    }
}


BLYNK_WRITE(V14){        // this function is dedicated for pin 14, which will run in loo() function
  int pinValue14 = param.asInt();         //this param.asInt()has been used to store the incoming data
  if(pinValue14 != 1){
    digitalWrite(14,LOW);
    }
  else
  {
    digitalWrite(14,HIGH);
    }
}









void setup()
{
  setupForIrRemote(); // IR remote setup
  
  pinMode(16,OUTPUT);
  pinMode(19,OUTPUT);
  pinMode(21,OUTPUT);
  pinMode(22,OUTPUT);
  Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();
}


//--------------------------------------
//Loop function for IR remote starts here
void loopForIrRemote(){
    if (irrecv.decode(&results)){
    long int decCode = results.value;
    Serial.println(decCode);
    if (results.value == 16753245) //on button for 16
    {
      digitalWrite(16, HIGH);
      Serial.println("LED turned ON");
    }
    
    if (results.value == 16712445) //off button for 16
    {
      digitalWrite(16, LOW);
    }

        if (results.value == 16736925) //on button for 19
    {
      digitalWrite(19, HIGH);
    }
    
    if (results.value == 16761405) //off button for 19
    {
      digitalWrite(19, LOW);
    }

        if (results.value == 16769565) //on button for 21
    {
      digitalWrite(21, HIGH);
    }
    
    if (results.value == 16769055) //off button for 21
    {
      digitalWrite(21, LOW);
    }

        if (results.value == 16720605) //on button for 22
    {
      digitalWrite(22, HIGH);
    }
    
    if (results.value == 16754775) //off button for 22
    {
      digitalWrite(22, LOW);
    }

    
        if (results.value == 16730805) //down button for 12
    {
      digitalWrite(12, HIGH);
      //delay(200);
      digitalWrite(12,LOW);
    }

        if (results.value == 16726215) //ENTER or OK button for 14
    {
      digitalWrite(14, HIGH);
      digitalWrite(14,LOW);
    }
    
    irrecv.resume();
  }
  }
//Loop function for IR remote ends here
//------------------------------------------------

void loop() {
  loopForIrRemote();
  BlynkEdgent.run();
}
