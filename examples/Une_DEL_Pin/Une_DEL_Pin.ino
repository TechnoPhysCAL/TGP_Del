/*
  Librairie TPG DEL - Une_DEL.ino

  ###DESCRIPTION

  Note: ###NOTE

*/

#include <DelPin.h> //Pour utiliser la librairie Del
#define PIN_LED 4 //Le numéro du port de la DEL, ici la DEL par défaut sur le board.

DelPin maDEL(PIN_LED); // Initialisation de la DEL sur le port choisi

void setup()
{ 
  maDEL.begin();
  maDEL.setBlinkingInterval(100);
}

void loop()
{
  maDEL.refresh();  // Permet d'actualiser l'état de la DEL. CETTE MÉTHODE EST OBLIGATOIRE EN DÉBUT DE LOOP(), IDÉALEMENT.

  unsigned long curTime = millis() % 4000;

  if (curTime < 1000)  // Est VRAIE durant 2.5 secondes, à chaque période de 5 secondes.
  {
    maDEL.set(true);
    maDEL.setBrightness(100.0);
    maDEL.setBlinking(false);
  }
   else if (curTime < 2000) {
    maDEL.set(true);
    maDEL.setBlinking(true);
  } 
  else if (curTime < 3000) {
    maDEL.set(true);
    maDEL.setBlinking(false);
    maDEL.setBrightness((3000 - curTime) / 10.0);
  } 
  else {
    maDEL.set(false);
  }
}
