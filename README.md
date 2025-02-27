# 🔥 Bluetooth Macro Pad – Un mini Stream Deck DIY

## 📌 Présentation

J'ai conçu un **boîtier de type Stream Deck** permettant d'automatiser des actions sur un ordinateur grâce à **12 boutons physiques**. Ce boîtier fonctionne comme un **clavier Bluetooth**, envoyant des commandes configurables sur n'importe quel appareil compatible Bluetooth (PC, Mac, Linux, etc.).

L'objectif était de créer une solution simple et efficace pour faciliter certaines tâches informatiques, le tout en **DIY**, avec une programmation en **C**.

---

## 🎯 Fonctionnalités

- **Connexion Bluetooth** 📡 : Le boîtier fonctionne comme un clavier sans fil.
- **12 boutons programmables** 🎛️ : Chaque bouton envoie un signal pouvant être associé à une action.
- **Multi-plateforme** 🖥️ : Fonctionne avec Windows, macOS et Linux.
- **Conception DIY** 🛠️ : Basé sur un microcontrôleur programmable en **C**.
- **Faible consommation d'énergie** ⚡ : Idéal pour une utilisation prolongée.
- **LEDs adressables** 🌈 : Un anneau de LEDs RGB autour du boîtier permettant d'afficher des effets lumineux personnalisables.

---

## 🖼️ Aperçu du Boîtier
<img src="https://github.com/user-attachments/assets/df758d20-3555-4970-9b97-a7e7296d4002" width="200">
<img src="https://github.com/user-attachments/assets/49999977-cafb-4097-9be0-a4bdceb20d67" width="200">
<img src="https://github.com/user-attachments/assets/c7706af9-b20a-42cb-81db-62da8738f270" width="200">
<img src="https://github.com/user-attachments/assets/df8f2908-ce51-4b14-8be7-a9c8990f1937" width="400">


---

## 📜 Conception & Réalisation

### 1️⃣ Matériel Utilisé

- Un microcontrôleur compatible Bluetooth (ESP32).
- 12 boutons physiques.
- Un boîtier imprimé en 3D.
- Une alimentation USB.
- Un anneau de **LEDs adressables** (type WS2812B) pour un affichage lumineux personnalisé.

### 2️⃣ Programmation

Le firmware du boîtier est écrit en **C** et permet d'attribuer des touches à chaque bouton.


Les **LEDs adressables** sont contrôlées avec la bibliothèque **Adafruit NeoPixel**, permettant d'afficher des effets lumineux dynamiques en fonction des actions effectuées.
