// Motor A
int en_dreta = 5;
int en_esquerra = 6;
int motor_dreta = 7;
int motor_esquerra = 9;

// Motor B
int enB = 6;
int in3 = 9;
int in4 = 11;

void setup() {
  // Configurem tots els pins com a sortida
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void moureEndavant() {
  // Motor A endavant
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 200); // Velocitat (0-255)

  // Motor B endavant
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 200);
}

void moureEnrere() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void parar() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void loop() {
  moureEndavant();
  delay(2000); // Mou-te 2 segons
  
  parar();
  delay(1000); // Para 1 segon
  
  moureEnrere();
  delay(2000); // Enrere 2 segons
  
  parar();
  delay(1000);
}