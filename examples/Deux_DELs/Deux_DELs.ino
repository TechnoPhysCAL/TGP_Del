/*
  Librairie TPG DEL - Une_DEL.ino

  ###DESCRIPTION

  Note: ###NOTE

*/

#include <Del.h> //Pour utiliser la librairie Del

const int pinA = 4; //Le numéro du port de la DEL A.
const int pinB = 2; //Le numéro du port de la DEL B.

Del maDELA(pinA); // Initialisation de la DEL A sur le port choisi
Del maDELB(pinB); // Initialisation de la DEL B sur le port choisi

void setup()
{
  maDELB.setBlinking(true); //Activer le mode clignotement pour la DEL B
}

void loop()
{
  maDELA.refresh(); //Permet d'actualiser l'état de la DEL A. CETTE MÉTHODE EST OBLIGATOIRE EN DÉBUT DE LOOP(), IDÉALEMENT.
  maDELB.refresh(); //Permet d'actualiser l'état de la DEL B. CETTE MÉTHODE EST OBLIGATOIRE EN DÉBUT DE LOOP(), IDÉALEMENT.

  if (millis() % 5000 < 2500) // Est VRAIE durant 2.5 secondes, à chaque période de 5 secondes.
  {
    maDELA.set(true);
    maDELB.set(false);
  }
  else
  {
    maDELA.set(false);
    maDELB.set(true);
  }
}