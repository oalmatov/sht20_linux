/* sht20.h
****************************************************************************************************************
****************************************************************************************************************
    Copyright (C) 2019 Omar Almatov
     
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU General
    Public License as published by the Free Software Foundation, either version 3 of the License, or (at your
    option) any later version.
    
    This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
    implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
    License for more details.
    
    You should have received a copy of the GNU General Public License along with this program. If not, see
    <http://www.gnu.org/licenses/>.
*/

#ifndef SHT20_H_
#define SHT20_H_ 1

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

#endif // SHT20_H_
