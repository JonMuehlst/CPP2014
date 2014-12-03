COMPILER = g++ # or CC if you prefer it on Hercules

DRIVER = main

FILE = matrix

FILE2 = mergesort

CXXFLAGS = -Wall -Wvla -Werror -g -pthread

GTESTFLAGS = -lgtest -pthread 
#-lgtest_main

all: $(DRIVER)

$(DRIVER) : $(FILE).o $(FILE2).o $(DRIVER).o  #the first character on the next line is a tab 
	$(COMPILER) $(CXXFLAGS) -o $(DRIVER) $(FILE).o $(FILE2).o $(DRIVER).o $(GTESTFLAGS)

$(DRIVER).o :  $(DRIVER).cpp  $(FILE).cpp $(FILE).h $(FILE2).cpp $(FILE2).h
	$(COMPILER) -c  $(DRIVER).cpp  -o $(DRIVER).o

$(FILE).o :  $(FILE).cpp $(FILE).h
	$(COMPILER) -c  $(FILE).cpp  -o  $(FILE).o

$(FILE2).o :  $(FILE2).cpp $(FILE2).h
	$(COMPILER) -c  $(FILE2).cpp  -o  $(FILE2).o


clean:
	@ /bin/rm -f *.o

##############################################
# installs that should be done once
##############################################
installonce: gtestinstall makedependinstall valgrindinstall

gtestinstall: 
	sudo apt-get install libgtest-dev
	sudo apt-get install cmake
	cd /usr/src/gtest; \
	sudo cmake CMakeLists.txt; \
	sudo make; \
	sudo cp *.a /usr/lib
	sudo chmod u+r /usr/lib/libgtest.a
	sudo chmod u+r /usr/lib/libgtest_main.a

makedependinstall:
	sudo apt-get install xutils-dev

valgrindinstall:
	sudo apt-get install valgrind
##############################################

.PHONY: all clean depend installonce gtestinstall makedependinstall valgrindinstall


# DO NOT DELETE THIS LINE -- make depend depends on it.