Written in ubuntu!


If you get a segfault when running during "LINK SEEDING", please run the executable again.  It's a rare bug that I haven't solved yet.  The odds are you won't even see it!

The program offers size options from 1-4 for seeding of the various universal elements. However, there is a test option '0', so that for all options you can choose 0-4.  Although the options allow
the user to select different sizes for each of the different elements, it is highly recommended that all options are selected with the same value so that the simulation has a reasonable ratio of 
planets to stars to mites.

The program was written in Ubuntu, although only one command will not work in Windows.  That command has been commented out.  It calls the linux program "imagemagick" which will convert the .png files located
in the directory where the program was run into a .gif. This program will grab all the pngs in a directory, so if multiple simulations are run with different amounts of time steps, where for each time
step there is a png file, then multiple simulations will be combined into the gif animation.  The imagemagick program is installed by default in ubuntu desktop distros. The commented out code is at the end of the main.cpp file at line 512-530.

Parts of the simulation will utilize up to 4 cores, therefore a 4 core CPU is a minimum requirement when running this program.  I suspect that all the computers at ODU are at least 4 cores so I don't
believe this to be an issue, but the program would have a compatibility issue with dual core or single core machines. Also the program needs special flags to compile correctly with the <thread> library.  There is more info on that below regarding codeblocks, although if compiled in linux using the included Makefile you will not have any issues with this as the flags are included.

The Makefile will run on a linux environment to produce a binary executable in the /mites_and_stars/bin folder and object files in the /mites_and_stars/obj folder.  By default the program will produce
a png file for each time step and that png file will be stored in the directory from which the program was run.  I recommend changing directories to the /mites_and_stars/plots folder before executing the program, so that all the png files will be stored there after an execution of the program.  This folder otherwise has no purpose.

I am also going to include a code blocks project file which will be located in the /mites_and_stars/mites_and_stars folder, for conveinence. To compile in codeblocks the c++ std 11 libraries need to be
selected. ***ALSO, in linker settings the additional option "-pthread" has to be included for the <thread> library.  The program should then compile with no issues.

I have left a test run of pngs and a gif in the plots folder.  The test run was with options 0,0,0,0,0.  If a number less than 100 is entered into the time steps, 100 time steps will still occur.  There is no maximum but testing with over a billion time steps will make you wait around for a few days...  You can also modify the resolution of the pngs.  Default resolution is 1920x1080.  In main.cpp at line 396
you can modify the following line to produce a png of any desired resolution. 4k is a real killer here on longer simulations, but produces noticeably nicer images if you can view them at 4k.

	plot_command<<" set terminal png size 1920, 1080 enhanced font \"Helvitica, 11\""<<endl;
	
	Replace 1920 and 1080 in the above line at main.cpp line 396 to your custom resolution, if desired.  
	
	
The gnuplot command assumes that the executable has been installed so that it can be called directly from the command line.  I expect this should work similarly in windows.  The only change would be to change the call to gnuplot to include the windows directory tree for the location of the gnuplot executable.  This is at line 412,

			system("gnuplot gnu_command.txt");
			
			Change the above to 
			
			system("C:\Program^ Files^ (x86)\gnuplot\bin\gnuplot.exe gnu_command.txt");
			
			The above might not be reflective of your enviroment.  Hopefully you're using linux so it doesn't matter...:) but If all else, it's simplest to copy the gnuplot.exe binary 
			file from it's directory and paste it into the directory where you will run the executable for mites_and_stars.  
			
			

			
			
