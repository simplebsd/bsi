# bsi

Bhyve simple installer

DESCRIPTION
	Bsi is a simple Bhyve VM manager. It helps to install and manage virtual machines on Bhyve hypervisor.

OPTIONS
	-a	 List all active virtual machines.

	-l	 List all virtual machines.

	-s VM	 Start a virtual machine.

	-f VM	 Force stop a virtual machine.

	-r VM	 Restart a virtual machine.

	-fa	 Force stop all virtual machines.

	-i	 Install a virtual machine.

	-d VM	 Delete a virtual machine.

	-c VM NEWVM	 Clone a virtual machine.

	-o VM	 Open a session with virtual machine.

	-u	 List all autostart virtual machines.

	-ua VM	 Add a virtual machine to autostart.

	-ud VM	 Delete a virtual machine from autostart.

	-k VM	 Show configuration of virtual machine.

	-ke VM	 Edit configuration of virtual machine.

	-dw	 Download installation iso.

	setup	 Setup bhyve configuration files.

	update	 Update bsi.



Installation.

git clone https://github.com/simplebsd/bsi<br/>
cd bsi/<br/>
make install
