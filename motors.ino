
const int MotorPinA = 4; // direction motor 1 (Channel A)
const int MotorSpeedPinA = 5; // for motor 1 (channel A)



const int MotorPinB = 7; // direction motor 2 (Channel B)
const int MotorSpeedPinB = 6;// for motor 2 (channel B)


const int CW  = HIGH;
const int CCW = LOW;

void setup() {
  // motor A pin assignment
  pinMode(MotorPinA, OUTPUT);
  pinMode(MotorSpeedPinA, OUTPUT);


  // motor B pin assignment
  pinMode(MotorPinB, OUTPUT);
  pinMode(MotorSpeedPinB, OUTPUT);

  Serial.begin(9600);//  seial monitor initialized 

}

void loop() {


  moveMotor('B', CCW, 250); 
  moveMotor('A', CCW, 250);
  
Serial.println("===== loop "); 

}// loop end




void moveMotor(char motor, int dir, int speed)
{
  int motorPin;
  int motorSpeedPin;
  
  if(motor =='A')
  {
    motorPin      = MotorPinA;
    motorSpeedPin = MotorSpeedPinA;  
  }else{
    motorPin      = MotorPinB;
    motorSpeedPin = MotorSpeedPinB;     
  }
   digitalWrite(motorPin, dir);// set direction for motor
   analogWrite(motorSpeedPin, speed);// set speed of motor   
}//moveMotor end

/*
 * for function is to be used with DFRobot Motor Shield
 * brake, stops the motor
 * @param motor is character A or B
 * example of usage:
 * brake('A');// stops motor A
 * brake('B');// stops motor B
 */
void brake(char motor)
{
  if(motor =='A')
  {
    digitalWrite(MotorSpeedPinA, 0);// stop motor A
    delay(1000);
  }else{
    digitalWrite(MotorSpeedPinB, 0);// stop motor B
    delay(1000);
   
  }
}// brake end
