#LDLIBS=-li2c -lsqlite3

sht20runner: sht20runner.cpp sht20.cpp sht20.h

clean:
	rm *.o
