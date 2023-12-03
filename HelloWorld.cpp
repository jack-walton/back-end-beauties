#include <iostream>
#include <string>

int main() {
    std::cout << "Hello, YOU!" << std::endl << std::endl;
    std::cout << "What's YOUR name?" << std::endl;
    
    std::string name;
    std::getline(std::cin, name);
    
    std::cout << std::endl;
    std::cout << "Ah, I see. So your name is " << name << ". I guess that's an okay name." << std::endl;

    return 0;
}