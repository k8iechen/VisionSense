#include <AccelStepper.h>
#include <Bounce2.h>

#define HALFSTEP 4

// Motor pin definitions
#define RmotorPin1  8    // connected to IN1 on the ULN2003 driver 1
#define RmotorPin2  10    // connected to IN2 on the ULN2003 driver 1
#define RmotorPin3  11    // connected to IN3 on the ULN2003 driver 1
#define RmotorPin4  12    // connected to IN4 on the ULN2003 driver 1
 
  int distanceF = 0;
  int distanceR = 0;
  int distanceL = 0;
  int distanceB = 0;
  int delayL = 0;
  int delayR - 0;
  int delayB = 0;

Bounce Rdebouncer = Bounce();
AccelStepper stepper1(HALFSTEP, RmotorPin1, RmotorPin3, RmotorPin2, RmotorPin4);

//step1 for Right, step2 for Left, step3 for back

  
void setup() {
  stepper1.setMaxSpeed(500.0);
  stepper1.setAcceleration(10000.0);
  stepper1.setSpeed(500.0);
  debouncer.interval(delayR); // interval in ms
  
  Serial.begin(9600);
}


void input(int distanceA, int distanceR, int distanceL){
  distanceF = distanceA;
  distanceR = distanceB;
  distanceL = distanceC;
}

void occilate (int delay1){
  stepper1.run();
  delay(10);
  //current = -current;
  
}

void loop() {
  void input();
  debouncer.update();
  int value = debouncer.fell();
  
  if (distanceR >300){
    //motor off
  }
  else if {distanceR <100){
    delayR = 50;
    occilate(delayR);
  }
   //motor on
  else{
   delayF = distanceR/2;
    occilate(delayR);
  }

  



}
