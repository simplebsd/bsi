install:
	pkg ins -y screen rsync grub2-bhyve
	mkdir -p /usr/bsi/vm
	mkdir -p /usr/bsi/iso
	mkdir -p /usr/local/etc/bsi
	touch /usr/local/etc/bsi/tap.conf
	chmod a+x /usr/share/examples/bhyve/vmrun.sh
	clang++ bsi.cpp -o /usr/local/bin/bsi
	clang++ s_wipe.cpp -o s_wipe
	clang++ tap.cpp -o tap
	./s_wipe
	rm s_wipe
	./tap
	rm tap

deinstall:
	pkg del -y screen rsync grub2-bhyve
	pkg autoremove -y
	rm /usr/local/bin/bsi
