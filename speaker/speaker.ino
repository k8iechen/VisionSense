#define NOTE_C2  65
#define NOTE_E2  82
#define NOTE_G2  98
int distanceF = 0;

void input(int distance){
  distanceF =distance;
}
int speaker = 23;

void notars (int note){
  tone(speaker, note);
  delay (500);
  noTone(speaker);
  delay (500);
}


void setup() {
  // put your setup code here, to run once:
  pinMode(speaker, OUTPUT)
}

void loop() {
 input(int distance);
 
 if(distanceF==3){ //Closest
  notars(NOTE_G2);
 }
 if(distanceF==2){
  notars(NOTE_E2);
 }
 if(distanceF==1){
  notars(NOTE_C2);
 }
 if(distanceF==0){
  noTone(speaker);
 }
}
