#include <iostream>
#include <time.h>
#include <stdio.h>
using namespace std;

char ltime() {
	time_t ltime;
	char lt;

	ltime = time(NULL);
	sprintf(lt, "%s", asctime(localtime(&ltime)));
	
	return lt;
}
