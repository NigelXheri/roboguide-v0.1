// L298 Motor Driver
const int E1 = 2; // Motor 1
const int E2 = 3; // Motor 2

const int M1 = 22; // Motor 1 direction
const int M2 = 23; // Motor 2 direction

// sensoret
// Ultrasonic Sensor
const int trigPin = 24;
const int echoPin = 25;

float duration, distance, distanceLeft, distanceRight;

// IR Sensor
const int i1 = 26;
const int i2 = 27;

// ndryshore per kalibrim
//const velocity
const int speed = 140;
const int speedTurning = 160;
const int speedTurning1 = 70;
const int speedTurning180 = 150;
const int speedTurningFast180 = 160;

//const delays
const int delayBeforeNormalTurn = 0;
const int timeTurning = 50;
const int timeBackword = 600;    //delay in miliseconds when going backword to avoid an obstacle
const int turn_90 = 300;    //delay in miliseconds to turn 90 degrees
const int timeOnCrosswalks = 1000;

//largesia nga ultrasoniku qe te ndalet
const int largesia = 15;



void setup()
{

  Serial.begin(9600);

  // L298 Motor Driver
  pinMode(E1, OUTPUT);
  pinMode(E2, OUTPUT);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);


  // Ultrasonic Sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);


  // IR Sensor
  pinMode(i1, INPUT);
  pinMode(i2, INPUT);
}




//============================================================================================================================================================

void loop()
{
  if(Serial.available()>0){
    char command = Serial.read();
    Serial.println(command);
    stop();
  }


  else{
    ultrasonic();
    
    if (distance >= largesia){
      Serial.print("larg");
      Serial.println(distance);
      if (infraredRight() && infraredLeft()){
          forward();
        }
      else if(infraredRight()==false && infraredLeft()) {
        delay(delayBeforeNormalTurn);
        right();
        delay(timeTurning);
      }
      else if(infraredRight() && infraredLeft()==false){
        delay(delayBeforeNormalTurn);
        left();
        delay(timeTurning);
      }
      else{
        stop();
        delay(500);
  
        ultrasonic();
        
        while (distance<largesia){
          stop();
          ultrasonic();
        }
  
        forward();
        delay(timeOnCrosswalks);
      }
    }
    else{
      Serial.print("afer ");
      Serial.println(distance);
      stop();
      delay(500);
  
      ultrasonic();
  
      if (distance<largesia){
        backword();
        delay(timeBackword);
        turning();
        delay(turn_90);
        while (infraredLeft()){
          turning();
        }
      }
    }
  }
}
  




// Sensor functions

int infraredRight(){
  int ir = digitalRead(i2);
  if (ir==0){
    return true;
  }
  else{
    return false;
  }
}

int infraredLeft(){
  int il = digitalRead(i1);
  if (il==0){
      return true;
    }
  else{
    return false;
  }
}

void ultrasonic(){

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  
}




//Movement modes

void stop(){
  digitalWrite(E1, LOW);
  digitalWrite(E2, LOW);
}

void forward(){

  digitalWrite(M1, LOW);
  digitalWrite(M2, LOW);
  analogWrite(E1, speed);
  analogWrite(E2, speed);

}

void left(){
  
  digitalWrite(M1, HIGH);
  digitalWrite(M2, LOW);
  analogWrite(E1, speedTurning1);
  analogWrite(E2, speedTurning);

}

void right(){
  
  digitalWrite(M1, LOW);
  digitalWrite(M2, HIGH);
  analogWrite(E1, speedTurning);
  analogWrite(E2, speedTurning1);

}

void turning(){
  
  digitalWrite(M1, LOW);
  digitalWrite(M2, HIGH);
  analogWrite(E1, speedTurning180);
  analogWrite(E2, speedTurning180);

}

void turningFast(){
  
  digitalWrite(M1, LOW);
  digitalWrite(M2, HIGH);
  analogWrite(E1, speedTurningFast180);
  analogWrite(E2, speedTurningFast180);

}

void backword(){
  
  digitalWrite(M1, HIGH);
  digitalWrite(M2, HIGH);
  analogWrite(E1, speed);
  analogWrite(E2, speed);
}