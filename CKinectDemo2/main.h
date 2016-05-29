#include <iostream>
#include <windows.h>
#include <Ole2.h>
#include <NuiApi.h>
using namespace std;

class KinectPrueba {
public:
	KinectPrueba();
	~KinectPrueba();

	INuiSensor*            m_pNuiSensor;
	BSTR                    m_instanceId;
	HANDLE					m_hNextSkeletonEvent;
	HRESULT Start();
	void Update();
	HRESULT	FindKinectSensor();
	void SkeletonFrameReady(NUI_SKELETON_FRAME* pSkeletonFrame);
	int a;
};