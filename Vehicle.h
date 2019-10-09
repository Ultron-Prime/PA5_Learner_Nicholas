#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>

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
		int getIdgen() { return s_idgen; }
		friend std::ostream & operator<<(std::ostream & os, const Vehicle & v);
};

#endif
