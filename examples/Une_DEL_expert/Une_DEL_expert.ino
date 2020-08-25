/*
  Librairie TPG DEL - Une_DEL_expert.ino

  Fait la démonstration d'une DEL en utilisant le mode clignotement sur un cycle de 9 secondes:
   - 3 secondes allumée;
   - 3 secondes allumée clignotante;
   - 3 secondes éteintes.
  
  Note:  La fonction .setBlinking(bool) active ou désactive le mode 'clignotement' : ELLE N'A PAS D'EFFET SUR L'ALLUMAGE OU NON DE LA DEL.

*/

#include <DELPin.h> //Pour utiliser la librairie DELPin

const int pin = LED_BUILTIN; //Le numéro du port de la DEL, ici la DEL par défaut sur le board.

DELPin maDEL(pin); // Initialisation de la DEL sur le port choisi

void setup()
{

  maDEL.setBlinkingInterval(100); //Ajuste le délai de clignotement à 150 millisecondes (Par défault, 250 millisecondes).
}

void loop()
{
  maDEL.refresh(); //Permet d'actualiser l'état de la DEL. CETTE MÉTHODE EST OBLIGATOIRE EN DÉBUT DE LOOP(), IDÉALEMENT.

  unsigned long current_time = millis() % 9000; // Un temps toujours situé entre 0 et 9 secondes.

  if (current_time < 3000) // Est VRAIE si le temps est inférieur à 3 secondes;
  {
    maDEL.set(true);          // Allume la DEL.
  }
  else if (current_time < 6000) // Est VRAIE si le temps est supérieur à 3 et inférieur à 6 secondes.
  {
    maDEL.setBlinking(true); //Active le mode clignotement.
  }
  else // Sinon, après 6 secondes.
  {
    maDEL.set(false); // Éteint la DEL.
    maDEL.setBlinking(false); //Désactive le mode clignotement.
  }
}
