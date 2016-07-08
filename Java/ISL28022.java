// Distributed with a free-will license.
// Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
// ISL28022
// This code is designed to work with the ISL28022_I2CS I2C Mini Module available from ControlEverything.com.
// https://www.controleverything.com/products

import com.pi4j.io.i2c.I2CBus;
import com.pi4j.io.i2c.I2CDevice;
import com.pi4j.io.i2c.I2CFactory;
import java.io.IOException;

public class ISL28022
{
    public static void main(String args[]) throws Exception
    {
        // Create I2C bus
        I2CBus Bus = I2CFactory.getInstance(I2CBus.BUS_1);
        // Get I2C device, ISL28022 I2C address is 0x40(64)
        I2CDevice device = Bus.getDevice(0x40);
        
        byte[] config = new byte[2];
        // No reset, Bus voltage range = 60V, PGA(Shunt voltage only) = +/- 320mV
        config[0] = (byte)0x79;
        // Bus & shunt ADC resolution = 15-bit, Shunt and bus & continuous mode
        config[1] = (byte)0x9F;
        // Write to configuration register, 0x00(00)
        device.write(0x00, config, 0, 2);
        
        // Read 2 bytes of data
        // raw_shunt msb, raw_shunt lsb
        byte[] data = new byte[2];
        device.read(0x01, data, 0, 2);
        
        // Convert the data
        int raw_shunt = ((data[0] & 0xFF)* 256 + (data[1] & 0xFF));
        if(raw_shunt > 32767)
        {
            raw_shunt -= 65536;
        }
        
        // Output data to screen
        System.out.printf("Raw value of Shunt Voltage : %d %n", raw_shunt);
    }
}
