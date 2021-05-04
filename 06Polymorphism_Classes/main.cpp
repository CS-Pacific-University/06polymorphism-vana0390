//****************************************************************************
// File name:		main.cpp
// Author:			Sara Vanaken
// Date:				5/3/2021
// Class:				CS 250
// Assignment:  06_Polymorphism
// Purpose:			Demonstrate the Parcel class
//****************************************************************************
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "Parcel.h"
#include "Letter.h"
#include "Postcard.h"
#include "OvernightPkg.h"

using namespace std;

//****************************************************************************
// Function:		main
//
// Description:	Demonstrates the uses of the parcel class and its 
//              sub-classes
//
// Parameters:	none
//
// Returned:		exit success
//****************************************************************************
int main() {
  const char LETTER = 'L';
  const char POSTCARD = 'P';
  const char OVERNIGHT = 'O';
  const int MAX_SIZE = 25;
  const int FIRST_TID = 1;
  const int FIRST_OPT = 1;
  const int SECOND_OPT = 2;
  const int THIRD_OPT = 3;
  const int FOURTH_OPT = 4;
  const int QUIT = 5;
  const string INPUT_FILE = "parcels.txt";

  bool bIsInsured = false;
  bool bIsRush = false;
  char parcelType;
  int numParcels = 0;
  int choice;
  int trackingID;
  Parcel* pacParcels[MAX_SIZE] = { nullptr };
  ifstream inputFile;
  OvernightPkg betaType;
  
  cout << fixed << setprecision(2);
  
  inputFile.open(INPUT_FILE);
  if (!inputFile.is_open()) {
    cout << "ERROR- COULD NOT OPEN FILE";
    return EXIT_FAILURE;
  }

  while (!inputFile.eof()) {
    inputFile >> parcelType;
    switch (parcelType) {
    case LETTER:
      pacParcels[numParcels] = new Letter();
      pacParcels[numParcels]->read(inputFile);
      ++numParcels;
      break;
    case POSTCARD:
      pacParcels[numParcels] = new Postcard();
      pacParcels[numParcels]->read(inputFile);
      ++numParcels;
      break;
    case OVERNIGHT:
      pacParcels[numParcels] = new OvernightPkg();
      pacParcels[numParcels]->read(inputFile);
      ++numParcels;
      break;
    }
  }
  cout << "Mail Simulator!\n";
  
  do {
    cout << "\n1. Print All"
      << "\n2. Add Insurance"
      << "\n3. Add Rush"
      << "\n4. Deliver"
      << "\n5. Quit\n";
    do {
      cout << "\nChoice> ";
      cin >> choice;
    } while (choice < FIRST_OPT || choice > QUIT);

    switch (choice) {
    case FIRST_OPT:
      cout << endl;
      for (int i = 0; i < numParcels; i++) {
        if (pacParcels[i] != nullptr) {
          pacParcels[i]->print(cout);
          cout << endl;
        }
      }
      break;
    case SECOND_OPT: cout << endl;
      cout << "TID> ";
      cin >> trackingID;

      if (trackingID >= FIRST_TID && trackingID <= numParcels) {
        bIsInsured = true;
        cout << "Added Insurance for $"
             << pacParcels[trackingID - 1]->setInsured(bIsInsured) << endl;
        pacParcels[trackingID - 1]->print(cout);
        cout << endl;
      }
      break;
    case THIRD_OPT: cout << endl;
      cout << "TID> ";
      cin >> trackingID;
      
      if (trackingID >= FIRST_TID && trackingID <= numParcels) {
        bIsRush = true;
        cout << "Added Rush for $"
          << pacParcels[trackingID - 1]->setRush(bIsRush) << endl;
        pacParcels[trackingID - 1]->print(cout);
        cout << endl;
      }
      break;
    case FOURTH_OPT: cout << endl;
      cout << "TID> ";
      cin >> trackingID;
      if (trackingID >= FIRST_TID && trackingID <= numParcels) {
        cout << "Delivered!\n"
          << pacParcels[trackingID - 1]->getDeliveryDay() << " Day, $"
          << pacParcels[trackingID - 1]->getCost() << endl;
        pacParcels[trackingID - 1]->print(cout);
        cout << endl;
        pacParcels[trackingID - 1] = nullptr;
      }
      break;
    }
    
  } while (choice != QUIT);

  for (int i = 0; i < MAX_SIZE; i++) {
    delete pacParcels[i];
  }
  
  return EXIT_SUCCESS;
}