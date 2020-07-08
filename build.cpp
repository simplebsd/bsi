#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

void build() {
    char rtext[100], jcom[100], jadd[500];
    string vm_name, os, iso, cores, mem, disk;

    string conf_arr[6] = {};

    ifstream rconf("./Bfile");
    if(rconf.fail()) {
        cout << "Can't find Bfile.";
    }
    else {

        for(int i = 0; i < (sizeof(conf_arr) / sizeof(conf_arr[0])); i++) {
            rconf.getline(rtext, 100);
            conf_arr[i] = rtext;
        }


        rconf.close();

        vm_name = conf_arr[0];
        os = conf_arr[1];
        iso = conf_arr[2];
        cores = conf_arr[3];
        mem = conf_arr[4];
        disk = conf_arr[5];

        if(vm_name.substr(0, 9) != "vm_name: ") {
            cout << "Wrong parameter vm_name\n";
        }
        else if(os.substr(0, 4) != "os: ") {
            cout << "Wrong parameter os\n";
        }
        else if(cores.substr(0, 7) != "cores: ") {
            cout << "Wrong parameter cores\n";
        }
        else if(mem.substr(0, 5) != "mem: ") {
            cout << "Wrong parameter mem\n";
        }
        else if(disk.substr(0, 6) != "disk: ") {
            cout << "Wrong parameter disk\n";
        }

        else {
            sprintf(jcom, "zfs clone zroot/jails/basejail@12.0-RELEASE zroot/jails/%s", bname.substr(7).c_str());
            system(jcom);

            sprintf(jadd, "%s { # jm_%s\n  host.hostname = \"%s\"; # jm_%s\n  interface = \"lo1\"; # jm_%s\n  ip4.addr = %s; # jm_%s\n} # jm_%s\n\n", bname.substr(7).c_str() , bname.substr(7).c_str(), jhostname.substr(11).c_str(), bname.substr(7).c_str(), bname.substr(7).c_str(), jipv4.substr(7).c_str(), bname.substr(7).c_str(), bname.substr(7).c_str());

            ofstream jconf("/etc/jail.conf", ios::app);
            jconf << jadd;
            jconf.close();

	    int t, nt;
	    char tap[100], name[100], com1[300], com2[300], folder[150], filename[150], uifilename[150], ifile[100], ufilename[150], sh_file[150], ush_file[300], br1[150], br2[150], atp[300];

	    if(os == "freebsd") {
 
		ifstream tapr("/usr/local/etc/bsi/tap.conf");
                tapr >> t;
                tapr.close();

                nt = t +1;

                sprintf(tap, "tap%i", nt);

		ofstream tapw("/usr/local/etc/bsi/tap.conf");
                tapw << nt;
                tapw.close();
		
		sprintf(br1, "/sbin/ifconfig %s create", tap);
		sprintf(br2, "/sbin/ifconfig bridge0 addm %s up", tap);
		system(br1);
		system(br2);
		system("sed -i '' '/^cloned_interfaces/s/.$//' /etc/rc.conf");
		system("sed -i '' '/^ifconfig_bridge0/s/...$//' /etc/rc.conf");
		sprintf(atp, "sed -i '' '/^cloned_interfaces/s/$/ %s\"/' /etc/rc.conf && sed -i '' '/^ifconfig_bridge0/s/$/addm %s up\"/' /etc/rc.conf", tap, tap); 
system(atp);
		
		sprintf(folder, "/usr/bsi/vm/%s", vm_name);
		mkdir(folder, 0777);
		sprintf(com1, "truncate -s %iG /usr/bsi/vm/%s/%s.img", disk, vm_name, vm_name);
		system(com1);
		sprintf(filename, "/usr/bsi/vm/%s/%s.sh", vm_name, vm_name);
		ofstream osconf;
		osconf.open(filename);
		osconf << "#!/bin/sh\n\n#OS: FreeBSD\n#CPU(cores): " << cores << "\n#Memory(MB): " << mem << "\n#Disk(GB): " << disk << "\n#Network : " << tap << "\n\n/usr/share/examples/bhyve/vmrun.sh -c " << cores << " -m " <<  mem << " -t " << tap << " -d " << vm_name << ".img " << vm_name << "\n";
		osconf.close();
		sprintf(sh_file, "/usr/bsi/vm/%s/%s.sh", vm_name, vm_name);
		chmod(sh_file, S_IRWXU|S_IXGRP|S_IXOTH);
		sprintf(com2, "/usr/share/examples/bhyve/vmrun.sh -c %i -m %i -t %s -d /usr/bsi/vm/%s/%s.img -i -I %s %s", cores, mem, tap, vm_name, vm_name, iso, vm_name);
		system(com2);	
	    }
	
	    else if(os == "ubuntu") {
		ifstream tapr("/usr/local/etc/bsi/tap.conf");
                tapr >> t;
                tapr.close();

                nt = t +1;

                sprintf(tap, "tap%i", nt);

		ofstream tapwu("/usr/local/etc/bsi/tap.conf");
                tapwu << nt;
                tapwu.close();

                sprintf(br1, "/sbin/ifconfig %s create", tap);
                sprintf(br2, "/sbin/ifconfig bridge0 addm %s up", tap);
                system(br1);
                system(br2);
                system("sed -i '' '/^cloned_interfaces/s/.$//' /etc/rc.conf");
                system("sed -i '' '/^ifconfig_bridge0/s/...$//' /etc/rc.conf");
		sprintf(atp, "sed -i '' '/^cloned_interfaces/s/$/ %s\"/' /etc/rc.conf && sed -i '' '/^ifconfig_bridge0/s/$/addm %s up\"/' /etc/rc.conf", tap, tap); 
		system(atp);

		sprintf(folder, "/usr/bsi/vm/%s", vm_name);
                mkdir(folder, 0777);
                sprintf(com1, "truncate -s %iG /usr/bsi/vm/%s/%s.img", disk, vm_name, vm_name);
                system(com1);
		sprintf(filename, "/usr/bsi/vm/%s/device.map", vm_name);
		ofstream osconf;
                osconf.open(filename);
		osconf << "(hd0) /usr/bsi/vm/" << vm_name << "/" << vm_name << ".img\n(cd0) " << iso << "\n";
		osconf.close();
		sprintf(uifilename, "/usr/bsi/vm/%s/%s-install.sh", vm_name, vm_name);
		ofstream ui_file;
		ui_file.open(uifilename);
		ui_file << "#!/bin/sh\nbhyvectl --destroy --vm=" << vm_name << "\ngrub-bhyve -r cd0 -m /usr/bsi/vm/" << vm_name << "/device.map -M " << mem << " " << vm_name << "\n\nbhyve -c " << cores << " -m " << mem << " -H -P -A \\\n-l com1,stdio \\\n-s 0:0,hostbridge \\\n-s 1:0,lpc \\\n-s 2:0,virtio-net," << tap << " \\\n-s 3,ahci-cd," << iso << " \\\n-s 4,virtio-blk,/usr/bsi/vm/" << vm_name << "/" << vm_name << ".img " << vm_name << "\nbhyvectl --destroy --vm=" << vm_name << "\n";
		ui_file.close();
		chmod(uifilename, S_IRWXU|S_IXGRP|S_IXOTH);
		sprintf(ifile, "/usr/bsi/vm/%s/./%s-install.sh", vm_name, vm_name);
		system(ifile);
		remove(uifilename);
		sprintf(ufilename, "/usr/bsi/vm/%s/%s.sh", vm_name, vm_name);
		ofstream ush_file;
		ush_file.open(ufilename);
		ush_file << "#!/bin/sh\n\n#OS: Ubuntu\n#CPU(cores): " << cores << "\n#Memory(MB): " << mem << "\n#Disk(GB): " << disk << "\n#Network : " << tap << "\n\n" << "#!/bin/sh\nwhile [ 1 ]; do\nbhyvectl --destroy --vm=" << vm_name << "\ngrub-bhyve -r hd0,msdos1 -m /usr/bsi/vm/" << vm_name << "/device.map -M " << mem << " " << vm_name << "\n\nbhyve -c " << cores << " -m " << mem << " -H -P -A \\\n-l com1,stdio \\\n-s 0:0,hostbridge \\\n-s 1:0,lpc \\\n-s 2:0,virtio-net," << tap << " \\\n-s 4,virtio-blk,/usr/bsi/vm/" << vm_name << "/" << vm_name << ".img " << vm_name << " \nbhyve_exit=$?\nif [ $bhyve_exit -ne 0 ]; then\nbreak\nfi\ndone\nbhyvectl --destroy --vm=" << vm_name << "\n";
		ush_file.close();
		chmod(ufilename, S_IRWXU|S_IXGRP|S_IXOTH);

		ofstream tapw("/usr/local/etc/bsi/tap.conf");
                tapw << nt;
                tapw.close();
	}
}
        }
    }
}
