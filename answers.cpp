// question-01
// answer:
// A parts manifesto is a detailed list of each and every part included in the shipment. Parts manifestos are made by the creators/manufacturers of complex machines (such as robots) and sent to institutions that order such machines. The receiving institution cross checks each and every part received with the manifesto to ensure nothing is missing.


// question-02
// answer:
// Typically, an institution will complete a full inventory of the shipped parts using the parts manifesto. Then they will individually test each component that requires testing to ensure full functionality. If anything goes wrong, they’ll troubleshoot with the manufacturers of the robot, the writers of the software, etc. Next, they build the subsystems of the robot/machine testing each subsystem along the way to ensure correct functionality and communication between parts. Then they assemble the entire robot/machine for its intended use. If any aftermarket modifications are needed, they’ll engineer, build, and incorporate those as needed. Finally, they perform a suite of final tests before deploying the robot/machine for live use.

// question-03
int main() {
    int day;
    int month;
    int year;
    std::cout << "Enter your birthdate as 'day month year'.\nUse two digits for the day and month, and four digits for the year:\n";
    std::cin >> day >> month >> year;
    int currentYear = 2023;

    if (currentYear - year < 50) {
        std::cout << "You will turn 50 in the year: " << year + 50 << std::endl;
    } else {
        std::cout << "You're already 50 or older." << std::endl;
    }
} 

// question-04
int main() {
  int num;
  std::cout << "Enter a positive integer: ";
  std::cin >> num;
  std::cout << "The distinct factors of " << num << " are: ";
  for (int i = 1; i <= num; i++) {
      if (num % i == 0) {
          std::cout << i << " ";
      }
  }
}

// question-05
#include <Servo.h>

Servo leftMotor;
Servo rightMotor;

void setup() {
// put your setup code here, to run once:
leftMotor.attach(10);
rightMotor.attach(11);

leftMotor.writeMicroseconds(1700);
rightMotor.writeMicroseconds(1700);
delay(1000);

leftMotor.writeMicroseconds(1500);
rightMotor.writeMicroseconds(1500);

leftMotor.writeMicroseconds(1300);
rightMotor.writeMicroseconds(1700);
delay(1000);

leftMotor.writeMicroseconds(1500);
rightMotor.writeMicroseconds(1500);
}


// question-06
// answer:
// 6. A pixel is (most often) an individual LED or other light-emitting object that emits a single color at a time. (Accept answers that describe pixels as tiny little portions of an images, each of which can only have one color at a time.) Pixels on a screen are arranged in a rectangular array.

// question-07
// answer:
// 7. A “blob” is a group of adjacent similarly-colored pixels. The term ‘blob data’ refers to one way that computers break up images to help understand them: by identifying and reacting to blobs.


// question-08
#include <Servo.h>              // Servo Library
#include <Pixy2.h>              // PixyCam Library

Servo leftMotor;
Servo rightMotor;
Pixy2 pixy;                     // PixyCam object

#define forward 410
#define slowForward 490
#define backward 590
#define slowBackward 510
#define stopServo 500

#define centerX 158
#define offsetX 25

void setup() {
  leftMotor.attach(10);
  rightMotor.attach(11);
  Serial.begin(115200);
  Serial.print("Starting..\n");
  pixy.init();
}

void loop() { 
  int i;
  
  // Grab signature blobs             
  pixy.ccc.getBlocks();   

  // Print blob data to Serial Monitor
  Serial.print("Detected ");
  Serial.println(pixy.ccc.numBlocks);
  for (i=0; i<pixy.ccc.numBlocks; i++) {
    Serial.print("  block ");
    Serial.print(i);
    Serial.print(": ");
    pixy.ccc.blocks[i].print();
  }
  
  // If the signature is towards right of view..
  if (pixy.ccc.blocks[0].m_x > centerX + offsetX) {
    
    // ..robot moves right 
    pixy.setServos(backward, stopServo);

  // If the signature is towards left of view..
  } else if (pixy.ccc.blocks[0].m_x < centerX - offsetX) {
    
    // ..robot moves left 
    pixy.setServos(stopServo, forward);

  } else {
    
    // ..robot moves straight
    pixy.setServos(backward, forward);
  }
}



