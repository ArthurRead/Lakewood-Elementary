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

	string comment;
	string morecomment;
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
	int bitsallocated;
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
//int bitstored;
	// For Sequence Variant function
	// Ask to set any variants or leave the settings alone (all = 0)
	// values
	//int SK;
	//int MTC;
	//int SS;
	//int TRSS;
	//int OSP;
	string sequencevar;
	int reptime;
	int echotime;

public:
	void settingMRI();
	void displayMRI();
	void displayall();
	void addcomment();
};
class Ct:public Imaging{
private:
//string imagetype;// Axial or Localizer
//int samplesperpixel;//should be one
string  photometricsel;// select either MONOCHROME1 or 2
//only selected when samples per pixel is one
//int bitsallocated;
int bitstored;  //should be b/t 12-16
//int highbit; //should be one less than bits stored
int rescaleint;// the b in HU = m*SV+b
int resaleslope; // m slope
int bitsallocated;
	int highbit;
public:
void settingCT();
void displayct();
void displayall();
void addcomment();
};
class Ultrasound : public Imaging{
//int samplesperpixel;
string photometricInterpretation;
//int bitallocated;
int bitstored;// how many bits are stored
//int highbit;
int bitsallocated;
	int highbit;
int planerconfig;//
string Pixelrep;//pixel representation
string lossyimagecompression; // either 00 or 01 type of compression
public:
void displayultrasound();
void settingultrasound();
void displayall();
void addcomment();
};

//


#endif /* HEADER_H_ */
