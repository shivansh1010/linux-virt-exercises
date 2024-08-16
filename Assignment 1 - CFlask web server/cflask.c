#include <stdio.h>
#include <stdbool.h>
#include "functions.h"
#include "functionslist.h"

static int request_handler(struct mg_connection *conn) {
    const struct mg_request_info *ri = mg_get_request_info(conn);

    // parser begins
    char param_key[100], param_value[100];
    int keyi = 0, vali = 0;
    bool flag = 0;
    for (int i=0 ; ri->query_string && ri->query_string[i]!='\0' ; i++) {
        if (ri->query_string[i] == '=')
            flag = 1;
        else if (flag)
            param_value[vali++] = ri->query_string[i];
        else
            param_key[keyi++] = ri->query_string[i];
    }
    param_value[vali] = param_key[keyi] = '\0';
    // parser ends

    int list_len = sizeof(urllist)/sizeof(urllistitem);
    for (int i=0 ; i<list_len ; i++) {
        if (!strcmp(ri->local_uri, urllist[i].url)) {
            // printf("url hit %s\n", ri->local_uri);
            char answer[100];
            flist[i](param_key, param_value, answer);
            mg_printf(conn, "HTTP/1.0 200 OK\r\n"
                        "Content-Type: text/plain\r\n\r\n"
                        "%s",
                        answer);
            return 1;
        }
    }
    return 0;
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Run as: ./cflask <port> <number_of_threads>\n");
        return 0;
    }
    struct mg_context *context;
    const char *options[] = {"listening_ports", argv[1], "num_threads", argv[2], NULL};
    struct mg_callbacks callbacks;

    memset(&callbacks, 0, sizeof(callbacks));
    callbacks.begin_request = request_handler;
    context = mg_start(&callbacks, NULL, options);
    getchar();
    mg_stop(context);

    return 0;
}
