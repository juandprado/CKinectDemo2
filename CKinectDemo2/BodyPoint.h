#pragma once
#include <iostream>
#include <windows.h>
#include <Ole2.h>
#include <NuiApi.h>
using namespace std;

#ifndef _BODY_PARTS_
#define _BODY_PARTS_
typedef
enum BodyParts
{
	HipCenter,
	Spine,
	ShoulderCenter,
	Head,
	ShoulderLeft,
	ElbowLeft,
	WristLeft,
	HandLeft,
	ShoulderRight,
	ElbowRight,
	WristRight,
	HandRight,
	HipLeft,
	KneeLeft,
	AnkleLeft,
	FootLeft,
	HipRight,
	KneeRight,
	AnkleRight,
	FootRight,
	Default
};

struct BodyPointPosition
{
	BodyParts name;
	float x;
	float y;
	float z;


	bool operator==(const BodyPointPosition& rhs) const
	{
		return (x == rhs.x && y == rhs.y) && (z == rhs.z && name == rhs.name);
	}

	bool operator!=(const BodyPointPosition& lhs)
	{
		return !((lhs.x == x && lhs.y == y) && (lhs.z == z && lhs.name == name));
	}
};



#endif _BODY_PARTS_

class BodyPoint
{
public:
	BodyPoint();
	BodyPoint(BodyParts point);
	~BodyPoint();
	BodyParts pointRepresented;
	void setPosition(BodyPointPosition position);
	BodyPointPosition getCurrentPosition();

private:
	BodyPointPosition currentPosition;
};

