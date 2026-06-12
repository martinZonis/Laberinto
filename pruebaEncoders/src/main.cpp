#include <Arduino.h>

// Definición de pines para el Motor A
#define PWMA 32  // Pin de PWM para Motor A
#define AIN1 33  // Dirección 1 para Motor A
#define AIN2 25  // Dirección 2 para Motor A

// Definición de pines para el Motor B
#define PWMB 14   // Pin de PWM para Motor B
#define BIN1 27  // Dirección 1 para Motor B
#define BIN2 26  // Dirección 2 para Motor B


// Configuración de PWM
#define PWM_FREQ 5000
#define PWM_RESOLUTION 8 // Rango de 0 a 255 (8 bits)
#define PWM_SPEED 100    // Velocidad seteada a 100

// Canales PWM
#define PWM_CHANNEL_A 0
#define PWM_CHANNEL_B 1

void setup() {
  Serial.begin(115200);

  // Configurar pines de dirección y standby como salida
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  
  // Configurar PWM para ESP32
  ledcSetup(PWM_CHANNEL_A, PWM_FREQ, PWM_RESOLUTION);
  ledcAttachPin(PWMA, PWM_CHANNEL_A);

  ledcSetup(PWM_CHANNEL_B, PWM_FREQ, PWM_RESOLUTION);
  ledcAttachPin(PWMB, PWM_CHANNEL_B);
}

void loop() {
  Serial.println("Moviendo motores hacia un lado...");
  
  // Motor A
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  ledcWrite(PWM_CHANNEL_A, PWM_SPEED);

  // Motor B
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  ledcWrite(PWM_CHANNEL_B, PWM_SPEED);

  delay(3000);

  Serial.println("Moviendo motores hacia el otro lado...");
  
  // Motor A
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  ledcWrite(PWM_CHANNEL_A, PWM_SPEED);

  // Motor B
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  ledcWrite(PWM_CHANNEL_B, PWM_SPEED);

  delay(3000);
  
  Serial.println("Deteniendo motores...");
  
  // Motor A
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  ledcWrite(PWM_CHANNEL_A, 0);

  // Motor B
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
  ledcWrite(PWM_CHANNEL_B, 0);
 
  delay(2000);
}