// Boto
#define botoPin 13

// ultrasons
#define ultrasonsTriggerPin A5
#define ultrasonsEchoPin A4
#define ultrasonsTempsPausa 10
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
  return distancia;
}
float distancia(){
  float mitjana = 0;
  for (int i = 0; i < 5; i++){
    mitjana += ultrasons();
    delayMicroseconds(10);
  }
  mitjana /= 5;
  Serial.println(mitjana);
  return mitjana;
}

// Motors
#define motorDreVelocitatPin 6
#define motorDreIn1Pin 11
#define motorDreIn2Pin 9
#define motorEsqVelocitatPin 5
#define motorEsqIn3Pin 7
#define motorEsqIn4Pin 8

// Velocitats
#define velocitatGir 128
#define velocitatEndevant 255

// Altres
#define tempsEntreUltrasons 100
#define distanciaDAtac 50

// Moviments
void parar(){
  digitalWrite(motorDreIn1Pin, LOW);
  digitalWrite(motorDreIn2Pin, LOW);
  analogWrite(motorDreVelocitatPin, 0);
  digitalWrite(motorEsqIn3Pin, LOW);
  digitalWrite(motorEsqIn4Pin, LOW);
  analogWrite(motorEsqVelocitatPin, 0);
}
void endevant() {
  digitalWrite(motorDreIn1Pin, LOW);
  digitalWrite(motorDreIn2Pin, HIGH);
  analogWrite(motorDreVelocitatPin, velocitatEndevant);
  digitalWrite(motorEsqIn3Pin, LOW);
  digitalWrite(motorEsqIn4Pin, HIGH);
  analogWrite(motorEsqVelocitatPin, velocitatEndevant);
}
void giraDreta() {
  digitalWrite(motorDreIn1Pin, HIGH);
  digitalWrite(motorDreIn2Pin, LOW);
  analogWrite(motorDreVelocitatPin, velocitatGir);
  digitalWrite(motorEsqIn3Pin, LOW);
  digitalWrite(motorEsqIn4Pin, HIGH);
  analogWrite(motorEsqVelocitatPin, velocitatGir);
}




// Setup
void setup() {
  // miServo.attach(servoPin);

  pinMode(ultrasonsTriggerPin, OUTPUT);
  pinMode(ultrasonsEchoPin, INPUT);

  pinMode(motorDreVelocitatPin, OUTPUT);
  pinMode(motorDreIn1Pin, OUTPUT);
  pinMode(motorDreIn2Pin, OUTPUT);
  pinMode(motorEsqVelocitatPin, OUTPUT);
  pinMode(motorEsqIn3Pin, OUTPUT);
  pinMode(motorEsqIn4Pin, OUTPUT);

  pinMode(botoPin, INPUT);

  Serial.begin(9600);
}

bool acaba_de_comencar = true;

// Loop principal
void loop() {

  if (digitalRead(botoPin) == 0) {
    if (acaba_de_comencar){
      acaba_de_comencar = false;
      delay(200);
    }
    giraDreta();
    while(distancia() > distanciaDAtac && digitalRead(botoPin) == 0){
      //delay(tempsEntreUltrasons);
    }
    endevant();
    while(distancia() <= distanciaDAtac && digitalRead(botoPin) == 0){
      //delay(tempsEntreUltrasons);
    }
    parar();
    //delay(5000);
  }
  else {
    acaba_de_comencar = true;
  }

}
