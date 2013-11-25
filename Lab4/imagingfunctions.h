/*
 * imagingfunctions.h
 *
 *  Created on: Nov 24, 2013
 *      Author: David
 */

#ifndef IMAGINGFUNCTIONS_H_
#define IMAGINGFUNCTIONS_H_

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
void MRI::MRIScanningSeq()
{

}

#endif /* IMAGINGFUNCTIONS_H_ */
