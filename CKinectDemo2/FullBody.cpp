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
			Movement mov;
			switch (x) {
			case 0:
				collect.headMovements();
				mov = collection[0];
				cout << "Angulo" << mov.getAngleMov() << endl;
				break;
			case 1:
				collect.headMovements();
				mov = collection[1];
				cout << "Angulo" << mov.getAngleMov() << endl;
				break;
			case 2:
				collect.headMovements();
				mov = collection[2];
				cout << "Angulo " << mov.getAngleMov() << endl;
				break;
			case 3:
				collect.shoulderRigthMovements();
				mov = collection[3];
				cout << "Angulo " << mov.getAngleMov() << endl;
				break;
			case 4:
				collect.shoulderRigthMovements();
				mov = collection[4];
				cout << "Angulo " << mov.getAngleMov() << endl;
				break;
			case 5:
				collect.shoulderRigthMovements();
				mov = collection[5];
				cout << "Angulo " << mov.getAngleMov() << endl;
				break;
			case 6:
				collect.shoulderRigthMovements();
				mov = collection[6];
				cout << "Angulo " << mov.getAngleMov() << endl;
				break;
			case 7:
				collect.shoulderRigthMovements();
				mov = collection[7];
				cout << "Angulo " << mov.getAngleMov() << endl;
				break;
			case 8:
				collect.elbowMovements();
				mov = collection[8];
				cout << "Angulo " << mov.getAngleMov() << endl;
				break;
			case 9:
				collect.wristMovements();
				mov = collection[9];
				cout << "Angulo " << mov.getAngleMov() << endl;
				break;
			case 10:
				collect.wristMovements();
				mov = collection[10];
				cout << "Angulo " << mov.getAngleMov() << endl;
				break;
			case 11:
				collect.hipMovements();
				mov = collection[11];
				cout << "Angulo " << mov.getAngleMov() << endl;
				break;
			case 12:
				collect.hipMovements();
				mov = collection[12];
				cout << "Angulo " << mov.getAngleMov() << endl;
				break;
			case 13:
				collect.hipMovements();
				mov = collection[13];
				cout << "Angulo " << mov.getAngleMov() << endl;
				break;
			case 14:
				collect.hipMovements();
				mov = collection[14];
				cout << "Angulo " << mov.getAngleMov() << endl;
				break;
			case 15:
				collect.hipMovements();
				mov = collection[15];
				cout << "Angulo " << mov.getAngleMov() << endl;
				break;
			case 16:
				collect.hipMovements();
				mov = collection[16];
				cout << "Angulo " << mov.getAngleMov() << endl;
				break;
			case 17:
				collect.kneeMovements();
				mov = collection[17];
				cout << "Angulo " << mov.getAngleMov() << endl;
				break;
			case 18:
				collect.spineMovements();
				mov = collection[18];
				cout << "Angulo " << mov.getAngleMov() << endl;
				break;
			case 19:
				collect.spineMovements();
				mov = collection[19];
				cout << "Angulo " << mov.getAngleMov() << endl;
				break;
			default:
				cout << "No movimientos " << endl;
				break;

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

