
# 🔥 Gas Detection System using Arduino

An Arduino-based gas monitoring system that uses **MQ-2 and MQ-7 gas sensors** to detect potentially dangerous gas or smoke levels. When the sensor readings cross predefined threshold values, the system activates an **LED and buzzer** to provide an immediate warning.

This project is a simple hardware-based safety prototype that demonstrates how gas sensors, Arduino, and basic alert components can be combined to create a real-time gas detection system.

## 📌 Features

* Detects gas/smoke levels using **MQ-2**
* Monitors CO levels using **MQ-7**
* Provides visual warning through an **LED**
* Provides an audible warning through a **5V buzzer**
* Displays live sensor readings through the **Arduino Serial Monitor**
* Automatically triggers an alarm when a threshold is exceeded
* Uses simple and easy-to-understand Arduino programming

## 🛠️ Components Required

| Component       |    Quantity |
| --------------- | ----------: |
| Arduino UNO     |           1 |
| MQ-2 Gas Sensor |           1 |
| MQ-7 Gas Sensor |           1 |
| 5V Buzzer       |           1 |
| LED             |           1 |
| 180Ω Resistor   |           1 |
| Jumper Wires    | As required |
| Breadboard      |           1 |
| USB Cable       |           1 |

> **Note:** The uploaded circuit diagram and source code are configured for **MQ-2 and MQ-7**. If you are using an MQ-5 sensor instead of MQ-2, the sensor configuration and threshold values should be adjusted accordingly.

---

## 💻 Software Requirements

* **Arduino IDE**
* Arduino UNO board
* USB cable for connecting Arduino to the computer

---

# ⚙️ Installation and Setup

## 1. Install Arduino IDE

Download and install the Arduino IDE from the official Arduino website:

**https://www.arduino.cc/en/software**

Install the version suitable for your operating system.

After installation, open the **Arduino IDE**.

## 2. Connect Arduino UNO

1. Connect the Arduino UNO to your computer using a USB cable.
2. Open Arduino IDE.
3. Go to:

```text
Tools → Board → Arduino AVR Boards → Arduino Uno
```

4. Select the correct COM port:

```text
Tools → Port → COMx
```

The exact port number may be different on your computer.

---

# 🔌 Circuit Connections

Build the circuit according to the provided circuit diagram.

### MQ-2 Sensor

| MQ-2 Pin/Output | Arduino UNO |
| --------------- | ----------- |
| VCC             | 5V          |
| GND             | GND         |
| AOUT            | A0          |

The MQ-2 reading is obtained through **analog pin A0**.

### MQ-7 Sensor

| MQ-7 Pin/Output | Arduino UNO |
| --------------- | ----------- |
| VCC             | 5V          |
| GND             | GND         |
| AOUT            | A1          |

The MQ-7 reading is obtained through **analog pin A1**.

### Buzzer

| Buzzer   | Arduino UNO    |
| -------- | -------------- |
| Positive | Digital Pin 11 |
| Negative | GND            |

### LED

| LED Circuit         | Arduino UNO    |
| ------------------- | -------------- |
| LED + 180Ω resistor | Digital Pin 12 |
| Other LED terminal  | GND            |

The **180Ω resistor** is used to limit current through the LED.

> Make sure all components share a **common GND** with the Arduino.

---

# 🧩 Pin Configuration

The project uses the following pins:

```cpp
const int MQ2_PIN = A0;
const int MQ7_PIN = A1;
const int BUZZER_PIN = 11;
const int LED_PIN = 12;
```

The system reads the two sensors through the Arduino's analog inputs and controls the buzzer and LED through digital pins.

---

# 📥 Uploading the Code

1. Open the provided `.ino` file in Arduino IDE.
2. Connect the Arduino UNO to your computer.
3. Select:

```text
Tools → Board → Arduino Uno
```

4. Select the correct COM port.
5. Click the **Verify** button to compile the program.
6. Click **Upload** to transfer the code to the Arduino.

Once the upload is completed successfully, the system will start running.

---

# ▶️ How the System Works

After powering the Arduino:

1. The system starts the MQ-2 and MQ-7 sensors.
2. It displays a startup message in the Serial Monitor.
3. The sensors are given **60 seconds of warm-up time**.
4. After warm-up, Arduino continuously reads both sensor values.
5. The readings are displayed on the Serial Monitor.
6. The readings are compared with predefined threshold values.
7. If either sensor reading goes above its threshold:

   * 🔴 LED turns ON
   * 🔊 Buzzer turns ON
   * Gas leakage warning is displayed
8. When the readings return below the thresholds, the LED and buzzer turn OFF.

---

# 📊 Threshold Values

The current program uses the following threshold values:

```cpp
const int MQ2_THRESHOLD = 300;
const int MQ7_THRESHOLD = 550;
```

The logic used by the program is:

```cpp
if (mq2_value > MQ2_THRESHOLD || mq7_value > MQ7_THRESHOLD)
```

This means the alarm is activated when **either MQ-2 or MQ-7 exceeds its configured threshold**.

> These threshold values are example values used in the prototype. They are not universal gas concentration limits. Sensor readings can vary depending on the sensor module, environment, warm-up condition, and calibration.

---

# 🖥️ Viewing Sensor Readings

After uploading the program:

1. Open **Tools → Serial Monitor**.
2. Set the baud rate to:

```text
9600
```

You should see messages similar to:

```text
Gas Detection System Starting Up...
Please wait 60 seconds for sensors to warm up...
Sensors Ready.
MQ-2 (Smoke/LPG): 245 | MQ-7 (CO): 430
```

When a threshold is exceeded:

```text
*** GAS LEAK DETECTED! ALARM ACTIVE! ***
```

The buzzer and LED will also turn ON.

---

# 🧠 Program Logic

The main working process can be summarized as:

```text
Start
   ↓
Initialize Arduino Pins
   ↓
Start Serial Communication
   ↓
60-Second Sensor Warm-Up
   ↓
Read MQ-2 and MQ-7
   ↓
Display Sensor Values
   ↓
Compare Values with Thresholds
   ↓
Is Any Threshold Exceeded?
   ↙                ↘
 Yes                 No
 ↓                    ↓
LED ON             LED OFF
Buzzer ON          Buzzer OFF
 ↓                    ↓
       Repeat
```

---

# 📁 Project Structure

A simple repository structure can be:

```text
Gas-Detection-Arduino/
│
├── README.md
├── gas_detection_ard_mq7.ino
└── gas_detection_mq7crkt.jpg
```


# 🎥 Project Demonstration

A demonstration video showing the working of the gas detection system is available here:

**Google Drive:**
`https://drive.google.com/drive/folders/1d26j2Yh5p9xnoa4tWckn3i0uHhMlXRr9?usp=sharing`

The video demonstrates the sensor readings, circuit operation, and activation of the LED and buzzer when the gas level crosses the configured threshold.

---


# ⚠️ Important Note

This project is intended as an **educational/prototype gas detection system**. MQ-series sensor modules require appropriate warm-up and calibration, and their raw analog readings should not be treated as certified gas concentration measurements or as a replacement for industrial safety equipment.

## 👩‍💻 Author

**Anushka Singh**

Built using **Arduino UNO, MQ-series gas sensors, C/C++, and basic electronics**.
