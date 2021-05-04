//****************************************************************************
// File name:		Postcard.h
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
#include "Parcel.h"

using namespace std;

class Postcard : public Parcel {
public:	
	Postcard();

	virtual int getDeliveryDay() const override;
	virtual double getCost() const override;

	virtual double setInsured(bool);
	virtual double setRush(bool);

	virtual bool read(istream&) override;
	virtual void print(ostream&) const override;
protected:
	string mMessage;
};