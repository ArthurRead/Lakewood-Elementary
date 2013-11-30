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
#include <sstring>
#include <cstdlib>
#include "imagingfunctions.h"

class Imaging
{
protected:
	string firstname;
	string lastname;
	string imagetype;
	int samplesperpixel;
	int bitsallocated;
	int highbit;
	string comment;
};

class MRI : public Imaging {
private:
	//string imagetype; // Select either MPR ,PROJECTION IMAGE, T1 MAP,
	//T2 MAP, DIFFUSION MAP, DENSITY MAP
	//PHASE MAP, VELOCITY MAP, IMAGE ADDITION,
	//PHASE SUBTRACT, MODULUS SUBTRACT, OTHER,
	//int samplesperpixel;
	//int bitsallocated;
	//int highbit;

	// For
	//needs enumerated values
	//for scanning sequence   NO SE and GR together in one go
	string Scanseq;
	//int SpinEcho;
	//int Inversionrecovery;
	//int GradientRecalled;
	//int Echoplanar;
	//int researchmode;

	// For Sequence Variant function
	// Ask to set any variants or leave the settings alone (all = 0)
	// values
	//int SK;
	//int MTC;
	//int SS;
	//int TRSS;
	//int OSP;
	string sequencevar;
public:
	void settingMRI();
	void displayMRI();
};
class Ct:public Imaging{
private:
//string imagetype;// Axial or Localizer
//int samplesperpixel;//should be one
string  photometricsel;// select either MONOCHROME1 or 2
//only selected when samples per pixel is one
//int bitsallocated;
int bitsstored;  //should be b/t 12-16
//int highbit; //should be one less than bits stored
int rescaleint;// the b in HU = m*SV+b
int resaleslope; // m slope
public:
void settingCT();
void displayct();

};
class Ultrasound : public Imaging{
//int samplesperpixel;
int photometricInterpretation;
//int bitallocated;
int bitstored;
//int highbit;
int planerconfig;
string Pixelrep;
string lossyimagecompression; // either 00 or 01
public:
void displayultrasound();
void settingultrasound();
};




#endif /* HEADER_H_ */
