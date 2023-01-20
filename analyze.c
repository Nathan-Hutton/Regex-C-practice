#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdbool.h>

void add_request(int request, int *informational, int *success, int *redirection, int *client_error, int *server_error);

int main(int argc, char *argv[])
{
    long http_total_bytes = 0;
    long https_total_bytes = 0;

    int num_informational = 0;
    int num_success = 0;
    int num_redirection = 0;
    int num_client_error = 0;
    int num_server_error = 0;

    int port_num;
    int request;
    long byte_num;

    while(scanf("%d %d %ld", &port_num, &request, &byte_num) != EOF)
    {
        if(port_num == 80){
            http_total_bytes += byte_num;
        }
        else{
            https_total_bytes += byte_num;
        }

        add_request(request, &num_informational, &num_success, &num_redirection, &num_client_error, &num_server_error);
    }

    printf("Requests\n");
    printf("\t1xx: %d\n", num_informational);
    printf("\t2xx: %d\n", num_success);
    printf("\t3xx: %d\n", num_redirection);
    printf("\t4xx: %d\n", num_client_error);
    printf("\t5xx: %d\n", num_server_error);
    printf("\tTotal: %d\n", num_informational + num_success + num_redirection + num_client_error + num_server_error);

    printf("Bytes transferred:\n");
    printf("\thttp: %ld\n", http_total_bytes);
    printf("\thttps: %ld\n", https_total_bytes);
    printf("\tTotal: %ld\n", http_total_bytes + https_total_bytes);

    return 0;
}

void add_request(int request, int *informational, int *success, int *redirection, int *client_error, int *server_error){
    request /= 100;
    switch(request)
    {
        case(1):
            (*informational)++;
            break;
        case(2):
            (*success)++;
            break;
        case(3):
            (*redirection)++;
            break;
        case(4):
            (*client_error)++;
            break;
        case(5):
            (*server_error)++;
            break;
    }
}


