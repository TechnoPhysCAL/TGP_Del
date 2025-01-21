/*
  Librairie TPG DEL - Del_generique.ino

  ###DESCRIPTION
  Cet exemple permet de contrôler une DEL à l'aide de la librairie Del. La fonction de contrôle de la DEL matérielle
  est définie dans la fonction updateSignal. Cette fonction est appelée à chaque fois que la DEL est mise à jour.

  ###NOTE
  Dans cet exemple, la DEL est contrôlée par une fonction de mise à jour définie par l'utilisateur.
*/

#include "Del.h" // Pour utiliser la librairie Del
#define PIN_LED 2
Del maDEL; // Initialisation de la DEL

void setup() {
  Serial.begin(115200);
  pinMode(PIN_LED, OUTPUT);
  maDEL.setSignalUpdater(&updateSignal);
  maDEL.setBlinkingInterval(100);
}

void loop() {
  maDEL.refresh(); // Permet d'actualiser l'état de la DEL. CETTE MÉTHODE EST OBLIGATOIRE EN DÉBUT DE LOOP(), IDÉALEMENT.

  unsigned long curTime = millis() % 4000;

  if (curTime < 1000) // Est VRAIE durant 1 seconde, à chaque période de 4 secondes.
  {
    maDEL.set(true);
    maDEL.setBrightness(100.0);
    maDEL.setBlinking(false);
  } else if (curTime < 2000) {
    maDEL.set(true);
    maDEL.setBlinking(true);
  } else if (curTime < 3000) {
    maDEL.set(true);
    maDEL.setBlinking(false);
    maDEL.setBrightness((3000 - curTime) / 10.0);
  } else {
    maDEL.set(false);
  }
}

void updateSignal(float percentage) {
  Serial.print("Je mets à jour la del ");
  Serial.println(percentage);
  digitalWrite(PIN_LED, percentage > 0 ? HIGH : LOW); //NOTE : dans cet exemple, le pourcentage est ignoré 
}
