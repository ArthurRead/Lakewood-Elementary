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
	string Gender; // male, female
	int Age;
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
public:
	CompleteBloodCount(string BT, string G, int R, int W, int P, int Hemo, int Hema, int M);
	void show(){cout << RBC << " " << WBC << " " << Platelets << " " << Hemoglobin << " " << Hematocrit << " " << MCV << " " << Gender << " "<< Bloodtype;}
	//function: normal ranges for males and females
};

class BloodChemistryTest : public BloodTest{
private:
	int Glucose; // units: (mg/dL) (milligrams/deciliter)
	char Diagnosis; // (N)ormal, (P)rediabetes, (D)iabetes
	int Calcium;
	int Electrolytes;
public:
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
	void show(){cout<<Total<<" "<<LDL<<" "<<HDL<<" "<<Bloodtype << " "<< Gender;}
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



/********** **********/



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
