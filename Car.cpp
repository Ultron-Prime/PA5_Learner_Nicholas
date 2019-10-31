/* -------------------------------------------------

FILE:		Car.cpp
DESCRIPTION:	Car .cpp file for Project 5 for Fall 2019 CS 202-1001 at UNR
COMPILER:	g++ compiler
NOTES:

MODIFICATION HISTORY:
Author			Date		Version
----------------	--------	-------
Version 1		YYYY-MM-DD	x.x Description
Nick Learner		2019-10-09	1.0 Created this file; Moved methods from WIP proj5.cpp
*/

#include "Car.h"

Car::Car()
{
	m_throttle = 0;
	
	std::cout << "Car #" << m_vin << ": Default Constructor" << std::endl;
}

Car::Car(char * plates, int vin, float * lla) : Vehicle(vin, lla)
{
	myStringCopy(m_plates, plates);
	m_throttle = 0;
	std::cout << "Car #" << m_vin << ": Parametrized Constructor" << std::endl;
}

Car::Car(const Car & c) : Vehicle(c)
{
	//*this = c;
	
	myStringCopy(m_plates, c.m_plates);
	m_throttle = c.m_throttle;
	
	for (int i = 0; i < NUM_OF_LOCATION_VALS; i++)
	{
		m_lla[i] = c.m_lla[i];
	}
	
	std::cout << "Car #" << m_vin << ": Copy Constructor" << std::endl;
}

Car::~Car()
{
	std::cout << "Car #" << m_vin << ": Destructor" << std::endl;
}

void Car::operator=(const Car & c)
{
	//*this = c;
	
	myStringCopy(m_plates, c.m_plates);
	m_throttle = c.m_throttle;
	
	for (int i = 0; i < NUM_OF_LOCATION_VALS; i++)
	{
		m_lla[i] = c.m_lla[i];
	}
	
	std::cout << "Car #" << m_vin << ": Assignment" << std::endl;
}

void Car::setPlates(char * plates)
{
	myStringCopy(m_plates, plates);
}

void Car::drive(int throttle)
{
	m_throttle = throttle;
}

void Car::move(float * lla)
{
	std::cout << "Car #" << m_vin << " DRIVE to destination, with throttle @ 75" << std::endl;
	
	this->drive(75);
	
	for (int i = 0; i < NUM_OF_LOCATION_VALS; i++, lla++)
	{
		m_lla[i] = *lla;
	}
}

std::ostream & operator<<(std::ostream & os, const Car & c)
{
	os << "Car #" << c.m_vin << " Plates: " << c.m_plates
		<< ", Throttle: " << c.m_throttle
		<< " @ [" << c.m_lla[0] << ", " << c.m_lla[1]
		<< ", " << c.m_lla[2] << "]" << std::endl;
	
	return os;
}
