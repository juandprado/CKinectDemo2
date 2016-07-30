#pragma once
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
	Movement(FullBody* myBody, string name, float initialAngle, float finalAngle, BodyPointPosition pointOne, BodyPointPosition positionCenter, BodyPointPosition positionTwo);
	
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
	float getAngleJoints(BodyPointPosition pointOne, BodyPointPosition pointCenter, BodyPointPosition pointTwo);
	void calPercentMov();
	void initMov();
	bool finishMov();


	/**
	* @brief the function calculate the angle with the points by default
	*/
	float getAngleMov();


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
	BodyPointPosition pointOne;

	// joint vertex of the angle, point of intersection
	BodyPointPosition pointCenter;

	//joint to set the point two of the vector two
	BodyPointPosition pointTwo;

	// angle of movement 
	float deltaAngle;

	// percent of the max movement
	float percentaje;

	// bool to indicate if the movement start
	bool initial;

};

