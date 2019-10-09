/**
 * This file is a test driver for the Inheritance classes prescribed in Project 5 of CS-202
 */
 
#include <iostream>

#include "Vehicle.h"

// Taken from Project 4
size_t myStringLength(const char * str);
int myStringCompare(const char * str1, const char * str2);
char * myStringCopy(char * destination, const char * source);
char * myStringCat(char * destination, const char * source);

//Vehicle.cpp
int Vehicle::s_idgen = 0;

Vehicle::Vehicle() : m_vin(0)
{
	s_idgen = m_vin;
	
	std::cout << "Vehicle #" << m_vin << ": Default Constructor" << std::endl;
}

Vehicle::Vehicle(int vin, float * lla) : m_vin((vin!=s_idgen) ? vin : 0)
{
	s_idgen = m_vin;
	
	for (int i = 0; i < NUM_OF_LOCATION_VALS; i++, lla++)
	{
		m_lla[i] = *lla;
	}
	
	std::cout << "Vehicle #" << m_vin << ": Parametrized Constructor" << std::endl;
}

Vehicle::Vehicle(const Vehicle & v) : m_vin(((v.m_vin + 1)!=s_idgen) ? (v.m_vin + 1) : 0)
{
	s_idgen = m_vin;
	
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
	//*this = v;
	
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
// /\ End of Vehicle.cpp

#include "Car.h"

//Car.cpp
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
// /\ End of Car.cpp


using namespace std;

int main(){

  cout << "\n" <<
          "////////////////////////////\n" <<
          "/////    Base Tests    /////\n" <<
          "////////////////////////////" << endl;

  cout << endl << "Testing Base Default ctor" << endl;
  Vehicle v1;

  cout << endl << "Testing Base insertion operator" << endl;
  cout << v1 << endl;
  cout << "Base idgen: " << v1.getIdgen() << endl;
  
  cout << endl << "Testing Base Parametrized ctor" << endl;
  float lla_rno[3] = {39.54, 119.82, 4500.0};
  Vehicle v99(99, lla_rno);
  
  cout << v99 << endl;
  cout << "Base idgen: " << v99.getIdgen() << endl;

  cout << endl << "Testing Base Copy ctor" << endl;
  Vehicle v99_cpy( v99 );  

  cout << v99_cpy << endl;
  cout << "Base idgen: " << v99_cpy.getIdgen() << endl;

  cout << endl << "Testing Base Assignment operator" << endl;
  v1 = v99_cpy;
  cout << v1 << endl;
  cout << "Base idgen: " << v1.getIdgen() << endl;

  cout << endl << "Testing Base Move Function" << endl;
  float lla_new[3] = {37.77, 122.42, 52.0};
  v1.move( lla_new );  


  cout << "\n" <<
          "////////////////////////////\n" <<
          "/////   Derived Tests  /////\n" <<
          "////////////////////////////" << endl;

  cout << endl << "Testing Derived Default ctor" << endl;
  Car c1;

  cout << endl << "Testing Derived insertion operator" << endl;
  cout << c1 << endl;
  cout << "Derived idgen: " << c1.getIdgen() << endl;
  
  cout << endl << "Testing Derived Parametrized ctor" << endl;
  char plates_999[] = "Gandalf";
  Car c999(plates_999, 999, lla_rno);
  
  cout << c999 << endl;
  cout << "Derived idgen: " << c999.getIdgen() << endl;

  cout << endl << "Testing Derived Copy ctor" << endl;
  Car c999_cpy( c999 );  

  cout << c999_cpy << endl;
  cout << "Derived idgen: " << c999_cpy.getIdgen() << endl;

  cout << endl << "Testing Derived Assignment operator" << endl;
  c1 = c999_cpy;
  cout << c1 << endl;
  cout << "Derived idgen: " << c1.getIdgen() << endl;

  cout << endl << "Testing Derived Move Function" << endl;
  c1.move( lla_new );  

  cout << "\n" <<
          "////////////////////////////\n" <<
          "/////    Tests Done    /////\n" <<
          "////////////////////////////" << endl;

  return 0;
  
}


/* -----------------------------------------------------------------------------
FUNCTION:          myStringLength()
DESCRIPTION:       Finds and returns the length of a given string
RETURNS:           size_t (like an int)
NOTES:             
------------------------------------------------------------------------------- */

size_t myStringLength(const char * str)
{
	size_t i = 0;
	
	while (*str++)
	{
		i++;
	}
	
	return i;
}


/* -----------------------------------------------------------------------------
FUNCTION:          myStringCompare()
DESCRIPTION:       Compares two char arrays 
RETURNS:           int
NOTES:             return value is less than 0 if str1 is less than str2,
					greater than 0 if str1 is greater than str2, 0 if they're ==
------------------------------------------------------------------------------- */

int myStringCompare(const char * str1, const char * str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	
	return *str1 - *str2;
}


/* -----------------------------------------------------------------------------
FUNCTION:          myStringCopy()
DESCRIPTION:       Copies a char array to a destination
RETURNS:           pointer to a char
NOTES:             
------------------------------------------------------------------------------- */

char* myStringCopy(char * destination, const char * source)
{
	while ((*destination++ = *source++));
	
	return destination;
}


/* -----------------------------------------------------------------------------
FUNCTION:          myStringCat()
DESCRIPTION:       Adds (concatenates) a char array to a destination
RETURNS:           pointer to a char
NOTES:             
------------------------------------------------------------------------------- */

char* myStringCat(char * destination, const char * source)
{
	while (*destination)// Goes until '\0', then stops there
	{
		destination++;
	}
	
	// Same basic function as myStringCopy()
	while ((*destination++ = *source++));
	
	return destination;
}
