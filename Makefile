configure:
	kldload vmm
	kldload if_bridge
	kldload if_tap
	sysctl net.link.tap.up_on_open=1

	echo 'vmm_load="YES"' >> /boot/loader.conf
	echo 'if_bridge_load="YES"' >> /boot/loader.conf
	echo 'if_tap_load="YES"' >> /boot/loader.conf
	echo 'net.link.tap.up_on_open=1' >> /etc/sysctl.conf

	
	
	
install:
	pkg ins -y screen rsync
	mkdir -p /usr/bsi/vm
	mkdir /usr/bsi/iso
	clang++ bsi.cpp -o /usr/local/bin/bsi

deinstall:
	pkg del -y screen rsync
	pkg autoremove -y
	rm /usr/local/bin/bsi
