
struct link_state {
	char source_router;
	int source_tcp_port;
	char destination_router;
	int destination_tcp_port;
	int link_cost;
	int sockfd;
};
