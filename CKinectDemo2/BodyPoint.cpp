#include "BodyPoint.h"

BodyPoint::BodyPoint() {

}

BodyPoint::BodyPoint(BodyParts point)
{
	pointRepresented = point;
	cout << "Inicia joint " << point << endl;
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
	currentPosition = position;
}

BodyPointPosition BodyPoint::getCurrentPosition() {
	return currentPosition;
}


