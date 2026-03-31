#include <iostream>
#include <string>

// Main function: entry point of the program
int main() {
    // Variable to store user's name
    std::string name;
    
    // Prompt user for input
    std::cout << "Enter your name: ";
    std::cin >> name;
    
    // Output greeting message
    std::cout << "Hello world from @" << name << std::endl;
    
    return 0;
}
