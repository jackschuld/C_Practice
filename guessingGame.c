#include <stdio.h>
#include <stdbool.h>

typedef struct {
    char name[25];
} User;

void getName(User *user) {
    printf("Hello! What's your name? ");
    scanf(" %[^\n]", user->name);
}

bool isConfirmed(User *user) {
    char response[3];
    printf("Is %s correct? ", user->name);
    scanf(" %2s", response);
    while (getchar() != '\n');
    if ((response[0] == 'y' || response[0] == 'Y') && response[1] == '\0') {
        return true; // Return true if response is 'y' or 'Y' and exactly one character long
    } else if ((response[0] == 'n' || response[0] == 'N') && response[1] == '\0') {
        return false; // Return false if response is 'n' or 'N' and exactly one character long
    } else {
        printf("Invalid input. Please enter 'y' or 'n'.\n");
    }
}


int main() {
    User user;
    do {
        getName(&user);
    } while (!isConfirmed(&user));
    printf("Hello %s!", user.name);
}

