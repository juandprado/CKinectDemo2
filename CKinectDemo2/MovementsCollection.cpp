#include "MovementsCollection.h"



MovementsCollection::MovementsCollection(FullBody* myBody)
{
	this->myBody = myBody;
	headMovements();
	shoulderRigthMovements();
	elbowMovements();
	wristMovements();
	hipMovements();
	kneeMovements();
	spineMovements();
}


MovementsCollection::~MovementsCollection()
{
}

void MovementsCollection::headMovements()
{

	// lateral flexion
	BodyPointPosition  pointOne = myBody->returnPosition(Spine);
	BodyPointPosition pointCenter = myBody->returnPosition(ShoulderCenter);
	BodyPointPosition pointTwo = myBody->returnPosition(Head);
	Movement headMovementFlex = Movement(myBody, "head_lateral_flexion", 0.0, 180.0, pointOne, pointCenter, pointTwo);
	collection[0] = headMovementFlex;


	//  frontal extension 

	pointOne = myBody->returnPosition(Spine);
	pointCenter = myBody->returnPosition(ShoulderCenter);
	pointTwo = myBody->returnPosition(Head);
	headMovementFlex = Movement(myBody, "head_flexion", 0.0, 60.0, pointOne, pointCenter, pointTwo);
	collection[1] = headMovementFlex;


	//frontal flexion
	headMovementFlex = Movement(myBody, "head_extension", 0.0, 70.0, pointOne, pointCenter, pointTwo);
	collection[2] = headMovementFlex;
}

void MovementsCollection::shoulderRigthMovements()
{

	// Abduccion 
	
	BodyPointPosition pointCenter = myBody->returnPosition(ShoulderRight);
	BodyPointPosition pointTwo = myBody->returnPosition(ElbowRight);
	BodyPointPosition pointOne = pointCenter;
	pointOne.y = pointOne.y - 0.2f;

	Movement headMovementFlex = Movement(myBody, "shoulder_abduccion", 0.0, 180.0, pointOne, pointCenter, pointTwo);
	collection[3] = headMovementFlex;


	//Flexion --same points 

	headMovementFlex = Movement(myBody, "shoulder_flexion", 0.0f, 180.0f, pointOne, pointCenter, pointTwo);
	collection[4] = headMovementFlex;



	// Extension -- same points 

	headMovementFlex = Movement(myBody, "shoulder_extension", 0.0f, 40.0f, pointOne, pointCenter, pointTwo);
	collection[5] = headMovementFlex;


	//Internal Rotation

	pointCenter = myBody->returnPosition(ElbowRight);
	pointTwo = myBody->returnPosition(WristRight);
	pointOne = pointCenter;
	pointOne.z = pointCenter.z - 0.2f;

    headMovementFlex = Movement(myBody, "shoulder_internal_rotation", 0.0f, 80.0f, pointOne, pointCenter, pointTwo);
	collection[6] = headMovementFlex;


	//External Rotation -- same points 

	headMovementFlex = Movement(myBody, "shoulder_external_rotation", 0.0f, 90.0f, pointOne, pointCenter, pointTwo);
	collection[7] = headMovementFlex;



}

void MovementsCollection::elbowMovements()
{
	// Flexion

	BodyPointPosition pointCenter = myBody->returnPosition(ElbowRight);
	BodyPointPosition pointTwo = myBody->returnPosition(WristRight);
	BodyPointPosition pointOne = myBody->returnPosition(ShoulderRight);

	Movement elbowMovementFlex = Movement(myBody, "elbow_flexion", 0.0, 180.0, pointOne, pointCenter, pointTwo);
	collection[8] = elbowMovementFlex;


}

void MovementsCollection::wristMovements()
{

	// Flexion 
	BodyPointPosition pointOne = myBody->returnPosition(ElbowRight);
	BodyPointPosition pointCenter = myBody->returnPosition(WristRight);
	BodyPointPosition pointTwo = myBody->returnPosition(HandRight);

	Movement elbowMovementFlex = Movement(myBody, "wrist_flexion", 0.0, 60.0, pointOne, pointCenter, pointTwo);
	collection[9] = elbowMovementFlex;

	//Extension -- same points

	elbowMovementFlex = Movement(myBody, "wrist_extension", 0.0, 60.0, pointOne, pointCenter, pointTwo);
	collection[10] = elbowMovementFlex;


}

void MovementsCollection::hipMovements()
{

	// Abduccion
	BodyPointPosition pointOne = myBody->returnPosition(HipLeft);
	BodyPointPosition pointCenter = myBody->returnPosition(HipRight);
	BodyPointPosition pointTwo = myBody->returnPosition(KneeRight);

	Movement elbowMovementFlex = Movement(myBody, "hip_abduccion", 0.0, 40.0, pointOne, pointCenter, pointTwo);
	collection[11] = elbowMovementFlex;


	// Aduccion -- same points

	elbowMovementFlex = Movement(myBody, "hip_aduccion", 0.0, 20.0, pointOne, pointCenter, pointTwo);
	collection[12] = elbowMovementFlex;


	// Flexion
	pointCenter = myBody->returnPosition(HipRight);
	pointTwo = myBody->returnPosition(KneeRight);
	pointOne = pointCenter;
	pointOne.y = pointOne.y + 0.2f;


	elbowMovementFlex = Movement(myBody, "hip_extension", 0.0, 100.0, pointOne, pointCenter, pointTwo);
	collection[13] = elbowMovementFlex;

	//Extension -- same points 

	elbowMovementFlex = Movement(myBody, "hip_flexion", 0.0, 30.0, pointOne, pointCenter, pointTwo);
	collection[14] = elbowMovementFlex;


	// Internal rotation

	pointCenter = myBody->returnPosition(KneeRight);
	pointTwo = myBody->returnPosition(AnkleRight);
	pointOne = pointCenter;
	pointOne.y = pointOne.y - 0.2f;

	elbowMovementFlex = Movement(myBody, "hip_internal_rotation", 0.0, 40.0, pointOne, pointCenter, pointTwo);
	collection[15] = elbowMovementFlex;

	//External rotation -- same points 

	elbowMovementFlex = Movement(myBody, "hip_external_rotation", 0.0, 50.0, pointOne, pointCenter, pointTwo);
	collection[16] = elbowMovementFlex;



}

void MovementsCollection::kneeMovements()
{

	//Flexion
	BodyPointPosition pointOne = myBody->returnPosition(HipRight);
	BodyPointPosition pointCenter = myBody->returnPosition(KneeRight);
	BodyPointPosition pointTwo = myBody->returnPosition(AnkleRight);

	Movement elbowMovementFlex = Movement(myBody, "knee_flexion", 0.0, 150.0, pointOne, pointCenter, pointTwo);
	collection[17] = elbowMovementFlex;

}

void MovementsCollection::spineMovements()
{
	// lateral flexion

	BodyPointPosition pointCenter = myBody->returnPosition(HipCenter);
	BodyPointPosition pointTwo = myBody->returnPosition(Spine);

	BodyPointPosition pointOne = pointCenter;
	pointOne.y = pointOne.x + 0.2f;

	Movement elbowMovementFlex = Movement(myBody, "spine_lateral_flexion", 0.0, 150.0, pointOne, pointCenter, pointTwo);
	collection[18] = elbowMovementFlex;

	// inclinacion

	pointCenter = myBody->returnPosition(HipCenter);
	pointTwo = myBody->returnPosition(Spine);

	pointOne = pointCenter;
	pointOne.y = pointOne.y - 0.2f;

	elbowMovementFlex = Movement(myBody, "spine_inclination", 0.0, 150.0, pointOne, pointCenter, pointTwo);
	collection[19] = elbowMovementFlex;






}




