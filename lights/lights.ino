// Set the pin numbers
// The following pins allow PWM
const int pin1 = 3;
const int pin2 = 5;
const int pin3 = 9;
const int pin4 = 11;
// The pin below allows interrupts
const int buttonpin = 2;


int trend = 1;
int choice = 0;
volatile int mode = 0;
volatile long first_time = 0;
volatile int press = 0;
int alternate = 1;
int option = 0;

int bright1 = 0;
int bright2 = 0;
int bright3 = 0;
int bright4 = 252;

// Set the millis
unsigned long previous_millis = 0;
// unsigned long prev_millis = 0;
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
 
}


void loop() {
  // put your main code here, to run repeatedly:
  
  unsigned long current_millis = millis();


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
    option = 0;
  }

  options(current_millis, mode);
}

void option0 (unsigned long current_millis) {
  // static unsigned long previous_millis = 0;
  if (current_millis - previous_millis >= 100) {
    previous_millis = current_millis;
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, LOW);
    digitalWrite(pin4, LOW);
  }
}

void option1 (unsigned long current_millis) {
  // static int brightness = 0;
  // static int light_increment = 3;
  // static unsigned long previous_millis = 0;

  if (current_millis - previous_millis >= interval) {
    previous_millis = current_millis;
    brightness += light_increment;
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

void option2 (unsigned long current_millis) {
  static unsigned long previous_millis = 0;
  static bool stat = HIGH;

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
  }
}

void option3 (unsigned long current_millis) {
  // static unsigned long previous_millis = 0;
  // static int bright1 = 0;
  // static int bright2 = 0;
  // static int bright3 = 0;
  // static int bright4 = 252;

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
  }
}

void option4 (unsigned long current_millis) {
  // static unsigned long previous_millis = 0;
  // static int alternate = 1;

  if (current_millis - previous_millis >= 500) {
    previous_millis = current_millis;
    // alternate = !alternate;

    digitalWrite(pin1, alternate);
    digitalWrite(pin2, !alternate);
    digitalWrite(pin3, alternate);
    digitalWrite(pin4, !alternate);
    alternate = !alternate;
  }
}

void option5 (unsigned long current_millis) {
  static unsigned long prev_millis = 0;
  // static int option = 1;
  // unsigned long curr_millis = millis();
  if (current_millis - prev_millis >= 9000) {
    option++;
    if (option > 4) {
      option = 1;
    }
    prev_millis = current_millis;
    // Serial.println(option);
  }
  switch (option) {
    // case 0: 
    //   option0(current_millis);
    case 1: 
      option1(current_millis);
      break;
    case 2: 
      option2(current_millis);
      break;
    case 3: 
      option3(current_millis);
      break;
    case 4: 
      option4(current_millis);
      break;
  }
    // option++;
    // if (option > 4) {
    //   option = 1;
    // }
    // prev_millis = current_millis;
    Serial.println(option);
  // }

}

void options (unsigned long current_millis, int mode) {
  if (mode == 0) {
    option0(current_millis);
  }
  else if (mode == 1) {
    option1(current_millis);
  }
  else if (mode == 2) {
    option2(current_millis);
  }
  else if (mode == 3) {
    option3(current_millis);
  }
  else if (mode == 4) {
    option4(current_millis);
  }
  else if (mode == 5) {
    option5(current_millis);
  }
}


void mode_change() {
  // unsigned long curr_time = millis();

  // if (curr_time - first_time > 200) {  
    mode++;
    press = 1;

    if (mode > 5) {
      mode = 0;
    }

  //   first_time = curr_time;
  // }
}