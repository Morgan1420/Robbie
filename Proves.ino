
// // Coses del servo
// #include <Servo.h>
// #define servoPin 3
// #define servoGrauInici 30
// #define servoGrauFi 150
// #define servoDelayGirs 10
// Servo miServo;
// void servoGir() {
//   for (int pos = servoGrauInici; pos <= servoGrauFi; pos += 1) {
//     miServo.write(pos);              // Indica al servo que vaya a la posición 'pos'
//     delay(servoDelayGirs);                       // Espera 15ms para que el servo llegue
//   }
//   for (int pos = servoGrauFi; pos >= servoGrauInici; pos -= 1) {
//     miServo.write(pos);              // Indica al servo que vaya a la posición 'pos'
//     delay(servoDelayGirs);                       // Espera 15ms para que el servo llegue
//   }
// }

// Coses del ultrason
#define ultrasonsTriggerPin A5
#define ultrasonsEchoPin A4
#define ultrasonsTempsPausa 500
float ultrasons(){
  // Netegem el pin Trig
  digitalWrite(ultrasonsTriggerPin, LOW);
  delayMicroseconds(2);
  // Enviem el pols de 10 microsegons
  digitalWrite(ultrasonsTriggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultrasonsTriggerPin, LOW);
  // Llegim el temps que triga a tornar el so
  long duracio = pulseIn(ultrasonsEchoPin, HIGH);
  // Calculem la distància en cm
  float distancia = duracio * 0.0343 / 2;
  // Mostrem el resultat pel Monitor Sèrie
  Serial.print("Distància: ");
  Serial.print(distancia);
  Serial.println(" cm");
  return distancia;
}

// Coses del sensor de colors
#define sensorColorsEsqPin 2
#define sensorColorsMigPin 4
#define sensorColorsDrePin 10
#define sensorColorsTempsPausa 100
int sensorColors(){
  // Leemos los tres sensores (digital: 0 o 1)
  int valorEsq = digitalRead(sensorColorsEsqPin);
  int valorMig = digitalRead(sensorColorsMigPin);
  int valorDre = digitalRead(sensorColorsDrePin);

  // Imprimimos los valores en una sola línea para que sea fácil de leer
  Serial.print("Esq: "); Serial.print(valorEsq);
  Serial.print(" | Mig: "); Serial.print(valorMig);
  Serial.print(" | Dre: "); Serial.println(valorDre);
  return valorEsq * 100 + valorMig * 10 + valorDre;
}


// Motor A
#define motorDreVelocitatPin 6
#define motorDreIn1Pin 11
#define motorDreIn2Pin 9
#define motorEsqVelocitatPin 5
#define motorEsqIn3Pin 7
#define motorEsqIn4Pin 8
void provaEndevantA(){
  digitalWrite(motorDreIn1Pin, HIGH);
  digitalWrite(motorDreIn2Pin, LOW);
  analogWrite(motorDreVelocitatPin, 100);
  digitalWrite(motorEsqIn3Pin, HIGH);
  digitalWrite(motorEsqIn4Pin, LOW);
  analogWrite(motorEsqVelocitatPin, 100);
  delay(1000);
  digitalWrite(motorDreIn1Pin, LOW);
  digitalWrite(motorDreIn2Pin, HIGH);
  analogWrite(motorDreVelocitatPin, 100);
  digitalWrite(motorEsqIn3Pin, LOW);
  digitalWrite(motorEsqIn4Pin, HIGH);
  analogWrite(motorEsqVelocitatPin, 100);
  delay(1000);
}

void parar(){
  digitalWrite(motorDreIn1Pin, LOW);
  digitalWrite(motorDreIn2Pin, LOW);
  analogWrite(motorDreVelocitatPin, 0);
  digitalWrite(motorEsqIn3Pin, LOW);
  digitalWrite(motorEsqIn4Pin, LOW);
  analogWrite(motorEsqVelocitatPin, 0);
}

void giraDreta45(){
  digitalWrite(motorDreIn1Pin, LOW);
  digitalWrite(motorDreIn2Pin, HIGH);
  analogWrite(motorDreVelocitatPin, 200);
  digitalWrite(motorEsqIn3Pin, HIGH);
  digitalWrite(motorEsqIn4Pin, LOW);
  analogWrite(motorEsqVelocitatPin, 200);
  delay(200);
  parar();
}
void giraEsquerra45(){
  digitalWrite(motorDreIn1Pin, HIGH);
  digitalWrite(motorDreIn2Pin, LOW);
  analogWrite(motorDreVelocitatPin, 200);
  digitalWrite(motorEsqIn3Pin, LOW);
  digitalWrite(motorEsqIn4Pin, HIGH);
  analogWrite(motorEsqVelocitatPin, 200);
  delay(200);
  parar();
}
void endevantFinsBlanc(){
  digitalWrite(motorDreIn1Pin, LOW);
  digitalWrite(motorDreIn2Pin, HIGH);
  analogWrite(motorDreVelocitatPin, 200);
  digitalWrite(motorEsqIn3Pin, LOW);
  digitalWrite(motorEsqIn4Pin, HIGH);
  analogWrite(motorEsqVelocitatPin, 200);
  delay(1000);
  parar();
}



void inici() {
  giraDreta45();
  delay(2000);
  // endevantFinsBlanc();
  giraEsquerra45();
  // endevantFinsBlanc();
}



enum estats {
  INICI,
  VOLTETA_MAGICA,
  ENVESTIDA,
  TOCANT_LINIA,
} estat;

// Setup
void setup() {
  // miServo.attach(servoPin);

  pinMode(ultrasonsTriggerPin, OUTPUT);
  pinMode(ultrasonsEchoPin, INPUT);

  pinMode(sensorColorsEsqPin, INPUT);
  pinMode(sensorColorsMigPin, INPUT);
  pinMode(sensorColorsDrePin, INPUT);

  pinMode(motorDreVelocitatPin, OUTPUT);
  pinMode(motorDreIn1Pin, OUTPUT);
  pinMode(motorDreIn2Pin, OUTPUT);
  pinMode(motorEsqVelocitatPin, OUTPUT);
  pinMode(motorEsqIn3Pin, OUTPUT);
  pinMode(motorEsqIn4Pin, OUTPUT);

  estat = INICI;
}

// Loop principal
void loop() {
  inici();
  delay(10000);
}