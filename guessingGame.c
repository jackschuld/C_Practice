#include <stdio.h>
#include <stdbool.h>

typedef struct {
    char name[25];
} User;

typedef struct {
    int answer;
} Game;

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

void runIntro(User *user) {
    sayHello();
    do {
        getName(user);
    } while (!confirmName(user)); // Repeat until the name is confirmed
    printf("Welcome, %s!\n", user->name);
}

int main() {
    User user;
    Game game;

    runIntro(&user);

    return 0;
}