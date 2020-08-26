/*
  Librairie TPG DEL - Une_DEL.ino

  ###DESCRIPTION

  Note: ###NOTE

*/

#include <Del.h> //Pour utiliser la librairie Del

const int pin = LED_BUILTIN; //Le numéro du port de la DEL, ici la DEL par défaut sur le board.

Del maDEL(pin); // Initialisation de la DEL sur le port choisi

void setup()
{

}

void loop()
{
  maDEL.refresh(); //Permet d'actualiser l'état de la DEL. CETTE MÉTHODE EST OBLIGATOIRE EN DÉBUT DE LOOP(), IDÉALEMENT.

  if (millis() % 5000 < 2500) // Est VRAIE durant 2.5 secondes, à chaque période de 5 secondes.
  {
    maDEL.set(true);
  }
  else
  {
    maDEL.set(false);
  }
}
