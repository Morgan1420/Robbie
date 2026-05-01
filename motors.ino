// Motor A
int en_dreta = 5;
int in_dreta = 7;

// Motor B
int en_esquerra = 9;
int in_esquerra = 9;

void setup() {
  // Configurem tots els pins com a sortida
  pinMode(en_dreta, OUTPUT);
  pinMode(in_dreta, OUTPUT);
  pinMode(en_esquerra, OUTPUT);
  pinMode(in_esquerra, OUTPUT);
}

void moureEndavant() {
  // Motor A endavant
  digitalWrite(in_dreta, HIGH);
  analogWrite(en_dreta, 200); // Velocitat (0-255)

  // Motor B endavant
  digitalWrite(in_esquerra, HIGH);
  analogWrite(en_esquerra, 200);
}

void moureEnrere() {
  digitalWrite(in_dreta, LOW);
  digitalWrite(in_esquerra, LOW);
}

void parar() {
  digitalWrite(in_dreta, LOW);
  digitalWrite(in_esquerra, LOW);
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