#pragma once
#include <iostream>
#include <windows.h>
#include <Ole2.h>
#include <NuiApi.h>
#include "BodyPoint.h"
using namespace std;


/**
  * @brief This class is an adapter to communicate the library with the sensor kinect v 1.0
  */

class KinectOneAdapter
{

public:
	/**
	  *@brief Constructor of the class, verify that the kinect is connected 
	  */
	KinectOneAdapter();

	/**
	* @brief Destructor of the class
	*/
	~KinectOneAdapter();

	/**
	* @brief Function to update the position of the body points joints 
	*/
	void Update();

	/**
	  * @brief Function to return the position of the body part joint (array x, y, z)
	  * @param part specified to return the position
	  */
	float* returnPosition(BodyParts part);

	/**
	  * @brief initialize the set of the body points 
	  * @param set of body points 
	  */
	void setBodyPoints(BodyPoint** points);

private:

	// References multiple Kinect sensors. If you are using only one Kinect sensor, use the functions in NUI Functions instead of implementing this interface
	INuiSensor* m_pNuiSensor;

	// PENDIENTE POR BORRAR 
	BSTR m_instanceId;

	// Variable to manage
	HANDLE m_hNextSkeletonEvent;

	/**
	* @brief function to start to  steam the data of the kinect 
	*/
	HRESULT Start();

	HRESULT	FindKinectSensor();
	void SkeletonFrameReady(NUI_SKELETON_FRAME* pSkeletonFrame);
	int counter;

	NUI_SKELETON_DATA currentBody;

	// Current position of the point
	BodyPointPosition currentPosition;

	// Point represented to a particular point 
	BodyParts pointRepresented;

	/**
	* @brief Function to update the current position of the body point 
	*/
	void updateBodyPoints(NUI_SKELETON_DATA & skeleton);

	BodyPointPosition updatePosition(NUI_SKELETON_DATA & skeleton, int jointIndex);


	BodyPoint** bodyPointsCollection;


	/**
	 * Function to return a body part with the kinect's library
	 * @param part part of the body according to enum of the kinect's library
	 **/
	_NUI_SKELETON_POSITION_INDEX mapPoint(BodyParts part);

};