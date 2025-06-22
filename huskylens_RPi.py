import random
import serial
import time
import json
import pygame
from huskylib import HuskyLensLibrary

# replace the address value with your I2C address from before in 0x00 form
hl = HuskyLensLibrary("I2C", "", address=0x32)


ser = serial.Serial('/dev/ttyACM0', 9600)
check = 0
pygame.mixer.init(devicename="Heju 2")
pygame.mixer.music.set_volume(1.0)

# AfterAprilTag
timeAfterRecognition = 3


terminal_banner = r'''
    ____  ____  ____  ____  ________  __________  ______                  ____   ___
   / __ \/ __ \/ __ )/ __ \/ ____/ / / /  _/ __ \/ ____/           _   __/ __ \ <  /
  / /_/ / / / / __  / / / / / __/ / / // // / / / __/    ______   | | / / / / / / / 
 / _, _/ /_/ / /_/ / /_/ / /_/ / /_/ // // /_/ / /___   /_____/   | |/ / /_/ / / /  
/_/ |_|\____/_____/\____/\____/\____/___/_____/_____/             |___/\____(_)_/   
                                                                                     '''

print(terminal_banner)


while True:
    try:
        if hl.getBlocksByID(1) and check != 1:
            print("taken")
            time.sleep(timeAfterRecognition)
            pygame.mixer.music.load("/home/enkel/Downloads/1_posta.wav")
            check = 1
            print('sent')
            pygame.mixer.music.play()
            while pygame.mixer.music.get_busy():
                ser.write(b'1')
                continue
            print('sent0')

    except:
        try:
            if hl.getBlocksByID(2) and check != 2:
                time.sleep(timeAfterRecognition)
                pygame.mixer.music.load("/home/enkel/Downloads/2_banka.wav")
                pygame.mixer.music.play()
                check = 2
                while pygame.mixer.music.get_busy():
                    ser.write(b'1')
                    continue
        except:
            try:
                if hl.getBlocksByID(3) and check != 3:
                    time.sleep(timeAfterRecognition)
                    pygame.mixer.music.load(
                        "/home/enkel/Downloads/3_universiteti.wav")
                    pygame.mixer.music.play()
                    check = 3
                    while pygame.mixer.music.get_busy():
                        ser.write(b'1')
                        continue
                    pygame.mixer.music.load(
                        "/home/enkel/Downloads/4_outro.wav")
                    pygame.mixer.music.play()
                    while True:
                        ser.write(b'1')
            except:
                pass
