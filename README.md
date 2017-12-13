# Gizmo 2017 : Panopticon

## Concept:

Panopticon is a responsive mechanical eye. The project integrates machine elements with simple feedback control systems, in which a variety of sensors and actuators are connected to Arduino and Raspberry Pi.

The eye responds to changes in light intensity. When these changes are sensed by a photoresistor, a servo is actuated resulting in the iris mechanism contracting or dilating appropriately. The eye also responds and rotates when it senses a presence, through the aid of two IR sensors and a stepper motor.  Within the structure in the centre of the eye sits a Raspberry Pi camera which projects a live camera feed onto a screen that reflects back to the observer via mirrors at the rear of the structure. 

Our name was inspired by the institutional building and system of control, ‘The Panopticon’, introduced by English philosopher, Jeremy Bentham. The theme of the design is to allow the inmates to be observed by a single watchman, the setup is such that the inmates do not know when they are being watched therefore are constantly under watch.

## Contributors:

Ruksana Shaukat Jali, Francesca Suer, Sophie Owen and Neel Le Penru

## Acknowledgements:

Parts of the code were inspired and adapted from the following sources. 
- Code for Stepper Motor and Servo modified from https://github.com/ICL-DE/Gizmo/blob/master/Chapter_7_Actuators/Actuators.md
- Sharp IR Range Sensor, distance calculation adapted from http://www.instructables.com/id/How-to-Use-the-Sharp-IR-Sensor-GP2Y0A41SK0F-Arduin/ 
- Installing PiCamera Module from https://www.raspberrypi.org/documentation/usage/camera/python/README.md
- Code for running startup on Raspberry Pi from https://raspberrypi.stackexchange.com/questions/8734/execute-script-on-start-up


