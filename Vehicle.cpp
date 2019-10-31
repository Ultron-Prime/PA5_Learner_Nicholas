/* -------------------------------------------------

FILE:		Vehicle.cpp
DESCRIPTION:	Vehicle .cpp file for Project 5 for Fall 2019 CS 202-1001 at UNR
COMPILER:	g++ compiler
NOTES:

MODIFICATION HISTORY:
Author			Date		Version
----------------	--------	-------
Version 1		YYYY-MM-DD	x.x Description
Nick Learner		2019-10-09	1.0 Created this file; Moved methods from WIP proj5.cpp
*/


#include "Vehicle.h"

int Vehicle::s_idgen = 0;

Vehicle::Vehicle() : m_vin(++s_idgen)
{
	std::cout << "Vehicle #" << m_vin << ": Default Constructor" << std::endl;
}

Vehicle::Vehicle(int vin, float * lla) : m_vin((vin > s_idgen) ? vin : (++s_idgen))
{
	s_idgen = m_vin;
	
	for (int i = 0; i < NUM_OF_LOCATION_VALS; i++, lla++)
	{
		m_lla[i] = *lla;
	}
	
	std::cout << "Vehicle #" << m_vin << ": Parametrized Constructor" << std::endl;
}

Vehicle::Vehicle(const Vehicle & v) : m_vin(++s_idgen)
{
	for (int i = 0; i < NUM_OF_LOCATION_VALS; i++)
	{
		m_lla[i] = v.m_lla[i];
	}
	
	std::cout << "Vehicle #" << m_vin << ": Copy Constructor" << std::endl;
}

Vehicle::~Vehicle()
{
	std::cout << "Vehicle #" << m_vin << ": Destructor" << std::endl;
}

void Vehicle::operator=(const Vehicle & v)
{
	for (int i = 0; i < NUM_OF_LOCATION_VALS; i++)
	{
		m_lla[i] = v.m_lla[i];
	}
	
	std::cout << "Vehicle #" << m_vin << ": Assignment" << std::endl;
}

void Vehicle::move(float * lla)
{
	std::cout << "Vehicle #" << m_vin << ": CANNOT MOVE - I DON'T KNOW HOW" << std::endl;
}

std::ostream & operator<<(std::ostream & os, const Vehicle & v)
{
	os << "Vehicle #" << v.m_vin << " @ [" << v.m_lla[0] << ", " << v.m_lla[1]
		<< ", " << v.m_lla[2] << "]" << std::endl;
	
	return os;
}
