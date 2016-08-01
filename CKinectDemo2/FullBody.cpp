#include "FullBody.h"
#include "MovementsCollection.h"
#include <thread>
#include <iostream>
using namespace std;



FullBody::FullBody()
{


}

void FullBody::dataKinect()
{
	// This function is make for test 

	int movs = 0;
	//cout << "Datakinect" << endl;
	MovementsCollection collect(this);
	Movement* collection = collect.collection;
	BodyPointPosition position;
	while (true) {
		sensorOneKinect->Update();
		position = bodyPointsCollection[1]->getCurrentPosition();
			//cout << "posicion z" << position.z << endl;
			cout << "posicion y" << position.y << endl;
			//cout << "posicion x" << position.x << endl;
			int  x;
			cin >> x;

			if (x==0) {
				collect.shoulderRigthMovements();
				Movement headMov = collection[3];
				cout << "angulo" << headMov.getAngleMov() << endl;
			}
		
	}
	
}

FullBody::FullBody(int sensor)
{
	// Initialize the set of BodyPoints 
	for (int i = 0; i < 21; i++) {
		bodyPointsCollection[i] = new BodyPoint(translateNumber(i));
		bodyPointsCollection[i]->getCurrentPosition();
	}	

	bodyPointsCollection[14]->getCurrentPosition();

	KinectOneAdapter hola;
	sensorOneKinect = &hola;
	sensorOneKinect->setBodyPoints(bodyPointsCollection);
	dataKinect();

}



FullBody::~FullBody()
{

}

BodyPointPosition FullBody::returnPosition(BodyParts joint)
{
	const int num = joint;
	//cout << "Numerojoint " << joint << "num: " << num << endl;
	BodyPointPosition position = bodyPointsCollection[num]->getCurrentPosition();
	//cout << "Position returnposition: " << endl;
	//cout << position.x << ", " << position.y << ", " << position.z << endl;
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

