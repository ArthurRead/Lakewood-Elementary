/*
 * imagingfunctions.h
 *
 *  Created on: Nov 24, 2013
 *      Author: David
 */

#ifndef IMAGINGFUNCTIONS_H_
#define IMAGINGFUNCTIONS_H_
#include <cstdlib>
void Ct::settingCT()
{
	cout<< "\nPlease enter the first name of the patient\n";
	cin >>firstname;
	cout <<"\n Please enter the last name of the patient\n";
	cin >> lastname;
	cout<<"\nNow performing the settings of the CT\n";
	cout<<"Please enter the type of image for the CT scan\n";
	int choice=0;
	int exit1=0;
	while(exit1==0)
	{
	cout <<"Press 1 for Axial\tPress 2 for Localizer";

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
	{
		cout << "\nPlease enter your selection. Please\n";

	}
	}
	}
	cout << "\nSmaple per pixel are automatically set to 1 for CT scans\n?";
	int samplesperpixel=1;
	choice =0;
	int exit=0;
	while (exit==0){
	cout << "\nPlease select the photometric interpretation\n";
	cout <<"Pick 1 for MONOCHROME1 PICK 2 for MONOCHROME2\n";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		photometricsel = "MONOCHROME1";
		exit=1;
	break;
	}
	case 2:
	{	photometricsel - "MONOSCHROME2";
		exit= 1;
		break;
	}
	default:{
		break;
	}
	}
	}
	cout <<"\nBits allocated is 16 bits for CT scans\n";
	bitsallocated = 16;
	exit = 0;
	choice = 0;
	while (exit == 0)
	{
		cout <<"Please enter how many bits are stored\n";
			cin >> choice;
			if (choice > 16 || choice <12)
			{
				cout << "\nPlease pick again\n";
			}
			else
			{
				bitstored = choice;
				highbit = bitstored - 1;
				cout << highbit << " is the high bit\n";
				exit =1;
			}


	}
	cout << "Please enter the rescale intercept\n";
	cin >> rescaleint;
	cout << "\nPlease enter the rescale slope\n";
	cin >> rescaleslope;
	cout <<"Enter any comments or just press return to enter none";
	getline(comment);
	cout <<"Please place the images in the same directory as the executable and rename it appropriately CT.jpg  ";

}
void Ct::displayct()
{
cout <<"Please place the images in the same directory as the executable and rename it appropriately CT.jpg  ";
system("CT.jpg");
}
void Ct::addcomment()
{
	cout<<"\n"<<comment;
	cout <<"\nPlease enter the comments\n";
	cin >> morecomment;
	comment+=morecomment;


}
void Ct::displayall()
{
	cout <<" \nThe patient is \t"<<firstname <<" "<<lastname;
	cout <<"\nThe imagetype is \t"<<imagetype<<"\n";
	cout <<"\nSamples per pixel is\t"<<samplesperpixel;
	cout<<"\nBits allocated is\t"<<bitsallocated;
	cout<<"\nHigh bit is \t"<<highbit;
	cout <<"\nBits stored:\t"<<bitstored;
cout <<"\nPhotometric Interpretation:\t"<<photometricsel;
	cout <<"\nRescale slope:\t"<<rescaleslope;
	cout <<"Rescale intercept:\t"<<rescaleint;
	cout<<"\nComments:\t"<<comment;
	displayct();
}
void MRI::settingMRI()
{
	cout<< "\nPlease enter the first name of the patient\n";
		cin >>firstname;
		cout <<"\n Please enter the last name of the patient\n";
		cin >> lastname;
		cout<<"\nNow performing the settings of the MRI\n";
		cout<<"Please enter the type of image for the MRI scan\n";
		int exit = 0;
		int choice = 0;
		cout << "Please enter the repetition time in ms";
		cin >> reptime;
		cout <<"Please enter the echo time in ms";
		cin >> echotime;
	while (exit==0)
	{

		cout << "\n Please enter one of the following for the image type\n";
		cout << "1. for MPR\n2 for PROJECTION IMAGE\n3 for T1 MAP";
	cout<<"\n4 for T2 MAP\n5 for DIFFUSION MAP\n6 for DENSITY MAP\n";
	cout <<"7 forPHASE MAP\n8 for VELOCITY MAP\n9 for IMAGE ADDITION";
	cout <<"10 for PHASE SUBTRACT\n11 for MODULUS SUBTRACT\n 13 of OTHER\n";
	cin >> choice;

		switch (choice)
		{
		case 1:
		{
			imagetype = "MPR";
			exit =1;
			break;
		}
		case 2:
		{
			imagetype ="PROJECTION IMAGE";
			exit =1;
			break;
		}
		case 3:
		{
			imagetype = "T1 MAP";
			exit =1;
			break;

		}
		case 4: {
			imagetype = "T2 MAP";
			exit =1;
			break;
		}
		case 5 :
		{
			imagetype= "DIFFUSION MAP";
			exit =1;
			break;
		}
		case 6 : {
			imagetype = "DENSITY MAP";
			exit =1;
			break;
		}
		case 7 :
		{
			imagetype = "PHASE MAP";
			exit =1;
			break;
		}
		case 8 :
		{
			imagetype = "Velocity MAP";
			exit =1;
			break;
		}
		case 9:
		{
			imagetype = "IMAGE ADDITION";
			exit = 1;
			break;
		}
		case 10:
		{
			imagetype = "PHASE SUBTRACT";
			exit =1 ;
			break;

		}
		case 11:
		{
			imagetype = "MODULUS SUBTRACT";
					exit =1 ;
					break;

		}
		case 12:
		{
			imagetype = "PHASE SUBTRACT";
					exit =1 ;
					break;
		}
		case 13:
		{
			cout <<"\nPlease type in the imagetype\n";
			getline(imagetype);
			exit =1;
			break;
		}
		default:
		{
			break;
		}
		}

}
	cout <<"\nBits allocated is 16 bits for MRI scans\n";
		bitsallocated = 16;
		exit = 0;
		choice = 0;


cout <<"\nPlease enter the Scan sequence\n";
exit =1;
choice =0;
while (exit==0)
{
cout << "Please select one of the following options\n";
cout << "1.SPIN ECHO\n2.Inversion Recovery\n3.Gradient Recalled\n";
cout << "4.Echo Planer\n5.Research Mode\n";
cin>> choice;
switch (choice){
case 1:
{
	Scanseq = "SPIN ECHO";
	exit =1;
	break;
}
case 2:
{
	Scanseq = "Inversion Recovery";
	exit =1;
	break;
}
case 3:
{
	Scanseq = "Gradient Recalled";
	exit =1;
	break;
}
case 4:
{
	Scanseq = "ECHO Planer";
	exit =1;
	break;
}
case 5:
{
	Scanseq = "Research Mode";
	exit =1;
	break;
}

default:
{
	break;
}
}
}
exit =0;
choice = 0;
while (exit==0)
{
cout << "\nPlease enter the Sequence Variant";
cout << "\n1.Segmented K-space\n2.Magentization Transfer Contrast\n3.Steady State";
cout << "\n4.Time Reversed Steady State\n5.Spoiled\n6.MAG prepared\n7.Oversampling Phase\n8.None";
cin >> choice;
 switch (choice)
 {
 case 1:
 {
	 sequencevar = "Segmented K-space";
	 exit =1;
	 break;

 }
 case 2:
  {
 	 sequencevar = "Magnetization Transfer contrast";
 	 exit =1;
 	 break;

  }
 case 3:
  {
 	 sequencevar = "Steady State";
 	 exit =1;
 	 break;

  }
 case 4:
  {
 	 sequencevar = "Time Reversed Steady State";
 	 exit =1;
 	 break;

  }
 case 5:
  {
 	 sequencevar = "Spoiled";
 	 exit =1;
 	 break;

  }
 case 6:
  {
 	 sequencevar = "MAG prepared";
 	 exit =1;
 	 break;

  }
 case 1:
  {
 	 sequencevar = "Oversampling phase";
 	 exit =1;
 	 break;

  }
 case 1:
  {
 	 sequencevar = "NONE";
 	 exit =1;
 	 break;

  }
default:
{
	break;
}
 }






}
cout <<"Enter any comments then press enter or just press return to enter none";
getline(comment);


cout <<"Please place the images in the same directory as the executable and rename it appropriately MRI.jpg  ";



}
void	MRI::displayMRI()
{
	cout <<"Please place the images in the same directory as the executable and rename it appropriately MRI.jpg  ";

	system("MRI.jpg");

}
void
void MRI::displayall()
{
	cout <<" \nThe patient is \t"<<firstname <<" "<<lastname;
		cout <<"\nThe imagetype is \t"<<imagetype<<"\n";
		cout <<"\nSamples per pixel is\t"<<samplesperpixel;
		cout<<"\nBits allocated is\t"<<bitsallocated;
		cout<<"\nHigh bit is \t"<<highbit;
		cout <<"\nBits stored:\t"<<bitstored;
		cout<<"\nScan sequence:\t"<<Scanseq;
		cout <<"\nSequence Variant:\t"<<sequencevar;
		cout<<"Repetition Time:\t"<<reptime;
		cout<<"Echo time:\t:"<<echotime;
		cout<<"Comments:\t"<<comment;
		displayMRI();
}
void MRI::addcomment()
{
	cout<<"\n"<<comment;
	cout <<"\nPlease enter the comments\n";
	cin >> morecomment;
	comment+=morecomment;


}
void Ultrasound::settingultrasound()
{
	cout<< "\nPlease enter the first name of the patient\n";
			cin >>firstname;
			cout <<"\n Please enter the last name of the patient\n";
			cin >> lastname;
			cout<<"\nNow performing the settings of the ultrasound\n";
			cout<<"Please enter the type of image for the ultrasound scan\n";
			int exit = 0;
			int choice = 0;

			cout << "\n Press type in the image type from the following\n";
			cout << "ABDOMINAL, BREAST, CHEST\n";
			cout <<"ENDOCAVITARY, ENDORECTAL, ENDOVAGINAL\n";
			cout <<"EPICARDIAL, FETAL HEART, GYNECOLOGY\n";
			cout<<"INTRACARDIAC, INTRAOPERATIVE, INTRAVASCULAR\n";
			cout<<"MUSCULOSKELETAL, NEONATAL HEAD, OBSTETRICAL\n";
			cout <<"OPHTHALMIC, PEDIATRIC, PELVIC\n";
			cout <<"RETROPERITONEAL, SCROTAL, SMALL PARTS\n";
			cout <<"TEE, THYROID, TRANSCRANIAL\n";
			cout <<"TTE, US BIOPSY, VASCULAR";
			getline(imagetype);




			cout << "\nPlease select the photometric interpreation \n";
			while (exit==0)
			{

			cout <<"\n1.MONOCHROME2\n2.RGB\n3.YBR FULL\n4.YBRFULL 422\n";
			cout <<"5.YRB Partial 422\n6.YBR RCT\n7.YBR ICT\n8.Palette Color 8bit\n9.Palette Color 16 bit\n";
			cin >> choice;
			switch (choice)
			{
			case 1:
			{

				photmetricInterpretation = "MONOCHROME2";
				bitstored =  8;
				samplesperpixel = 1;
				bitallocated = 8;
				highbit = bitallocated - 1;
				planerconfig = 0 ;
				exit=1;
				break;
			}
			case 2:
						{
							photometricInterpretation = "RGB";
							bitstored =  8;
							samplesperpixel =3 ;
							bitallocated = 8;
							highbit = bitallocated - 1;
							planerconfig = 1;
							exit=1;
							break;
						}
			case 3:
						{
							photometricInterpretation = "YBR FULL";
							bitstored = 8 ;
							samplesperpixel = 3;
							bitallocated = 8;
							highbit = bitallocated - 1;
							planerconfig = 1;
							exit=1;
							break;
						}
			case 4:
						{
							photometricInterpretation = "YBR FULL 422";
							bitstored =  8;
							samplesperpixel =3 ;
							bitallocated =8 ;
							highbit = bitallocated - 1;
							planerconfig = 0;
							exit=1;
							break;
						}
			case 1:
						{
							photometricInterpretation = "YBR PARTIAL 422";
							bitstored =  8;
							samplesperpixel = 3;
							bitallocated = 8;
							highbit = bitallocated - 1;
							planerconfig = 0;
							exit=1;
							break;
						}
			case 1:
						{
							photometricInterpretation = "YBR RCT";
							bitstored =  8;
							samplesperpixel = 3;
							bitallocated = 8;
							highbit = bitallocated - 1;
							planerconfig =0 ;
							exit=1;
							break;
						}

			case 1:
						{
							photometricInterpretation = "YBR ICT";
							bitstored = 8 ;
							samplesperpixel =3 ;
							bitallocated = 8;
							highbit = bitallocated - 1;
							planerconfig = 0;
							exit=1;
							break;
						}
			case 1:
						{
							photometricInterpretation = "Palette color 8 bit";
							bitstored =8  ;
							samplesperpixel = 1;
							bitallocated =8 ;
							highbit = bitallocated - 1;
							planerconfig =0 ;
							exit=1;
							break;
						}
			case 1:
						{
							photometricInterpretation = "Palette color 16 bit";
							bitstored = 16 ;
							samplesperpixel =1 ;
							bitallocated = 16;
							highbit = bitallocated - 1;
							planerconfig = 0;
							exit=1;
							break;
						}


			}
			}


			Pixelrep = "0000H";
	cout << "\nPixel Representation is equal to"<< Pixelrep<<"\n";
	cout <<	"\nPlease enter the lossy image compression\n";
	exit =0;
	choice = 0;
	while(exit ==0)
	{
		cout <<"1. 00\n 2.01";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			exit =1;
			lossyimagecompression ="00";
			break;
		}
		case 2:
		{
			exit =1;
			lossyimagecompression ="01";
		}
		default:
		{
			break;
		}

		}

	}
	cout <<"Enter any comments then press enter or just press return to enter none";
	getline(comment);
	cout <<"Please place the images in the same directory as the executable and rename it appropriately US.jpg  ";

}
void Ultrasound::displayultrasound()
{
	cout <<"Please place the images in the same directory as the executable and rename it appropriately US.jpg  ";

	system("US.jpg");
}
void Ultrasound::addcomment()

{
	cout<<"\n"<<comment;
	cout <<"\nPlease enter the comments\n";
	cin >> morecomment;
	comment+=morecomment;


}
void Ultrasound::displayall()
{
	cout <<" \nThe patient is \t"<<firstname <<" "<<lastname;
		cout <<"\nThe image type is \t"<<imagetype<<"\n";
		cout <<"\nSamples per pixel is\t"<<samplesperpixel;
		cout<<"\nBits allocated is\t"<<bitsallocated;
		cout<<"\nHigh bit is \t"<<highbit;
		cout <<"\nBits stored:\t"<<bitstored;
		cout<<"\nPhotometric Interpretation:\n"<<photometricInterpretation;
		cout<<"\nPlaner configuration:\t"<<planerconfig;
		cout<<"\nPixel Representation:\t"<<pixelrep;
		cout<<"\nLossy image compression:\t"<<lossyimagecompression;
displayultrasound();
//

}










#endif /* IMAGINGFUNCTIONS_H_ */
