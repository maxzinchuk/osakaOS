# osakaOS v1.0
<h3>THE operating system of all time.</h3>

osakaOS is a 32 bit, singletasking, megalithic operating system that is made with a focus on unconventional/ridicoulous design choices. It uses a text-based command line to edit files using the <b>Osaka FileSystem</b> and create small programs using the <b>AyumuScript</b> scripting language. 

It also features small programs called 'modes' for small games and entertainment. The commands include the ability to read and write directly to memory, disk sectors, and most importantly, print ASCII art of Osaka :)


<h2>How to run/compile</h2>

Included is a pre-compiled bootable iso image that you can use in any normal virtualization software.

To compile from source do 'sudo make run' and pray for the best. The binary will be built and QEMU will boot from the virtual disk.



<h2>Extra</h2>

There are quite a number of glitches that I've yet to fix. 
  
  -Deleting a file that was not the most recently created might cause files to be listed incorrectly.
  -Every 4th LBA won't save data correctly on it's last sector.
  -Recent versions of QEMU have deprecated the 'pcspk' option. It might take some work to get speaker emulation working.
  -Other stuff that I haven't found yet or are too insignificant to mention in the README.
