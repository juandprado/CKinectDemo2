#pragma once
#include "BodyPoint.h"
#include "FullBody.h"


/**
* @brief this class represent the movement executed by the pacient , and his functions to calculate it 
*/
class Movement
{
public:
	/**
	* @brief constructor of the class
	*/
	Movement();

	/**
	* @brief constructor of the class
	* @param myBody body to calculate to get the positions of the joints 
	* @param name of the body 
	* @param initialAngle angle initial of the movement
	* @param finalAngle angle final of the movement 
	* @param joinOne joint to set the point one of the vector one 
	* @paramn jointCenter joint vertex of the angle, point of intersection
	* @param jointTwo joint to set the point two of the vector two
	*/
	Movement(FullBody* myBody, string name, float initialAngle, float finalAngle, BodyParts joinOne, BodyParts joinCenter, BodyParts joinTwo);
	
	/**
	* @brief Destructor of the class 
	*/
	~Movement();

	/**
	* @brief the function calculate the angle of the joints 
	* @param joinOne joint to set the point one of the vector one 
	* @paramn jointCenter joint vertex of the angle, point of intersection
	* @param jointTwo joint to set the point two of the vector two
	* @return angle 
	*/
	float getAngleJoints(BodyParts pointOne, BodyParts pointCenter, BodyParts pointTwo);
	void calPercentMov();
	void initMov();
	bool finishMov();


private:
	// name of the movement
	string name;
	// angle initial of the movement
	float initialAngle;
	// angle final of the movement
	float finalAngle;
	//Body to get the position of the joints 
	FullBody* myBody;

	// joint to set the point one of the vector one 
	BodyParts jointOne;

	// joint vertex of the angle, point of intersection
	BodyParts jointCenter;

	//joint to set the point two of the vector two
	BodyParts jointTwo;

	// angle of movement 
	float deltaAngle;

	// percent of the max movement
	float percentaje;

	// bool to indicate if the movement start
	bool initial;

};

