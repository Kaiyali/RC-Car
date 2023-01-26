#include <IRremote.h>
#include <Stepper.h>

const int stepsPerRevolution = 2038;

Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);

IRrecv IR(3);
int motor = 6;
int motorR = 5;

void setup() {
 pinMode(motor, OUTPUT);
 pinMode(motorR, OUTPUT);
 pinMode(13,OUTPUT);
 pinMode(14,OUTPUT);

IR.enableIRIn();
Serial.begin(9600);
}

void loop() {
 
    if (IR.decode()) {
        Serial.println (IR.decodedIRData.decodedRawData, HEX);
    if (IR.decodedIRData.decodedRawData == 0xE718FF00){
        digitalWrite(motor, HIGH);
    }else{
        digitalWrite(motor, LOW);
    }
    if (IR.decodedIRData.decodedRawData == 0xAD52FF00){
        digitalWrite(motorR, HIGH);
    }else{
        digitalWrite(motorR, LOW);
    }
    if (IR.decodedIRData.decodedRawData == 0xA55AFF00){
        myStepper.setSpeed(5);
        myStepper.step(-150);
    }
    if (IR.decodedIRData.decodedRawData == 0xF708FF00){
        myStepper.setSpeed(5);
        myStepper.step(150);
    }
    delay(1500);
    IR.resume();
    }
}
