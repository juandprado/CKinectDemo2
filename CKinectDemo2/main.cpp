#include <iostream>
#include <windows.h>
#include <Ole2.h>
#include <NuiApi.h>
#include "FullBody.h"
#include "BodyPoint.h"
using namespace std;


int main() {
	FullBody f = FullBody(1);

	while (true) {
		f.dataKinect();
		//float angle = f.getAngleJoints(HipLeft, ShoulderLeft, ElbowLeft);
		//cout << "Position " << angle << endl;
	}
	system("pause");
	cout << "final" << endl;
	return 0;
}