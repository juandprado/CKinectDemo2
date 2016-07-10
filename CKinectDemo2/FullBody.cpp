#include "FullBody.h"
#include <thread>
#include <iostream>
using namespace std;



FullBody::FullBody()
{


}

void FullBody::dataKinect()
{
	cout << "Datakinect" << endl;
	sensorOneKinect->Update();
}

FullBody::FullBody(int sensor)
{
	cout << "Entra constructor" << endl;
	for (int i = 0; i < 21; i++) {
		bodyPointsCollection[i] = &BodyPoint(translateNumber(i));
	}	

	cout << "Sale del for " << endl;
	KinectOneAdapter hola;
	cout << "instancia kinectadapter" << endl;
	sensorOneKinect = &hola;
	sensorOneKinect->setBodyPoints(bodyPointsCollection);
	cout << "Referencia kinectadapter " << endl;
	cout << "Entra a datakinect " << endl;
	dataKinect();

}



FullBody::~FullBody()
{

}

BodyPointPosition FullBody::returnPosition(BodyParts joint)
{
	const int num = joint;
	BodyPointPosition position = bodyPointsCollection[num]->getCurrentPosition();
	return  position;
}

float FullBody::getAngleJoints(BodyParts pointOne, BodyParts pointCenter, BodyParts pointTwo)
{


	BodyPointPosition positionOne = returnPosition(pointOne);
	BodyPointPosition positionCenter = returnPosition(pointCenter);
	BodyPointPosition positionTwo = returnPosition(pointTwo);

	float vecAB[] = { positionOne.x - positionCenter.x, positionOne.y - positionCenter.y, positionOne.z - positionCenter.z };
	float vecBC[] = { positionTwo.x - positionCenter.x, positionTwo.y - positionCenter.y, positionTwo.z - positionCenter.z };

	float magAB = (float)sqrt(vecAB[0] * vecAB[0] + vecAB[1] * vecAB[1] + vecAB[2] * vecAB[2]);
	float magBC = (float)sqrt(vecBC[0] * vecBC[0] + vecBC[1] * vecBC[1] + vecBC[2] * vecBC[2]);

	float vecNormAB[] = { vecAB[0] / magAB, vecAB[1] / magAB, vecAB[2] / magAB };
	float vecNormBC[] = { vecBC[0] / magBC, vecBC[1] / magBC, vecBC[2] / magBC };

	float producto = vecNormAB[0] * vecNormBC[0] + vecNormAB[1] * vecNormBC[1] + vecNormAB[2] * vecNormBC[2];
	float angulo = cos(producto) * 180.0f / (PI);

	cout << "Angulo: ";

	return 0.0f;
}



BodyParts FullBody::translateNumber(int number) {
	switch (number) {
	case HipCenter:
		return HipCenter;
		break;
	case Spine:
		return Spine;
	case ShoulderCenter:
		return ShoulderCenter;
	case Head:
		return Head;
	case ShoulderLeft:
		return ShoulderLeft;
	case ElbowLeft:
		return ElbowLeft;
	case WristLeft:
		return WristLeft;
	case HandLeft:
		return HandLeft;
	case ShoulderRight:
		return ShoulderRight;
	case ElbowRight:
		return ElbowRight;
	case WristRight:
		return WristRight;
	case HandRight:
		return HandRight;
	case HipLeft:
		return HipLeft;
	case KneeLeft:
		return KneeLeft;
	case AnkleLeft:
		return AnkleLeft;
	case FootLeft:
		return FootLeft;
	case HipRight:
		return HipRight;
	case KneeRight:
		return KneeRight;
	case AnkleRight:
		return AnkleRight;
	case FootRight:
		return FootRight;
	}
}

