#include "FullBody.h"
#include <thread>
#include <iostream>
using namespace std;



FullBody::FullBody()
{


}

void FullBody::dataKinect()
{
	cout << "Entra a datakinect" << endl;
	while (true) {
		sensorOneKinect->Update();
		cout << "Position " << bodyPointsCollection[0][0].getCurrentPosition().x << bodyPointsCollection[0][0].getCurrentPosition().y  << bodyPointsCollection[0][0].getCurrentPosition().z << endl;
	}
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

