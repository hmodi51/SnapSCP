#include <libssh/libssh.h>
#include <stdlib.h>
#include <stdio.h>


int main(int argc , char*argv[])
{

    char*password;

    if(argc < 3){
        printf("not enough args\n");
        exit(-1);
    }
   ssh_session mysession = ssh_new();
   if(mysession == NULL){
    exit(-1);
   }
   char* host = argv[2];
   char* user = argv[1];
   printf("%s\n" , host);
   printf("%s\n" , user);
   int port = 22;
   ssh_options_set(mysession , SSH_OPTIONS_HOST , host);
   ssh_options_set(mysession , SSH_OPTIONS_USER , user);
   ssh_options_set(mysession , SSH_OPTIONS_PORT , &port);
   int connect =  ssh_connect(mysession);
   if(connect == SSH_ERROR){
    printf("connection failed");
    exit(-1);
   }
   printf("%d\n" , SSH_OK);
   password = getpass("Password: ");
   int authStatus = ssh_userauth_password(mysession , user , password);
   if(authStatus != SSH_AUTH_SUCCESS){
    printf("authentication failed\n");
    exit(-1);
   }
   printf("%d\n" , SSH_AUTH_SUCCESS );
   

   
} 
