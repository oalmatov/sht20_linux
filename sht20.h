// sht20.h

#ifndef SHT20_H
#define SHT20_H 1

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>

class Sht20
{

public:
    
                Sht20( const char* busFile, uint8_t i2cAddress );
    
    void        readData();
    float       humidity() const;
    float       temperature() const;

protected:

    int         fd_;
    uint16_t    humData_;
    uint16_t    tempData_;
};

#endif // SHT20_H
