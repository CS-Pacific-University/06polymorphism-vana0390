//****************************************************************************
// File name:		OvernightPkg.cpp
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
#include "OvernightPkg.h"

//****************************************************************************
// Constructor
//
// Description:	Sets default values for an overnight package
//
// Parameters:	none
//****************************************************************************
OvernightPkg::OvernightPkg() : Parcel(), mVolume(0)
{
}

//****************************************************************************
// Function:		getDeliveryDay
//
// Description:	gets the amount of days the overnight package
//							will be delivered
//
// Parameters:	none
//
// Returned:		int - the amount of days the package will be delivered
//****************************************************************************
int OvernightPkg::getDeliveryDay() const
{
	const int MAX_DISTANCE = 1000;
	const int DOUBLE = 2;
	int deliveryDay;

	if (getDistance() <= MAX_DISTANCE) {
		deliveryDay = getDistance() / MAX_DISTANCE;
		++deliveryDay;
		return deliveryDay;
	}
	else {
		deliveryDay = DOUBLE * getDistance();
		return deliveryDay / MAX_DISTANCE;
	}
}

//****************************************************************************
// Function:		getCost
//
// Description:	calculates the cost of an overnight package
//
// Parameters:	none
//
// Returned:		double - the cost of delivering the package
//****************************************************************************
double OvernightPkg::getCost() const
{
	const int MAX_VOLUME = 100;
	const double HIGH_PRICE = 20;
	const double LOW_PRICE = 12;
	const double INSURED = 0.25;
	const double RUSH = 0.75;
	double totalCost, insured, rush;

	if (mVolume <= MAX_VOLUME) {
		totalCost = LOW_PRICE;
	}
	else {
		totalCost = HIGH_PRICE;
	}

	if (mbInsured) {
		insured = totalCost * INSURED;
		totalCost += insured;
	}
	if (mbRush) {
		rush = totalCost * RUSH;
		totalCost += rush;
	}
	return totalCost;
}

//****************************************************************************
// Function:		setInsured
//
// Description:	sets the price of insurance on an overnight package
//
// Parameters:	bIsInsured - whether the user wants insurance or not
//
// Returned:		double		 -  value for insurance on a package
//****************************************************************************
double OvernightPkg::setInsured(bool bIsInsured)
{
	const double PERCENT_COST = 0.25;
	double cost = getCost();
	if (bIsInsured == true) {
		mbInsured = true;
	}
	return PERCENT_COST * cost;
}

//****************************************************************************
// Function:		setRush
//
// Description:	sets the price of rush on an overnight package
//
// Parameters:	bIsInsured - whether the user wants rush or not
//
// Returned:		double		 -  value for rush on a package
//****************************************************************************
double OvernightPkg::setRush(bool bIsRush)
{
	const double PERCENT_COST = 0.75;
	double cost = getCost();
	if (bIsRush == true) {
		mbRush = true;
	}
	return PERCENT_COST * cost;
}

//****************************************************************************
// Function:		read
//
// Description:	reads in a file for an overnight package
//
// Parameters:	rcIn - the input stream
//
// Returned:		bool - whether reading in the file was successful or not
//****************************************************************************
bool OvernightPkg::read(istream& rcIn)
{
	Parcel::read(rcIn);
	rcIn >> mVolume;
	return true;
}

//****************************************************************************
// Function:		print
//
// Description:	prints the information from an
//							overnight package to the screen
//
// Parameters:	rcOut - the output stream
//
// Returned:		none
//****************************************************************************
void OvernightPkg::print(ostream& rcOut) const
{
	Parcel::print(rcOut);
	rcOut << "\t OVERNIGHT!";
}