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
		BodyPointPosition p = f.returnPosition(Head);
		cout << "Position " << p.x << p.y << p.z << endl;
	}
	system("pause");
	cout << "final" << endl;
	return 0;
}