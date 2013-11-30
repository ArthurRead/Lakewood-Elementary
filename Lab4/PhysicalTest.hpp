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
	string gender;	//male / female
	int checkweight;	//weight in lbs
	int age;	// patients age

public:
	//void Person_to_administer_test();

};

class VitalSignsTest : public PhysicalTests{	//for sure this one as well
private:
	int theromemeter_reading;	//temperature in Celcius
	int bloodpressuremonitor;	//equipment used for heart and blood pressure
	int stethescope;	//equipment for breathing
	string methodoftakingtemperature;	//how the temperature is taken, i.e. armpit, supository, etc.
	int pulse;	//heart beats/min
	int systolic;	//pressure in Hg (top number in blood pressure reading)
	int diastolic;	//pressure in Hg (bottom number in blood pressure reading)
	int breathrate;	//breaths / min
	//**************status checking********************
	int HL_BloodPressure;	//0  normal, 1 warning for high, 2 high blood, -1 low blood - patient status for BP
	int Heartcondition; //0 athlete, 1 excellent, 2 good, 3 above average, 4 average, 5 below, 6 poor - patient status for HC
	int Tempregulation;	//0 normal, 1 higher, 2 high, 3 dangerous, -1 below normal - patient temperature status
	int respiratory; //0 normal, -1 below normal, 1 higher than normal - patients breathing status
public:
	void BloodPressure();
	/*Checks if the blood pressure monitor was used
	 * and then sees whether the patient is male or female.
	 * In this case, it does not matter whether gender
	 * is male or female. Then it sees what the systolic
	 * and diastolic ranges are. If the blood pressure
	 * falls between those values, then it gives a status
	 * condition to the patient. If not, assigns critical status
	 * to the patient.*/

	void HeartBeat();

	/*Checks if the blood pressure monitor was used. Then
	 * check if the gender is male or female. Then
	 * looks at the age range of the patient. Once the patient
	 * falls between one of those ranges, it looks at the pulse of
	 * that patient. Depending on the pulse rate, it assigns the
	 * Heart condition.*/

	void BodyTemp();

	/*Checks what method the temperature was taken by. Then
	 * looks at the thermometer reading ranges. Once the data
	 * falls between one of those values, it assigns a
	 * Temp regulation status to the patient.*/
	void Breathing();

	/*Check what gender, male or female. Then checks if the
	 * right equipment was used (stethescope). Then checks
	 * the weight of the patient. If it falls between some range,
	 * it looks at the breathing rate of the patient. Once
	 * the breathing rate falls between some range, it assigns
	 * the condition of the patients respiratory status*/

	void VitalsCheck();	//uses all of the tests and makes a conclusion to the data recieved from all tests in vital signs

};

class UrineSampleTest : public PhysicalTests{
private:
	int phValue;	//could be in base class, however needs to be use
	int Proteins;	//used
	int sugar; 		//in mg/dL
	int ketone;		//in mg/dL
	int nitrate;	//used
	int bilirubin; //(breaks down hemoglobin. Defective = bad blood.	NOT USED YEt!!!!
	int ketonecheck;	//is ketone present or not 1 yes, 0 no
	int diabetescheck; //0 maybe, 1 yes, -1 no
	int redbloodcells;
	int whitebloodcells;
	//**************status checking***************************
	int infected; //0 maybe, 1 yes, -1 no
	int inflamed; //-1 not inflamed, 1 inflamed kidneys
public:
	void Inflamationcheck(/*protein level*/);	//high protein = inflamation in kidney

	/*Checks if there are proteins present. If there are
	 * the patient has inflamed kindey, if not then not inflamed*/

	void diabetuscheck(/*int sugar and ketone*/);		//high ketone and sugar = diabetus

	/*Checks if ketone is present or not in urine. Then looks
	 * at the values of sugar and ketone values. Depending on
	 * the ranges, it gives a diabetes status check,
	 * yes or no*/

	void bacterialcheck(/*int whitebloodcells and nitrite*/);		//high white bloodcells = bacterial infection (USE WHITEBLOODCELLS FROM BASE)

	/*checks if there are white blood cells, red blood cells
	 * or nitrate preset. If they are not, it then checks the
	 * ph value of the urine. If its between some range, it
	 * gives a status to infected or not.*/

	void UrineCheck();	//checks all tests and makes a conclusion
	};

class MobilityTest : public PhysicalTests {	//definetly this one
private:
	int joint_mobility;	// angle of mobile joint
	int type_of_spine_allignemnt;  //curved, bent, straight, etc.
	int reflexhammer;
	int paralyzed;	//limited, average, too much
	int  T25FW; //Time to walk 25 foot steps test (actual test), if completed in a certain time = normal movement for legs
public:
	void neckmovement();

	/*Checks the weight of the patient. If its between a value
	 * then check the range of angles of joint mobility. Once that
	 * is between a certain range it looks at the status of paralysis
	 * of neck movement*/

	void armmovement();

	/*Check how much the arm can rotate (angle wise) with joint
	 * mobility. Then sees if the arm paralysis state*/

	void legmovement();

	/*Check if the right equipment was used. If the reflex hammer
	 * was used, it then looks at the weight of the patient. If it
	 * falls between a range of values, it then looks at the angle of the movement
	 * of the leg with joint_mobility. Then it checks if the T25FW (
	 * Walking 25 feet test was successful or not.*/

	void spinemovement();

	/*Check what type of spine allignment the spine has.
	 * Depending on the allignment, it looks at the weight
	 * of the patient. It then looks at the angle (amount
	 * the spine can bend/can't bend). Then it gives a condition
	 * of paralysis if the spine is paralyzed or not.*/

	void Testmobilitystatus();       //can move, somewhat, paralyzed
};

//class NonVitalsTest : public PhysicalTests {
//
//	int texture;
//	int moisture;
//	int bumps_on_skin;
//
//	int hearing_level;
//
//	int ABCabc_sightchart;
//	int distance;	//for the 20/20 checking
//					//20/20 means 20feet person vs 20 feet normal average person
//
//	void Skinapperance_skincancer(); //maybe?
//	void earcheck_hearingcheck_hearingloss();
//	void paincheck_problem_withskin();
//	void eyesightcheck_blindness();	//finds 20/20 perfect vision, or some sort of vision
//
//	void nosecheck(); //related to breathing eventually, maybe remove?
//
//};

//class NervousSystem : public PhysicalTests {	//maybe don't do this class?
//
//	void checkmentalstatus();
//	void checkreflexes(); 	//related to mobility and responsivness
//	void checkcranialnerves ();
//	void checksensorysystem();
//
//
//};


//*******************************************************************************************************
//**********************************LAB 4 ENDS HERE (Based on what's required)****************************


//**********************************(If integers and variables in functions are required to be shown)*******
//********************************************Please look below********************************************



//***********Project samples*************
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
				if (pulse >= 49 && pulse >= 55){Heartcondition = 0;}
				if (pulse >= 56 && pulse >= 61){Heartcondition = 1;}
				if (pulse >= 62 && pulse >= 65){Heartcondition = 2;}
				if (pulse >= 66 && pulse >= 69){Heartcondition = 3;}
				if (pulse >= 70 && pulse >= 73){Heartcondition = 4;}
				if (pulse >= 74 && pulse >= 81){Heartcondition = 5;}
				if (pulse >= 82){Heartcondition = 6;}
			}
			if (age >=26 && age <=35){
				if (pulse >= 49 && pulse >= 54){Heartcondition = 0;}
				if (pulse >= 55 && pulse >= 61){Heartcondition = 1;}
				if (pulse >= 62 && pulse >= 65){Heartcondition = 2;}
				if (pulse >= 66 && pulse >= 70){Heartcondition = 3;}
				if (pulse >= 71 && pulse >= 74){Heartcondition = 4;}
				if (pulse >= 75 && pulse >= 81){Heartcondition = 5;}
				if (pulse >= 82){Heartcondition = 6;}
			}
			if (age >=36 && age <=45){
				if (pulse >= 59 && pulse >= 56){Heartcondition = 0;}
				if (pulse >= 57 && pulse >= 62){Heartcondition = 1;}
				if (pulse >= 63 && pulse >= 66){Heartcondition = 2;}
				if (pulse >= 67 && pulse >= 70){Heartcondition = 3;}
				if (pulse >= 71 && pulse >= 75){Heartcondition = 4;}
				if (pulse >= 76 && pulse >= 82){Heartcondition = 5;}
				if (pulse >= 83){Heartcondition = 6;}
			}
			if (age >=46 && age <=55){
				if (pulse >= 50 && pulse >= 57){Heartcondition = 0;}
				if (pulse >= 58 && pulse >= 63){Heartcondition = 1;}
				if (pulse >= 64 && pulse >= 67){Heartcondition = 2;}
				if (pulse >= 68 && pulse >= 71){Heartcondition = 3;}
				if (pulse >= 72 && pulse >= 76){Heartcondition = 4;}
				if (pulse >= 77 && pulse >= 83){Heartcondition = 5;}
				if (pulse >= 84){Heartcondition = 6;}
			}
			if (age >=56 && age <=65){
				if (pulse >= 51 && pulse >= 56){Heartcondition = 0;}
				if (pulse >= 57 && pulse >= 61){Heartcondition = 1;}
				if (pulse >= 62 && pulse >= 67){Heartcondition = 2;}
				if (pulse >= 68 && pulse >= 71){Heartcondition = 3;}
				if (pulse >= 72 && pulse >= 75){Heartcondition = 4;}
				if (pulse >= 76 && pulse >= 81){Heartcondition = 5;}
				if (pulse >= 82){Heartcondition = 6;}
			}
			if (age >= 66){
				if (pulse >= 50 && pulse >= 55){Heartcondition = 0;}
				if (pulse >= 56 && pulse >= 61){Heartcondition = 1;}
				if (pulse >= 62 && pulse >= 65){Heartcondition = 2;}
				if (pulse >= 66 && pulse >= 69){Heartcondition = 3;}
				if (pulse >= 70 && pulse >= 73){Heartcondition = 4;}
				if (pulse >= 74 && pulse >= 79){Heartcondition = 5;}
				if (pulse >= 80){Heartcondition = 6;}
			}
			else {
				cout << "Age too low or heart beat much too low!";
				Heartcondition = 6;
			}
		}
		if (gender == 'female'){

			if (age >=18 && age <=25){
				if (pulse >= 54 && pulse >= 60){Heartcondition = 0;}
				if (pulse >= 61 && pulse >= 65){Heartcondition = 1;}
				if (pulse >= 66 && pulse >= 69){Heartcondition = 2;}
				if (pulse >= 70 && pulse >= 73){Heartcondition = 3;}
				if (pulse >= 74 && pulse >= 78){Heartcondition = 4;}
				if (pulse >= 79 && pulse >= 84){Heartcondition = 5;}
				if (pulse >= 85){Heartcondition = 6;}
			}
			if (age >=26 && age <=35){
				if (pulse >= 54 && pulse >= 59){Heartcondition = 0;}
				if (pulse >= 60 && pulse >= 64){Heartcondition = 1;}
				if (pulse >= 65 && pulse >= 68){Heartcondition = 2;}
				if (pulse >= 69 && pulse >= 72){Heartcondition = 3;}
				if (pulse >= 73 && pulse >= 76){Heartcondition = 4;}
				if (pulse >= 77 && pulse >= 82){Heartcondition = 5;}
				if (pulse >= 83){Heartcondition = 6;}
			}
			if (age >=36 && age <=45){
				if (pulse >= 54 && pulse >= 59){Heartcondition = 0;}
				if (pulse >= 60 && pulse >= 64){Heartcondition = 1;}
				if (pulse >= 65 && pulse >= 69){Heartcondition = 2;}
				if (pulse >= 70 && pulse >= 73){Heartcondition = 3;}
				if (pulse >= 74 && pulse >= 78){Heartcondition = 4;}
				if (pulse >= 79 && pulse >= 84){Heartcondition = 5;}
				if (pulse >= 85){Heartcondition = 6;}
			}
			if (age >=46 && age <=55){
				if (pulse >= 54 && pulse >= 60){Heartcondition = 0;}
				if (pulse >= 61 && pulse >= 65){Heartcondition = 1;}
				if (pulse >= 66 && pulse >= 69){Heartcondition = 2;}
				if (pulse >= 70 && pulse >= 73){Heartcondition = 3;}
				if (pulse >= 74 && pulse >= 77){Heartcondition = 4;}
				if (pulse >= 78 && pulse >= 83){Heartcondition = 5;}
				if (pulse >= 84){Heartcondition = 6;}
			}
			if (age >=56 && age <=65){
				if (pulse >= 54 && pulse >= 59){Heartcondition = 0;}
				if (pulse >= 60 && pulse >= 64){Heartcondition = 1;}
				if (pulse >= 65 && pulse >= 68){Heartcondition = 2;}
				if (pulse >= 69 && pulse >= 73){Heartcondition = 3;}
				if (pulse >= 74 && pulse >= 77){Heartcondition = 4;}
				if (pulse >= 78 && pulse >= 83){Heartcondition = 5;}
				if (pulse >= 84){Heartcondition = 6;}
			}
			if (age >= 66){
				if (pulse >= 54 && pulse >= 59){Heartcondition = 0;}
				if (pulse >= 60 && pulse >= 64){Heartcondition = 1;}
				if (pulse >= 65 && pulse >= 68){Heartcondition = 2;}
				if (pulse >= 69 && pulse >= 72){Heartcondition = 3;}
				if (pulse >= 73 && pulse >= 76){Heartcondition = 4;}
				if (pulse >= 77 && pulse >= 84){Heartcondition = 5;}
				if (pulse >= 85){Heartcondition = 6;}
			}

			else {
				cout << "Patient age too low or much too low heart beat!";
				Heartcondition = 6;

			}
		}
	}

	else {cout << "Equipment was used incorrectly!";
	}
}

void VitalSignsTest::BodyTemp(){
	if(methodoftakingtemperature == 'insert method here'){
		if (theromemeter_reading >= 36.6 && theromemeter_reading <= 37.2){
			Tempregulation = 0;
		}
		if (theromemeter_reading >= 37.3 && theromemeter_reading <= 38.6){
			 Tempregulation = 1;
		}
		if (theromemeter_reading >= 38.7 && theromemeter_reading <= 41.6){
					 Tempregulation = 2;
		}
		if (theromemeter_reading >= 41.7){
					cout << "Near death!";
					Tempregulation = 3;
		}
		if (theromemeter_reading <= 36.5){
			 Tempregulation = -1;
		}
	}

	else {
		cout << "Please use the correct method!";

	}
}

void VitalSignsTest::Breathing(){	//use blood pressure to influence breathing rate
	if (gender == 'male'){
		if (stethescope == 1){
			if (checkweight >= 5 && checkweight <= 15){
				if (breathrate >= 30 && breathrate <= 60){respiratory = 0;}
				if (breathrate <= 29){respiratory = -1;}
				if (breathrate >= 61){respiratory = 1;}
			}
			if (checkweight >= 16 && checkweight <= 50){
				if (breathrate >= 20 && breathrate <= 30){respiratory = 0;}
				if (breathrate <= 19){respiratory = -1;}
				if (breathrate >= 31){respiratory = 1;}
			}
			if (checkweight >= 51 && checkweight <= 80){
				if (breathrate >= 18 && breathrate <= 25){respiratory = 0;}
				if (breathrate <= 17){respiratory = -1;}
				if (breathrate >= 26){respiratory = 1;}
			}
			if (checkweight > 81){
				if (breathrate >= 12 && breathrate <= 20){respiratory = 0;}
				if (breathrate <= 11){respiratory = -1;}
				if (breathrate >= 21){respiratory = 1;}
			}
		}
	}

	if (gender == 'female'){/*.... Similiar case statment....*/}

	else {
		cout << "Please use the proper method!";
	}
}

void VitalSignsTest::VitalsCheck(){

BloodPressure();
HeartBeat();
BodyTemp();
Breathing();

}


void UrineSampleTest::Inflamationcheck(){
	if (Proteins == -1){
		inflamed = -1;
	}

	if (Proteins == 1){
		inflamed = 1;
	}
}

void UrineSampleTest::diabetuscheck(){
	if (ketonecheck == 1){
		if ((ketone < 20) | sugar < 70 | (sugar <=70 && sugar <=130) ){diabetescheck =  -1;}
		if ((ketone >=20 && ketone <30)){diabetescheck =  0;}
		if ((ketone >=80) | (sugar > 130)){diabetescheck = 1;}
	}

	if (ketonecheck == 0){
		if (sugar < 70){diabetescheck = -1;}
		if (sugar <=70 && sugar <=130){diabetescheck = -1;}
		if (sugar > 130){diabetescheck = 1;}

	}
}

void UrineSampleTest::bacterialcheck(){
	if (whitebloodcells == 0 && redbloodcells ==  0 && nitrate == 0){
		if (phValue <=6){infected = 0;}
		if (phValue >6 && pHvalue <8){infected = -1;}
		if (phValue >=8){infected = 1;}
	}

	if (whitebloodcells == 1){infected = 1;}
	if (redbloodcells == 1){infected = 1;
	if (nitrate == 1){infected = 1;}
	}
}

void UrineSampleTest::Urinecheck(){
	Inflamationcheck();
	diabetuscheck();
	bacterialcheck();
}

void MobilityTest::Testmobilitystatus(){
neckmovement();
armmovement();
legmovement();
spinemovement();

}


void MobilityTest::neckmovement(){
	if (checkweight == 'between some sort of values'){
		if (joint_mobility == 'between some range of angle values'){
			paralyzed = 0; /*or*/ paralyzed = 1; /*or*/ paralyzed = 2;
		}
	}

}

void MobilityTest::armmovement(){

				if (joint_mobility == 'between some range of angle values'){

						paralyzed = 0; /*or*/ paralyzed = 1; /*or*/ paralyzed = 2;
					}
				}


void MobilityTest::legmovement(){
	if (reflexhammer == 1){
		if (checkweight == 'between some sort of values'){
			if (joint_mobility == 'between some range of angle values'){
				if (T25FW == 'yes or no'){
					paralyzed = 0; /*or*/ paralyzed = 1; /*or*/ paralyzed = 2;
				}
			}
		}
	}
}

void MobilityTest::spinemovement(){
	if (type_of_spine_allignemnt == 'curved or bent completely'){
		if (checkweight == 'between some sort of values'){
			if (joint_mobility == 'between some range of angle values'){
				paralyzed = 0; /*or*/ paralyzed = 1; /*or*/ paralyzed = 2;
			}
		}
	}

}

	if (type_of_spine_allignemnt == 'straight'){
		paralyzed = -1;

}






#endif /* PHYSICALTEST_HPP_ */
