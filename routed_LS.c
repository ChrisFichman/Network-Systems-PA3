#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>   /* memset() */
#include <sys/time.h> /* select() */
#include <signal.h>
#include <unistd.h>
#include <errno.h>
#include <math.h>
#include <string.h>
//#include <ctype.h>

#define USAGE "./routed_LS <RouterID> <LogFileName> <Initialization file>"

int main(int argc, char *argv[]) {
	if (argc != 4)
	{
		fprintf(stderr, "Incorrect number of arguments. Usage should be:\n %s\n", USAGE);
		return EXIT_FAILURE;
	}
	
	//routerID argv[1]
	char* routerID = argv[1];
	
	//LogFileName argv[2]
	FILE* log_file;
	log_file = fopen(argv[2], "w+");
	if(log_file == NULL)
	{
		fprintf(stderr, "Log file %s could not be opened.\n", argv[2]);
		return EXIT_FAILURE;
	}
	
	//Initialization File argv[3]
	FILE* initialization_file;
	initialization_file = fopen(argv[3], "r");
	if(initialization_file == NULL)
	{
		fprintf(stderr, "Initialization file %s could not be opened.\n", argv[3]);
		return EXIT_FAILURE;
	}
	
	// Parse the initialization file.
	// File format: <source router, source TCP port, destination router, destination TCP port, link cost>
	//<A,9701,B,9704,4>
	
	char source_router = "Z";
	int source_tcp_port = -999;
	char destination_router = "Z";
	int destination_tcp_port = -999;
	int link_cost = -999;
	
	fprintf(stderr, "Sup?\n");
	
	while ( fscanf(initialization_file, "<%c,%d,%c,%d,%d>\n", &source_router, &source_tcp_port, &destination_router, &destination_tcp_port, &link_cost) != EOF) 
	{
		
		printf("<%c,%d,%c,%d,%d>\n", source_router, source_tcp_port, destination_router, destination_tcp_port, link_cost);
		sleep(5);
	}
	
	
	
	
	return EXIT_SUCCESS;
}
