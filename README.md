# 🛡️ SentinelX: Edge AI Fall Risk Prediction & Prevention Wearable

**Problem Statement ID:** MC-48 | **Campus:** SVYASA BANGALORE

[![Simulation Available](https://img.shields.io/badge/Wokwi-Live_Simulation-blue?logo=arduino)](https://wokwi.com/projects/461212275018990593)
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)
[![Hardware](https://img.shields.io/badge/Hardware-ESP32%20%7C%20MPU6050-orange)](#)

## 📌 The Challenge
Elderly falls cause severe injuries and delayed medical responses. Existing market solutions either detect falls *after* the impact has occurred, are prohibitively expensive, or rely heavily on constant cloud connectivity. There is a critical need for an affordable, offline system that predicts risk early, detects falls reliably, and alerts caregivers immediately.

## 💡 Our Solution: SentinelX
SentinelX is a low-cost wearable device that utilizes an MPU6050 motion sensor connected to an ESP32. By running an edge Machine Learning model for real-time analysis, it achieves offline pre-fall prediction and instant alerts. 

### Key Innovations
* **Pre-Fall Prediction:** Analyzes motion patterns to calculate an instability score before a critical fall occurs.
* **Fully Offline Edge Processing:** No cloud dependency; processing happens locally on the ESP32 in `<200ms`.
* **Ultra Low-Cost:** Total Bill of Materials (BOM) comes under ₹2,500 (~₹2,170 current estimate).
* **Real-Time Visual Interface:** A 0.96” OLED provides immediate status feedback (`SAFE` / `RISK` / `FALL DETECTED`).

---

## ⚙️ Interactive Live Simulation
You can interact with our exact hardware and software architecture without any physical components! 

**👉 [Run the SentinelX Simulation on Wokwi](https://wokwi.com/projects/461212275018990593)**

*Instructions:*
1. Open the link and click the **Play** button.
2. The OLED will initialize and show `SentinelX Booting...` before transitioning to the `SAFE` status.
3. Click on the MPU6050 sensor in the simulator to change the acceleration values.
4. Spike the `Z` axis `> 15 m/s²` or drop it `< 2.0 m/s²` (simulating freefall/impact) to trigger the `RISK/FALL DETECTED` alert and activate the buzzer.

---

## 🛠️ Hardware Architecture & BOM

| Component | Purpose | Cost Estimate |
| :--- | :--- | :--- |
| **ESP32 DevKit V1** | Edge compute + Wi-Fi | ₹500 |
| **MPU6050 IMU** | 6-axis motion sensing | ₹150 |
| **0.96” I2C OLED** | Real-time visual status display | ₹200 |
| **SIM800L GSM Module** | Caregiver SMS alert routing | ₹400 |
| **Buzzer & Li-ion Battery**| On-device audio alert & portable power | ₹470 |

*(Total Prototype Cost Estimate: ₹2,170)*

---

## 💻 Software Stack
* **Firmware:** Developed in Arduino IDE / PlatformIO using C++.
* **Edge ML:** Built utilizing TensorFlow Lite Micro for on-device inference optimization.
* **Data Processing:** Python (NumPy, Pandas) used for dataset cleaning and threshold baselining.

## 🚀 Execution & Timeline
Our team is committed to a structured 60-day development cycle:
* **Phase 1:** Component procurement, sensor calibration, and normal vs. stumble IMU data collection.
* **Phase 2:** Training lightweight classifiers to achieve `≥85%` baseline accuracy.
* **Phase 3:** TFLite Micro conversion, ESP32 deployment, and OLED/Buzzer integration.
* **Phase 4:** Field testing, threshold tuning, and mitigating false positives through activity gating.

---

## 👥 The Team
**Team: SentinelX**
* **Sankirth R Bhat** (CSE)
* **Manish P Shetty** (CSE)
* **N Darshit** (CSE)

---
*Built for the Makers Conclave 2026. Empowering independent living through accessible embedded technology.*
