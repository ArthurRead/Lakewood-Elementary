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

class MRI{
private:
	string imagetype;
	int samplesperpixel;
	int bitsallocated;
	int highbit;


public:
	void MRIScanningseq();

};
class Ct{
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
class Ultrasound{

};

void Ct::settingCT()
{
	cout<<"\nNow performing the settings of the CT\n";
	cout<<"Please enter the type of image for the CT scan\n";
	while(choice!=112)
	{
	cout <<"Press 1 for Axial\tPress 2 for Localizer";
	int choice=11;
	int exit1=0;
	cin >>choice;

	switch(choice)
	{
	case 1:
	{   imagetype ="Axial";
		exit1=112;
		break;
	}
	case2:
{	imagetype = "Localizer";
	exit1=112;
	break;
}
	default:
	{cout << "\nPlease enter your selection. Please\n";

	}
	}
	}


}



#endif /* HEADER_H_ */
