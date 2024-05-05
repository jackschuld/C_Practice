#include <iostream>
#include <string>
#include <limits>

class User {
private:
    std::string name;

public:
    // Constructor
    User() {}

    // Method to set the user's name
    void setName(const std::string& newName) {
        name = newName;
    }

    // Method to get the user's name
    std::string getName() const {
        return name;
    }

    // Method to confirm the user's name
    bool confirmName() const {
        std::string response;
        while (true) {
            std::cout << "Name is " << name << ". Is that correct? [y/n]: ";
            std::cin >> response;
            if (response.length() == 1 && (response[0] == 'y' || response[0] == 'Y')) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
                return true;
            } else if (response.length() == 1 && (response[0] == 'n' || response[0] == 'N')) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
                return false;
            } else {
                std::cout << "Invalid input. Please enter 'y' or 'n'.\n";
                std::cin.clear(); // Clear error flags
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
            }
        }
    }
};

int main() {
    User user;
    std::string name;

    std::cout << "Hello world!\n";

    do {
        std::cout << "Please enter your name: ";
        std::getline(std::cin, name);
        user.setName(name);
    } while (!user.confirmName());

    std::cout << "Welcome, " << user.getName() << "!\n";

    return 0;
}
