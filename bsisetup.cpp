void setup() {
	char a;
	
	cout << "WARNING! This setup will add configuration to your /boot/loader.conf and /etc/rc.conf configuration files. If you already have configurated bhyve, say n to exit from setup.\n\n";
	cout << "Do you want to setup Bhyve on this server? y/n: ";
	cin >> a;

	if(a == 'y') {
		ofstream loader;
		loader.open("/boot/loader.conf", ios::app);
		loader << "vmm_load=\"YES\"\nif_bridge_load=\"YES\"\nif_tap_load=\"YES\"\n";
		loader.close();

		cout << "Setup is finished.\n";
	}
	
	else cout << "Setup is canceled.\n";
}
