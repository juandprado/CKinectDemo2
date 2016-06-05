#pragma once
#include <iostream>
#include <windows.h>
#include <Ole2.h>
#include <NuiApi.h>
#include "BodyPoint.h"
using namespace std;

class FullBody
{
public:
	FullBody();
	~FullBody();
	void Update();
	BodyPointPosition returnPosition(BodyParts nameBodyPoint);
private:
	BodyPoint bodyPointsCollection[NUI_SKELETON_POSITION_COUNT];
	INuiSensor* m_pNuiSensor;
	BSTR m_instanceId;
	HANDLE m_hNextSkeletonEvent;
	HRESULT Start();
	
	HRESULT	FindKinectSensor();
	void SkeletonFrameReady(NUI_SKELETON_FRAME* pSkeletonFrame);
	int counter;

	BodyParts translateNumber(int number);
	NUI_SKELETON_DATA currentBody;
	void updateBodyPoints(NUI_SKELETON_DATA & skeleton);
};

