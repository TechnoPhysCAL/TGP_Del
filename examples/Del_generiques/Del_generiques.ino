/*
  Librairie TPG DEL - Del_generique.ino

  ###DESCRIPTION
  Cet exemple permet de contrôler une DEL à l'aide de la librairie Del. La fonction de contrôle de la DEL matérielle
  est définie dans la fonction updateSignal. Cette fonction est appelée à chaque fois que la DEL est mise à jour.

  ###NOTE
  Dans cet exemple, la DEL est contrôlée par une fonction de mise à jour définie par l'utilisateur.
*/

#include "Del.h" // Pour utiliser la librairie Del

Del delA; // Initialisation de la DEL, la fonction de mise à jour est définie plus tard

Del delB(&updateSignalB); // Initialisation de la DEL avec une fonction de référence

Del delC([](float percentage) {
  Serial.println("Je mets à jour la del C à " + String(percentage));
  }); // Initialisation de la DEL avec une fonction lambda


void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);

  delA.setSignalUpdater(&updateSignalA); // Définit la fonction de mise à jour de la DEL A

  delA.on();
  delB.on();
  delC.on();

}

void loop() {
  delA.refresh(); // Permet d'actualiser l'état de la DEL. CETTE MÉTHODE EST OBLIGATOIRE EN DÉBUT DE LOOP(), IDÉALEMENT.
  delB.refresh(); 
  delC.refresh(); 

  delA.set(millis()%1000 < 500);
  delB.set(millis()%1500 < 750);
  delC.set(millis()%2000 < 1000);
  
}

void updateSignalA(float percentage) {
  Serial.println ("Je mets à jour la del A à " + String(percentage));
  digitalWrite(LED_BUILTIN, percentage > 0 ? HIGH : LOW); //NOTE : dans cet exemple, le pourcentage est ignoré 
}


void updateSignalB(float percentage) {
  Serial.println ("Je mets à jour la del B à " + String(percentage));
}
