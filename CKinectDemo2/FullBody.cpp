#include "FullBody.h"



FullBody::FullBody()
{
	for (int i = 0; i < NUI_SKELETON_POSITION_COUNT; i++) {
		bodyPointsCollection[i] = BodyPoint(translateNumber(i));
	}
	counter = NULL;
	Start();
}


FullBody::~FullBody()
{
}

BodyParts FullBody::translateNumber(int number) {
	switch (number) {
	case HipCenter:
		return HipCenter;
	case Spine:
		return Spine;
	case ShoulderCenter:
		return ShoulderCenter;
	case Head:
		return Head;
	case ShoulderLeft:
		return ShoulderLeft;
	case ElbowLeft:
		return ElbowLeft;
	case WristLeft:
		return WristLeft;
	case HandLeft:
		return HandLeft;
	case ShoulderRight:
		return ShoulderRight;
	case ElbowRight:
		return ElbowRight;
	case WristRight:
		return WristRight;
	case HandRight:
		return HandRight;
	case HipLeft:
		return HipLeft;
	case KneeLeft:
		return KneeLeft;
	case AnkleLeft:
		return AnkleLeft;
	case FootLeft:
		return FootLeft;
	case HipRight:
		return HipRight;
	case KneeRight:
		return KneeRight;
	case AnkleRight:
		return AnkleRight;
	case FootRight:
		return FootRight;
	}
}

// Call Start once at application start.
HRESULT FullBody::Start()
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
void FullBody::Update()
{
	// Wait for 0ms, just quickly test if it is time to process a skeleton
	if (WAIT_OBJECT_0 == WaitForSingleObject(m_hNextSkeletonEvent, 0))
	{
		NUI_SKELETON_FRAME skeletonFrame = { 0 };

		// Get the skeleton frame that is ready
		if (SUCCEEDED(m_pNuiSensor->NuiSkeletonGetNextFrame(0, &skeletonFrame)))
		{
			// Process the skeleton frame
			SkeletonFrameReady(&skeletonFrame);
		}
	}
}

HRESULT	FullBody::FindKinectSensor()
{
	return NuiCreateSensorByIndex(0, &m_pNuiSensor);
}

void FullBody::SkeletonFrameReady(NUI_SKELETON_FRAME* pSkeletonFrame)
{
	for (int i = 0; i < NUI_SKELETON_COUNT; i++)
	{
		const NUI_SKELETON_DATA & skeleton = pSkeletonFrame->SkeletonData[i];

		switch (skeleton.eTrackingState)
		{
		case NUI_SKELETON_TRACKED:
			cout << "New Tracked Frame" << endl;
			currentBody = skeleton;
			updateBodyPoints(currentBody);
			break;

		case NUI_SKELETON_POSITION_ONLY:
			cout << skeleton.Position.y << endl;
			break;
		}

	}
}

void FullBody::updateBodyPoints(NUI_SKELETON_DATA & skeleton) {
	int pointsDifferent = 0;
	for (int i = 0; i < NUI_SKELETON_POSITION_COUNT; i++) {
		try
		{
			BodyPointPosition last = bodyPointsCollection[i].getCurrentPosition();
			cout << "Llega 3" << endl;
			BodyPointPosition current = bodyPointsCollection[i].updatePosition(currentBody);
			if (current != last) {
				pointsDifferent++;
			}
		}
		catch (exception e) {
			cout << "Excepcion en updateBodyPoints: " << e.what() << endl;
		}
	}
	cout << "Puntos diferentes: " << pointsDifferent << endl;
}

BodyPointPosition FullBody::returnPosition(BodyParts nameBodyPoint) {
	try {
		BodyPoint pointTrack = bodyPointsCollection[nameBodyPoint];
		return pointTrack.getCurrentPosition();
	}
	catch (exception e) {
		cout << e.what() << endl;
		BodyPointPosition a;
		a.name = Default;
		a.x = 0.0f;
		a.y = 0.0f;
		a.z = 0.0f;
		return a;
	}
}