 [![ISL28022](ISL28022_I2CS.png)](https://www.controleverything.com/products)
# ISL28022
ISL28022 Precision Digital Power Monitor.

The ISL28022 is a bidirectional high-side and low-side digital current sense and voltage monitor with serial interface.

This Device is available from ControlEverything.com [SKU: ISL28022_I2CS]

https://www.controleverything.com/products

This Sample code can be used with Raspberry Pi, Arduino Nano, Particle Photon, Beaglebone Black and Onion Omega.

## Java
Download and install pi4j library on Raspberry Pi. Steps to install pi4j are provided at:

http://pi4j.com/install.html

Download (or git pull) the code in pi.

Compile the java program.
```cpp
$> pi4j ISL28022.java
```

Run the java program.
```cpp
$> pi4j ISL28022
```

## Python
Download and install smbus library on Raspberry pi. Steps to install smbus are provided at:

https://pypi.python.org/pypi/smbus-cffi/0.5.1

Download (or git pull) the code in pi. Run the program.

```cpp
$> python ISL28022.py
```

## Arduino
Download and install Arduino Software (IDE) on your machine. Steps to install Arduino are provided at:

https://www.arduino.cc/en/Main/Software

Download (or git pull) the code and double click the file to run the program.

Compile and upload the code on Arduino IDE and see the output on Serial Monitor.


## Particle Photon
Login to your Photon and setup your device according to steps provided at:

https://docs.particle.io/guide/getting-started/connect/photon/

Download (or git pull) the code. Go to online IDE and copy the code.

https://build.particle.io/build/

Verify and flash the code on your Photon. Code output is shown in logs at dashboard:

https://dashboard.particle.io/user/logs


## C
Setup your device according to steps provided at:

https://beagleboard.org/getting-started

Download (or git pull) the code in Beaglebone Black.

Compile the c program.
```cpp
$>gcc ISL28022.c -o ISL28022
```
Run the c program.
```cpp
$>./ISL28022
```

## Onion Omega

Get Started and setting up the Onion Omega according to steps provided at :

https://wiki.onion.io/Get-Started

To install the Python module, run the following commands:
```cpp
opkg update
```
```cpp
opkg install python-light pyOnionI2C
```

Download (or git pull) the code in Onion Omega. Run the program.

```cpp
$> python ISL28022.py
```

#####The code output is raw value of the shunt voltage.
