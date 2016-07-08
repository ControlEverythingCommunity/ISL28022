// Distributed with a free-will license.
// Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
// ISL28022
// This code is designed to work with the ISL28022_I2CS I2C Mini Module available from ControlEverything.com.
// https://www.controleverything.com/products

#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>

void main()
{
    // Create I2C bus
    int file;
    char *bus = "/dev/i2c-1";
    if((file = open(bus, O_RDWR)) < 0)
    {
        printf("Failed to open the bus. \n");
        exit(1);
    }
    // Get I2C device, ISL28022 I2C address is 0x40(64)
    ioctl(file, I2C_SLAVE, 0x40);
    
    // Select configuration register(0x00)
    // No reset, Bus voltage range = 60V, PGA(Shunt voltage only) = +/- 320mV is (0x79)
    // Bus & shunt ADC resolution = 15-bit, Shunt and bus & continuous mode is (0x9F)
    char config[3] = {0};
    config[0] = 0x00;
    config[1] = 0x79;
    config[2] = 0x9F;
    write(file, config, 3);
    sleep(1);
    
    // Read 2 bytes of data from register(0x01)
    // raw_shunt msb, raw_shunt lsb
    char reg[1] = {0x01};
    write(file, reg, 1);
    char data[2] = {0};
    if(read(file, data, 2) != 2)
    {
        printf("Error : Input/output Error \n");
        exit(1);
    }
    else
    {
        // Convert the data
        int raw_shunt = (data[0] * 256 + data[1]) / 16;
        if(raw_shunt > 32767)
        {
            raw_shunt -= 32768;
        }
        
        
        // Output data to screen
        printf("Raw value of Shunt Voltage is: %d\n", raw_shunt);
    }
}
