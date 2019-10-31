/* -------------------------------------------------

FILE:		Vehicle.h
DESCRIPTION:	Vehicle header file for Project 5 for Fall 2019 CS 202-1001 at UNR
COMPILER:	g++ compiler
NOTES:

MODIFICATION HISTORY:
Author			Date		Version
----------------	--------	-------
Version 1		YYYY-MM-DD	x.x Description
Nick Learner		2019-10-09	1.0 Created this file; Moved Vehicle class from WIP proj5.cpp
*/

#ifndef VEHICLE_H
#define VEHICLE_H

#include "strprgms.h"

#define NUM_OF_LOCATION_VALS 3

class Vehicle
{
	protected:
		float m_lla[NUM_OF_LOCATION_VALS];
		const int m_vin;
	private:
		static int s_idgen;
	public:
		Vehicle();
		Vehicle(int vin, float * lla);
		Vehicle(const Vehicle & v);
		virtual ~Vehicle();
		void operator=(const Vehicle & v);
		int getVIN() { return m_vin; }
		void move(float * lla);
		float * getLLA() { return m_lla; }
		static int getIdgen() { return s_idgen; }
		friend std::ostream & operator<<(std::ostream & os, const Vehicle & v);
};

#endif
