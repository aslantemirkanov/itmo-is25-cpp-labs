#ifndef LAB_2_CURL_CLASS
#define LAB_2_CURL_CLASS
#include <iostream>
#include "curl/curl.h"

class Curl {
private:
    std::string data;

    static size_t Write_Callback(void *ptr, size_t size, size_t nmemb, void *userdata) {
        ((std::string *) userdata)->append((char *) ptr, size * nmemb);
        return size * nmemb;
    }

public:
    Curl() = default;

    Curl(const Curl& other){
        data = other.data;
    }

    Curl& operator=(const Curl&other){
        if (&other == this){
            return *this;
        }
        this->data = other.data;
        return *this;
    }

    void Get_Data_From(const std::string &url) {
        CURL *curl = curl_easy_init();
        CURLcode response;

        if (curl) {
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, Write_Callback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);
            response = curl_easy_perform(curl);
            curl_easy_cleanup(curl);
        }
    }

    [[nodiscard]] const std::string& Get_Str() const {
        return data;
    }

    ~Curl() = default;
};

#endif