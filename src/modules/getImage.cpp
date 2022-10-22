#include <iostream>
#include <chrono>
#include <thread>

#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

#include "getImage.h"
#include "clear.h"

image get_image() {
    std::string url;
    std::string artist;

    try {
        std::cout << "Fetching image..." << std::endl;
        cpr::Response response = cpr::Get(cpr::Url{ "https://api.catboys.com/img" });

        if(response.status_code == 0) {
            std::cerr << "FAIL" << std::endl;
            std::cerr << response.error.message << std::endl; 
        } else if(response.status_code >= 400) {
            std::cerr << "FAIL" << std::endl;
            std::cerr << response.status_code << " Something went massively wrong." << std::endl;
        } else {
            std::cout << "DONE" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
            clear();

            nlohmann::json parser = nlohmann::json::parse(response.text);
            std::cout << "Parsing API..." << std::endl;

            url = parser["url"].get<std::string>();
            artist = parser["artist"].get<std::string>();

            std::cout << "URL: OK" << std::endl;

            std::this_thread::sleep_for(std::chrono::milliseconds(500));

            if(artist == "unknown" || artist.find("?") == 0) {
                std::cout << "ARTIST: NIL" << std::endl;
            } else {
                std::cout << "ARTIST: OK" << std::endl;
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(1200));
            clear();
        }
    } catch (const std::exception& e) {
        std::ofstream stream("src/modules/log.txt", std::ios::out | std::ios::app);

        if(stream.is_open()) {
            std::cerr << "Something went wrong, please check the log file in the module folder." << std::endl;
            stream << e.what() << std::endl;
        
            stream.close();            
        }

    }

return (image) {.url = url, .artist = artist};    
}