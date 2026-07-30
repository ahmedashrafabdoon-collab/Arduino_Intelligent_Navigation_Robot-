//right wheel


int in1 = 4;
int in2 = 5;


//left wheel


int in3 = 6;
int in4 = 7;




//------------------------THE SERVO-------------------------------------------------------------------------------------------------------------

#include <Servo.h>
float angle;
int dt = 500;
int servoPin = 12;

Servo myServo;




//---------------ALTRA SONIC-----------------------------------------------------------------------------------------------------

int echoPin = 10;
int trigPin = 11;
int PTT;
int distance;
int front;
int right;
int left;
int scanDelay = 800;
int max1;
int best;


//----------------MY FOUNCTIONS-------------------------------------------------------------------------------------------------


//STOP//

   void stop() {

  

   digitalWrite(in1, LOW);
   digitalWrite(in2, LOW);

   digitalWrite(in3, LOW);
   digitalWrite(in4, LOW);
   }    



 //GOFORWARD//

   void goForward() {


   digitalWrite(in1, HIGH);
   digitalWrite(in2, LOW);

   digitalWrite(in3, HIGH);
   digitalWrite(in4, LOW);
   }    

  //GOBACK//

  void goBack() {


   digitalWrite(in2, HIGH);
   digitalWrite(in1, LOW);

   digitalWrite(in4, HIGH);
   digitalWrite(in3, LOW);
   }    

   //TURN RIGHT//

    void turnRight() {

  

   digitalWrite(in1, LOW);
   digitalWrite(in2, HIGH);

   digitalWrite(in3, HIGH);
   digitalWrite(in4, LOW);
   }   


    //TURN LEFT//
 
   void turnLeft() {
    
   

   digitalWrite(in1, HIGH);
   digitalWrite(in2, LOW);

   digitalWrite(in3, LOW);
   digitalWrite(in4, HIGH);
   }    

    
    //GET DISTANCE//

    int getDistance() {

     digitalWrite(trigPin, LOW);
     delayMicroseconds(2);
     digitalWrite(trigPin, HIGH);
     delayMicroseconds(10);
     digitalWrite(trigPin, LOW);
     PTT = pulseIn(echoPin, HIGH);
     distance = PTT*0.0178571429;
     return distance;

    }



    //SCAN FRONT//

    int scanFront() {
     
    myServo.write(90);
    delay(300);
    getDistance();
    return front = distance;
    
    }

    //SCAN RIGHT//

     int scanRight() {

      myServo.write(0);
      delay(300);
      getDistance();
      return right = distance;

     }



     //SCAN LEFT//

     int scanLeft() {
     
      myServo.write(180);
      delay(300);
      getDistance();
      return left = distance;
    
     }
      
      


//-------------------------SETUP--------------------------------------------------------------------------------------------------
void setup() {
  // put your setup code here, to run once:
  
  //THE MOTORS:-


pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);



//THE SERVO//

pinMode(servoPin, OUTPUT);
myServo.attach(servoPin);
myServo.write(90);
//ALTRA SONIC:-

pinMode(echoPin, INPUT);
pinMode(trigPin, OUTPUT);

}





//---------------------LOOP------------------------------------------------------------------------------------------------------------------

void loop() {
  // put your main code here, to run repeatedly:



  
  



  //---------------------MOTORS DIRECTION----------------------------------------------------------------------------------------------------- 
 
 getDistance();

 if (distance > 15) {

  goForward();

 }else{
 
    stop();

  scanFront();
    delay(scanDelay);

  scanRight();
    delay(scanDelay);

  scanLeft();
    delay(scanDelay);

     myServo.write(90);


    max1 = max(front, right);
    best = max(max1 , left);

    if(best == front) {
     
     goForward();

    }else if (best == right) {

   stop();
   delay(300);
   turnRight();
   delay(300);
   goForward();

    }else if(best == left) {

    stop();
   delay(300);
   turnLeft();
   delay(300);
   goForward();

    }else if(front < 20 && right < 20 && left > 20){

   goBack();
   delay(500);
   return;

    }

 }

}








































