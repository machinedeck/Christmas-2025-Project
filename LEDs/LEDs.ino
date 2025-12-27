// #include <Scheduler.h>

const int pin1 = 3;
const int pin2 = 5;
const int pin3 = 9;
const int pin4 = 11;
const int buttonpin = 2;

int trend = 1;
int choice = 0;
volatile int mode = 0;
volatile long first_time = 0;
volatile int press = 0;
int alternate = 1;

int bright1 = 0;
int bright2 = 0;
int bright3 = 0;
int bright4 = 252;

// Set the millis
unsigned long previous_millis = 0;
const int interval = 20;
int light_increment = 3;
int light_increment_ = 0;
int brightness = 0;
bool stat = HIGH;
int stat_ = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(buttonpin, INPUT_PULLUP);
  Serial.begin(57600);
  attachInterrupt(digitalPinToInterrupt(buttonpin), mode_change, FALLING);
  // Scheduler.start(red_led);
  // Scheduler.start(yellow_led);
  // Scheduler.start(green_led);
  // Scheduler.start(blue_led);
}

// void red_led() {
//   triangle_light(pin1);
// }

// void green_led() {
//   triangle_light(pin2);
// }

// void yellow_led() {
//   triangle_light(pin3);
// }

// void blue_led() {
//   triangle_light(pin4);
// }
void loop() {
  // put your main code here, to run repeatedly:
  // triangle_light(pin1);
  // triangle_light(pin2);
  // triangle_light(pin3);
  // triangle_light(pin4);
  // int buttonstate  = digitalRead(buttonpin);
  // if (buttonstate == 0) {
  //   mode++;

  //   if (mode > 2) {
  //     mode = 0;
  //   }
  // }
  // attachInterrupt(digitalPinToInterrupt(buttonpin), mode_change, FALLING);
  // Serial.println(buttonstate);
  // Serial.println(buttonstate);
  // Serial.println(mode);

  unsigned long current_millis = millis();

  // if (Serial.available() > 0) {
  //   String content = Serial.readStringUntil("\n");
  //   choice = content.toInt();
  //   brightness = 0;
  //   stat = LOW;
  //   bright1 = 0;
  //   bright2 = 0;
  //   bright3 = 0;
  //   bright4 = 252;

  //   // if (choice == 0) {
  //   //   brightness = 0;
  //   // }

  //   // else if (choice == 0) {
  //   //   brightness = 0;
  //   // }

  // }

   if (press == 1) {
    // String content = Serial.readStringUntil("\n");
    // choice = content.toInt();
    brightness = 0;
    stat = LOW;
    bright1 = 0;
    bright2 = 0;
    bright3 = 0;
    bright4 = 252;
    press = 0;
    alternate = 1;
  }

  // if (choice == 0) {
  // if (current_millis - previous_millis >= interval) {
  //   previous_millis = current_millis;

    // if (trend = 1) {
    //   brightness = brightness + light_increment;
    // }
    // else if (trend = -1) {
    //   brightness = brightness - light_increment;
    // }
  // if (brightness < 0 || brightness > 249){
  //   light_increment = -light_increment;
  //   if (brightness < 0) {
  //     brightness = 3;
  //   }
  // }

  if (mode == 0) {
    if (current_millis - previous_millis >= 100) {
      previous_millis = current_millis;
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, LOW);
      digitalWrite(pin3, LOW);
      digitalWrite(pin4, LOW);
    }
  }

  // if (choice == 0) {
  if (mode == 1) {
    if (current_millis - previous_millis >= interval) {
    previous_millis = current_millis;
  // Serial.println(brightness);
    brightness += light_increment;

    // if (brightness < 0) {
    //   brightness = 0;
    //   light_increment = abs(light_increment);
    // }
    // else if (brightness > 252) {
    //   light_increment_ = - light_increment;
    // }
    if (brightness < 0 || brightness > 252){
      light_increment = -light_increment;
      if (brightness < 0) {
        brightness = 0;
      if (brightness > 252) {
        brightness = 252;
      }
      }
    }
      

      analogWrite(pin1, brightness);
      analogWrite(pin2, brightness);
      analogWrite(pin3, brightness);
      analogWrite(pin4, brightness);
  }
  }  

  // else if (choice == 1) {
  else if (mode == 2) {
    if (current_millis - previous_millis >= 250) {
    previous_millis = current_millis;
    stat = !stat;
    // stat = LOW;
    if (stat == LOW) {
      stat_ = 0;
    }
    else if (stat == HIGH) {
      stat_ = 252;
    }
    analogWrite(pin1, stat_);
    analogWrite(pin2, stat_);
    analogWrite(pin3, stat_);
    analogWrite(pin4, stat_);
    // stat = !stat; 
    }

  }

  // else if (choice == 2) {
  else if (mode == 3) {
    if (current_millis - previous_millis >= 250) {
    previous_millis = current_millis;

    if (bright1 == 252) {
      bright1 = 0;
      bright2 = 252;
      bright3 = 0;
      bright4 = 0;
    }

    else if (bright2 == 252) {
      bright1 = 0;
      bright2 = 0;
      bright3 = 252;
      bright4 = 0;
    }

    else if (bright3 == 252) {
      bright1 = 0;
      bright2 = 0;
      bright3 = 0;
      bright4 = 252;
    }

    else if (bright4 == 252) {
      bright1 = 252;
      bright2 = 0;
      bright3 = 0;
      bright4 = 0;
    }

    analogWrite(pin1, bright1);
    analogWrite(pin2, bright2);
    analogWrite(pin3, bright3);
    analogWrite(pin4, bright4);

    // if (bright1 == 252) {
    //   bright1 = 0;
    //   bright2 = 252;
    //   bright3 = 0;
    //   bright4 = 0;
    // }

    // else if (bright2 == 252) {
    //   bright1 = 0;
    //   bright2 = 0;
    //   bright3 = 252;
    //   bright4 = 0;
    // }

    // else if (bright3 == 252) {
    //   bright1 = 0;
    //   bright2 = 0;
    //   bright3 = 0;
    //   bright4 = 252;
    // }

    // else if (bright4 == 252) {
    //   bright1 = 252;
    //   bright2 = 0;
    //   bright3 = 0;
    //   bright4 = 0;
    // }


    }
  }
  else if (mode == 4) {
    current_millis = millis();
    if (current_millis - previous_millis >= 500) {
      previous_millis = current_millis;
      alternate = !alternate;
      // if (alternate == 0) {
      //   digitalWrite(pin1, !alternate);
      //   digitalWrite(pin2, alternate);
      //   digitalWrite(pin3, !alternate);
      //   digitalWrite(pin4, alternate);
      // }

      // else if (alternate == 1) {
      //   digitalWrite(pin1, alternate);
      //   digitalWrite(pin2, !alternate);
      //   digitalWrite(pin3, alternate);
      //   digitalWrite(pin4, !alternate);
      // }

      digitalWrite(pin1, alternate);
      digitalWrite(pin2, !alternate);
      digitalWrite(pin3, alternate);
      digitalWrite(pin4, !alternate);

      // alternate = !alternate;
      Serial.println(alternate);

    }
  }
    // if (brightness <= 0 ){
    //   brightness = 0;
    //   trend = 1;
    // }
    // else if (brightness >= 249 ){
    //   brightness = 249;
    //   trend = - 1;
    // }
    // if (brightness <= 0 || brightness >= 255) {
    //   brightness = 0;
    // }


  // }
  // Serial.println(brightness);
  // }

  // else if (choice == 1) {
  //   analogWrite(pin1, 252);
  //   delay(500);
  //   analogWrite(pin2, 252);
  //   delay(500);
  //   analogWrite(pin3, 252);
  //   delay(500);
  //   analogWrite(pin4, 252);
  //   delay(500);
  // }
  // Serial.print(trend);
}

// void triangle_light (int LED_pin){
//   for (int i = 0; i <= 75; i++){
//     analogWrite(LED_pin, i * 3);
//     delay(10);
//   }
//   for (int i = 75; i > 0; i--){
//     analogWrite(LED_pin, i * 3);
//     delay(10);
//   }
// }


// int triangle(int t){
//   return
// }
void mode_change() {
  // unsigned long curr_time = millis();

  // if (curr_time - first_time > 200) {  
    mode++;
    press = 1;

    if (mode > 4) {
      mode = 0;
    }

  //   first_time = curr_time;
  // }
}