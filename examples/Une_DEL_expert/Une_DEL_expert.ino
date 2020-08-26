/*
  Librairie TPG DEL - Une_DEL_expert.ino

  Fait la démonstration d'une DEL en utilisant le mode clignotement sur un cycle de 12 secondes:
   - 3 secondes allumée;
   - 3 secondes allumée clignotante;
   - 3 secondes allumée où l'intensité lumineuse varie de 0 à 100%;
   - 3 secondes éteintes.
  
  Note:  La fonction .setBlinking(bool) active ou désactive le mode 'clignotement' : Elle n'a pas d'effet sur l'allumage ou non de la DEL.

*/

#include <Del.h> //Pour utiliser la librairie Del

const int pin = LED_BUILTIN; //Le numéro du port de la DEL, ici la DEL par défaut sur le board.

Del maDEL(pin); // Initialisation de la DEL sur le port choisi

void setup()
{
  maDEL.setBlinkingInterval(100); //Ajuste le délai de clignotement à 150 millisecondes (Par défault, 250 millisecondes).
}

void loop()
{
  maDEL.refresh(); //Permet d'actualiser l'état de la DEL. CETTE MÉTHODE EST OBLIGATOIRE EN DÉBUT DE LOOP(), IDÉALEMENT.

  unsigned long current_time = millis() % 12000; // Un temps toujours situé entre 0 et 12 secondes.

  if (current_time < 3000) // Est VRAIE si le temps est inférieur à 3 secondes;
  {
    maDEL.set(true); // Allume la DEL.
  }
  else if (current_time < 6000)
  {
    maDEL.setBlinking(true); //Active le mode clignotement.
  }
  else if (current_time < 9000) // Est VRAIE si le temps est supérieur à 3 et inférieur à 9 secondes.
  {
    maDEL.setBlinking(false);
    float percentage = (current_time-6000)/3000.0 *100.0 ; //Calcule une valeur variant de 0 à 100, sur 3 secondes.
    maDEL.setBrightness(percentage); //Ajuste la luminosité de la Del selon le pourcentage calculé, entre 0 et 100.

  }
  else
  {                           // Sinon, après 6 secondes.
    maDEL.set(false);         // Éteint la DEL.
    
  }
}
