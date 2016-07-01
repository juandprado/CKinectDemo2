#pragma once
#include <iostream>
#include <windows.h>
#include <Ole2.h>
#include <NuiApi.h>
#include "BodyPoint.h"
using namespace std;

class KinectOneAdapter
{

public:
	KinectOneAdapter();
	~KinectOneAdapter();
	void Update();
private:
	INuiSensor* m_pNuiSensor;
	BSTR m_instanceId;
	HANDLE m_hNextSkeletonEvent;
	HRESULT Start();
	float* returnPosition(BodyParts part);

	HRESULT	FindKinectSensor();
	void SkeletonFrameReady(NUI_SKELETON_FRAME* pSkeletonFrame);
	int counter;

	NUI_SKELETON_DATA currentBody;
	void updateBodyPoints(NUI_SKELETON_DATA & skeleton);

	_NUI_SKELETON_POSITION_INDEX mapPoint(BodyParts part)

};