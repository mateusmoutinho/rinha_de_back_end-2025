//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../imports/imports.fdeclare.h"
//silver_chain_scope_end

CwebHttpResponse *payments_route(CwebHttpRequest *request){
    cJSON *body = CWebHttpRequest_read_cJSON(request,2000);
    if(!body){
        return cweb_send_text("Invalid JSON", 400);
    }
    cJSON *amount_item = cJSON_GetObjectItem(body, "amount");
    if(amount_item == NULL || amount_item->type != cJSON_Number){
        return cweb_send_text("Invalid or missing 'amount' field", 400);
    }
    cJSON *currency_item = cJSON_GetObjectItem(body, "currency");
    if(currency_item == NULL || currency_item->type != cJSON_String){
        return cweb_send_text("Invalid or missing 'currency' field", 400);
    }

    double amount = amount_item->valuedouble;
    char *currency = currency_item->valuestring;

    long now = time(NULL);
    char *now_in_unix = dtw_convert_unix_time_to_string(now);
    printf("%s\n", now_in_unix);

    
    return cweb_send_text("Payment processed successfully", 200);
}