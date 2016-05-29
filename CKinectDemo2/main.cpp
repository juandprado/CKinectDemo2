#include "main.h"

KinectPrueba::KinectPrueba() {
	a = 0;
	Start();
}

KinectPrueba::~KinectPrueba() {

}

// Call Start once at application start.
HRESULT KinectPrueba::Start()
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
void KinectPrueba::Update()
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

HRESULT	KinectPrueba::FindKinectSensor()
{
	return NuiCreateSensorByIndex(0, &m_pNuiSensor);
}

void KinectPrueba::SkeletonFrameReady(NUI_SKELETON_FRAME* pSkeletonFrame)
{
	for (int i = 0; i < NUI_SKELETON_COUNT; i++)
	{
		const NUI_SKELETON_DATA & skeleton = pSkeletonFrame->SkeletonData[i];

		switch (skeleton.eTrackingState)
		{
		case NUI_SKELETON_TRACKED:
			cout << "Posicion codo" << endl;
			cout << skeleton.SkeletonPositions[NUI_SKELETON_POSITION_ELBOW_RIGHT].y << endl;
			break;

		case NUI_SKELETON_POSITION_ONLY:
			cout << skeleton.Position.y << endl;
			break;
		}

	}
}


int main() {
	KinectPrueba k = KinectPrueba();
	while (true) {
		k.Update();
	}
	system("pause");
	return 0;
}