# MyDropBox
A file management system that allows storage of files for multiple users. All data flows over a secure connection.

## System Requirements
MyDropBox runs on Linux based platforms only. It requires the following packages :
- GNU gcc compiler
- QtCreator package
- OpenSSL toolkit and certificate
- pthread library

## Features
### Interface
Qt, a cross-platform application and UI framework is used to develop the user inter-face of the application.

### Secure Connection
The entire communication between the server and the client happens on a secure connection, established using OpenSSL.

### File Handling
The hierarchical structure of the user directory is maintained on the server side.

### Database Management
\*.txt files are used to maintain databases. Passwords are encrypted using standard library c++ hash function before storage.

### Multithreading
In order to enable independent and uninterrupted working of the server and multiple client systems, multithreading is used.

### Persistent storage
The user’s contents are stored in a local folder on the system. If user’s session breaks for some reason like pressing close button or power failure, there is no need to download everything again.
Contents of the local folder are monitored on re-login and updated accordingly on the server end.

### Synchronisation
The content of user’s account remains synced with the server on each login. The contents of the server are updated when the user presses the upload button or signs out from his account.

### Makefile
Makefile is used to build the application from its source code, organize the code, and its compilation and linking.

## Usage Instructions
* In the terminal, change the current directory to "MyDropBox".
* To run the main program:
  * Type "make".
  * This version is for normal users.
- To run the debug version:
  * Type "make DEBUG".
  * This version is for programmers only. It is used to debug the program.
- "make server" spawns the server.
- "make client server=x" spawns a client which connects to server x, where x is a combination of server's ip address and port number.
- "make clean" cleans all the temporary files and executables.
- Once the application is running, follow the on screen instructions.
  * New user has to register first.
  * The user has to enter a non-used username and a password consisting of minimum 6 characters.
  * Existing user can login with his username and password.
- After successful login, the folder corresponding to that user is created. 
  * Addition, deletion and modifications of files and folders can be done.
  * All changes done in the user folder only will be saved to drive.
  * To select files or folders, click on "Select" button.
- Select files and folders from the MyDropBox interface and do various operations on them like:
  * ”Upload all” : Clicking this button uploads all the files in the client
  home folder to the server.  
  * "Download" : Clicking on this button will download all your files from the server.
  * "Upload" : Clicking on this button will upload the selected file to the server.
  * If you click on the sign out button a message prompt will ask you if you want to upload all files.
  * Clicking yes will upload all your files to the server.
  * Clicking no will close the application.
- At each transfer of data between server and client, the corresponding message with the data flow direction and the data being transferred is displayed.
