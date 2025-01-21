/*
  Librairie TPG DEL - Del_lambda.ino

  ###DESCRIPTION
  Cet exemple permet d'utiliser une lambda pour définir la fonction de mise à jour de la DEL.
  La fonction de mise à jour de la DEL est définie dans la fonction setSignalUpdater.

  ###NOTE
  Dans cet exemple, la DEL est simulée par des messages au port série.
*/

#include <Del.h> // Pour utiliser la librairie Del

Del maDel; // Initialisation de la DEL générique

void setup()
{
  Serial.begin(115200); // Initialiser la communication série

  maDel.setBlinking(true); // Activer le mode clignotement pour la DEL
  maDel.setBrightness(100); //Mettre l'intensité de la DEL à 100%
  maDel.setSignalUpdater([](float percentage) {
    Serial.println("Ma del est à un pourcentage de " + String(percentage));
  }); // Définit la fonction de mise à jour de la DEL (dans l'exemple, un message est envoyé au port série pour simuler la Del)

   maDel.on(); // Allume la DEL
}

void loop()
{
  maDel.refresh(); // Permet d'actualiser l'état de la DEL. CETTE MÉTHODE EST OBLIGATOIRE EN DÉBUT DE LOOP(), IDÉALEMENT.
}