import pyaudio
import numpy as np
import matplotlib.pyplot as plt
import serial
import time
import struct
arduino = serial.Serial('/dev/cu.usbmodem14101', 115200, timeout=.1)

time.sleep(1)

np.set_printoptions(suppress=True) # don't use scientific notation

CHUNK = 4096 # number of data points to read at a time
RATE = 44100 # time resolution of the recording device (Hz)

p=pyaudio.PyAudio() # start the PyAudio class
stream=p.open(format=pyaudio.paInt16,channels=1,rate=RATE,input=True,
              frames_per_buffer=CHUNK) #uses default input device

# create a numpy array holding a single read of audio data
while True: #to it a few times just to see
    data = np.fromstring(stream.read(CHUNK),dtype=np.int16)
    data = data * np.hanning(len(data)) # smooth the FFT by windowing data
    fft = abs(np.fft.fft(data).real)
    fft = fft[:int(len(fft)/2)] # keep only first half
    freq = np.fft.fftfreq(CHUNK,1.0/RATE)
    freq = freq[:int(len(freq)/2)] # keep only first half
    freqPeak = freq[np.where(fft==np.max(fft))[0][0]]+1
    print("peak frequency: %d Hz"%freqPeak)
    if (freqPeak > 5000 and freqPeak <= 800):
        print(1)
        arduino.write(struct.pack('>B', 1))
        #arduino.write(str(1))
    elif (freqPeak > 800 and freqPeak <= 1000):
        print(2)
        arduino.write(struct.pack('>B', 2))
        #arduino.write(str(2))
    elif (freqPeak > 1000 and freqPeak <= 1100):
        print(3)
        arduino.write(struct.pack('>B', 3))
        #arduino.write(str(3))
    elif (freqPeak > 1100 and freqPeak <= 1150):
        print(4)
        arduino.write(struct.pack('>B', 4))
        #arduino.write(str(4))
    elif (freqPeak > 1150 and freqPeak <= 1200):
        print(5)
        arduino.write(struct.pack('>B', 5))
        #arduino.write(str(5))
    elif (freqPeak > 1200 and freqPeak <= 1350):
        print(6)
        arduino.write(struct.pack('>B', 6))
        #arduino.write(str(6))
    elif (freqPeak > 1350):
        print(7)
        arduino.write(struct.pack('>B', 7))
        #arduino.write(str(7))
    else:
        arduino.write(struct.pack('>B', 0))
        #arduino.write(str(0))

    # uncomment this if you want to see what the freq vs FFT looks like
    #plt.plot(freq,fft)
    #plt.axis([0,4000,None,None])
    #plt.show()
    #plt.close()

# close the stream gracefully
stream.stop_stream()
stream.close()
p.terminate()