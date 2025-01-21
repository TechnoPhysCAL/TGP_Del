# Librairie TGP Del

Permet le contrôle d'une diode électroluminescente (DEL) pour Arduino. Outre son état, on peut la mettre en mode clignotant, ajuster le délai et modifier son intensité lumineuse. Son mode de fonctionnement est non-bloquant.

Il existe deux classes : DelPin.h pour une DEL branchée sur une broche, et Del.h, pour contrôler une DEL virtuelle où l'utilisateur aura la responsabilité de faire le contrôle matériel correspondant.

## Utilisation

Voici l'exemple simple avec une DEL branchée sur une broche.

```cpp

#include <DelPin.h> 

#define PIN_LED LED_BUILTIN

DelPin maDEL(PIN_LED); 

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
DelPin(int pin)
```
On spécifie le numéro de la broche sur lequel est branché la Del.

```cpp
Del()
```
Constructeur générique pour une DEL virtuelle, sans spécification matérielle. 

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
Permet de lire et modifier l'intensité lumineuse de la del, entre 0 et 100%.

---
```cpp
void setSignalUpdater(SignalUpdater func)
```
Permet de définir une fonction de mise à jour personnalisée pour la DEL. Cette fonction est appelée à chaque fois que la DEL est mise à jour.

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
