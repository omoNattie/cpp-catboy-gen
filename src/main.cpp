#include <iostream>

#include "modules/getImage.h"

int main() {
    image img = get_image();
    std::cout << "Url: " << img.url << "\n" << "Artist: " << img.artist;

    std::cout << "Made with the catboys.com API.\n";
return 0;    
}