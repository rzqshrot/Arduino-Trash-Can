# Arduino-Trash-Can
Controlled trash using Arduino, which uses an ultrasonic sensor and a servo motor.
The ultrasonic sensor is fixed on the front side of the garbage. When a person approaches 20 cm from the trash basket, the sensor is activated and ordered the trash to open by means of a servo motor that rotates 65 degrees. When he goes away more than 30 cm, the servo motor closes the trash at a rate of
4/100 ms. If a person is detected again during the closure phase, the trash will open again.
