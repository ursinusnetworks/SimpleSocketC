#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>
#include <arpa/inet.h>

#define BUFSIZE 1024

struct myargs {
    char* ip;
    char* port; // 80 by default
    struct timeval timeout; // 10 (second) by default
};

struct myargs parseArgs(int argc, char** argv) {
    struct myargs ret;
    // Step 1: Setup default values
    ret.ip = "127.0.0.1";
    ret.port = "5800";
    ret.timeout.tv_sec = 10;
    ret.timeout.tv_usec = 0;

    // Step 2: Parse user specified values
    // Advance to the next element
    argv++; 
    argc--; 
    while (argc > 0) {
        if((*argv)[0] == '-') {
            if (strcmp(*argv, "--help") == 0) {
                printf("Usage: ./client");
                printf(" [--ip <ip address of server>]");
                printf(" [--port <port number of server>] [--timeout <timeout>]\n");
                exit(0);
            }
            else if (strcmp(*argv, "--ip") == 0) {
                argv++; argc--;
                if (argc > 0) {
                    ret.ip = *argv;
                }
                else {
                    printf("Error: Expecting field after --ip\n");
                    exit(0);
                }
            }
            else if (strcmp(*argv, "--port") == 0) {
                argv++; argc--;
                if (argc > 0) {
                    ret.port = *argv;
                }
                else {
                    printf("Error: Expecting field after --port\n");
                    exit(0);
                }
            }
        }
        else {
            fprintf(stderr, "Warning: Unrecognized field %s\n", *argv);
        }
        argv++; argc--;
    }

    return ret;
}


int main(int argc, char** argv) {
    struct myargs args = parseArgs(argc, argv);
    // TODO: Fill this in
    
}