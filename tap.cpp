#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

int main() {
	int t = 100;

	ofstream tapr("/usr/local/etc/bsi/tap.conf");
	tapr << t;
	tapr.close();

	return 0;
}
