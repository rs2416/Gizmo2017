#---Before running the following Python code, the following steps need to be take (using Linux on the Pi):

#sudo apt-get update //update to the latest version of Raspbian
#sudo apt-get install python-picamera //Install the python PiCamera interface to work with the Raspberry Pi camera module.

#We made the code to start the video stream to the display work on startup for convenience, which also takes a few steps:

#---To make the code run on startup (adapted from https://raspberrypi.stackexchange.com/questions/8734/execute-script-on-start-up):
#We saved the code below in a .py file in the pi folder (accessed by $ cd ~ ) and made it executable with $ sudo chmod +x filename.py
#Then edit the last line of .bashrc: 
    # $ sudo nano .bashrc
#Add ./filename.py to the bottom line of .bashrc and save and exit.


#---The actual contents of the Python script:

import time #to create a delay which will set the time in which the camera actively outputs to the HDMI display.
import picamera #import the Python camera module
camera = picamera.PiCamera() #define our camera as the one attached to the Raspberry Pi's dedicated camera connection port.
camera.start_preview() #instantly starts outputting the camera feed to the attached HDMI display
time.sleep(900) #delay for 900 seconds (15 minutes) so that the camera outputs to the display for 15 minutes. The length of time can of course be changed.
camera.stop_preview() #stops streaming a live feed of the camera to the display.
