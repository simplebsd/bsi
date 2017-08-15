void setup() {
	char a;
	
	cout << "WARNING! This setup will add configuration to your /boot/loader.conf and /etc/rc.conf configuration files. If you already have configurated bhyve, say n to exit from setup.\n\n";
	cout << "Do you want to setup Bhyve configuration files on this server? y/n: ";
	cin >> a;

	if(a == 'y') {
		ofstream loader("/boot/loader.conf", ios::app);
		loader << "vmm_load=\"YES\"\nif_bridge_load=\"YES\"\nif_tap_load=\"YES\"\nhw.vmm.topology.cores_per_package=2\n";
		loader.close();
		
		ofstream sysctl("/etc/sysctl.conf", ios::app);
		sysctl << "net.link.tap.up_on_open=1\n";
		sysctl.close();

		system("/sbin/sysctl net.link.tap.up_on_open=1");
		system("kldload vmm");
		system("kldload if_tap");
		system("kldload if_bridge");

		cout << "Setup is finished.\n";
	}
	
	else cout << "Setup is canceled.\n";
}
