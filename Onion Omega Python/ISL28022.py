# Distributed with a free-will license.
# Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
# ISL28022
# This code is designed to work with the ISL28022_I2CS I2C Mini Module available from ControlEverything.com.
# https://www.controleverything.com/products

from OmegaExpansion import onionI2C
import time

# Get I2C bus
i2c = onionI2C.OnionI2C()

# ISL28022 address, 0x40(64)
# Select configuration register, 0x00(00)
#		0x799F(31135)   No reset, Bus voltage range = 60V, PGA(Shunt voltage only) = +/- 320mV
#                       Bus & shunt ADC resolution = 15-bit, Shunt and bus & continuous mode
data = [0x799F]
i2c.writeBytes(0x40, 0x00, data)

time.sleep(0.5)

# ISL28022 address, 0x40(64)
# Read data back from 0x01(01), 2 bytes
data = i2c.readBytes(0x40, 0x01, 2)

# Convert the data
raw_shunt = data[0] * 256 + data[1]
if raw_shunt > 32767 :
    raw_shunt -= 65536

# Output data to screen
print "Raw Value of Shunt Voltage :%d" %raw_shunt
