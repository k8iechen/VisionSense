#include <Bounce2.h>

#include <AccelStepper.h>

int r =1;


#define HALFSTEP 4
// Motor pin 1 definitions
#define motorPin1  4    // connected to IN1 on the ULN2003 driver 1
#define motorPin2  5   // connected to IN2 on the ULN2003 driver 1
#define motorPin3  6    // connected to IN3 on the ULN2003 driver 1
#define motorPin4  7    // connected to IN4 on the ULN2003 driver 1

// Motor pin 2 definitions
#define motorPin5  4    // connected to IN1 on the ULN2003 driver 1
#define motorPin6  5   // connected to IN2 on the ULN2003 driver 1
#define motorPin7  8    // connected to IN3 on the ULN2003 driver 1
#define motorPin8  9    // connected to IN4 on the ULN2003 driver 1

// Motor pin 3 definitions
#define motorPin9  4    // connected to IN1 on the ULN2003 driver 1
#define motorPin10 5   // connected to IN2 on the ULN2003 driver 1
#define motorPin11 2    // connected to IN3 on the ULN2003 driver 1
#define motorPin12 3    // connected to IN4 on the ULN2003 driver 1

// Instantiate a Bounce object
Bounce debouncer = Bounce(); 

#define BUTTON_PIN 13

// Initialize with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper with 28BYJ-48
AccelStepper stepper1(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);
AccelStepper stepper2(HALFSTEP, motorPin5, motorPin6, motorPin7, motorPin8);
AccelStepper stepper3(HALFSTEP, motorPin9, motorPin10, motorPin11, motorPin12);


void setup() {

  Serial.begin(9600);

  
  stepper1.setMaxSpeed(500.0);
  stepper1.setAcceleration(10000.0);
  stepper1.setSpeed(500.0);

  stepper2.setMaxSpeed(500.0);
  stepper2.setAcceleration(10000.0);
  stepper2.setSpeed(500.0);

  stepper3.setMaxSpeed(500.0);
  stepper3.setAcceleration(10000.0);
  stepper3.setSpeed(500.0);

  
  // Setup the button with an internal pull-up :
  pinMode(BUTTON_PIN,INPUT_PULLUP);

  // After setting up the button, setup the Bounce instance :
  debouncer.attach(BUTTON_PIN);
  debouncer.interval(5); // interval in ms
}

void loop() {

  
  // Update the Bounce instance :
  debouncer.update();

  // Get the updated value :
  int value = debouncer.fell();
  
  
  // Turn on or off the LED as determined by the state :
  if (stepper1.distanceToGo() == 0 && Serial.available()) {
    r=Serial.read()-'0';
    stepper1.moveTo(stepper1.currentPosition()+(r*100));
  } 
  
  stepper1.run();

  // Turn on or off the LED as determined by the state :
  if (value == HIGH && stepper2.distanceToGo() == 0) {
    stepper2.moveTo(stepper2.currentPosition()+0);
  } 
  
  stepper2.run();


  // Turn on or off the LED as determined by the state :
  if (value == HIGH && stepper3.distanceToGo() == 0) {
    stepper3.moveTo(stepper3.currentPosition()+000);
  } 
  
  stepper3.run();

  
}
