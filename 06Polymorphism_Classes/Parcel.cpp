//****************************************************************************
// File name:		Parcel.cpp
// Author:			Sara Vanaken
// Date:				5/3/2021
// Class:				CS 250
// Assignment:  06_Polymorphism
// Purpose:			Demonstrate the Parcel class
//****************************************************************************

#include <iostream>
#include <string>
#include <fstream>
#include "Parcel.h"

using namespace std;

//****************************************************************************
// Constructor: Parcel
//
// Description:	Sets default values for a parcel
//
// Parameters:	none
//****************************************************************************
Parcel::Parcel()
{
	mTrackingID = 0;
	mTo = "";
	mFrom = "";
	mWeight = 0;
	mDistance = 0;
	mCost = 0;
	mbInsured = false;
	mbRush = false;
	mbDelivered = false;
}

//****************************************************************************
// Function:		getWeight
//
// Description:	gets the value for the weight of a parcel
//
// Parameters:	none
//
// Returned:		int - the weight of the parcel
//****************************************************************************
int Parcel::getWeight() const
{
	return mWeight;
}

//****************************************************************************
// Function:		getDistance
//
// Description:	gets the value for the distance of the parcel
//
// Parameters:	none
//
// Returned:		int - the distance of the parcel
//****************************************************************************
int Parcel::getDistance() const
{
	return mDistance;
}

//****************************************************************************
// Function:		getRush
//
// Description:	determines whether the user wants rush or not
//
// Parameters:	none
//
// Returned:		bool - rush (true) or no rush (false)
//****************************************************************************
bool Parcel::getRush() const
{
	bool mbRush = true;
	return mbRush;
}

//****************************************************************************
// Function:		getInsured
//
// Description:	determines whether the user wants insurance or not
//
// Parameters:	none
//
// Returned:		bool -  insurance (true) or no insurance (false)
//****************************************************************************
bool Parcel::getInsured() const
{
	bool mbInsured = true;
	return mbInsured;
}

//****************************************************************************
// Function:		getTrackingID
//
// Description:	gets the value for the tracking ID
//
// Parameters:	none
//
// Returned:		int - the tracking ID of the parcel
//****************************************************************************
int Parcel::getTrackingID() const
{
	return mTrackingID;
}

//****************************************************************************
// Function:		read
//
// Description:	reads in a file for a parcel
//
// Parameters:	rcIn - the input stream
//
// Returned:		bool - whether reading in the file was successful or not
//****************************************************************************
bool Parcel::read(istream& rcIn)
{
	rcIn >> mTrackingID >> mTo >> mFrom
			 >> mWeight >> mDistance;
	return true;
}

//****************************************************************************
// Function:		print
//
// Description:	displays the data of a parcel
//
// Parameters:	rcOut - the output stream
//
// Returned:		none
//****************************************************************************
void Parcel::print(ostream& rcOut) const
{
	rcOut << "TID: " << mTrackingID << "\tFrom: "
				<< mFrom << "\tTo: " << mTo;
	if (mbInsured == true) {
		rcOut << "\t INSURED";
	}
	if (mbRush == true) {
		rcOut << "\t RUSH";
	}
}

//****************************************************************************
// Function:		getCost
//
// Description:	gets the cost of a parcel
//
// Parameters:	none
//
// Returned:		double - the cost of delivering the parcel
//****************************************************************************
double Parcel::getCost() const
{
	return mCost;
}

//****************************************************************************
// Function:		getDeliveryDay
//
// Description:	gets the amount of days the parcel will be delivered
//
// Parameters:	none
//
// Returned:		int - the minimum amount of days the parcel will be delivered
//****************************************************************************
int Parcel::getDeliveryDay() const
{
	const int MINIMUM_DAY = 1;
	return MINIMUM_DAY;
}
