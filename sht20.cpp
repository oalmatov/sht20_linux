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
