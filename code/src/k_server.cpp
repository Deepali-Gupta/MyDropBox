//SSL-Server.c
#include <errno.h>
#include <pthread.h>
#include <unistd.h>
#include <malloc.h>
#include <string>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <resolv.h>
#include "openssl/ssl.h"
#include "openssl/err.h"
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <fstream>
#include "password.h"
#include <dirent.h>
#include <vector>
#include <iostream>
 
#define FAIL    -1
#define LENGTH 1000000
using namespace std;
char curr_user[LENGTH];
int n=1;
SSL *temp_ssl;
 char revbuf[LENGTH];
 int nsockfd; 
 
 std::vector<char*> open(char* path = ".") 
 {

    DIR*    dir;
    dirent* pdir;
    std::vector<char*> files;

    dir = opendir(path);

    while (pdir = readdir(dir)) {
		int flag=1;
		char ch;
		
        files.push_back(pdir->d_name);
	#ifdef DEBUG
	        printf("\tFile read:%s",pdir->d_name);
	#endif
    }
  
    
    return files;
}
 
int OpenListener(int port)
{   int sd;
    struct sockaddr_in addr;
 
    sd = socket(PF_INET, SOCK_STREAM, 0);
    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;
    if ( bind(sd, (struct sockaddr*)&addr, sizeof(addr)) != 0 )
    {
        perror("can't bind port");
        abort();
    }
    if ( listen(sd, 10) != 0 )
    {
        perror("Can't configure listening port");
        abort();
    }
    return sd;
}
 
int isRoot()
{
    if (getuid() != 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
 
}

SSL_CTX* InitServerCTX(void)
{   const SSL_METHOD *method;
    SSL_CTX *ctx;
 
    OpenSSL_add_all_algorithms();  /* load & register all cryptos, etc. */
    SSL_load_error_strings();   /* load all error messages */
    method = SSLv3_server_method();  /* create new server-method instance */
    ctx = SSL_CTX_new(method);   /* create new context from method */
    if ( ctx == NULL )
    {
        ERR_print_errors_fp(stderr);
        abort();
    }
    return ctx;
}
 
void LoadCertificates(SSL_CTX* ctx, char* CertFile, char* KeyFile)
{
    /* set the local certificate from CertFile */
    if ( SSL_CTX_use_certificate_file(ctx, CertFile, SSL_FILETYPE_PEM) <= 0 )
    {
        ERR_print_errors_fp(stderr);
        abort();
    }
    /* set the private key from KeyFile (may be the same as CertFile) */
    if ( SSL_CTX_use_PrivateKey_file(ctx, KeyFile, SSL_FILETYPE_PEM) <= 0 )
    {
        ERR_print_errors_fp(stderr);
        abort();
    }
    /* verify private key */
    if ( !SSL_CTX_check_private_key(ctx) )
    {
        fprintf(stderr, "Private key does not match the public certificate\n");
        abort();
    }
}
 
void ShowCerts(SSL* ssl)
{   X509 *cert;
    char *line;
 
    cert = SSL_get_peer_certificate(ssl); /* Get certificates (if available) */
    if ( cert != NULL )
    {
        printf("Server certificates:\n");
        line = X509_NAME_oneline(X509_get_subject_name(cert), 0, 0);
        printf("Subject: %s\n", line);
        free(line);
        line = X509_NAME_oneline(X509_get_issuer_name(cert), 0, 0);
        printf("Issuer: %s\n", line);
        free(line);
        X509_free(cert);
    }
    else
        printf("No certificates.\n");
}

char buf[LENGTH];
int sd, bytes;
 bool fileExists(const char* file) {
    struct stat buf;
    return (stat(file, &buf) == 0);
}
   
 
void createDir(char dir[]){
	char newpath[100000]; strcpy(newpath,"mkdir -p "); strcat(newpath,dir); system(newpath);
	
}
long int time(char* path)
{
	 
    
	FILE *pfile;
	pfile =fopen(path,"r");
	
	{
		
		struct stat filestatus;
		stat(path,&filestatus);
	
		long int time_mod = (long int) filestatus.st_mtime;
			
	}
}  
bool rec_client_all(char* path, SSL* ssl)
 {
	  mkdir(path,0777);
	 chdir(path);
	 int size=0;
			
			{
				char num[2];
				int l=SSL_read(ssl,num,2);
				num[2]=0;
				size=(int)(num[0]);
				#ifdef DEBUG
					printf("\nNo of files is %u",size);
				#endif
			}
			int n=0;
			while(n<size)
			{
				n++;
				/*Receive File from Client */
				char fr_name[10000];
				int length=SSL_read(ssl,fr_name,10000);
				fr_name[length]=0;
				#ifdef DEBUG
					printf("\nFile name received %s",fr_name);
				#endif
				std::string filename;
				std::string extension;
				for(int i=0;fr_name[i]!='\0';i++)
				{
					filename.append(1,fr_name[i]);
				}
				std::string::size_type idx;
		
				idx = filename.rfind('.');

				if(idx != std::string::npos)
				{
					extension = filename.substr(idx+1);
					#ifdef DEBUG
						printf("\nExtension=%s",extension.c_str());					
					#endif
				}
				else
				{
					#ifdef DEBUG
						printf("\nNo extension found");
					#endif
					mkdir(fr_name,0777);
					rec_client_all(fr_name,ssl);
					chdir("..");
					continue;
				}
				
				int lastindex = filename.find_last_of("."); 
				std::string rawname = filename.substr(0, lastindex); 			
				rawname.append(".txt");
				#ifdef DEBUG
					printf("\nModified %s",rawname.c_str());
				#endif
				
				FILE *fr = fopen(rawname.c_str(), "w");
				if(fr == NULL)
					printf("\nFile %s Cannot be opened file on server.\n", fr_name);
				bytes = SSL_read(ssl, buf, sizeof(buf)); // get request 
				#ifdef DEBUG
					printf("\ntest\n");
				#endif
				
				if ( bytes > 0 )
				{
					buf[bytes] = 0;
					int write_sz = fwrite(buf, sizeof(char), bytes, fr);
					rename(rawname.c_str(),filename.c_str());
				}
				
				else
					ERR_print_errors_fp(stderr);
				
				fclose(fr);
			}
	return true;
 }

 bool rec_client(char* path, SSL* ssl)
 {
	  mkdir(path,0777);
	 chdir(path);
	 int size=0;
			//if(!ctr)
			{
				char num[2];
				int l=SSL_read(ssl,num,2);
				num[2]=0;
				size=(int)(num[0]);
				#ifdef DEBUG
					printf("\nNo of files is %u",size);
				#endif
			}
			int n=0;
			while(n<size)
			{
				n++;
				/*Receive File from Client */
				char fr_name[10000];
				int length=SSL_read(ssl,fr_name,10000);
				fr_name[length]=0;
				#ifdef DEBUG
					printf("\nFile name received %s",fr_name);
				#endif
				std::string filename;
				std::string extension;
				for(int i=0;fr_name[i]!='\0';i++)
				{
					filename.append(1,fr_name[i]);
				}
				std::string::size_type idx;
		
				idx = filename.rfind('.');

				if(idx != std::string::npos)
				{
					extension = filename.substr(idx+1);
					#ifdef DEBUG
						printf("\nExtension=%s",extension.c_str());					
					#endif
				}
				else
				{
					#ifdef DEBUG
						printf("\nNo extension found");
					#endif
					mkdir(fr_name,0777);
					rec_client(fr_name,ssl);
					chdir("..");
					continue;
				}
				long int t=time((char*)filename.c_str());
				char tim[1024];
				int len=SSL_read(ssl,tim,1024);
				if(len>0)
			
				tim[len]=0;
				ofstream fo;
				fo.open("temp.txt");
				fo<<tim;
				fo.close();
				ifstream fi;
				fi.open("temp.txt");

				long int t2;
				fi>>t2;
				fi.close();
												system("rm temp.txt");
					#ifdef DEBUG
						cout<<"\nOriginal time "<<t<<"\nTime being received "<<t2;
					#endif
				char rep[1024];
				if(t2<=t&&(t<1000000000000))
				{
					strcpy(rep,"old");
				}
				else if(t>1000000000000)
				{
					strcpy(rep,"new");
				}
				else
				{
					strcpy(rep,"new");
				}
				SSL_write(ssl,rep,sizeof(rep));
			
			if(t2>t||t>1000000000000) {
				
				int lastindex = filename.find_last_of("."); 
				std::string rawname = filename.substr(0, lastindex); 			
				rawname.append(".txt");
				#ifdef DEBUG
					printf("\nModified %s",rawname.c_str());
				#endif
				
				FILE *fr = fopen(rawname.c_str(), "w");
				if(fr == NULL)
					printf("\nFile %s Cannot be opened file on server.\n", fr_name);
				bytes = SSL_read(ssl, buf, sizeof(buf)); // get request 
				#ifdef DEBUG
				printf("\ntest\n");
				#endif
				if ( bytes > 0 )
				{
					buf[bytes] = 0;
					int write_sz = fwrite(buf, sizeof(char), bytes, fr);
					rename(rawname.c_str(),filename.c_str());
				}
				else
					ERR_print_errors_fp(stderr);
				
				fclose(fr);
			}
			}
				
				
			
	return true;
 }


bool sendfile(char path_in[], SSL* ssl){
	// modify path to start creating directories from myDropBox onwards in path at server side
	
	char path[100000];
	char newpath[100000];
	strcpy(path,path_in);
	bool done = false;
	char * pch;
	pch = strtok(path,"/");
	pch=strtok(NULL,"/");
	while (pch != NULL)
	{   
		if (strcmp(pch,"MyDropBox")==0) // you have read myDropbox folder
		{
			char nextpath[100000];
			
			strcpy(nextpath,pch); 
			
			strcpy(newpath,""); 
			createDir(nextpath); //check if this directory exists, create one if it does not
			pch=strtok(NULL,"/");
			while (pch != NULL) // next value not null
			{
				// read directory/file and create one if non-existent
				strcat(newpath,nextpath);
				// strcat(newpath,"/");
				strcpy(nextpath,pch);
				pch=strtok(NULL,"/");
				if (pch == NULL) {
					// create directory and then create file
					createDir(newpath);
					strcat(newpath,"/");
					strcat(newpath,nextpath);
					
				}
				else {
					strcat(newpath,"/");
					strcat(newpath,nextpath);
					strcpy(nextpath,"");
				};
			}
		}
		if (pch != NULL) {pch=strtok(NULL,"/");};
	}
	char sdbuf[LENGTH]; 
	FILE *fs = fopen(newpath, "r");
	if(fs == NULL)
	{
		printf("\nERROR: File %s not found.\n", newpath);
		exit(1);
	}
	bzero(sdbuf, LENGTH); 
	int fs_block_sz; 
	fs_block_sz = fread(sdbuf, sizeof(char), LENGTH, fs);
	SSL_write(ssl, sdbuf, strlen(sdbuf));  
	fclose(fs);
	//file.close();
	done=true;
	//chdir("client");
	//chdir("..");
	return done;
}
bool getfile(char path_in[], SSL* ssl){
	// modify path to start creating directories from myDropBox onwards in path at server side
	
	char path[100000];
	char newpath[100000];
	strcpy(path,path_in);
	bool done = false;
	char * pch;
	pch = strtok(path,"/");
	pch=strtok(NULL,"/");
	while (pch != NULL)
	{   
		if (strcmp(pch,"MyDropBox")==0) // you have read myDropbox folder
		{
			char nextpath[100000];
			
			strcpy(nextpath,pch); 
			//strcat(nextpath,"/");
			//strcat(nextpath,curr_user);
			#ifdef DEBUG
				printf("nextpath is : %s",nextpath);
			#endif
			strcpy(newpath,""); 
			createDir(nextpath); //check if this directory exists, create one if it does not
			pch=strtok(NULL,"/");
			while (pch != NULL) // next value not null
			{
				// read directory/file and create one if non-existent
				strcat(newpath,nextpath);
				#ifdef DEBUG
					printf("newpath is : %s",newpath);
				#endif
				// strcat(newpath,"/");
				strcpy(nextpath,pch);
				#ifdef DEBUG
					printf("nextpath is : %s",nextpath);
				#endif
				pch=strtok(NULL,"/");
				if (pch == NULL) {
					// create directory and then create file
					createDir(newpath);
					strcat(newpath,"/");
					strcat(newpath,nextpath);
					#ifdef DEBUG
						printf("newpath is : %s",newpath);
					#endif
					std::ofstream file;
					file.open(newpath);
					file.close();
					done = true;
				}
				else {
					strcat(newpath,"/");
					strcat(newpath,nextpath);
					#ifdef DEBUG
						printf("newpath is : %s",newpath);
					#endif
					strcpy(nextpath,"");
				};
			}
		}
		if (pch != NULL) {pch=strtok(NULL,"/");};
	}
	
	char bu[LENGTH];
	int bytesu=SSL_read(ssl,bu,sizeof(bu));
	bu[bytesu]=0;
	
	std::ofstream file1;
		file1.open(newpath);
	file1.seekp(0,ios::beg);
	file1.write(bu,bytesu);
	file1.close();
	return done;
}

void send_client(char* path,SSL* ssl)
{
	 std::vector<char*> f;

				f = open(path); // or pass which dir to open
				chdir(path);
				char num[2];
				num[0]=(char)(f.size()-2);
				#ifdef DEBUG
					printf("\nSending no of files to the server:%c",num[0]);
				#endif
				SSL_write(ssl,num,2);
		
				for(int i=2;i<f.size();i++)
				{
					FILE *fin;
					char buf[LENGTH];
						bzero(buf,LENGTH);
					#ifdef DEBUG
						printf("\nSending file name %s to the server",f[i]);
					#endif
					for(int j=0;j<strlen(f[i]);j++)
					{
						buf[j]=f[i][j];
					}
				
					int name_block_sz=strlen(f[i]);
					SSL_write(ssl,buf,name_block_sz);
					std::string::size_type idx;
		std::string filename;
		filename.append(f[i]);
				idx = filename.rfind('.');

				if(idx != std::string::npos)
				{
									
				}
				else
				{
					
					send_client(f[i],ssl);
					chdir("..");
					continue;
				}
			long int t=time((char*)filename.c_str());
			//cout<<t;
			//printf("%l",t);
			char tim[1024];
			bzero(tim,1024);
		
		ofstream ti;
		ti.open("temp.txt");
		ti<<t;
		ti.close();
		ifstream to;
		to.open("temp.txt");

		to>>tim;
		to.close();
						system("rm temp.txt");

			int len=strlen(tim);
			#ifdef DEBUG
				printf("\ntime being sent %s",tim);
			#endif
			SSL_write(ssl,tim,len);			
			char rep[1024];
			int r=SSL_read(ssl,rep,1024);
			rep[r]=0;
			if(strcmp(rep,"new")==0)
			{
					char sdbuf[LENGTH]; 
					#ifdef DEBUG
						printf("\n[Client] Sending %s to the Server... ", buf);
					#endif
					FILE *fs = fopen(f[i], "r");
					if(fs == NULL)
					{
						printf("\nERROR: File %s not found.\n", f[i]);
						exit(1);
					}

					bzero(sdbuf, LENGTH); 
					int fs_block_sz; 
					fs_block_sz = fread(sdbuf, sizeof(char), LENGTH, fs);
					SSL_write(ssl, sdbuf, strlen(sdbuf));  
					fclose(fs);
			}
					
				}
}
 

bool dropbox_sync(SSL* ssl){
	bool val=false;
	chdir("MyDropBox");
	struct stat st;
	if(stat(curr_user,&st) == 0) 
	{
        printf(" /tmp is present\n");
		char hint[1024];
		bzero(hint,1024);
		strcpy(hint,"some");
		SSL_write(ssl,hint,sizeof(hint));
		rec_client(curr_user,ssl);
		chdir("..");
		
	
		send_client(curr_user,ssl);
		chdir("..");
		chdir(".."); 
	}
	else 
	{
		char hint[1024];
		bzero(hint,1024);
		strcpy(hint,"all");
		SSL_write(ssl,hint,sizeof(hint));
		
		rec_client_all(curr_user,ssl);
		chdir("..");
		chdir("..");
	}
	val=true;
	return val;
	}
 
void Servlet(SSL* ssl) /* Serve the connection -- threadable */
{ 
	
    const char* HTMLecho="<html><body><pre>%s</pre></body></html>\n\n";
	int f=1;
    if ( SSL_accept(ssl) == FAIL )     // do SSL-protocol accept 
    {
        ERR_print_errors_fp(stderr);
        f=0;
    }
    else
    {
		mkdir("server",0777);
		printf("success");
        ShowCerts(ssl);        // get any certificates 
      //  FILE *fr = fopen("server/client.txt", "a");
      std::ofstream fr;
      fr.open("server/client.txt");
				//if(fr == NULL)
				//	printf("\nFile %s Cannot be opened file on server.\n", fr_name);
				bytes = SSL_read(ssl, buf, sizeof(buf)); // get request 
				printf("%s",buf);
				
				if ( bytes > 0 )
				{
					buf[bytes] = 0;
				
					fr.write(buf, bytes);
					
					
				}
				
				else
					ERR_print_errors_fp(stderr);
			fr.close();	
			
		
			
			std::ifstream readfile("server/client.txt");
			readfile.seekg(0,std::ios::beg);
			char c[LENGTH];
			readfile>>c;
			int rq=atoi(c);
			printf("rq is %d\n",rq);
			switch(rq) {
				// register user
				case 1 : { std::string user;
							readfile>>user;
							std::string pass;
							readfile>>pass;
							readfile.close();
							int k = set_user(user,pass);
							char reply[LENGTH];
							if (k==0) strcpy(reply,"YES");
							else strcpy(reply,"NO");
							SSL_write(ssl,reply,strlen(reply));
							break; }
				// verify user
				case 2 : { std::string user;
							readfile>>user;
							std::string pass;
							readfile>>pass;
							readfile.close();
							int k = check_password(user,pass);
							char reply[LENGTH];
							if (k==1) strcpy(reply,"YES");
							if (k==-1) strcpy(reply,"NO");
							if (k==0) strcpy(reply,"NULL");
							SSL_write(ssl,reply,strlen(reply));
							break; }
				// upload a file
				case 3 : { char hi[1024];
							readfile>>hi;
							strcpy(curr_user,hi);
							#ifdef DEBUG
							printf("current user: %s\n",curr_user);
							#endif
							char path[1024];
							readfile>>path;
							#ifdef DEBUG
							printf("current path: %s\n",path);
							#endif
							readfile.close();
							bool k = getfile(path,ssl);
							char reply[LENGTH];
							if (k) strcpy(reply,"YES");
							else strcpy(reply,"NO");
							SSL_write(ssl,reply,strlen(reply));
							break;}
				// upload all files
				case 4 : { char path[1024];
							readfile>>path;
							strcpy(curr_user,path);
							readfile.close();
							chdir("MyDropBox");
							createDir(curr_user);
							bool k = rec_client_all(curr_user,ssl);
							char reply[LENGTH];
							if (k) strcpy(reply,"YES");
							else strcpy(reply,"NO");
							SSL_write(ssl,reply,strlen(reply));
							chdir("..");
							chdir("..");
							break;}
				// download a file
				case 5 : { char path[1024];
							readfile>>path;
							strcpy(curr_user,path);
							readfile>>path;
							readfile.close();
							bool k =sendfile(path,ssl);
							char reply[LENGTH];
							if (k) strcpy(reply,"YES");
							else strcpy(reply,"NO");
							SSL_write(ssl,reply,strlen(reply));
							break;}
				// sync
				case 6 : {  char path[1024];
							readfile>>path;
							strcpy(curr_user,path);
							#ifdef DEBUG
							printf("current user: %s\n",curr_user);
							#endif
							readfile.close();
							bool k = dropbox_sync(ssl); 
							char reply[LENGTH];
							if (k) strcpy(reply,"YES");
							else strcpy(reply,"NO");
							SSL_write(ssl,reply,strlen(reply)); 
							break;} 
					// share file with a user
				case 7 : {break;}
			
				// check if file is old
				case 8 : {
												
							break;}
				default : {printf("Default called\n");break;}
			}
	
			
	}
	
	sd = SSL_get_fd(ssl);       // get socket connection 
	SSL_free(ssl);         // release SSL state 
	close(sd);          // close connection 
}

void *func(void *k){
	SSL *ssl;
	ssl = (SSL *) k;
	Servlet(ssl);
}
 
int main(int count, char *strings[])
{   SSL_CTX *ctx;
    int server;
    int portnum=20000;
 
    SSL_library_init();
 

    ctx = InitServerCTX();        /* initialize SSL */
    LoadCertificates(ctx, "mycert.pem", "mycert.pem"); /* load certs */
    server = OpenListener((portnum));    /* create server socket */
    while (1)
    {   struct sockaddr_in addr;
        socklen_t len = sizeof(addr);
        
 
        int client = accept(server, (struct sockaddr*)&addr, &len);  /* accept connection as usual */
        printf("Connection: %s:%d\n",inet_ntoa(addr.sin_addr), ntohs(addr.sin_port));
        temp_ssl = SSL_new(ctx);              /* get new SSL state with context */
        SSL_set_fd(temp_ssl, client);      /* set connection socket to SSL state */
        pthread_t t1;
        pthread_create(&t1,NULL,func,(void *) temp_ssl);
    }
    close(server);          /* close server socket */
    SSL_CTX_free(ctx);         /* release context */
}
