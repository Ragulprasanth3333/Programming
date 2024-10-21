Project: Bluetooth Controlled 4-Motor Robot

Description:
This project is a Bluetooth-controlled robot built using an Arduino Uno, an HC-05 Bluetooth module, and an L293D motor driver. The robot is controlled via a smartphone, and the motors move according to commands received from the HC-05 Bluetooth module. Two motors are connected in parallel to Motor 1 (M1), and two motors are connected in parallel to Motor 2 (M2). A 12V battery powers the motors.

Components:
1. Arduino Uno
2. HC-05 Bluetooth Module
3. L293D Motor Driver
4. 4 DC Motors (2 connected to M1, 2 connected to M2 in parallel)
5. 12V Battery
6. Smartphone (for transmitting Bluetooth commands)

Wiring:
- **Motors**: 
   - 2 motors connected in parallel to M1 pins of L293D
   - 2 motors connected in parallel to M2 pins of L293D
- **HC-05 Bluetooth Module**:
   - VCC -> 5V
   - GND -> GND
   - TXD -> Arduino RX (Pin 0)
   - RXD -> Arduino TX (Pin 1)
- **L293D Motor Driver**:
   - Connect the inputs IN1, IN2, IN3, and IN4 to Arduino digital pins (as specified in code)
   - EN1 connected to PWM pin for speed control
   - Motors connected to output pins of L293D (M1, M2)

Arduino Code:
The code reads serial data received from the HC-05 Bluetooth module and controls the direction and speed of the motors accordingly. It accepts the following commands:
- 'F' for Forward
- 'B' for Backward
- 'L' for Left turn
- 'R' for Right turn
- 'S' for Stop

Power Supply:
- A 12V battery is used to power the motors via the L293D motor driver.

Setup Instructions:
1. Wire the motors, Bluetooth module, and motor driver to the Arduino as per the wiring diagram.
2. Upload the provided Arduino code to the Arduino Uno.
3. Connect the smartphone to the HC-05 Bluetooth module.
4. Use a Bluetooth terminal app on the smartphone to send commands ('F', 'B', 'L', 'R', 'S') to control the robot.

Commands:
- 'F' -> Move Forward
- 'B' -> Move Backward
- 'L' -> Turn Left
- 'R' -> Turn Right
- 'S' -> Stop

Author: Ragul prasanth
