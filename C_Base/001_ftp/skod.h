/* skod.h - headers and global stuff */

#ifndef SKOD_H
#define SKOD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <stdarg.h>
#include <signal.h>
#include <ctype.h>
#include <sys/stat.h>

#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#include <getopt.h>

#pragma comment(lib,"ws2_32.lib")
//#pragma comment(lib,"subst.lib")
#define close(X) closesocket(X);WSACleanup()
#define WINSOCK_INIT WORD socket_version;WSADATA wsadata;socket_version=MAKEWORD(2,2);if(WSAStartup(socket_version, &wsadata) != 0){printf("wsastartup error !");return;}
#define socklen_t int

#else

#include <unistd.h>
#include <getopt.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#endif

#define MAX_STR	256
#define FD_MODE	"r+"
#define PACKAGE_VERSION "v1.0.0"

#include "utils.h"
#include "tcp.h"
#include "ftp.h"

char ip[MAX_STR];
enum { False=0, True=1 };

/* fot socket */
int fd;
int dfd;

/* Flags */
int flag;
int ipv4;
int ipv6;

/* types */
typedef struct {
	char *user;
	char *password;
	char *server;
	char *port;
	char *path;
	char *os;
	char *prod;
	char *dest;
} skod_t;

/* prototypes */
unsigned long skod_checksum(char*);
void skod_detect_ip(void);

#endif /*skod_H*/
