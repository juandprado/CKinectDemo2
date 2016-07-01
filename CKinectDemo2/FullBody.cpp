#include "FullBody.h"



FullBody::FullBody()
{


}


FullBody::FullBody(int sensor)
{

	

	switch (sensor)
	{
	case 1:
		sensorOneKinect = KinectOneAdapter();
		break;
	default:
		break;
	}

}

FullBody::~FullBody()
{
}

BodyPointPosition FullBody::returnPosition(BodyParts nameBodyPoint)
{
	return BodyPointPosition();
}
