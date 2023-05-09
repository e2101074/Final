#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "appdev.h"
#include <curl/curl.h>

void send_data(rock r) {
    CURL* curl;
    CURLcode res;
    char poststr[100]; //100 charcters should be enough for three values
    //prepare post data
    sprintf(poststr, "min=%d&max=%d&user=%s", r.min, r.max, r.rname);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.cc.puv.fi/~e2101074/adddev.php");
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, poststr);
        /*
         * perform the request res will get the return code*/
        res = curl_easy_perform(curl);
        //check for errors
        if (res != CURLE_OK) {
            fprintf(stderr, "curl easy perform failed: %s\n", curl_easy_strerror(res));
            curl_easy_cleanup(curl);
        }
    }
}