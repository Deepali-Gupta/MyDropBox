#include "drop_box.h"
#include <QApplication>
#include <pthread.h>
#include <fstream>
#include <string.h>
#include <iostream>
//#define OUTPUT "10.208.20.217,20000"

char output[100000];

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    strcpy(output,"10.208.20.206,20000");
    //strcpy(output,argv[1]);
     char* pch;
     char ip[40];
    char port[40];
        pch = strtok(output,",");
        strcpy(ip,pch);
        printf("ip=%s",ip);
     pch= strtok(NULL,",");

     strcpy(port,pch);
      printf("port=%s",pch);

      strcpy(output,"./ssl-client ");
      strcat(output,ip);
      strcat(output," ");
      strcat(output,port);
      printf("output=%s",output);
    drop_box w;
    w.showMaximized();

    return a.exec();
}
