//****************************************************************************
// File name:		Parcel.h
// Author:			Sara Vanaken
// Date:				5/3/2021
// Class:				CS 250
// Assignment:  06_Polymorphism
// Purpose:			Demonstrate the Parcel class
//****************************************************************************
#pragma once

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Parcel {
public:
	Parcel();

	int getWeight() const;
	int getDistance() const;
	
	virtual bool getRush() const;
	virtual bool getInsured() const;
	int getTrackingID() const;

	virtual double setRush(bool) = 0;
	virtual double setInsured(bool) = 0;

	virtual bool read(istream&);
	virtual void print(ostream&) const;

	virtual double getCost() const;
	virtual int getDeliveryDay() const;

protected:
	int mTrackingID;
	string mTo;
	string mFrom;
	
	int mWeight;
	int mDistance;
	double mCost;

	bool mbInsured;
	bool mbRush;
	bool mbDelivered;
};