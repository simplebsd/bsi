void confed(char *vm) {
	char path_img[150], os[250], cpu[250], mem[250], disk[250], net[250], old_namef[250], old_coref[250], old_memf[250], old_name[100], old_core[100], old_mem[100], new_name[100], change_core[250], change_mem[250], change_core2[250], change_mem2[250], old_corec[250], old_memc[250], new_corec[250], new_memc[250], old_corec2[250], old_memc2[250], new_corec2[250], new_memc2[250];
	int new_core, new_mem;

        sprintf(path_img, "/usr/bsi/vm/%s/%s.img", vm, vm);
        ifstream vm_img(path_img);

        if(vm_img) {	
//		sprintf(old_namef, "/usr/local/bin/bsi -k %s | /usr/bin/grep Name | /usr/bin/awk '{print $2}' > /usr/local/etc/bsi/confed_name.txt", vm);
		sprintf(old_coref, "/usr/local/bin/bsi -k %s | /usr/bin/grep CPU | /usr/bin/awk '{print $2}' > /usr/local/etc/bsi/confed_core.txt", vm);
		sprintf(old_memf, "/usr/local/bin/bsi -k %s | /usr/bin/grep Memory | /usr/bin/awk '{print $2}' > /usr/local/etc/bsi/confed_mem.txt", vm);
//		system(old_namef);
		system(old_coref);
		system(old_memf);

//		ifstream namer("/usr/local/etc/bsi/confed_name.txt");
//		namer >> old_name;
//		namer.close();
		
		ifstream corer("/usr/local/etc/bsi/confed_core.txt");
		corer >> old_core;
		corer.close();

		ifstream memr("/usr/local/etc/bsi/confed_mem.txt");
		memr >> old_mem;
		memr.close();
		
//		cout << "Name[" << old_name << "]: ";
//		cin >> new_name;
		cout << "CPU, cores[" << old_core << "]: ";
		cin >> new_core;
		cout << "Memory, MB[" << old_mem << "]: ";
		cin >> new_mem;

		sprintf(old_corec, "CPU(cores): %s", old_core);
		sprintf(old_memc, "Memory(MB): %s", old_mem);
		sprintf(new_corec, "CPU(cores): %i", new_core);
		sprintf(new_memc, "Memory(MB): %i", new_mem);
		sprintf(old_corec2, "-c %s", old_core);
		sprintf(old_memc2, "-m %s", old_mem);
		sprintf(new_corec2, "-c %i", new_core);
		sprintf(new_memc2, "-m %i", new_mem);

		sprintf(change_core, "sed -i '' 's/%s/%s/g' /usr/bsi/vm/%s/%s.sh", old_corec, new_corec, vm, vm);
		sprintf(change_mem, "sed -i '' 's/%s/%s/g' /usr/bsi/vm/%s/%s.sh", old_memc, new_memc, vm, vm);
		sprintf(change_core2, "sed -i '' 's/%s/%s/g' /usr/bsi/vm/%s/%s.sh", old_corec2, new_corec2, vm, vm);
		sprintf(change_mem2, "sed -i '' 's/%s/%s/g' /usr/bsi/vm/%s/%s.sh", old_memc2, new_memc2, vm, vm);
		system(change_core);
		system(change_mem);
		system(change_core2);
		system(change_mem2);
	}

	else {
                cout << "\n";   
                cout << "VM does not exists.\n\n";
        }
}
