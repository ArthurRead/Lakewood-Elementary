/*
 * header.h
 *
 *  Created on: Nov 12, 2013
 *      Author: David
 */

#ifndef HEADER_H_
#define HEADER_H_
#include  <iostream>
#include <string>
#include "imagingfunctions.h"

class Imaging
{
protected:
	string Doctor;
	string Nurse;
};

class MRI : public Imaging {
private:
	string imagetype; // Select either MPR ,PROJECTION IMAGE, T1 MAP,
	//T2 MAP, DIFFUSION MAP, DENSITY MAP
	//PHASE MAP, VELOCITY MAP, IMAGE ADDITION,
	//PHASE SUBTRACT, MODULUS SUBTRACT, OTHER,
	int samplesperpixel;
	int bitsallocated;
	int highbit;

	// For
	//needs enumerated values
	//for scanning sequence   NO SE and GR together in one go
	int SpinEcho;
	int Inversionrecovery;
	int GradientRecalled;
	int Echoplanar;
	int researchmode;

	// For Sequence Variant function
	// Ask to set any variants or leave the settings alone (all = 0)
	// values
	int SK;
	int MTC;
	int SS;
	int TRSS;
	int OSP;

public:
	void MRIScanningseq();
	void SequenceVariant();
};
class Ct:public Imaging{
private:
string imagetype;// Axial or Localizer
int samplesperpixel;//should be one
int  photometricsel;// select either MONOCHROME1 or 2
//only selected when samples per pixel is one
int bitsallocated;
int bitsstored;  //should be b/t 12-16
int highbit; //should be one less than bits stored
int rescaleint;// the b in HU = m*SV+b
int resaleslope; // m slope
public:
void settingCT();
};
class Ultrasound : public Imaging{
int samplesperpixel;
int photometricInterpretation;
int bitallocated;
int bitstored;
int highbit;
int planerconfig;
int frameincrementpointer;
int lossyimagecompression; // either 00 or 01
public:

};




#endif /* HEADER_H_ */
