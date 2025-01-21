/*
  Librairie TPG DEL - Del_lambda.ino

  ###DESCRIPTION
  Cet exemple permet d'utiliser une lambda pour définir la fonction de mise à jour de la DEL.
  La fonction de mise à jour de la DEL est définie dans la fonction setUpdateFunction.

  ###NOTE
  Dans cet exemple, la DEL est simulée par des messages au port série.
*/

#include <Del.h> // Pour utiliser la librairie Del

#define PIN 2 // Le numéro du port de la DEL.

DelPin maDel(PIN); // Initialisation de la DEL sur le port choisi

void setup()
{
  maDel.setBlinking(true); // Activer le mode clignotement pour la DEL
  maDel.setBrightness(100);
  maDel.setUpdateFunction([](float percentage) {
    Serial.println("Ma del est à un pourcentage de " + String(percentage));
  }); // Définit la fonction de mise à jour de la DEL
}

void loop()
{
  maDel.refresh(); // Permet d'actualiser l'état de la DEL. CETTE MÉTHODE EST OBLIGATOIRE EN DÉBUT DE LOOP(), IDÉALEMENT.
}