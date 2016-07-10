#include "KinectOneAdapater.h"
#include <thread>
using namespace std;


KinectOneAdapter::KinectOneAdapter()
{
	counter = NULL;
	HRESULT connect = Start();
	if (connect!=S_OK) {
		cout << "Kinect not connected" << endl;
	}
}


KinectOneAdapter::~KinectOneAdapter()
{
}

HRESULT KinectOneAdapter::Start()
{
	m_hNextSkeletonEvent = NULL;

	// Initialize m_pNuiSensor
	HRESULT hr = FindKinectSensor();

	if (SUCCEEDED(hr))
	{
		// Initialize the Kinect and specify that we'll be using skeleton
		hr = m_pNuiSensor->NuiInitialize(NUI_INITIALIZE_FLAG_USES_SKELETON);
		if (SUCCEEDED(hr))
		{
			// Create an event that will be signaled when skeleton data is available
			m_hNextSkeletonEvent = CreateEventW(NULL, TRUE, FALSE, NULL);

			// Open a skeleton stream to receive skeleton data
			hr = m_pNuiSensor->NuiSkeletonTrackingEnable(m_hNextSkeletonEvent, 0);
		}
	}

	return hr;
}


// Call UpdateKinectST on each iteration of the application's update loop.
void KinectOneAdapter::Update()
{

	//cout << "def up" << endl;
		// Wait for 0ms, just quickly test if it is time to process a skeleton
		if (WAIT_OBJECT_0 == WaitForSingleObject(m_hNextSkeletonEvent, 0))
		{
			//cout << "def up2" << endl;

			NUI_SKELETON_FRAME skeletonFrame = { 0 };

			// Get the skeleton frame that is ready
			if (SUCCEEDED(m_pNuiSensor->NuiSkeletonGetNextFrame(0, &skeletonFrame)))
			{
				// Process the skeleton frame
				SkeletonFrameReady(&skeletonFrame);
			}
		}
		else {
			//cout << WaitForSingleObject(m_hNextSkeletonEvent, 0) << endl;
		}

}



void KinectOneAdapter::updateBodyPoints(NUI_SKELETON_DATA & skeleton) {

	int pointsDifferent = 0;
	for (int i = 0; i < NUI_SKELETON_POSITION_COUNT; i++) {
		try
		{
			BodyPointPosition current = updatePosition(skeleton, i);
			//cout << "Trin 1" << endl;
			bodyPointsCollection[i]->setPosition(current);
			//cout << "Trin 2" << endl;
		}
		catch (exception e) {
			cout << "Excepcion en updateBodyPoints: " << e.what() << endl;
		}
	}
}



HRESULT	KinectOneAdapter::FindKinectSensor()
{
	return NuiCreateSensorByIndex(0, &m_pNuiSensor);
}

void KinectOneAdapter::SkeletonFrameReady(NUI_SKELETON_FRAME* pSkeletonFrame)
{
	for (int i = 0; i < NUI_SKELETON_COUNT; i++)
	{
		const NUI_SKELETON_DATA & skeleton = pSkeletonFrame->SkeletonData[i];

		switch (skeleton.eTrackingState)
		{
		case NUI_SKELETON_TRACKED:
			//cout << "New Tracked Frame" << endl;
			currentBody = skeleton;
			updateBodyPoints(currentBody);
			break;

		case NUI_SKELETON_POSITION_ONLY:
			cout << skeleton.Position.y << endl;
			break;
		}

	}
}

BodyPointPosition KinectOneAdapter::updatePosition(NUI_SKELETON_DATA & skeleton, int jointIndex)
{
	currentPosition.x = skeleton.SkeletonPositions[jointIndex].x;
	currentPosition.y = skeleton.SkeletonPositions[jointIndex].y;
	currentPosition.z = skeleton.SkeletonPositions[jointIndex].z;
	return currentPosition;

}


void KinectOneAdapter::setBodyPoints(BodyPoint** points)
{
	bodyPointsCollection = points;
}

_NUI_SKELETON_POSITION_INDEX KinectOneAdapter::mapPoint(BodyParts part) {
	switch (part) {
	case HipCenter:
		return NUI_SKELETON_POSITION_HIP_CENTER;
	case Spine:
		return NUI_SKELETON_POSITION_SPINE;
	case ShoulderCenter:
		return NUI_SKELETON_POSITION_SHOULDER_CENTER;
	case Head:
		return NUI_SKELETON_POSITION_HEAD;
	case ShoulderLeft:
		return NUI_SKELETON_POSITION_SHOULDER_LEFT;
	case ElbowLeft:
		return NUI_SKELETON_POSITION_ELBOW_LEFT;
	case WristLeft:
		return NUI_SKELETON_POSITION_WRIST_LEFT;
	case HandLeft:
		return NUI_SKELETON_POSITION_HAND_LEFT;
	case ShoulderRight:
		return NUI_SKELETON_POSITION_SHOULDER_RIGHT;
	case ElbowRight:
		return NUI_SKELETON_POSITION_ELBOW_RIGHT;
	case WristRight:
		return NUI_SKELETON_POSITION_WRIST_RIGHT;
	case HandRight:
		return NUI_SKELETON_POSITION_HAND_RIGHT;
	case HipLeft:
		return NUI_SKELETON_POSITION_HIP_LEFT;
	case KneeLeft:
		return NUI_SKELETON_POSITION_KNEE_LEFT;
	case AnkleLeft:
		return NUI_SKELETON_POSITION_ANKLE_LEFT;
	case FootLeft:
		return NUI_SKELETON_POSITION_FOOT_LEFT;
	case HipRight:
		return NUI_SKELETON_POSITION_HIP_RIGHT;
	case KneeRight:
		return NUI_SKELETON_POSITION_KNEE_RIGHT;
	case AnkleRight:
		return NUI_SKELETON_POSITION_ANKLE_RIGHT;
	case FootRight:
		return NUI_SKELETON_POSITION_FOOT_RIGHT;
	}
}



