#include <iostream>
#include <stdlib.h>
using namespace std;

void stop_all() {
	system("pkill screen");

	cout << "\n";
	cout << "All vm's was stoped.\n\n";
}
