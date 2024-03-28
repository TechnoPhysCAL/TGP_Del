/*
  Librairie TPG DEL - Une_DEL.ino

  ###DESCRIPTION

  Note: ###NOTE

*/

#include "Del.h"  //Pour utiliser la librairie Del
#define PIN_LED 34
Del maDEL();  // Initialisation de la DEL sur le port choisi

void setup() {

  pinMode(PIN_LED, OUTPUT);
  maDEL.setBlinkingInterval(100);
}

void loop() {
  maDEL.refresh(&updateDel);  // Permet d'actualiser l'état de la DEL. CETTE MÉTHODE EST OBLIGATOIRE EN DÉBUT DE LOOP(), IDÉALEMENT.

  unsigned long curTime = millis() % 4000;

  if (curTime < 1000)  // Est VRAIE durant 2.5 secondes, à chaque période de 5 secondes.
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
    maDEL.setBrightness((4000 - curTime) / 10.0);
  } else {
    maDEL.set(false);
  }
}

void updateDel(bool state, float brightness) {
  digitalWrite(LED_BUILTIN, state ? HIGH : LOW);
}
