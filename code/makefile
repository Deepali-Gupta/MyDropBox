# call CC2 when you need to pass the value of OUTPUT to main.cpp
#------------------------------------------------------------------------------

CC=g++ -w 
ARGS=
SRC=src
SERVER=$(SRC)/server
STUDAPA=$(SRC)/studapa
SERVER_DROPBOX=$(SRC)/MyDropBox
BUILD=$(SRC)/build-studapa-Desktop-Debug
CLIENT_DROPBOX=$(BUILD)/MyDropBox
LIBS= -lpthread -lcrypto -lssl -L/usr/lib

#------------------------------------------------------------------------------
# make                 compile source code
# make clean           to remove all .obj and .exe files 
# make DEBUG           for debug-mode
# make server          spawn the server
# make client server=
#------------------------------------------------------------------------------

debug: CC+= -DDEBUG

all: $(SRC)/ssl-server $(BUILD)/studapa

server: $(SRC)/ssl-server 
	./$(SRC)/ssl-server && cd src
	
$(SRC)/ssl-server: 
	$(CC) -o $(SRC)/ssl-server $(SRC)/k_server.cpp $(SRC)/password.cpp $(LIBS)
	
exe: $(BUILD)/studapa
	cd $(BUILD)
	
client: $(BUILD)/studapa
	cd $(BUILD) && ./studapa ${server}

$(BUILD)/studapa: $(BUILD)/Makefile
	cd $(BUILD) && make && cd ../..

$(BUILD)/Makefile: $(STUDAPA)/studapa.pro
	qmake $(STUDAPA)/studapa.pro -o $(BUILD)/Makefile
	
	

