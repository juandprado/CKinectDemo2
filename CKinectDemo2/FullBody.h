#pragma once
#include <iostream>
#include <windows.h>
#include <Ole2.h>
#include <stdio.h>
#include <math.h>
#include <NuiApi.h>
#include "BodyPoint.h"
#include "KinectOneAdapater.h"
#define PI 3.14159265

using namespace std;

class FullBody
{
public:
	FullBody();
	FullBody(int sensor);
	~FullBody();
	BodyPointPosition returnPosition(BodyParts joint);
	float getAngleJoints(BodyParts pointOne, BodyParts pointCenter, BodyParts pointTwo);
	void dataKinect();


private:	

	BodyPoint* bodyPointsCollection[21];
	BodyParts translateNumber(int number);
	KinectOneAdapter* sensorOneKinect;

};

