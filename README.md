# SG90 Servo — Sample Code

Sample sketch for the **[SG90 Micro Servo](https://circuit.rocks/search?q=SG90)**, sold by [Circuitrocks](https://circuit.rocks/).

This example sweeps the servo from 0° to 180° and back, using the built-in Arduino `Servo` library. No extra installation required.

## What you need

- 1x SG90 micro servo
- 1x Arduino Uno (or compatible)
- 3x jumper wires

## Wiring

| SG90 wire | Arduino Uno pin |
|-----------|-----------------|
| Brown (-) | GND             |
| Red (+)   | 5V              |
| Orange    | D9 (signal)     |

> **Power tip:** an SG90 draws ~10 mA when idle but can briefly spike to 600 mA or more when starting motion or under load. A single SG90 driven gently usually works on the Arduino's 5 V pin, but if the Arduino keeps resetting, use a separate 5–6 V supply (battery pack or a 5 V buck converter) and **share GND** between the supply and the Arduino.

## How to use

1. Open `sg90.ino` in the Arduino IDE.
2. Select **Tools → Board → Arduino Uno** and the correct COM port.
3. Click **Upload**.
4. The servo immediately starts sweeping 0° → 180° → 0° in a continuous loop.
5. Open **Tools → Serial Monitor** at **9600** baud if you want to see the startup message.

## Adapting it

- **Different signal pin:** change `SERVO_PIN` at the top of the sketch.
- **Limit travel:** change the loop ranges (`for (int angle = 30; angle <= 150; ...)`).
- **Move to a specific angle:** call `servo.write(90);` and skip the loops.

## Notes

- The SG90 is rated for **0°–180°** travel but the actual range varies by unit (some only do 170°, some do 185°+). Don't drive it past its mechanical stops or you'll strip the gears.
- The library uses Timer1 on Arduino Uno, which means **PWM on pins 9 and 10 is unavailable** while a Servo is attached.
- For a continuous-rotation SG90 (different model — the "FS90R" variant), `servo.write(0)` is full reverse, `servo.write(90)` is stop, and `servo.write(180)` is full forward.

## Datasheet

[SG90 datasheet (Tower Pro, PDF)](http://www.ee.ic.ac.uk/pcheung/teaching/DE1_EE/stores/sg90_datasheet.pdf)

## Troubleshooting

- **Servo twitches and resets the Arduino** — the servo is pulling too much current. Power it from a separate supply.
- **Servo only moves a few degrees** — check the signal wire. Some SG90 clones have the signal wire as the middle one — swap if needed.
- **Servo buzzes when at rest** — small drift in the PWM signal is normal. If it's constant, try `servo.detach()` after reaching the target angle to silence it.

## License

MIT — see [LICENSE](LICENSE).

## Got stuck?

Drop by [circuit.rocks](https://circuit.rocks/) — happy to help our customers get their modules working.
