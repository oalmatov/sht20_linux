#include "sht20.h"

using namespace std;

int main()
{
    Sht20   sht20( "/dev/i2c-1", 0x40 );

    sht20.readData();

    cout << "relative humidity: " << sht20.humidity() << endl;
    cout << "temperature: " << sht20.temperature() << endl;
}
