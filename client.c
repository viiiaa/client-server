#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <dirent.h>
#define SIZE 1024
int fcpy(FILE * sourceFile, FILE * destFile);
void send_file(FILE *fp, int sockfd){
	char data[SIZE] = {0};
		
	while(fgets(data, SIZE, fp) != NULL){
		if(send(sockfd, data, sizeof(data), 0) == -1)
		{
			perror("[-]Error in sending data");
			exit(1);
		}
		bzero(data,SIZE);
	}
}

int main()
{
	char *ip = "127.0.0.1";
	int port = 8080;
	int e; 
	int sockfd;
	int clientSocket;
	char  *filename;
	FILE *fp;
	struct sockaddr_in serverAddr;
	//Menu option //
	printf("Do you want to :\n");
	printf("1. Download a file from the server\n");
	printf("2. See all the available files on the server\n");
	printf("3. Delete a file from the server\n");
	int c;
	printf("Please select one file : ");
	scanf("%d",&c);

	while(c < 1 || c > 3 ){
		printf("YOu have enter and invalid choice\n");
		printf("Please enter between [1 - 3]\n");
		scanf("%d",&c);
	}

	if (c == 1){
		printf("You have chose to Download a file from the server\n");
		printf("\n");
		printf("List of Programs on the server : \n");
		printf("1. Add\n");
		printf("2. Substract\n");
		printf("3. Multiplication\n");
		printf("4. Division\n");
		printf("\n");
		printf("All the files are available in: \n");
		printf("1. C programming\n");
		printf("2. Python\n");
		printf("3. C++\n");
		printf("4. BASH Script\n");
		printf("\n");
		printf("Please choose a programming language \n");
		int pchoice;
		scanf("%d",&pchoice);
		printf("Please enter between [1 - 4]\n");
			while(pchoice < 1 || pchoice > 4 )
			{
				printf("You have enter and invalid choice\n");
				printf("Please enter between [1 - 4]\n");
				scanf("%d",&pchoice);
			}
		if (pchoice == 1){
		//C PROGRAMMING//
			printf("You have choose C Programming\n");
			int choice;
			//Choice to download C programming files//
			printf("Please select one file [1 - 4] : ");
			scanf("%d",&choice);
			//Validation of the choice//
			while(choice < 1 || choice > 4 )
			{
				printf("You have enter and invalid choice\n");
				printf("Please enter between [1 - 4]\n");
				scanf("%d",&choice);
			}

			if (choice == 1){
				printf("You have choose Addition\n");
				filename = "add.c";
			}
			else if (choice == 2){
				printf("You have choose Substraction\n");
				filename = "sub.c";
			}
			else if (choice == 3){
				printf("You have choose Multiplication\n");
				filename = "multi.c";
			}
			else if (choice == 4){
				printf("You have choose Division\n");
				filename = "div.c";
			}
			else{
				printf("Invalid input");
			}
		}
		//PYTHON//
		else if (pchoice == 2){
			printf("YOu have choose Python \n");
			int choice;
			//Choice to download Python files//
			printf("Please select one file [1 - 4] : ");
			scanf("%d",&choice);
			while(choice < 1 || choice > 4 )
			{
				printf("You have enter and invalid choice\n");
				printf("Please enter between [1 - 4]\n");
				scanf("%d",&choice);
			}

			if (choice == 1){
				printf("You have choose Addition\n");
				filename = "add.py";
			}
			else if (choice == 2){
				printf("You have choose Substraction\n");
				filename = "sub.py";
			}
			else if (choice == 3){
				printf("You have choose Multiplication\n");
				filename = "multi.py";
			}
			else if (choice == 4){
				printf("You have choose Division\n");
				filename = "div.py";
			}
			else{
				printf("Invalid input");
			}
		}
		//C++//
		else if (pchoice == 3){
			printf("You have choose C++ \n");
			int choice;
			//Choice to download C++ files//
			printf("Please select one file [1 - 4] : ");
			scanf("%d",&choice);
			while(choice < 1 || choice > 4 )
			{
				printf("You have enter and invalid choice\n");
				printf("Please enter between [1 - 4]\n");
				scanf("%d",&choice);
			}

			if (choice == 1){
				printf("You have choose Addition\n");
				filename = "add.cpp";
			}
			else if (choice == 2){
				printf("You have choose Substraction\n");
				filename = "sub.cpp";
			}
			else if (choice == 3){
				printf("You have choose Multiplication\n");
				filename = "multi.cpp";
			}
			else if (choice == 4){
				printf("You have choose Division\n");
				filename = "div.cpp";
			}
			else{
				printf("Invalid input");
			}
		}
		//BASH//
		else if (pchoice == 4){
			printf("You have choose Bash \n");
			int choice;
			//Choice to download BASH files//
			printf("Please select one file [1 - 4] : ");
			scanf("%d",&choice);
			while(choice < 1 || choice > 4 )
			{
				printf("You have enter and invalid choice\n");
				printf("Please enter between [1 - 4]\n");
				scanf("%d",&choice);
			}

			if (choice == 1){
				printf("You have choose Addition\n");
				filename = "add.sh";
			}
			else if (choice == 2){
				printf("You have choose Substraction\n");
				filename = "sub.sh";
			}
			else if (choice == 3){
				printf("You have choose Multiplication\n");
				filename = "multi.sh";
			}
			else if (choice == 4){
				printf("You have choose Division\n");
				filename = "div.sh";
			}
			else{
				printf("Invalid input");
			}
		}
		else{
			printf("Invalid Input");
		}
		
	}
	else if (c == 2){
		printf("You have choose to see all the available files on the server\n");
		filename = "list";
		printf("Run the file received.sh in terminal \n");
	}
	//To delete a file from the server//
	else if (c == 3){
		printf("You have choose delete a file from the server\n"); 
		DIR* dir = opendir(".");
		if(dir == NULL){
			return 1;
		}

		struct dirent* entity;
		entity = readdir(dir);
		while(entity != NULL){
			printf("%s\n", entity->d_name);
			entity = readdir(dir);
		}

		closedir(dir);
		printf("\n");
		FILE *sourceFile;
    		FILE *destFile;
    		char sourcePath[100];
    		char destPath[] = "TRASH";
 int count;


    /* Input path of files to copy */
    printf("Enter the file you want to delete : ");
    scanf("%s", sourcePath);

    /* 
     * Open source file in 'r' and 
     * destination file in 'w' mode 
     */
    sourceFile  = fopen(sourcePath, "r");
    destFile    = fopen(destPath,   "w");

    /* fopen() return NULL if unable to open file in given mode. */
    if (sourceFile == NULL || destFile == NULL)
    {
        /* Unable to open file hence exit */
        printf("\nUnable to open file.\n");
        printf("Please check if file exists and you have read/write privilege.\n");

        exit(EXIT_FAILURE);
    }


    // Call function to copy file
    count = fcpy(sourceFile, destFile);
    printf("\nFiles DELETED successfully.\n");


    /* Finally close files to release resources */
    fclose(sourceFile);
    fclose(destFile);

    		remove(sourcePath);
    		printf("\nYou have delete the file %s",sourcePath);
    		printf("\nYour deleted file is in the TRASH\n");
    		filename = "list";
		printf("Run the file *received* in terminal to see all the files available on the server \n");
    		printf("\n");
		}
	else{
		printf("-");
	}	
	
	//creating client socket//
	sockfd=socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd <0){
		perror("[-]Error in socket");
		exit(1);
	}
	printf("[+]Server socket created\n");
	serverAddr.sin_family=AF_INET;
	serverAddr.sin_port=port;
	serverAddr.sin_addr.s_addr=inet_addr(ip);
	
	e=connect(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	if(e == -1){
		perror("[-]Error in connecting");
		exit(1);
	}
	printf("[+]Conected to the Server successfully\n");
	fp = fopen(filename, "r");	
	if(fp == NULL){
		perror("[-]Error in reading file.");
		exit(1);
	}
	send_file(fp, sockfd);
	printf("[+]File data send successfully.\n");

	close(sockfd);
	printf("[+]Disconnecting from the server.\n");
	return 0;
}

//function copy file//
int fcpy(FILE * sourceFile, FILE * destFile)
{
    int  count = 0;
    char ch;

    /* Copy file contents character by character. */
    while ((ch = fgetc(sourceFile)) != EOF)
    {
        fputc(ch, destFile);

        /* Increment character copied count */
        count++;
    }

    return count;
}
