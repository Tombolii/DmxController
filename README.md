# DMX Controller mit Arduino UNO R4 WiFi

## Projektbeschreibung

Das **DmxController**-Projekt ist ein Arduino-basiertes System zur Steuerung von DMX-Geräten (wie Lichtern, Nebelmaschinen, etc.) über ein WiFi-Interface. Es ermöglicht dir, professionelle Beleuchtungs- und Effektgeräte mit einer webbasierten Schnittstelle zu steuern.

### Hauptfunktionen

- **WiFi-Steuerung**: Web-API über HTTP zum Kontrollieren von DMX-Geräten
- **Hazer-Steuerung**: Spezielle Unterstützung für Nebelmaschinen mit Volumens- und Lüfter-Kontrolle
- **DMX-Adapter**: Direkte Kontrolle von DMX-Kanälen
- **Timer-basierte Effekte**: Zeitgesteuerte Szenen und Effekte
- **Echtzeit-Steuerung**: Schnelle und responsive Kontrolle über HTTP-Anfragen

### Hardware

- **Mikrocontroller**: Arduino UNO R4 WiFi
- **Schnittstelle**: DMX512 (über Adapter)
- **Verbindung**: WiFi (IEEE 802.11b/g/n)

---

## Installation & Setup

### Voraussetzungen

Installiere folgende Software:

1. **Python 3.6+** (erforderlich für PlatformIO)
   - Download: https://www.python.org/downloads/
   - Stelle sicher, dass "Add Python to PATH" aktiviert ist
   - Überprüfe: `python --version` im Terminal

2. **Visual Studio Code** - https://code.visualstudio.com/
   - Download und Installation folgen dem Standard-Installer

3. **Git** (optional, aber empfohlen)
   - Download: https://git-scm.com/

### PlatformIO Installation & Setup

#### Schritt A: PlatformIO Extension installieren

1. Öffne **Visual Studio Code**
2. Gehe zu **Extensions** (Ctrl+Shift+X oder Klick auf Icon in der linken Seitenleiste)
3. Suche nach **"PlatformIO IDE"** (von PlatformIO Inc.)
4. Klicke auf **Install**
5. Warte, bis die Installation abgeschlossen ist (kann 2-3 Minuten dauern)
6. **VS Code wird einmal neu geladen** - das ist normal

#### Schritt B: PlatformIO Core initialisieren

Nach Installation der Extension:

1. Öffne die **Command Palette** (Ctrl+Shift+P)
2. Gib ein: `PlatformIO: Initialize PlatformIO`
3. Folge den Anweisungen auf dem Bildschirm
4. Die PlatformIO-Toolchain wird automatisch heruntergeladen und installiert

Alternativ im Terminal:
```bash
platformio system info
```

Wenn alles korrekt installiert ist, siehst du folgende Ausgabe:
```
PlatformIO Core [Version]
Python [Version]
...
```

#### Schritt C: Board-Support installieren

Das Arduino UNO R4 WiFi Board wird automatisch installiert, wenn du das Projekt öffnest.

Falls du es manuell installieren möchtest:

1. Öffne die **Command Palette** (Ctrl+Shift+P)
2. Gib ein: `PlatformIO: Manage Platforms`
3. Wähle `Install` → Suche nach `renesas-ra`
4. Installiere die **Renesas RA** Platform (enthält UNO R4 WiFi Support)

#### Schritt D: Umgebungsvariablen prüfen (Windows)

Falls PlatformIO nicht korrekt erkannt wird:

1. Öffne **Systemeinstellungen** → **Umgebungsvariablen bearbeiten**
2. Stelle sicher, dass folgende Pfade in der `PATH`-Variablen enthalten sind:
   - Python-Installationspfad (z.B. `C:\Users\[DeinName]\AppData\Local\Programs\Python\Python311`)
   - PlatformIO-Pfad (z.B. `C:\Users\[DeinName]\.platformio\penv\Scripts`)

3. Starte VS Code neu nach Änderungen

### Schritt 1: Repository klonen

```bash
git clone https://github.com/Tombolii/DmxController.git
cd DmxController
```

### Schritt 2: Projekt in VS Code öffnen

1. Öffne VS Code
2. Klicke auf **File** → **Open Folder**
3. Wähle den `DmxController`-Ordner aus
4. VS Code fragt: "Do you trust the authors?" → Klicke **Yes, I trust the authors**
5. PlatformIO erkennt automatisch `platformio.ini` und indexiert das Projekt (kann 30-60 Sekunden dauern)

Oder über Terminal:
```bash
code .
```

### Schritt 3: Dependencies installieren

Dies geschieht **automatisch**, wenn du das Projekt öffnest. Du siehst in der VS Code Status-Leiste:
- `[PlatformIO] Initializing...`
- `[PlatformIO] Building project...`

Falls nötig, kannst du das manuell triggern:

1. Öffne die **Command Palette** (Ctrl+Shift+P)
2. Gib ein: `PlatformIO: Build`
3. Der Build-Prozess startet und installiert alle Abhängigkeiten

**Abhängigkeiten** (automatisch installiert):
- **ArduinoJson** v7.4.2+ - Für JSON-Verarbeitung
- **Arduino Core für Renesas RA** - Wird mit der Platform installiert

### Schritt 4: WiFi-Credentials konfigurieren

1. Öffne die Datei `include/arduino_secrets.h` (oder erstelle sie, falls nicht vorhanden)
2. Füge folgende Inhalte ein:

```cpp
#ifndef ARDUINO_SECRETS_H
#define ARDUINO_SECRETS_H

#define SECRET_SSID "Dein_WiFi_Netzwerk"
#define SECRET_PASS "Dein_WiFi_Passwort"

#endif
```

3. Ersetze die Platzhalter mit deinen echten WiFi-Daten
4. **Speichere die Datei** (Ctrl+S)

⚠️ **Wichtig**: Diese Datei enthält sensitive Daten - nicht in Git committen!

### Schritt 5: Arduino Hardware verbinden

1. Verbinde das **Arduino UNO R4 WiFi** per **USB-Kabel** mit deinem Computer
2. Windows sollte den Treiber automatisch erkennen
3. In VS Code Status-Leiste solltest du einen Port sehen (z.B. `COM3`, `COM4`)

Falls der Port nicht erkannt wird:
- Installiere die [SEGGER J-Link Treiber](https://www.segger.com/downloads/jlink/)
- oder nutze den [Arduino IDE Boards Manager](https://docs.arduino.cc/software/ide-v1/tutorials/installing-boards)

### Schritt 6: Projekt kompilieren und hochladen

#### Option 1: Mit PlatformIO GUI (empfohlen)

1. Öffne die **Command Palette** (Ctrl+Shift+P)
2. Gib ein: `PlatformIO: Upload` oder nutze **Ctrl+Alt+U**
3. Wähle den richtigen Port (z.B. `COM3` oder `/dev/cu.usbserial-*`)
4. Der Build-Prozess startet automatisch
5. Nach erfolgreicher Kompilierung wird der Code hochgeladen

Du siehst folgende Ausgaben im Terminal:
```
Compiling .pio/build/uno_r4_wifi/src/...
Linking .pio/build/uno_r4_wifi/firmware.elf
Creating firmware image...
Uploading to board...
Verifying...
[SUCCESS] Took x.xx seconds
```

#### Option 2: Mit Terminal-Befehlen

```bash
# Nur kompilieren (ohne hochzuladen)
platformio run

# Kompilieren und hochladen
platformio run --target upload

# Nur sauberer Build (Cache löschen)
platformio run --target clean
platformio run --target upload
```

### Schritt 7: Serial Monitor überwachen

Nach erfolgreichem Upload können Sie die WiFi-Verbindung im Serial Monitor überwachen:

1. Öffne die **Command Palette** (Ctrl+Shift+P)
2. Gib ein: `PlatformIO: Monitor` oder nutze **Ctrl+Alt+M**
3. Der Monitor zeigt die Konsolen-Ausgaben des Arduino:

```
Connecting to WiFi: MyNetwork
WiFi connected!
IP Address: 192.168.1.100
Ready to receive HTTP requests
```

**Serial Monitor Tastenkombinationen:**
- `Ctrl+C` - Beende Monitor
- `Ctrl+L` - Clear Bildschirm
- Baud Rate: 9600 (wie in Code konfiguriert)

---

## Benutzung

### Web-Interface

Sobald das Arduino verbunden ist, kannst du auf die Web-API zugreifen:

```
http://<Arduino-IP-Adresse>
```

Die IP-Adresse wird im Serial Monitor angezeigt (z.B. `10.10.1.1`).

### Beispiel HTTP-Anfragen

**Hazer starten:**
```http
GET /api/hazer/start?duration=5000&effect=fade
```

**DMX-Kanal steuern:**
```http
GET /api/dmx/channel?channel=1&value=255
```

---

## Projektstruktur

```
├── DmxController.ino          # Haupteinstiegspunkt
├── platformio.ini             # PlatformIO-Konfiguration
├── include/                   # Header-Dateien
│   ├── WifiController.h       # WiFi-Verwaltung
│   ├── DmxAdapter.h          # DMX-Steuerung
│   ├── HazerController.h      # Nebelmaschinen-Kontrolle
│   ├── LightController.h      # Lichtkontrolle
│   └── ...
├── src/                       # Implementierungsdateien (.cpp)
│   ├── WifiController.cpp
│   ├── DmxAdapter.cpp
│   ├── HazerController.cpp
│   └── ...
└── build/                     # Kompilier-Artefakte (generiert)
```

---

## Fehlerbehebung

### Arduino wird nicht erkannt
- Überprüfe die USB-Verbindung
- Installiere die korrekten **USB-Treiber** für Arduino UNO R4 WiFi
- Versuche einen anderen USB-Port

### WiFi-Verbindung schlägt fehl
- Überprüfe `arduino_secrets.h` - SSID und Passwort müssen korrekt sein
- Stelle sicher, dass das WiFi-Netzwerk verfügbar ist
- Überprüfe im Serial Monitor die Fehlermeldungen

### Kompilierfehler
- Führe `platformio run --target clean` aus um den Cache zu löschen
- Überprüfe, dass alle Abhängigkeiten installiert sind: `platformio run --target install-dependencies`

---

## Weitere Informationen

- [Arduino UNO R4 WiFi Dokumentation](https://docs.arduino.cc/hardware/uno-r4-wifi)
- [PlatformIO Dokumentation](https://docs.platformio.org/)
- [DMX512 Standard](https://de.wikipedia.org/wiki/DMX512)

---

## Lizenz

Dieses Projekt ist unter der MIT-Lizenz lizenziert.
