#include <stdio.h>
#include <stdbool.h>

// Define a struct to hold the user data
typedef struct {
    char name[100];
} User;

// Function to greet the user
void sayHello() {
    printf("Hello world!\n");
}

// Function to get the user's name
void getName(User *user) {
    printf("Please enter your name: ");
    scanf(" %[^\n]", user->name); // Read the entire line including spaces
}

// Function to confirm the user's name
bool confirmName(User *user) {
    // Allocate space for two characters
    char response[3]; // This way we can see the response is only y or n without additional letters
    while (1) {
        printf("Name is %s. Is that correct? [y/n]: ", user->name);
        scanf(" %2s", response); // Read up to two characters
        while (getchar() != '\n'); // Clear the input buffer
        
        if ((response[0] == 'y' || response[0] == 'Y') && response[1] == '\0') {
            return true; // Return true if response is 'y' or 'Y' and exactly one character long
        } else if ((response[0] == 'n' || response[0] == 'N') && response[1] == '\0') {
            return false; // Return false if response is 'n' or 'N' and exactly one character long
        } else {
            printf("Invalid input. Please enter 'y' or 'n'.\n");
        }
    }
}

int main() {
    User user;
    sayHello();
    
    do {
        getName(&user);
    } while (!confirmName(&user)); // Repeat until the name is confirmed

    printf("Welcome, %s!\n", user.name);

    return 0;
}