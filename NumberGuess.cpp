#include <iostream>
#include <cstdlib>   // for rand(), srand()
#include <ctime>     // for time()
using namespace std;

int main() {
    // Seed random number generator with current time
    srand(static_cast<unsigned int>(time(nullptr)));

    int maxRange = 100;          // change this to make it harder/easier
    int secret = rand() % maxRange + 1; // random number in [1, maxRange]
    int guess = 0;
    int attempts = 0;

    cout << "Welcome to Number Guessing! I'm thinking of a number between 1 and " 
         << maxRange << ".\n";

    while (true) {
        cout << "Enter your guess: ";
        if (!(cin >> guess)) {            // handle non-number input
            cout << "Please enter a valid integer.\n";
            cin.clear();                 // clear error
            cin.ignore(10000, '\n');     // skip bad input
            continue;
        }
        attempts++;

        if (guess == secret) {
            cout << "🎉 Correct! You guessed the number in " << attempts << " attempts.\n";
            break;
        } else if (guess < secret) {
            cout << "Too low. Try again.\n";
        } else {
            cout << "Too high. Try again.\n";
        }
    }

    // Ask to play again
    char playAgain;
    cout << "Play again? (y/n): ";
    cin >> playAgain;
    if (playAgain == 'y' || playAgain == 'Y') {
        cout << "Restart the program to play again — or I can modify it to loop automatically.\n";
    } else {
        cout << "Thanks for playing! Goodbye.\n";
    }

    return 0;
}
