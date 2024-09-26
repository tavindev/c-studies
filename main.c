// Server side C program to demonstrate Socket
// programming
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include "server.h"
#include <pthread.h>
#include <sys/types.h>

#define ARENA_IMPLEMENTATION
#include "arena.h"

#define BUFFER_SIZE 2048

typedef struct
{
	int *fd;
	pthread_t thread;
} handle_client_args;

void *handle_client(void *arg)
{
	int client_fd = *(int *)arg;
	char buffer[BUFFER_SIZE];

	printf("Client fd %d\n", client_fd);

	ssize_t bytes_received = recv(client_fd, &buffer, BUFFER_SIZE, MSG_WAITALL);

	if (bytes_received > 0)
	{
		printf("%s\n", buffer);
	}

	send(client_fd, buffer, BUFFER_SIZE, MSG_EOR);

	close(client_fd);
	free(arg);

	return NULL;
}

int main(int argc, char const *argv[])
{
	printf("Server pid %d\n", getpid());
	int server_fd;
	ssize_t valread;
	struct sockaddr_in address;
	int opt = 1;
	socklen_t addrlen = sizeof(address);

	// Creating socket file descriptor
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("socket failed");
		exit(EXIT_FAILURE);
	}

	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)))
	{
		perror("setsockopt");
		exit(EXIT_FAILURE);
	}

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	// Forcefully attaching socket to the port 8080
	if (bind(server_fd, (struct sockaddr *)&address,
					 sizeof(address)) < 0)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	if (listen(server_fd, 10) < 0)
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		struct sockaddr_in client_addr;
		socklen_t client_addr_num = sizeof(client_addr);
		int *client_fd = malloc(sizeof(int));

		if ((*client_fd = accept(server_fd, (struct sockaddr *)&address,
														 &addrlen)) < 0)
		{
			perror("accept");
			exit(EXIT_FAILURE);
		}

		printf("Accepted new connection from\n");

		pthread_t thread_id;
		pthread_create(&thread_id, NULL, handle_client, (void *)client_fd);
		pthread_detach(thread_id);
	}

	return 0;
}
