#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

int main() {
	int t;

	ifstream tapr("/usr/local/etc/bsi/tap.conf");
	tapr >> t;
	tapr.close();

	cout << t << "\n";

	/*system("sed -i '' '/bsitap tap10/d' /usr/local/etc/bsi/tap.conf");
	ofstream tap;
	tap.open("/usr/local/etc/bsi/tap.conf", ios::app);
	tap << "bsitap tap10\n";
	tap.close();
*/

	return 0;
}
