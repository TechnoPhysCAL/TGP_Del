# Librairie TGP Del

Permet le contrôle d'une diode électroluminescente (DEL) pour Arduino. Outre son état, on peut la mettre en mode clignotant, ajuster le délai et modifier son intensité lumineuse. Son mode de fonctionnement est non-bloquant.

Il existe deux classes : DelPin.h pour une DEL branchée sur une broche, et Del.h, pour contrôler une DEL virtuelle où l'utilisateur aura la responsabilité de faire le contrôle matériel correspondant.


## Notes de version

### 2.0.1 : 
  - Uniformisation du pointeur de fonction pour toutes les plateformes.

### 2.0.0 : 
 - Refonte pour que Del gère les comportements virtuels et que DelPin gère une Del matérielle.
 - Permet l'utilisation de la Del générique via une fonction de référence;
 - Permet l'utilisation des fonctions lambdas
 - Mise à jour de la gestion des PWMs sur la version 3 de ESP32-Arduino
 - Permettre le fonctionnement (PWM) sur la version antérieure 2 de ESP32-Arduino


## Utilisation

Voici l'exemple simple avec une DEL branchée sur une broche.

```cpp

#include <DelPin.h> 

DelPin maDEL(LED_BUILTIN); 

void setup()
{
    maDel.on();
    maDel.setBlinking(true);
    maDel.setBlinkingInterval(250);
    maDel.setBrightness(100);
}

void loop()
{
  maDEL.refresh();

}
```

## Constructeurs
```cpp
Del()
Del(SignalUpdater updater);
```
Constructeur générique pour une DEL virtuelle, sans spécification matérielle. On peut aussi fournir une fonction qui aura la responsabilité de modifier matériellement la del; la fonction doit recevoir un float, qui correspond au pourcentage d'intensité voulu pour la 

```cpp
DelPin(int pin)
```
On spécifie le numéro de la broche sur lequel est branché la Del.


## Méthodes disponibles

### Méthodes de Del.h

```cpp
 void refresh()
```
Cette méthode doit être placée en début de boucle loop(): elle permet de mettre à jour l'état de la DEL sans bloquer l'exécution du reste de la boucle.

---
```cpp
 void on()
 void off()
```
Ces méthodes permettent respectivement d'allumer ou d'éteindre la del. Elles sont équivalentes à set(true) et set(false).

---
```cpp
void set(bool value) 
bool get()
```
Permet de lire et modifier l'état de la del (allumée ou éteinte).

---
```cpp
void setBlinking(bool value)
bool getBlinking()
```
Permet de lire et modifier le mode clignotement (activé ou non). Même si le mode clignotement est activé, cela n'allume pas pour autant la del.

---
```cpp
void setBlinkingInterval(unsigned long value)
unsigned long getBlinkingInterval()
```
Permet de lire et modifier le temps d'intervalle du clignotement, en millisecondes.

---
```cpp
void setBrightness(float value)
float getBrightness()
```
Permet de lire et modifier l'intensité lumineuse de la del, entre 0 et 100%. NOTE: Modifier l'intensité lumineuse supérieur à 0 ne va pas nécessairement allumer la DEL: il faut également faire appel à la méthode .on() ou .set(true).

---
```cpp
void setSignalUpdater(SignalUpdater updater)
```
Permet de définir une fonction de mise à jour personnalisée pour la DEL. Cette fonction est appelée à chaque fois que la DEL est mise à jour. La fonction doit recevoir un float, qui correspond au pourcentage d'intensité voulu pour la del.

### Méthodes de DelPin.h

---
```cpp
void begin()
```
Initialise la DEL. Cette méthode doit être appelée dans la fonction setup().

---
```cpp
int getPinNumber()
```
Retourne le numéro de la broche sur laquelle la DEL est connectée.

---
```cpp
int getChannel()
```
Retourne le numéro du canal PWM utilisé (uniquement pour les anciennes versions d'ESP32).

---
```cpp
int getAddress()
```
Permet de lire le numéro de la broche utilisée lors de l'initialisation de l'objet pour la classe DelPin.
