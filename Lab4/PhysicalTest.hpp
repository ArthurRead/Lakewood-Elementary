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

	int redbloodcells;
	int whitebloodcells;

	int color;


	void Person_to_administer_test();

	//more to be added in the base class


};

class VitalSignsTest : public PhysicalTests{	//for sure this one as well

	int theromemeter;
	int bloodpressuremonitor;
	int stethescope;	//for breathing
	string methodoftakingtemperature;
	int pulse;



	void BloodPressure();
	void HeartRhythym();	//pulse uses bloodpressure to determine strength, and pulse.
	void BodyTemp();
	void Breathing();

};

class UrineSampleTest : public PhysicalTests{
	int phValue;	//could be in base class, however needs to be used

	int Proteins;	//used

	int sugar; 		//used
	int ketone;		//used

	int nitrate;	//used


	int bilirubin; //(breaks down hemoglobin. Defective = bad blood.	NOT USED YEt!!!!


void Inflamationcheck(/*protein level*/);	//high protein = inflamation in kidney
void diabetuscheck(/*int sugar and ketone*/);		//high ketone and sugar = diabetus
void bacterialcheck(/*int whitebloodcells and nitrite*/);		//high white bloodcells = bacterial infection (USE WHITEBLOODCELLS FROM BASE)
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

	int joint_mobility;	//limited, average, too much
	int type_of_spine_allignemnt;  //curved, bent, straight, etc.
	int reflexhammer;

	void neckmovement();
	void armmovement();
	void legmovement();
	void spinemovement();
};

class NervousSystem : public PhysicalTests {	//maybe don't do this class?

	void checkmentalstatus();
	void checkreflexes(); 	//related to mobility and responsivness
	void checkcranialnerves ();
	void checksensorysystem();


};









#endif /* PHYSICALTEST_HPP_ */
