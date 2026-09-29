// ============================================
//  GESTURE CONTROL ROBOT - ARDUINO CODE
//  Motor Driver: L293D / L298N
// ============================================

#define IN1 8    // Left motor
#define IN2 9    // Left motor
#define IN3 10   // Right motor
#define IN4 11   // Right motor

// ---------- Motor functions ----------
void stopMotors() {
  digitalWrite(IN1, LOW);  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);  digitalWrite(IN4, LOW);
}

void forward() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
}

void backward() {
  digitalWrite(IN1, LOW);  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);  digitalWrite(IN4, HIGH);
}

void left() {
  digitalWrite(IN1, LOW);  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
}

void right() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);  digitalWrite(IN4, HIGH);
}

void leftOnly() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);  digitalWrite(IN4, LOW);
}

void rightOnly() {
  digitalWrite(IN1, LOW);  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
}

void demo() {
  Serial.println("DEMO shuru (roka jaane ke liye reset dabao)");
  forward();  delay(2000); stopMotors(); delay(500);
  backward(); delay(2000); stopMotors(); delay(500);
  left();     delay(2000); stopMotors(); delay(500);
  right();    delay(2000); stopMotors(); delay(500);
  Serial.println("DEMO khatam");
}

void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  stopMotors();

  Serial.println("=== Gesture Robot Ready ===");
  Serial.println("F=Aage B=Peeche L=Left R=Right S=Stop");
  Serial.println("1=Sirf Left motor  2=Sirf Right motor  D=Demo");
}

void loop() {
  if (Serial.available()) {
    char c = Serial.read();

    switch (c) {
      case 'F': forward();   Serial.println("FORWARD");  break;
      case 'B': backward();  Serial.println("BACKWARD"); break;
      case 'L': left();      Serial.println("LEFT");     break;
      case 'R': right();     Serial.println("RIGHT");    break;
      case 'S': stopMotors();Serial.println("STOP");     break;
      case '1': leftOnly();  Serial.println("TEST: Sirf LEFT motor");  break;
      case '2': rightOnly(); Serial.println("TEST: Sirf RIGHT motor"); break;
      case 'D': demo();      break;
      default: break;   
    }
  }
}