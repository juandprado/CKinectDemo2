#pragma once
#include <iostream>
#include <windows.h>
#include <Ole2.h>
#include <NuiApi.h>

#include <cstdlib>
#include <string>
#include <mutex>
#include <condition_variable>
#include "BodyPoint.h"
using namespace std;

class KinectOneAdapter
{

public:
	KinectOneAdapter();
	~KinectOneAdapter();
	void Update();
	float* returnPosition(BodyParts part);
	void setBodyPoints(BodyPoint** points);
	void Start();
	void Stop();

private:
	INuiSensor* m_pNuiSensor;
	BSTR m_instanceId;
	HANDLE m_hNextSkeletonEvent;
	HRESULT HStart();

	

	HRESULT	FindKinectSensor();
	void SkeletonFrameReady(NUI_SKELETON_FRAME* pSkeletonFrame);
	int counter;

	NUI_SKELETON_DATA currentBody;

	// Current position of the point
	BodyPointPosition currentPosition;

	// Point represented to a particular point 
	BodyParts pointRepresented;

	// Function to return the current position of the body point 
	void updateBodyPoints(NUI_SKELETON_DATA & skeleton);

	BodyPointPosition updatePosition(NUI_SKELETON_DATA & skeleton, int jointIndex);


	BodyPoint** bodyPointsCollection;


	/**
	 * Function to return a body part with the kinect's library
	 * @param part part of the body according to enum of the kinect's library
	 **/
	_NUI_SKELETON_POSITION_INDEX mapPoint(BodyParts part);

};