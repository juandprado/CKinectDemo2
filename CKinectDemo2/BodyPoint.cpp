#include "BodyPoint.h"

BodyPoint::BodyPoint() {

}

BodyPoint::BodyPoint(BodyParts point)
{
	pointRepresented = point;
	//cout << "Point inicial " << pointRepresented << endl;
	//cout << "Inicia joint " << point << endl;
	currentPosition.name = point;
	currentPosition.x = 0.0f;
	currentPosition.y = 0.0f;
	currentPosition.z = 0.0f;
	cout << "Termina joint " << point << endl;
}


BodyPoint::~BodyPoint()
{
}

void BodyPoint::setPosition(BodyPointPosition position)
{
	currentPosition.name = position.name;
	currentPosition.x = position.x;
	currentPosition.y = position.y;
	currentPosition.z = position.z;
}

BodyPointPosition BodyPoint::getCurrentPosition() {
	//cout << "Point represented " << pointRepresented << endl;
	return currentPosition;
}


