/*
 * class.hpp
 *
 *  Created on: Nov 12, 2013
 *      Author: aquach
 */

#ifndef CLASS_HPP_
#define CLASS_HPP_

#include <iostream>
#include <string>
// ok
using namespace std;

class BloodTest{
protected:
	string Bloodtype;
public:

};

class CompleteBloodCount : public BloodTest{
private:
	int RBC;	// Red Blood Cells
	int WBC;	// White Blood Cells
	int Platelets;
	int Hemoglobin;
	int Hematocrit;
public:

};

class BloodChemistryTest : public BloodTest{
private:
	int Glucose;
	int Calcium;
	int Electrolytes;
public:

};

class BloodEnzymeTest : public BloodTest{
private:
	int Troponin;
	int Creatine;
public:

};


#endif /* CLASS_HPP_ */
