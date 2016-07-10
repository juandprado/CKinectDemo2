#pragma once
#include "BodyPoint.h"
#include "FullBody.h"



class Movement
{
public:
	Movement();
	Movement(FullBody* myBody, string name, float initialAngle, float finalAngle, BodyParts joinOne, BodyParts joinCenter, BodyParts joinTwo);
	~Movement();
	float getAngleJoints(BodyParts pointOne, BodyParts pointCenter, BodyParts pointTwo);
	void calPercentMov();
	void initMov();
	bool finishMov();


private:
	string name;
	float initialAngle;
	float finalAngle;
	FullBody* myBody;
	BodyParts jointOne;
	BodyParts jointCenter;
	BodyParts jointTwo;
	float deltaAngle;
	float percentaje;
	bool initial;

};

