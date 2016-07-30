#pragma once
#include "FullBody.h"
#include "Movement.h"

class MovementsCollection
{
public:

	/**
	* @brief Constructor to create the select movements, agree to its initial angles 
	*/
	MovementsCollection(FullBody* myBody);

	/**
	* @brief  Destructor of the class
	*/
	~MovementsCollection();


	// Array to each movement
	Movement collection[20];

private:


	//Body to get the position of the joints 
	FullBody* myBody;

	/**
	* @brief initiate the angles for the head movement
	*/
	void headMovements();
	void shoulderRigthMovements();
	void elbowMovements();
	void wristMovements();
	void hipMovements();
	void kneeMovements();
	void spineMovements();
};

