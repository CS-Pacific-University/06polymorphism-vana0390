//****************************************************************************
// File name:		Letter.cpp
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
#include "Letter.h"

//****************************************************************************
// Constructor
//
// Description:	Sets default values for a letter
//
// Parameters:	none
//****************************************************************************
Letter::Letter() : Parcel()
{
}

//****************************************************************************
// Function:		getDeliveryDay
//
// Description:	gets the amount of days the letter will be delivered
//
// Parameters:	none
//
// Returned:		int - the amount of days the letter will be delivered
//****************************************************************************
int Letter::getDeliveryDay() const
{
	const int MAX_DISTANCE = 100;
	int letterDistance = getDistance();
	
	if (letterDistance % MAX_DISTANCE == 0) {
		return letterDistance / MAX_DISTANCE;
	}
	else {
		letterDistance /= MAX_DISTANCE;
		++letterDistance;
		return letterDistance;
	}
}

//****************************************************************************
// Function:		getCost
//
// Description:	calculates the cost of a letter
//
// Parameters:	none
//
// Returned:		double - the cost of delivering the letter
//****************************************************************************
double Letter::getCost() const
{
	const double INSURED = 0.45;
	double totalCost = 0.45 * getWeight();
	double rush = 0.10 * totalCost;

	if (mbInsured) {
		totalCost += INSURED;
	}
	if (mbRush) {
		totalCost += rush;
	}
	
	return totalCost;
}

//****************************************************************************
// Function:		setInsured
//
// Description:	sets the price of insurance on a letter
//
// Parameters:	bIsInsured - whether the user wants insurance or not
//
// Returned:		double		 -  value for insurance on a letter
//****************************************************************************
double Letter::setInsured(bool bIsInsured)
{
	const double LETTER_INSURED = 0.45;
	if (bIsInsured == true) {
		mbInsured = true;
	}
	return LETTER_INSURED;
}

//****************************************************************************
// Function:		setRush
//
// Description:	sets the price of rush on a letter
//
// Parameters:	bIsInsured - whether the user wants rush or not
//
// Returned:		double		 -  value for rush on a letter
//****************************************************************************
double Letter::setRush(bool bIsRush)
{
	const double PERCENT_COST = 0.10;
	if (bIsRush == true) {
		mbRush = true;
	}
	return PERCENT_COST * getCost();
}

//****************************************************************************
// Function:		read
//
// Description:	reads in a file for a letter
//
// Parameters:	rcIn - the input stream
//
// Returned:		bool - whether reading in the file was successful or not
//****************************************************************************
bool Letter::read(istream& rcIn)
{
	Parcel::read(rcIn);
	return true;
}
