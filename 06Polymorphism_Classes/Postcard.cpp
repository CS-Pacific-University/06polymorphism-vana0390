//****************************************************************************
// File name:		Postcard.cpp
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
#include "Postcard.h"

//****************************************************************************
// Constructor
//
// Description:	Sets default values for a postcard
//
// Parameters:	none
//****************************************************************************
Postcard::Postcard() : Parcel(), mMessage("")
{
}

//****************************************************************************
// Function:		getDeliveryDay
//
// Description:	gets the amount of days the postcard will be delivered
//
// Parameters:	none
//
// Returned:		int - the amount of days the postcard will be delivered
//****************************************************************************
int Postcard::getDeliveryDay() const
{
	const int MAX_DISTANCE = 10;
	int postcardDistance = Parcel::getDistance();

	if (postcardDistance % MAX_DISTANCE == 0) {
		return postcardDistance / MAX_DISTANCE;
	}
	else {
		postcardDistance /= MAX_DISTANCE;
		++postcardDistance;
		return postcardDistance;
	}
}

//****************************************************************************
// Function:		getCost
//
// Description:	calculates the cost of a postcard
//
// Parameters:	none
//
// Returned:		double - the cost of delivering the postcard
//****************************************************************************
double Postcard::getCost() const
{
	const double INSURED = 0.15;
	const double RUSH = 0.25;
	double totalCost = 0.15;
	
	if (mbInsured) {
		totalCost += INSURED;
	}
	if (mbRush) {
		totalCost += RUSH;
	}
	
	return totalCost;
}

//****************************************************************************
// Function:		setInsured
//
// Description:	sets the price of insurance on a postcard
//
// Parameters:	bIsInsured - whether the user wants insurance or not
//
// Returned:		double		 -  value for insurance on a postcard
//****************************************************************************
double Postcard::setInsured(bool bIsInsured)
{
	const double POSTCARD_INSURED = 0.15;
	if (bIsInsured == true) {
		mbInsured = true;
	}
	return POSTCARD_INSURED;
}

//****************************************************************************
// Function:		setRush
//
// Description:	sets the price of rush on a postcard
//
// Parameters:	bIsInsured - whether the user wants rush or not
//
// Returned:		double		 -  value for rush on a postcard
//****************************************************************************
double Postcard::setRush(bool bIsRush)
{
	const double POSTCARD_RUSH = 0.25;
	if (bIsRush == true) {
		mbRush = true;
	}
	return POSTCARD_RUSH;
}

//****************************************************************************
// Function:		read
//
// Description:	reads in a file for a postcard
//
// Parameters:	rcIn - the input stream
//
// Returned:		bool - whether reading in the file was successful or not
//****************************************************************************
bool Postcard::read(istream& rcIn)
{
	Parcel::read(rcIn);
	rcIn >> mMessage;
	return true;
}

//****************************************************************************
// Function:		print
//
// Description:	prints the information from a postcard to the screen
//
// Parameters:	rcOut - the output stream
//
// Returned:		none
//****************************************************************************
void Postcard::print(ostream& rcOut) const
{
	Parcel::print(rcOut);
	rcOut << "\t" << mMessage;
}
