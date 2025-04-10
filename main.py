# pip install pyserial psutil

import serial
import time
import psutil

# Adjust COM port to match your setup (e.g., "COM3" or "/dev/ttyUSB0")
arduino = serial.Serial('COM3', 9600)
time.sleep(2)  # Wait for Arduino to reset

while True:
    cpu = psutil.cpu_percent()
    ram = psutil.virtual_memory().percent
    data = f"{int(cpu)},{int(ram)}\n"
    arduino.write(data.encode('utf-8'))
    time.sleep(1)
