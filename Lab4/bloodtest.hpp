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

using namespace std;
/********** Base Class **********/

class BloodTest{
protected:
	string Bloodtype; // A, B, O, AB
	string Gender; // male, female, N/A
	//int Age;
public:
	BloodTest(string BT, string G){Bloodtype = BT; Gender = G;}
};



/********** Derived Classes **********/
class CompleteBloodCount : public BloodTest{
private:
	int RBC;	// Red Blood Cells, units: (cells/mcL) (cells/microliter)
	int WBC;	// White Blood Cells, units: (cells/mcL)
	int Platelets; // units: (cells/mcL)
	int Hemoglobin; // units: (gm/dL) (grams/deciliter)
	int Hematocrit; // units: (%)
	int MCV; // Mean Corpuscular Volume, units: femtoliter
	int rRBC, rWBC, rPlatelets, rHemoglobin, rHematocrit, rMCV; // results for ranges of the variable 1-normal, 0-notnormal
public:
	CompleteBloodCount(string BT, string G, int R, int W, int P, int Hemo, int Hema, int M);
	CompleteBloodCount(string G, int R, int W, int P, int Hemo, int Hema, int M);
		// Bloodtype not needed for these tests
	void BloodCellRange();
	void PlateletsRange();
	void HemRange();
	void MCVRange();
	void TESTALL();
};

class BloodChemistryTest : public BloodTest{
private:
	int Glucose; // units: (mg/dL) (milligrams/deciliter)
	char Diagnosis; // (N)ormal, (P)rediabetes, (D)iabetes
	int Calcium;
	int Electrolytes;
public:
	BloodChemistryTest(int G, int C, int E);
	//function: diabetes diagnosis
};

class HeartTest : public BloodTest{
private:
	int Total; // Total cholesterol level (mg/dL)
	int LDL; // Bad cholesterol (mg/dL)
	int HDL; // Good cholesterol (mg/dL)
	char TCC; // Total Cholesterol Category: (D)esirable, (B)orderlineHigh, (H)igh
	char LCC; // LDL Cholesterol Category: (O)ptimal, (N)earOptimal, (B)orderlineHigh, (H)igh, (V)eryHigh
	char HCC; // HDL cholesterol Category: (R)isk, (G)ood, (P)rotectiveAgainstHeartDisease
public:
	HeartTest(string BT, string G, int T, int L, int H);
	HeartTest(int T, int L, int H); // Gender and bloodtype not necessary for this test
};



/********** Functions for CompleteBloodCount class **********/
CompleteBloodCount::CompleteBloodCount(string BT, string G, int R, int W, int P, int Hemo, int Hema, int M)
:BloodTest(BT, G)
{
	RBC = R;
	WBC = W;
	Platelets = P;
	Hemoglobin = Hemo;
	Hematocrit = Hema;
	MCV = M;
}

CompleteBloodCount::CompleteBloodCount(string G, int R, int W, int P, int Hemo, int Hema, int M)
:BloodTest("N/A",G)
{
	RBC = R;
	WBC = W;
	Platelets = P;
	Hemoglobin = Hemo;
	Hematocrit = Hema;
	MCV = M;
}

void CompleteBloodCount::BloodCellRange()
{
	if(Gender == "male")
	{
		if(RBC>=5000000 && RBC<=6000000)
			rRBC = 1; // normal
		else
			rRBC = 0; // not normal
	}

	if(Gender == "female")
	{
		if(RBC>=4000000 && RBC<=5000000)
			rRBC = 1; // normal
		else
			rRBC = 0; // not normal
	}

	if(WBC>=4500 && WBC<=10000) // same for males and females
		rWBC = 1;
	else
		rWBC = 0;
}

void CompleteBloodCount::PlateletsRange()
{
	if(Platelets>=140000 && Platelets<=450000)
		rPlatelets = 1;
	else
		rPlatelets = 0;
}

void CompleteBloodCount::HemRange()
{
	if(Gender == "male")
	{
		if(Hemoglobin>=14 && Hemoglobin<=17)
			rHemoglobin = 1;
		else
			rHemoglobin = 0;
		if(Hematocrit>=41 && Hematocrit<=50)
			rHematocrit = 1;
		else
			rHematocrit = 0;
	}
	if(Gender == "female")
	{
		if(Hemoglobin>=12 && Hemoglobin<=15)
			rHemoglobin = 1;
		else
			rHemoglobin = 0;
		if(Hematocrit>=36 && Hematocrit<=44)
			rHematocrit = 1;
		else
			rHematocrit = 0;
	}
}

void CompleteBloodCount::MCVRange()
{
	if(MCV>=80 && MCV<=95)
		rMCV = 1;
	else
		rMCV = 0;
}

void CompleteBloodCount::TESTALL()
{
	BloodCellRange();
	PlateletsRange();
	HemRange();
	MCVRange();
}


/********** Functions for BloodChemistryTest class **********/
BloodChemistryTest::BloodChemistryTest(int G, int C, int E)
:BloodTest("N/A","N/A")
{
	Glucose = G;
	Calcium = C;
	Electrolytes = E;
}


/********** Functions for HeartTest class **********/
HeartTest::HeartTest(string BT, string G, int T, int L, int H)
:BloodTest(BT, G)
{
	Total = T;
	LDL = L;
	HDL = H;
}

HeartTest::HeartTest(int T, int L, int H)
:BloodTest("N/A", "N/A")
{
	Total = T;
	LDL = L;
	HDL = H;
}


#endif /* CLASS_HPP_ */
