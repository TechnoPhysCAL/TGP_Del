# Librairie TGL Del

Permet le contrôle d'une diode électroluminescente (DEL) pour Arduino. Outre son état, on peut la mettre en mode clignotant, ajuster le délai et modifier son intensité lumineuse. Son mode de fonctionnement est non-bloquant.

## Utilisation

```cpp

#include <Del.h> 

const int pin = LED_BUILTIN;

Del maDEL(pin); 

void setup()
{
    maDel.set(true);
    maDel.setBlinking(true);
    maDel.setBlinkingItnerval(250);
    maDel.setBrightness(100);
}

void loop()
{
  maDEL.refresh(); 

 
}
```

## Méthodes disponibles


```cpp
 void refresh()
```
Cette méthode doit être placée en début de boucle loop(): elle permet de mettre à jour l'état de la DEL sans bloquer l'exécution du reste de la boucle.

---

```cpp
void set(bool value) 
bool get()
```
Permet de lire et écrire l'état de la del (allumée ou éteinte).

---

```cpp
void setBlinking(bool value)
bool getBlinking()
```
Permet de lire et écrire le mode clignotement (activé ou non). Même si le mode clignotement est activé, cela n'allume pas pour autant la del.

---
```cpp
void voidsetBlinkingInterval(unsigned long value)
unsigned long getBlinkingInterval()
```
Permet de lire et écrire le temps d'intervalle du clignotement, en millisecondes.

---
```cpp
void setBrightness(float value)
float getBrightness()
```

Permet de lire et écrire l'intensité lumineuse de la del, entre 0 et 100%. Selon le microcontrôleur utilisé, un signal PWM est utilisé pour modifier l'intensité lumineuse produite.

---
```cpp
int getAddress()
```

Permet de lire le numéro de la broche utilisée lors de l'initialisation de l'objet.

---