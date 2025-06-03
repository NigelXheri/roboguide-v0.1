
# 🤖 ROBOGUIDE v0.1 - TL;DR Quickstart Section

Download all the files in this repository.
To work with the huskylens code you should install some prerequisites. Most of them require creating a virtual environment so it is better to do that.

Create a virtual environment in Python.
Install prerequisites(these are what I remember but thre could be more):
  - pyserial
  - pypng
  - json
  - pygame

Check online on how to install them or how to create the virtual environment.
You can also copy/paste this README file to an LLM like ChatGPT and just follow the instructions.



# 🤖 ROBOGUIDE v0.1 - Detailed Section

**RoboGuide v0.1** is the MVP prototype of an autonomous robotic guide that assists users in indoor environments such as museums, malls, or events. This version of RoboGuide combines vision recognition (via HuskyLens), Raspberry Pi-based processing, and Arduino-powered motor control. RoboGuide was the winning robot at RoboTech 2024.

---

## 🧠 Features

- 🚶 Object tracking using HuskyLens AI camera
- 🔁 Communication between Raspberry Pi and Arduino via Serial
- 🔊 Real-time user feedback (screen/sound capable)
- 🧠 Modular architecture for future upgrades (navigation, speech, AI agents)
- 🏆 Built and tested for RoboTech 2024

---

## 📂 Project Structure

```
roboguide-v0.1/
├── huskylens_RPi.py     # Main Python script to interface with HuskyLens
├── huskylib.py          # The official HUSKYLENS library
├── v0_15.ino            # Arduino code controlling motors and sensors
├── README.md            # Project documentation
└── LICENSE              # MIT License
```

---

## 🖥️ System Requirements

### Hardware

- Raspberry Pi 3 or 4
- HuskyLens AI Camera (DFRobot)
- Arduino Mega or Uno (recommended: Mega)
- Motor driver (e.g. L298N)
- Ultrasonic sensors (optional for obstacle detection)
- Power supply (USB or Li-ion)

### Software

- Python 3.8+
- Arduino IDE 1.8+
- Libraries: `pyserial`, `pygame`, `json`, `pypng`

---

## 🛠️ Installation

### Python Side (Raspberry Pi)

```bash
python3 -m venv venv
source venv/bin/activate
pip install -r requirements.txt
```

### Arduino Side

1. Open `v0_15.ino` in Arduino IDE
2. Select the correct board (e.g., Arduino Mega)
3. Upload the sketch to the board

---

## 🚀 Running the System

1. Connect the HuskyLens to the Raspberry Pi via I2C (SDA/SCL)
2. Connect the Arduino to the Pi via USB
3. Run:

```bash
python huskylens_RPi.py
```

4. The robot will detect learned tags from HuskyLens and send corresponding commands to Arduino to move accordingly (Make sure to enable Learn Multiple if you want to use multiple April tags at once).

---

## 📡 Architecture Diagram

```
[HuskyLens] <--UART--> [Raspberry Pi] <--USB Serial--> [Arduino Mega]
			                                              |
			                                              |--> Motor Drivers
			                                              |--> Ultrasonic Sensor
			                                              |--> Infrared Sensors
```

---

## 🏅 Achievements

- 🥇 Winner of RoboTech 2024
- 🛠️ Built using low-cost and modular components
- 👨‍💻 Designed for educational and commercial scalability

---

## 📄 License

This project is licensed under the MIT License - see the LICENSE file for details.

---

## 🙌 Credits

Developed by Nigel Xherimeja and Sara Kola  
University Metropolitan Tirana – RoboTech 2024


