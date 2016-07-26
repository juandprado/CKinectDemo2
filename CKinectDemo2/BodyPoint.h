#pragma once
#include <iostream>
#include <windows.h>
#include <Ole2.h>
#include <NuiApi.h>
using namespace std;

// Struct to identify the joints of the body
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


// Struct to manage basic operations of the joints 
struct BodyPointPosition
{
	BodyParts name;

	// position with  cartesians coodinates
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

/**
* this class stoore the name of the joint and the current position
*/
class BodyPoint
{
public:
	/**
	* @brief Constructor of the class
	*/
	BodyPoint();
	
	/**
	* @brief Constructor of the class
	* @param point struct with the name, and position of the joint 
	*/
	BodyPoint(BodyParts point);

	/**
	* @brief Destructor of the class
	*/
	~BodyPoint();


	BodyParts pointRepresented;

	/**
	* @brief Set the position of the joint 
	* @param name, and cordinates of the joint 
	*/
	void setPosition(BodyPointPosition position);

	/**
	* @brief return the current position of the joint 
	*/
	BodyPointPosition getCurrentPosition();

private:
	BodyPointPosition currentPosition;
};

