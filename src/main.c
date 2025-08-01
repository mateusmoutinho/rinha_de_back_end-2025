//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "imports/imports.fdefine.h"
//silver_chain_scope_end

int main(int argc,char *argv[]){
   
    if (argc != 2){
        printf("Usage: rinha (server or payment_verifier) \n");
        return 1;
    }
    char *mode = argv[1];
    if (strcmp(mode, "server") == 0){
        start_main_server();
    } else if (strcmp(mode, "payment_verifier") == 0){
        start_payment_verifier();
    } else {
        printf("Invalid mode. Use 'server' or 'payment_verifier'.\n");
        return 1;
    }
}