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
protected:
	string gender;
	int checkweight;
	int checkheight;
	int age;
	int redbloodcells;
	int whitebloodcells;
	int color;


public:
	void Person_to_administer_test();

};

class VitalSignsTest : public PhysicalTests{	//for sure this one as well
private:
	int theromemeter;
	int bloodpressuremonitor;
	int stethescope;	//for breathing
	string methodoftakingtemperature;
	int pulse;
	int systolic;
	int diastolic;
	int HL_BloodPressure;	//0  normal, 1 warning for high, 2 high blood, -1 low blood
	int Heartcondition; //0 athlete, 1 excellent, 2 good, 3 above average, 4 average, 5 below, 6 poor

public:
	void BloodPressure();
	void HeartBeat();	//pulse uses bloodpressure to determine strength, and pulse.
	void BodyTemp();
	void Breathing();
	void VitalsCheck();

};

class UrineSampleTest : public PhysicalTests{
private:
	int phValue;	//could be in base class, however needs to be use
	int Proteins;	//used
	int sugar; 		//used
	int ketone;		//used
	int nitrate;	//used
	int bilirubin; //(breaks down hemoglobin. Defective = bad blood.	NOT USED YEt!!!!

public:
	void Inflamationcheck(/*protein level*/);	//high protein = inflamation in kidney
	void diabetuscheck(/*int sugar and ketone*/);		//high ketone and sugar = diabetus
	void bacterialcheck(/*int whitebloodcells and nitrite*/);		//high white bloodcells = bacterial infection (USE WHITEBLOODCELLS FROM BASE)
	void UrineCheck();
	};

class NonVitalsTest : public PhysicalTests {

	int texture;
	int moisture;
	int bumps_on_skin;

	int hearing_level;

	int ABCabc_sightchart;
	int distance;	//for the 20/20 checking
					//20/20 means 20feet person vs 20 feet normal average person

	void Skinapperance_skincancer(); //maybe?
	void earcheck_hearingcheck_hearingloss();
	void paincheck_problem_withskin();
	void eyesightcheck_blindness();	//finds 20/20 perfect vision, or some sort of vision

	void nosecheck(); //related to breathing eventually, maybe remove?

};



class MobilityTest : public PhysicalTests {	//definetly this one
private:
	int joint_mobility;	//limited, average, too much, angle of mobile joint
	int type_of_spine_allignemnt;  //curved, bent, straight, etc.
	int reflexhammer;
public:
	void neckmovement();
	void armmovement();
	void legmovement();
	void spinemovement();
	void Testmobilitystatus();       //can move, somewhat, paralyzed
};



class NervousSystem : public PhysicalTests {	//maybe don't do this class?

	void checkmentalstatus();
	void checkreflexes(); 	//related to mobility and responsivness
	void checkcranialnerves ();
	void checksensorysystem();


};



//	void BodyTemp();
//	void Breathing();
//	void VitalsCheck();

void VitalSignsTest::BloodPressure(){
	if (bloodpressuremonitor == 1){	//if bloodpressure monitor used

		if (gender == 'male' | 'female'){

			if ((systolic >= 90 && systolic <= 120) && (diastolic <= 80 && diastolic >= 60) ){
				HL_BloodPressure = 0;
			}

			if ((systolic >= 120 && systolic <= 140) && (diastolic <= 90 && diastolic >= 80) ){
				HL_BloodPressure = 0;
			}
			if ((systolic >= 140 && systolic <= 190) && (diastolic <= 100 && diastolic >= 90) ){
				HL_BloodPressure = 0;
			}
			if ((systolic >= 70 && systolic <= 90) && (diastolic <= 60 && diastolic >= 40) ){
				HL_BloodPressure = 0;
			}

			else{
				cout << "This Patient is in serious danger of dying!!!!";
			}



		}
	}

	else{

		cout << "Blood pressure monitor was not used correctly!";
	}

}

void VitalSignsTest::HeartBeat(){
	if (bloodpressuremonitor == 1){

		if (gender == 'male'){
			if (age >=18 && age <=25){
				if (pulse >= 49 && pulse >= 55){Heartcondition == 0;}
				if (pulse >= 56 && pulse >= 61){Heartcondition == 1;}
				if (pulse >= 62 && pulse >= 65){Heartcondition == 2;}
				if (pulse >= 66 && pulse >= 69){Heartcondition == 3;}
				if (pulse >= 70 && pulse >= 73){Heartcondition == 4;}
				if (pulse >= 74 && pulse >= 81){Heartcondition == 5;}
				if (pulse >= 82){Heartcondition == 6;}
			}
			if (age >=26 && age <=35){
				if (pulse >= 49 && pulse >= 54){Heartcondition == 0;}
				if (pulse >= 55 && pulse >= 61){Heartcondition == 1;}
				if (pulse >= 62 && pulse >= 65){Heartcondition == 2;}
				if (pulse >= 66 && pulse >= 70){Heartcondition == 3;}
				if (pulse >= 71 && pulse >= 74){Heartcondition == 4;}
				if (pulse >= 75 && pulse >= 81){Heartcondition == 5;}
				if (pulse >= 82){Heartcondition == 6;}
			}
			if (age >=36 && age <=45){
				if (pulse >= 59 && pulse >= 56){Heartcondition == 0;}
				if (pulse >= 57 && pulse >= 62){Heartcondition == 1;}
				if (pulse >= 63 && pulse >= 66){Heartcondition == 2;}
				if (pulse >= 67 && pulse >= 70){Heartcondition == 3;}
				if (pulse >= 71 && pulse >= 75){Heartcondition == 4;}
				if (pulse >= 76 && pulse >= 82){Heartcondition == 5;}
				if (pulse >= 83){Heartcondition == 6;}
			}
			if (age >=46 && age <=55){
				if (pulse >= 50 && pulse >= 57){Heartcondition == 0;}
				if (pulse >= 58 && pulse >= 63){Heartcondition == 1;}
				if (pulse >= 64 && pulse >= 67){Heartcondition == 2;}
				if (pulse >= 68 && pulse >= 71){Heartcondition == 3;}
				if (pulse >= 72 && pulse >= 76){Heartcondition == 4;}
				if (pulse >= 77 && pulse >= 83){Heartcondition == 5;}
				if (pulse >= 84){Heartcondition == 6;}
			}
			if (age >=56 && age <=65){
				if (pulse >= 51 && pulse >= 56){Heartcondition == 0;}
				if (pulse >= 57 && pulse >= 61){Heartcondition == 1;}
				if (pulse >= 62 && pulse >= 67){Heartcondition == 2;}
				if (pulse >= 68 && pulse >= 71){Heartcondition == 3;}
				if (pulse >= 72 && pulse >= 75){Heartcondition == 4;}
				if (pulse >= 76 && pulse >= 81){Heartcondition == 5;}
				if (pulse >= 82){Heartcondition == 6;}
			}
			if (age >= 66){
				if (pulse >= 50 && pulse >= 55){Heartcondition == 0;}
				if (pulse >= 56 && pulse >= 61){Heartcondition == 1;}
				if (pulse >= 62 && pulse >= 65){Heartcondition == 2;}
				if (pulse >= 66 && pulse >= 69){Heartcondition == 3;}
				if (pulse >= 70 && pulse >= 73){Heartcondition == 4;}
				if (pulse >= 74 && pulse >= 79){Heartcondition == 5;}
				if (pulse >= 80){Heartcondition == 6;}
			}
			else {
				cout << "Age too low or heart beat much too low!";
				Heartcondition == 6;
			}
		}
		if (gender == 'female'){

			if (age >=18 && age <=25){
				if (pulse >= 54 && pulse >= 60){Heartcondition == 0;}
				if (pulse >= 61 && pulse >= 65){Heartcondition == 1;}
				if (pulse >= 66 && pulse >= 69){Heartcondition == 2;}
				if (pulse >= 70 && pulse >= 73){Heartcondition == 3;}
				if (pulse >= 74 && pulse >= 78){Heartcondition == 4;}
				if (pulse >= 79 && pulse >= 84){Heartcondition == 5;}
				if (pulse >= 85){Heartcondition == 6;}
			}
			if (age >=26 && age <=35){
				if (pulse >= 54 && pulse >= 59){Heartcondition == 0;}
				if (pulse >= 60 && pulse >= 64){Heartcondition == 1;}
				if (pulse >= 65 && pulse >= 68){Heartcondition == 2;}
				if (pulse >= 69 && pulse >= 72){Heartcondition == 3;}
				if (pulse >= 73 && pulse >= 76){Heartcondition == 4;}
				if (pulse >= 77 && pulse >= 82){Heartcondition == 5;}
				if (pulse >= 83){Heartcondition == 6;}
			}
			if (age >=36 && age <=45){
				if (pulse >= 54 && pulse >= 59){Heartcondition == 0;}
				if (pulse >= 60 && pulse >= 64){Heartcondition == 1;}
				if (pulse >= 65 && pulse >= 69){Heartcondition == 2;}
				if (pulse >= 70 && pulse >= 73){Heartcondition == 3;}
				if (pulse >= 74 && pulse >= 78){Heartcondition == 4;}
				if (pulse >= 79 && pulse >= 84){Heartcondition == 5;}
				if (pulse >= 85){Heartcondition == 6;}
			}
			if (age >=46 && age <=55){
				if (pulse >= 50 && pulse >= 55){Heartcondition == 0;}
				if (pulse >= 56 && pulse >= 61){Heartcondition == 1;}
				if (pulse >= 62 && pulse >= 65){Heartcondition == 2;}
				if (pulse >= 66 && pulse >= 69){Heartcondition == 3;}
				if (pulse >= 70 && pulse >= 73){Heartcondition == 4;}
				if (pulse >= 74 && pulse >= 79){Heartcondition == 5;}
				if (pulse >= 80){Heartcondition == 6;}
			}
			if (age >=56 && age <=65){
				if (pulse >= 50 && pulse >= 55){Heartcondition == 0;}
				if (pulse >= 56 && pulse >= 61){Heartcondition == 1;}
				if (pulse >= 62 && pulse >= 65){Heartcondition == 2;}
				if (pulse >= 66 && pulse >= 69){Heartcondition == 3;}
				if (pulse >= 70 && pulse >= 73){Heartcondition == 4;}
				if (pulse >= 74 && pulse >= 79){Heartcondition == 5;}
				if (pulse >= 80){Heartcondition == 6;}
			}
			if (age >= 66){
				if (pulse >= 50 && pulse >= 55){Heartcondition == 0;}
				if (pulse >= 56 && pulse >= 61){Heartcondition == 1;}
				if (pulse >= 62 && pulse >= 65){Heartcondition == 2;}
				if (pulse >= 66 && pulse >= 69){Heartcondition == 3;}
				if (pulse >= 70 && pulse >= 73){Heartcondition == 4;}
				if (pulse >= 74 && pulse >= 79){Heartcondition == 5;}
				if (pulse >= 80){Heartcondition == 6;}
			}

			else {
				cout << "Patient age too low or much too low heart beat!";
				Heartcondition == 6;

			}
		}
	}

	else {cout << "Equipment was used incorrectly!";
	}
}




























#endif /* PHYSICALTEST_HPP_ */
