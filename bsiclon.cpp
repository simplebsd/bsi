void clon(char *vm, char *vm2) {
	char com[300], path_img[100], img1[100], img2[100], sh1[100], sh2[100], old_tap[100], new_tap[100], check_tap[250], change_tap[350], br1[150], br2[150], atp[300];
	int t, nt;

	sprintf(path_img, "/usr/bsi/vm/%s/%s.img", vm, vm);
	ifstream vm_img(path_img);

	if(vm_img) {
		cout << "\n";

		sprintf(com, "/usr/local/bin/rsync -a --info=progress2 /usr/bsi/vm/%s/* /usr/bsi/vm/%s; sed -i '' 's/%s/%s/g' /usr/bsi/vm/%s/%s.sh", vm, vm2, vm, vm2, vm2, vm);  
		system(com);

		sprintf(img1, "/usr/bsi/vm/%s/%s.img", vm2, vm);
		sprintf(img2, "/usr/bsi/vm/%s/%s.img", vm2, vm2);
		sprintf(sh1, "/usr/bsi/vm/%s/%s.sh", vm2, vm);
		sprintf(sh2, "/usr/bsi/vm/%s/%s.sh", vm2, vm2);
		rename(img1, img2);
		rename(sh1, sh2);

		ifstream tapr("/usr/local/etc/bsi/tap.conf");
		tapr >> t;
		tapr.close();

		nt = t + 1;
		
		sprintf(new_tap, "tap%i", nt);


		sprintf(check_tap, "/usr/local/bin/bsi -k %s | /usr/bin/grep tap | /usr/bin/awk '{print $3}' > /usr/local/etc/bsi/tap_change.txt", vm);
		system(check_tap);
		
		ifstream tapr2("/usr/local/etc/bsi/tap_change.txt");
		tapr2 >> old_tap;
		tapr2.close();


		sprintf(change_tap, "sed -i '' 's/%s/%s/g' %s", old_tap, new_tap, sh2);
		system(change_tap);

		
		ofstream tapw("/usr/local/etc/bsi/tap.conf");
		tapw << nt;
		tapw.close();


		sprintf(br1, "/sbin/ifconfig %s create", new_tap);
                sprintf(br2, "/sbin/ifconfig bridge0 addm %s up", new_tap);
                system(br1);
                system(br2);
                system("sed -i '' '/^cloned_interfaces/s/.$//' /etc/rc.conf");
                system("sed -i '' '/^ifconfig_bridge0/s/...$//' /etc/rc.conf");
                sprintf(atp, "sed -i '' '/^cloned_interfaces/s/$/ %s\"/' /etc/rc.conf && sed -i '' '/^ifconfig_bridge0/s/$/addm %s up\"/' /etc/rc.conf", new_tap, new_tap); 
                system(atp);

		cout << "\n";
		cout << "VM is cloned.\n";
		cout << "Don't forget to change hostname and ip address.\n\n";
	}

	else {
		cout << "\n";	
		cout << "VM does not exists.\n\n";
	}

}
	
