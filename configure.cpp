#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
using namespace std;

int main() {
	system("/sbin/kldload vmm"); 
	system("/sbin/kldload if_bridge; /sbin/kldload if_tap");
	
/*	ofstream lcf;
	lcf.open("/boot/loader.conf", ios::app);
	lcf << "vmm_load=\"YES\"\nif_bridge_load=\"YES\"\nif_tap_load=\"YES\"\n";
	lcf.close();

	ofstream scf;
	scf.open("/etc/sysctl.conf", ios::app);
	scf << "net.link.tap.up_on_open=1\n";*/

	return 0;
}
