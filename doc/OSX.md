Build qaul.net on Mac OSX
=========================

This tutorial describes all the steps to build qaul.net-ng on Mac OSX. qaul.net works on
Mac OSX > 10.5. This Tutorial has been tested on the following versions of Mac OSX:

* OSX 10.6 (Snow Leopard)
* OSX 10.8 (Mountain Lion)
* OSX 10.11 (El Capitan)

The qaul.net software is running on OSX >= 10.5 (OSX 10.5 needs a special build).


Prerequisites
-------------

The following tools need to be installed

* XCode 
  * download and install from app store
* cmake (install via macports)
  * download macports from https://www.macports.org/
  * install programs via terminal:

	# install cmake
	sudo port install cmake


Get the source
--------------

Download the source from [github](https://github.com/WachterJud/qaul.net-ng) 

	git clone https://github.com/WachterJud/qaul.net-ng.git


Build
-----

    # create build directory in qaul.net-ng source folder
    mkdir build
    cd build
	
	# build qaul.net
    cmake ../
    make
    
    # generate a DMG installer image
    ./make_dmg.sh
    
    # install qaul.net build on your local system
    sudo make install


You can start the qaul app by double clicking the app in your Applications folder.
To start qaul from the terminal execute the following:

	# start qaul from the terminal to see the log messages
	/Applications/qaul.app/Contents/MacOS/qaul


Remove and Re-Install qaul
--------------------------

To remove or reinstall the qaul application do the following:

	# remove the installed application and files
	## delete the app folder
	sudo rm -R /Applications/qaul.app
	## delete the libraries and helper files
	sudo rm -R /Library/qaul.net
	## delete the user data folder
	rm -R ~/Library/qaul.net
	
	# rebuild the application LaunchServices
	/System/Library/Frameworks/CoreServices.framework/Frameworks/LaunchServices.framework/Support/lsregister -kill -r -domain local -domain system -domain user


Now you can re-install the app via the installer.