//****************************************************************************
// File name:		Letter.h
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

class Letter : public Parcel {
public:
	Letter();

	virtual int getDeliveryDay() const override;
	virtual double getCost() const override;
	
	virtual double setInsured(bool);
	virtual double setRush(bool);

	virtual bool read(istream&) override;

};