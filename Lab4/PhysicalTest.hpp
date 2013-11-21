/*
 * PhysicalTest.hpp
 *
 *  Created on: Nov 20, 2013
 *      Author: Borys
 */

#ifndef PHYSICALTEST_HPP_
#define PHYSICALTEST_HPP_

#include <iostream>
#include <string>

using namespace std;

class PhysicalTests {

	int checkweight;
	int checkheight;


//this will contain variables related to the three derived classes
	//i.e. such as a needle or some instrument used for three of the tests.

};

class VitalSignsTest : public PhysicalTests{

	int theromemeter;
	int bloodpressuremonitor;
	int stethescope;	//for breathing


void BloodPressure();
void Pulse();
void BodyTemp();
void Breathing();

};

class UrineSampleTest : public PhysicalTests{




};

class EyesightTest : public PhysicalTests {




};














#endif /* PHYSICALTEST_HPP_ */