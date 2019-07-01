/* sht20.cpp
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

#include <arpa/inet.h>

#include "sht20.h"

using namespace std;

Sht20::Sht20( const char* busFile, uint8_t i2cAddress )
{
    fd_ = open( busFile, O_RDWR );

    if (fd_ < 0 )
    {
        cerr << "Cannot open bus" << endl;
    }

    ioctl( fd_, I2C_SLAVE, i2cAddress );
    usleep( 1000 );
}

void
Sht20::readData()
{
    i2c_smbus_write_byte( fd_, 0xf5 );
    usleep( 100000 );

    if ( read( fd_, &humData_, sizeof(humData_) ) != 2 )
    {
        cerr << "Input/output error" << endl;
    }
    
    i2c_smbus_write_byte( fd_, 0xf3 );
    usleep( 100000 );

    if ( read( fd_, &tempData_, sizeof(tempData_) ) != 2 )
    {
        cerr << "Input/output error" << endl;
    }
}

float
Sht20::humidity() const
{
    return ntohs( humData_ ) * 0.001907348632812 - 6.0;
}

float
Sht20::temperature() const
{
    return ntohs( tempData_ ) * 0.002681274414 - 46.85;
}
