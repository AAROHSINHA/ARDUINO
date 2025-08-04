int ea = 5;
int pin1 = 6;
int pin2 = 7;
int pin3 = 8;
int pin4 = 9;
int eb = 10;

#define FORWARD_SPEED 210
#define LEFT_MOTOR_ONLY_SPEED 100
#define RIGHT_MOTOR_ONLY_SPEED 100
#define ALTERNATE_SPEED 40
#define GRADUAL_START_LIMIT 150

void move_forward(){
  analogWrite(ea, FORWARD_SPEED);
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, LOW);
  analogWrite(eb, FORWARD_SPEED);
  digitalWrite(pin3, HIGH);
  digitalWrite(pin4, LOW);
}

void turn_left(){
  analogWrite(ea, RIGHT_MOTOR_ONLY_SPEED);
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, LOW);
  analogWrite(eb, 0);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
}

void turn_right(){
  analogWrite(eb, LEFT_MOTOR_ONLY_SPEED);
  digitalWrite(pin3, HIGH);
  digitalWrite(pin4, LOW);
  analogWrite(ea, 0);
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
}

void gradual_start(int finalSpeed, int step = 10, int delayTime = 50) {
  for (int speed = 0; speed <= finalSpeed; speed += step) {
    analogWrite(ea, speed);
    analogWrite(eb, speed);
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, HIGH);
    digitalWrite(pin4, LOW);
    delay(delayTime);
  }
}
