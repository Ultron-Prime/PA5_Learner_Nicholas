#ifndef CAR_H
#define CAR_H

#include <iostream>
#include "Vehicle.h"

#define MAX_CHAR_ARRAY_SIZE 256

class Car : public Vehicle
{
	private:
		char m_plates[MAX_CHAR_ARRAY_SIZE];
		int m_throttle;
	public:
		Car();
		Car(char * plates, int vin, float * lla);
		Car(const Car & c);
		~Car();
		void operator=(const Car & c);
		void setPlates(char * plates);
		char * getPlates() { return m_plates; }
		void drive(int throttle);
		int getThrottle() { return m_throttle; }
		void move(float * lla);
		friend std::ostream & operator<<(std::ostream & os, const Car & c);
};

#endif
