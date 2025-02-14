# **HappyCube – The Curious Little Cube**

HappyCube is an interactive project that brings a small, expressive cube to life. Users can interact with it by pressing a button to receive responses, watching its eyes move as if it’s observing the world, or simply enjoying its animations. It doesn't just display information but creates the illusion of curiosity, making it feel like a tiny character looking around. Inspired by a children's book about a small computer sent to the moon, HappyCube is more about interaction than functionality.

## **What is HappyCube?**

HappyCube appears as a tiny digital companion, looking around, blinking, and reacting as if exploring its surroundings. It doesn't just sit idle but gives the impression of observing and processing what it sees.

It also has a few extra features:

- **Tells the time** by synchronizing with an online time server
- **Answers important life questions** when you press its button, just like a wise oracle

## **How It Works**

HappyCube runs on a **microcontroller** with an **OLED display** and is programmed to display facial animations, respond to user input, and even connect to the internet to retrieve the correct time.

### **Main Components**

1. **Face Animation** (`FaceAnimation.cpp/h`)
   - The cube's eyes move and blink, making it appear alive
   - Uses precomputed bitmap animations for smooth movement

2. **Display Handling** (`Display.cpp/h`)
   - Controls an **SSD1306 OLED display** (128x64 pixels)
   - Prints text, renders bitmaps, and centers messages dynamically

3. **Magic 8-Ball Functionality** (`Magic8Ball.cpp/h`)
   - Provides randomly generated answers when the button is pressed
   - Stores responses in **flash memory** to save RAM

4. **Time Synchronization** (`TimeModule.cpp/h`)
   - Uses an **ESP01** to connect to **NTP servers**
   - Retrieves and formats the current time

## **Required Components**

To build your own HappyCube, you will need the following components. Below is a list with a brief explanation of why each is necessary:

- **ESP01** ([Amazon Link](https://amzn.to/4gP3Pmg)) - The main microcontroller responsible for running the HappyCube software and handling Wi-Fi connectivity.
- **SSD1306 OLED Display** ([Amazon Link](https://amzn.to/4gKW9Bc)) - Displays animations, time, and responses to user inputs.
- **USB-C Port** ([Amazon Link](https://amzn.to/4gXwLZn)) - Supplies power to the HappyCube.
- **M2 Screws and Nuts (4 pieces, 6mm) or a kit** ([Amazon Link](https://amzn.to/41fhJcw)) - Used to secure the display to the frame.
- **5V to 3.3V Converter** ([Amazon Link](https://amzn.to/4hUir4z)) - Ensures safe voltage conversion for the ESP01, which operates at 3.3V.
- **Adapter board for ESP01** ([Amazon Link](https://amzn.to/4gJpQmm)) - Makes it easier to connect the ESP01 without soldering directly to its pins.
- **Button** ([Amazon Link](https://amzn.to/4gFSTqH)) - Allows user interaction, triggering functions like the Magic 8-Ball feature.
- **3D Printing Filament** ([Amazon Link](https://amzn.to/3X2V80l)) - Used to print the physical casing for the HappyCube.
- **Soldering tin and wires** - Necessary for making electrical connections between components.

## **Installation and Setup**

### **Hardware Assembly (Coming Soon)**
A detailed guide on assembling the hardware and wiring connections will be added soon.

### **Software Requirements**

- Arduino IDE
- Libraries:
  - `Adafruit_GFX`
  - `Adafruit_SSD1306`
  - `ESP8266WiFi`
  - `NTPClient`

### **Flashing the Code**

Follow the following instructions to upload the code. For beginners who have never worked with an ESP01, I recommend the following tutorial which helped me a lot my first time using an ESP01 (link to tutorial: https://www.instructables.com/Program-ESP01-Using-FTDI/):

1. **Install the Arduino IDE**: Download and install the **Arduino IDE** from the [official website](https://www.arduino.cc/en/software).

2. **Add ESP8266 Board Support**:
   - Open **Arduino IDE** and go to `File` > `Preferences`.
   - In the "Additional Board Manager URLs" field, enter:
     ```
     http://arduino.esp8266.com/stable/package_esp8266com_index.json
     ```
   - Go to `Tools` > `Board` > `Boards Manager` and search for "ESP8266".
   - Install the **ESP8266 by ESP8266 Community** package.

3. **Install Required Libraries**:
   - Open **Arduino IDE** and go to `Sketch` > `Include Library` > `Manage Libraries`.
   - Search for and install the following libraries:
     - `Adafruit GFX`
     - `Adafruit SSD1306`
     - `ESP8266WiFi`
     - `NTPClient`

4. **Connecting and Programming the ESP01**:
   - Connect TX -> RX and RX -> TX between the ESP01 and the FTDI adapter to ensure proper communication.

5. **Open the Code**:
   - Download the HappyCube code and open `HappyCube.ino` in the Arduino IDE.
   - In `TimeModule.cpp`, replace `your-SSID` and `your-PASSWORD` with your Wi-Fi credentials.

6. **Select the ESP01 Board and Port**:
   - Go to `Tools` > `Board` and select **Generic ESP8266 Module**.
   - Set `Flash Size` to **1MB (FS: 64KB)**.
   - Choose the correct COM port under `Tools` > `Port`.

7. **Upload the Code**:
   - Click the **Upload** button (✓ → ➡).
   - Wait for the upload to complete.
   - If you get an error, check your connections and ensure GPIO0 is held low during upload.

8. **Restart Your ESP01**:
   - Once uploaded, restart the ESP01 by disconnecting and reconnecting power.
   - The HappyCube should start running immediately.

## **Usage**

- When powered on, HappyCube begins exploring, moving its eyes and blinking randomly
- Press the button to get a randomly generated answer to a yes/no question
- The time is displayed periodically, automatically synced via Wi-Fi

## **Customization**

- Modify **bitmap animations** in `FaceAnimation.cpp` to create new facial expressions
- Add more **8-ball responses** in `Magic8Ball.h`
- Adjust **display settings** in `Display.cpp`

## **Inspiration**

This project is inspired by a children's book about a small computer that is sent to the moon. The focus is not just on technology but on **interaction** – making it feel as if the cube is thinking, observing, and reacting in its own little world.
