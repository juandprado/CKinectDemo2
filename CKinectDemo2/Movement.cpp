#include "Movement.h"



Movement::Movement()
{
}

Movement::Movement(FullBody * myBody, string name, float initialAngle, float finalAngle, BodyParts jointOne, BodyParts jointCenter, BodyParts jointTwo)
{
	this->myBody = myBody;
	this->name = name;
	this->initialAngle = initialAngle;
	this->finalAngle = finalAngle;
	this->jointOne = jointOne;
	this->jointCenter = jointCenter;
	this->jointTwo = jointTwo;
	deltaAngle = abs(finalAngle - initialAngle);
	percentaje = 0;
	initial = false;

}

Movement::~Movement()
{
}


float Movement::getAngleJoints(BodyParts pointOne, BodyParts pointCenter, BodyParts pointTwo)
{


	BodyPointPosition positionOne = myBody->returnPosition(pointOne);
	//cout << positionOne.x << ", " << positionOne.y << ", " << positionOne.z << endl;
	BodyPointPosition positionCenter = myBody->returnPosition(pointCenter);
	//cout << positionCenter.x << ", " << positionCenter.y << ", " << positionCenter.z << endl;
	BodyPointPosition positionTwo = myBody->returnPosition(pointTwo);
	//cout << positionTwo.x << ", " << positionTwo.y << ", " << positionTwo.z << endl;

	float vecAB[] = { positionOne.x - positionCenter.x, positionOne.y - positionCenter.y, positionOne.z - positionCenter.z };
	float vecBC[] = { positionTwo.x - positionCenter.x, positionTwo.y - positionCenter.y, positionTwo.z - positionCenter.z };

	float magAB = (float)sqrt(vecAB[0] * vecAB[0] + vecAB[1] * vecAB[1] + vecAB[2] * vecAB[2]);
	float magBC = (float)sqrt(vecBC[0] * vecBC[0] + vecBC[1] * vecBC[1] + vecBC[2] * vecBC[2]);

	float vecNormAB[] = { vecAB[0] / magAB, vecAB[1] / magAB, vecAB[2] / magAB };
	float vecNormBC[] = { vecBC[0] / magBC, vecBC[1] / magBC, vecBC[2] / magBC };

	float producto = vecNormAB[0] * vecNormBC[0] + vecNormAB[1] * vecNormBC[1] + vecNormAB[2] * vecNormBC[2];
	float angulo = acos(producto) * 180.0f / (PI);

	return angulo;
}



void Movement::calPercentMov()
{
	float  angleMov = getAngleJoints(jointOne, jointCenter, jointTwo);
	float progress = abs(angleMov - initialAngle);

	float tempPercent = (progress / deltaAngle)*100;
	if ((tempPercent > percentaje)&&(initial)) {
		percentaje = tempPercent;
	}
	cout << progress << "/" << deltaAngle << endl;
	//cout << "Percentaje " << percentaje << endl;
}

void Movement::initMov()
{
	float  angleMov = getAngleJoints(jointOne, jointCenter, jointTwo);

	initial =  (angleMov >= initialAngle-7)&&(angleMov <= initialAngle + 7);
	if (initial) {
		cout << "Inicia movimiento" << endl;
	}
	else {
		//cout << "Angle " << angleMov << endl;
	}
}

bool Movement::finishMov()
{

	//cout << "Angulo : " << getAngleJoints(jointOne, jointCenter, jointTwo) << endl;

	if (initial) {
		calPercentMov();
		if (percentaje > 90) {
			initial = false;
			percentaje = 0;
			return true;
		}
		else{
			return false;
		}
	}
	else {
		initMov();
		return false;
	}
	
	return false;
}
