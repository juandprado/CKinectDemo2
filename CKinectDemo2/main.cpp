#include <iostream>
#include <windows.h>
#include <Ole2.h>
#include <NuiApi.h>
#include "FullBody.h"
using namespace std;


int main() {
	FullBody f = FullBody();
	while (true) {
		f.Update();
	}
	system("pause");
	return 0;
}