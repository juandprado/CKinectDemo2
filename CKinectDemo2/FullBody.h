#pragma once
#include <iostream>
#include <windows.h>
#include <Ole2.h>
#include <NuiApi.h>
#include "BodyPoint.h"
#include "KinectOneAdapater.h"

using namespace std;

class FullBody
{
public:
	FullBody();
	FullBody(int sensor);
	~FullBody();
	BodyPointPosition returnPosition(BodyParts joint);

private:	

	BodyPoint* bodyPointsCollection[21];
	BodyParts translateNumber(int number);
	KinectOneAdapter* sensorOneKinect;
	void dataKinect();

};

