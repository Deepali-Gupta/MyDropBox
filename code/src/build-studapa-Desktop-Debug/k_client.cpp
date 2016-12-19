#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <malloc.h>
#include <string>
#include <sys/socket.h>
#include <resolv.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
//#include <ctype.h>          
#include <arpa/inet.h>

#include <dirent.h>
#include <vector>
#include <fstream>
#include <string.h>
#define LENGTH 1000000
#define FAIL    -1
using namespace std;

 //int n=1;
 int sockfd; 
 void send_server(char* path,SSL* ssl);
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
        printf("\tFile read:%s",pdir->d_name);
    }
  //  printf("%s\n",files[2]);
    
    return files;
}
int OpenConnection(const char *hostname, int port)
{   int sd;
    struct hostent *host;
    struct sockaddr_in addr;
 
    if ( (host = gethostbyname(hostname)) == NULL )
    {
        perror(hostname);
        abort();
    }
    sd = socket(PF_INET, SOCK_STREAM, 0);
    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = *(long*)(host->h_addr);
    if ( connect(sd, (struct sockaddr*)&addr, sizeof(addr)) != 0 )
    {
        close(sd);
        perror(hostname);
        abort();
    }
    return sd;
}
 
SSL_CTX* InitCTX(void)
{   const SSL_METHOD *method;
    SSL_CTX *ctx;
 
    OpenSSL_add_all_algorithms();  /* Load cryptos, et.al. */
    SSL_load_error_strings();   /* Bring in and register error messages */
    method = SSLv3_client_method();  /* Create new client-method instance */
    ctx = SSL_CTX_new(method);   /* Create new context */
    if ( ctx == NULL )
    {
        ERR_print_errors_fp(stderr);
        abort();
    }
    return ctx;
}
 
void ShowCerts(SSL* ssl)
{   X509 *cert;
    char *line;
 
    cert = SSL_get_peer_certificate(ssl); /* get the server's certificate */
    if ( cert != NULL )
    {
        printf("Server certificates:\n");
        line = X509_NAME_oneline(X509_get_subject_name(cert), 0, 0);
        printf("Subject: %s\n", line);
        free(line);       /* free the malloc'ed string */
        line = X509_NAME_oneline(X509_get_issuer_name(cert), 0, 0);
        printf("Issuer: %s\n", line);
        free(line);       /* free the malloc'ed string */
        X509_free(cert);     /* free the malloc'ed certificate copy */
    }
    else
        printf("No certificates.\n");
}
long int time(char* path)
{
	 
    
	FILE *pfile;
	pfile =fopen(path,"r");
	if (pfile == NULL) {printf("Error opening file");}
	else {
		//path=s;
		struct stat filestatus;
		stat(path,&filestatus);
		int size=(int) filestatus.st_size;
		long int time_mod = (long int) filestatus.st_mtime;
		//printf("%l",time_mod);
	//	cout<<time_mod<<"\n";
		
		
	}
}
 void send_server_all(char* path,SSL* ssl)
 {
	 std::vector<char*> f;

				f = open(path); // or pass which dir to open
				chdir(path);
				char num[2];
				num[0]=(char)(f.size()-2);
				printf("\nSending no of files to the server:%c",num[0]);
				SSL_write(ssl,num,2);
		
				for(int i=2;i<f.size();i++)
				{
					FILE *fin;
					char buf[LENGTH];
						bzero(buf,LENGTH);
					printf("\nSending file name %s to the server",f[i]);
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
					//extension = filename.substr(idx+1);
					//printf("\nExtension=%s",extension.c_str());					
				}
				else
				{
					//strcat(path,"/");
					//strcat(path,f[i]);
					send_server_all(f[i],ssl);
					chdir("..");
					continue;
				}
					char sdbuf[LENGTH]; 
					printf("\n[Client] Sending %s to the Server... ", f[i]);
			
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
 void send_server(char* path,SSL* ssl)
 {
	 std::vector<char*> f;

				f = open(path); // or pass which dir to open
				chdir(path);
				char num[2];
				num[0]=(char)(f.size()-2);
				printf("\nSending no of files to the server:%c",num[0]);
				SSL_write(ssl,num,2);
		
				for(int i=2;i<f.size();i++)
				{
					FILE *fin;
					char buf[LENGTH];
						bzero(buf,LENGTH);
					printf("\nSending file name %s to the server",f[i]);
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
					//extension = filename.substr(idx+1);
					//printf("\nExtension=%s",extension.c_str());					
				}
				else
				{
					//strcat(path,"/");
					//strcat(path,f[i]);
					send_server(f[i],ssl);
					chdir("..");
					continue;
				}
			long int t=time((char*)filename.c_str());
			cout<<t;
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
			printf("\ntime being sent %s",tim);
			SSL_write(ssl,tim,len);			
			char rep[1024];
			int r=SSL_read(ssl,rep,1024);
			rep[r]=0;
			if(strcmp(rep,"new")==0)
			{
					char sdbuf[LENGTH]; 
					printf("\n[Client] Sending %s to the Server... ", f[i]);
			
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
void rec_server(char* path, SSL* ssl)
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
				printf("\nNo of files is %u",size);
			}
			int n=0;
			while(n<size)
			{
				n++;
				/*Receive File from Client */
				char fr_name[10000];
				int length=SSL_read(ssl,fr_name,10000);
				fr_name[length]=0;
				printf("\nFile name received %s",fr_name);
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
					printf("\nExtension=%s",extension.c_str());					
				}
				else
				{
					printf("\nNo extension found");
					mkdir(fr_name,0777);
					rec_server(fr_name,ssl);
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
					cout<<"\nOriginal time "<<t<<"\nTime being received "<<t2;
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
				printf("\nModified %s",rawname.c_str());
				//rename("server/receive1.txt","server/receive.jpg");
				FILE *fr = fopen(rawname.c_str(), "w");
				if(fr == NULL)
					printf("\nFile %s Cannot be opened file on server.\n", fr_name);
					char buf[LENGTH];
				int bytes = SSL_read(ssl, buf, sizeof(buf)); // get request 
				printf("\ntest\n");
				
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
				
				
			
	return ;
 }

 
	 
int main(int count, char *strings[])
{   SSL_CTX *ctx;
    int server;
    SSL *ssl;
    int bytes;
    char *hostname, *portnum;
 
    if ( count != 3 )
    {
        printf("usage: %s <hostname> <portnum>\n", strings[0]);
        exit(0);
    }
    SSL_library_init();
    hostname=strings[1];
    portnum=strings[2];
 
    ctx = InitCTX();
    server = OpenConnection(hostname, atoi(portnum));
    ssl = SSL_new(ctx);      /* create new SSL connection state */
    SSL_set_fd(ssl, server);    /* attach the socket descriptor */
    if ( SSL_connect(ssl) == FAIL )   /* perform the connection */
        ERR_print_errors_fp(stderr);
    else
    {
		char sdbuf[LENGTH]; 
		printf("\n[Client] Sending  to the Server... ");
		ifstream fs;
		fs.open("newuser.txt");
		//FILE *fs = fopen("newuser.txt", "r");
		if(fs == NULL)
		{
			//printf("\nERROR: File %s not found.\n", f[i]);
			exit(1);
		}

		bzero(sdbuf, LENGTH); 
		fs.read(sdbuf,LENGTH);
		printf("%s",sdbuf);
		SSL_write(ssl, sdbuf, strlen(sdbuf));  
		fs.close();
		fs.open("newuser.txt");
		fs.seekg(0,ios::beg);
		int f;
		char num[1024];
		fs>>num;
		f=atoi(num);
		//f=3;
		char path[1024];
		char user[1024];
		fs>>user;
		fs>>path;
		//strcpy(path,"input.txt");
		fs.close();
		char tmp[1024];
		strcpy(tmp,"MyDropBox/");
		strcat(tmp,user);
			
											
										
		if(f==3)
		{
			printf("\n case3\n path=%s\n***",path);
						
			char rel[1024];
			int ctr=0;
			char* pch;
			pch=strtok(path,"/");
			pch=strtok(NULL,"/");
			while(pch!=NULL)
			{
				printf("\n%s\n",pch);
				strcpy(rel,"");
				if(strcmp(pch,"MyDropBox")==0)
				{
					ctr++;
					while (pch != NULL)
					{			
						strcat(rel,pch);
			
						pch=strtok(NULL,"/");
						
						if (pch != NULL) 
						{
							strcat(rel,"/");
							ctr++;
						}
					}
				}
				pch=strtok(NULL,"/");

			}
	
			ifstream file;
		
			printf("\npt=%s\n",rel);
			
			{
				file.open(rel);
				char buf[LENGTH];
				bzero(buf,LENGTH);
				file.read(buf,LENGTH);
				printf("\ncontents=%s\n",buf);
				SSL_write(ssl,buf,strlen(buf));
				file.close();
			}
			//chdir("..");
		}
		else if(f==4)
		{
			char rel[1024];
			strcpy(rel,"MyDropBox/");
			strcat(rel,user);
			send_server_all(rel,ssl);
			chdir("..");
			chdir("..");
		}
					
		else if(f==5)
		{
			char buf[LENGTH];
			int len=SSL_read(ssl,buf,sizeof(buf));
			buf[len]=0;
			char rel[1024];
			char* pch;
			pch=strtok(path,"/");
			pch=strtok(NULL,"/");
			while(pch!=NULL)
			{
				printf("\n%s\n",pch);
				strcpy(rel,"");
				if(strcmp(pch,"MyDropBox")==0)
				{
					while (pch != NULL)
					{
			
						strcat(rel,pch);
			
						pch=strtok(NULL,"/");
						if (pch != NULL) {strcat(rel,"/");}
					}
				}
				pch=strtok(NULL,"/");			
			}
			ofstream fout;
			fout.open(rel);
			fout.write(buf,len);
			fout.close();
		}  
		else if(f==6)
		{
			char rel[1024];
			strcpy(rel,"MyDropBox/");
			strcat(rel,user);
			char hint[1024];
			int h=SSL_read(ssl,hint,1024);
			hint[h]=0;
			if(strcmp(hint,"some")==0)
			{
			send_server(rel,ssl);
			chdir("..");
			chdir("..");
			rec_server(rel,ssl);
			chdir("..");
			chdir("..");
			}
			else
			{
				send_server_all(rel,ssl);
				chdir("..");
				chdir("..");
			}
			
		}
					
		std::ofstream fr;
		fr.open("reply.txt");
		char reply[LENGTH];
		//if(fr == NULL)
		//	printf("\nFile %s Cannot be opened file on server.\n", fr_name);
		int bytes = SSL_read(ssl, reply, sizeof(reply)); // get request 
		printf("%s\n###",reply);
				
		if ( bytes > 0 )
		{
			reply[bytes] = 0;
			//int write_sz = fwrite(buf, sizeof(char), bytes, fr);
			fr.write(reply, bytes);
					
			//int write_sz = fwrite(buf, sizeof(char), bytes, fr);
			//rename(rawname.c_str(),filename.c_str());
		}
		fr.close();
		 
		
        SSL_free(ssl);        /* release connection state */
    
	}
       
    close(server);         /* close socket */
    SSL_CTX_free(ctx);        /* release context */
    return 0;
}
