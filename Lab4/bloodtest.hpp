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
	string comment;
public:
	CompleteBloodCount(string BT, string G, int R, int W, int P, int Hemo, int Hema, int M);
	CompleteBloodCount(string G, int R, int W, int P, int Hemo, int Hema, int M);
		// Bloodtype not needed for these tests
	void BloodCellRange();
	void PlateletsRange();
	void HemRange();
	void MCVRange();
	void TESTALL();
	void Results();
	void AddComments();
};

class BloodChemistryTest : public BloodTest{
private:
	int Glucose; // units: (mg/dL) (milligrams/deciliter)
	char Diagnosis; // (N)ormal, (P)rediabetes, (D)iabetes, (U)nderAverage
	int Calcium;
	int Electrolytes;
	string comment;
public:
	BloodChemistryTest(int G, int C, int E);
	void GlucoseRange();
	void Results();
	void AddComments();
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
	string comment;
public:
	HeartTest(string BT, string G, int T, int L, int H);
	HeartTest(int T, int L, int H); // Gender and bloodtype not necessary for this test
	void TestTotal();
	void TestLDL();
	void TestHDL();
	void TestAll();
	void Results();
	void AddComments();
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

void CompleteBloodCount::Results()
{
	if(rRBC==1)
		cout << "Normal RBC range.";
	else
		cout << "Not normal RBC range.";
	cout << "\n";
	if(rWBC==1)
		cout << "Normal WBC range.";
	else
		cout << "Not normal WBC range.";
	cout << "\n";
	if(rPlatelets==1)
		cout << "Normal Platelets range.";
	else
		cout << "Not normal Platelets range.";
	cout << "\n";
	if(rHemoglobin==1)
		cout << "Normal Hemoglobin range.";
	else
		cout << "Not normal Hemoglobin range.";
	cout << "\n";
	if(rHematocrit==1)
		cout << "Normal Hematocrit range.";
	else
		cout << "Not normal Hematocrit range.";
	cout << "\n";
	if(rMCV==1)
		cout << "Normal MCV range.";
	else
		cout << "Not normal MCV range.";
	cout << "\n";
}

void CompleteBloodCount::AddComments()
{
	string addc = "a";
	cout << "Hit [Enter] key twice to end comment.";

	while(addc.length()!=0)
	{
		getline(cin,addc);
		comment = comment + " " + addc;
	}
}


/********** Functions for BloodChemistryTest class **********/
BloodChemistryTest::BloodChemistryTest(int G, int C, int E)
:BloodTest("N/A","N/A")
{
	Glucose = G;
	Calcium = C;
	Electrolytes = E;
}

void BloodChemistryTest::GlucoseRange()
{
	if(Glucose < 70)
		Diagnosis = 'U'; // under average
	if(Glucose >=70 && Glucose <=99)
		Diagnosis = 'N';
	if(Glucose >=100 && Glucose <=125)
		Diagnosis = 'P';
	if(Glucose >=126)
		Diagnosis = 'D';
}

void BloodChemistryTest::Results()
{
	if(Diagnosis=='U')
		cout << "Under normal levels of glucose." << endl;
	if(Diagnosis == 'N')
		cout << "Normal levels of glucose." << endl;
	if(Diagnosis == 'P')
		cout << "Prediabetes range of glucose." << endl;
	if(Diagnosis == 'D')
		cout << "Patient has diabetes." << endl;
}

void BloodChemistryTest::AddComments()
{
	string addc = "a";
	cout << "Hit [Enter] key twice to end comment.";

	while(addc.length()!=0)
	{
		getline(cin,addc);
		comment = comment + " " + addc;
	}
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

void HeartTest::TestTotal()
{
	if(Total<200)
		TCC = 'D';
	if(Total >=200 && Total <=239)
		TCC = 'B';
	if(Total >= 240)
		TCC = 'H';
}

void HeartTest::TestLDL()
{
	if(LDL<100)
		LCC = 'O';
	if(LDL>=100 && LDL<=129)
		LCC = 'N';
	if(LDL>=130 && LDL<=159)
		LCC = 'B';
	if(LDL>=160 && LDL<=189)
		LCC = 'H';
	if(LDL>=190)
		LCC = 'V';
}

void HeartTest::TestHDL()
{
	if(HDL<40)
		HCC = 'R';
	if(HDL>=40 && HDL <=59)
		HCC = 'G';
	if(HDL>=60)
		HCC = 'P';
}

void HeartTest::TestAll()
{
	TestTotal();
	TestLDL();
	TestHDL();
}

void HeartTest::Results()
{
	if(TCC == 'D')
		cout << "Desirable cholesterol level." << endl;
	if(TCC == 'B')
			cout << "Borderline high cholesterol level." << endl;
	if(TCC == 'H')
			cout << "High cholesterol level." << endl;
	if(LCC == 'O')
			cout << "Optimal LDL cholesterol level." << endl;
	if(LCC == 'N')
			cout << "Near optimal LDL cholesterol level." << endl;
	if(LCC == 'B')
			cout << "Borderline high LDL cholesterol level." << endl;
	if(LCC == 'H')
			cout << "High cholesterol level." << endl;
	if(LCC == 'V')
			cout << "Very high cholesterol level." << endl;
	if(HCC == 'R')
			cout << "Patient has major risk of heart disease." << endl;
	if(HCC == 'G')
			cout << "Good levels of HCC cholesterol." << endl;
	if(HCC == 'P')
			cout << "Patient considered protective against heart disease." << endl;
}

void HeartTest::AddComments()
{
	string addc = "a";
	cout << "Hit [Enter] key twice to end comment.";

	while(addc.length()!=0)
	{
		getline(cin,addc);
		comment = comment + " " + addc;
	}
}


#endif /* CLASS_HPP_ */
