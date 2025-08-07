## 🏦 STM32 UART Bootloader with ESP32 BLE/MQTT FOTA

### Overview

This project implements a **firmware update system over UART** for the `STM32F103C8T6` microcontroller, with **update requests triggered wirelessly** by an `ESP32` acting as a central device. The firmware is received via UART, written to flash, verified using CRC, and backed up to allow rollback in case of failure.

The system is built in a **modular, maintainable structure using STM32CubeIDE HAL**.

---

## 🧹 Architecture

```
 Backend Server
     |
     | (Firmware Forwarding via BLE/MQTT)
     ↓
 ESP32 (Central)
     |
     | (Pulls UPDATE Pin High + UART Tx)
     ↓
 STM32F103C8T6
   └── Bootloader
        ├── Checks update pin
        ├── Receives firmware via UART
        ├── Verifies CRC
        ├── Stores firmware and backup
        └── Jumps to main application
```

---

## 📁 Project Structure

```
FotaSecure/              → Backend + client app for managing firmware
ESP32_Central/           → ESP32 BLE/MQTT firmware forwarder
STM32_Bootloader/        → STM32CubeIDE project
│
├── Core/                → Bootloader source files
├── Drivers/             → STM32 HAL drivers
├── FOTA_BOOTLOADER.ioc  → STM32CubeMX config file
└── STM32F103C8TX_FLASH.ld → Linker script (bootloader at 0x08000000)
```

---

## 🧐 Features

* **Modular Bootloader** for STM32F103C8T6
* **UART-based firmware reception**
* **Backup and rollback mechanism**
* **CRC32 check before flashing**
* **Firmware jumps to main app at a defined flash address**
* **BLE/MQTT wireless update trigger via ESP32**
* **Backend support for firmware upload & management**

---

## ⚙️ Flash Memory Map

| Region           | Address      | Size   | Description       |
| ---------------- | ------------ | ------ | ----------------- |
| Bootloader       | `0x08000000` | 16KB   | UART-based loader |
| Main Application | `0x08004000` | \~32KB | Updated firmware  |
| Backup Firmware  | `0x0800C000` | \~32KB | For rollback      |

---

## 🚀 Workflow

1. **Firmware is uploaded** to the backend server.
2. **ESP32** receives firmware via BLE/MQTT.
3. ESP32 **pulls STM32 update pin high** and sends firmware via UART.
4. STM32 **bootloader starts on reset**, checks OTA pin.
5. Firmware is received, **CRC32 is verified**.
6. If valid, firmware is flashed to app region.
7. Backup is stored.
8. Execution is transferred to new firmware.
9. If CRC fails or flashing error occurs, **rollback to backup** is triggered.

---

## 💠 Setup Instructions

### STM32 Bootloader (STM32CubeIDE)

1. Open the `.ioc` file with STM32CubeIDE.
2. Build and flash the bootloader to your STM32.
3. Bootloader starts at `0x08000000` and jumps to the app at `0x08004000`.

### ESP32 Firmware

* Use `ESP32_Central` to:

  * Connect to backend via BLE/MQTT.
  * Forward firmware to STM32 via UART.
  * Pull update GPIO high to trigger OTA.

### Backend + Frontend

* Navigate to `FotaSecure/`.
* Run:

  ```bash
  npm install
  npm run db:push //posgresql database migration
  npm run dev
  ```

---

## ✅ Dependencies

### STM32 Bootloader

* STM32CubeIDE + HAL drivers
* Flash API (HAL)
* UART
* GPIO
* CRC HAL module

### ESP32

* ESP-IDF
* UART communication
* BLE/MQTT libraries

### Backend

* Node.js
* Express or similar
* BLE or MQTT broker integration (e.g mosquito)

---

## 🧪 Testing & Debugging

* Use a UART terminal to simulate firmware transmission.
* Confirm CRC passes before flashing.
* If CRC fails or pin is low, bootloader skips flashing.
* Validate firmware execution post-jump.

---

## 🧱 Future Work

* Add encrypted firmware transmission (AES encryption)
* Add watchdog fallback recovery.
* Implement version checks before update.

---

## ✍️ Author

**Boateng Samuel**
Embedded Systems Developer | Hardware & Software Innovator
*Goal: Enable a hardware revolution from Africa to the world 🌍*
