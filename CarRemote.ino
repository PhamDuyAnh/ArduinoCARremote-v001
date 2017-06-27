/*
* Create: 2017-06-27 by CKD - Pham Duy Anh - phamduyanh@gmail.com
*
* Arduino UNO -> L298 module
* Pin 2       -> IN4
* Pin 3       -> IN3
* Pin 4       -> IN1
* Pin 5       -> IN2
* Pin 9  ~    -> ENA    PWM for speed control motor A
* Pin 10 ~    -> ENB    PWM for speed control motor B
*
* Use SoftwareSerial for communication to Bluetooth module
* Arduino UNO -> HC-05 Bluetooth module
* A4 (Tx)     -> Rx
* A5 (Rx)     -> Tx
* 5V          -> Vcc
* Gnd         -> Gnd
*/

#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5
#define SP1 9
#define SP2 10

#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(A5, A4); // RX, TX

char cmd;
int sp = 70;

void setup()
{
  Serial.begin(115200);
  Bluetooth.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(SP1, OUTPUT);
  pinMode(SP2, OUTPUT);
  motor(0, 0);
}

void loop()
{
  if (Bluetooth.available())
  {
    cmd = Bluetooth.read();
    switch (cmd)
    {
      default:
        motor(0, 0);
        break;
      case 'S':
        motor(0, 0);
        break;
      case 'F':
        motor(1, 1);
        break;
      case 'B':
        motor(-1, -1);
        break;
      case 'L':
        motor(-1, 1);
        break;
      case 'R':
        motor(1, -1);
        break;
      case 'I':
        motor(1, 0);
        break;
      case 'G':
        motor(0, 1);
        break;
      case 'H':
        motor(0, -1);
        break;
      case 'J':
        motor(-1, 0);
        break;
      case '1':
        sp = 1*20 + 50;
        break;
      case '2':
        sp = 2*20 + 50;
        break;
      case '3':
        sp = 3*20 + 50;
        break;
      case '4':
        sp = 4*20 + 50;
        break;
      case '5':
        sp = 5*20 + 50;
        break;
      case '6':
        sp = 6*20 + 50;
        break;
      case '7':
        sp = 7*20 + 50;
        break;
      case '8':
        sp = 8*20 + 50;
        break;
      case '9':
        sp = 9*20 + 50;
        break;
      case 'q':
        sp = 10*20 + 50;
        break;
    } 
    Serial.println(cmd);
    Serial.println(sp);
    analogWrite(SP1, sp);
    analogWrite(SP2, sp);
  }
}

void motor(int motor1, int motor2)
{
  switch (motor1)
  {
    case 0:
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      break;
    case 1:
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      break;
    case -1:
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      break;
    default:
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      break;    
  }
  switch (motor2)
  {
    case 0:
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      break;
    case 1:
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      break;
    case -1:
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      break;
    default:
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      break;    
  }  
}
