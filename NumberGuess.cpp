#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <fstream>
#include <limits>
#include <chrono>
#include <cmath>
#include <iomanip>

using namespace std;
using Clock = chrono::steady_clock;

struct HighScore {
    int attempts = 0;
    double seconds = 0.0;
};

HighScore load_highscore(const string &filename) {
    HighScore hs;
    ifstream in(filename);
    if (!in) return hs;
    in >> hs.attempts >> hs.seconds;
    return hs;
}

void save_highscore(const string &filename, const HighScore &hs) {
    ofstream out(filename);
    if (!out) return;
    out << hs.attempts << ' ' << fixed << setprecision(3) << hs.seconds << '\n';
}

int get_integer_input(const string &prompt, int minVal = numeric_limits<int>::min(),
                      int maxVal = numeric_limits<int>::max()) {
    int x;
    while (true) {
        cout << prompt;
        if (cin >> x) {
            if (x < minVal || x > maxVal) {
                cout << "Please enter a number between " << minVal << " and " << maxVal << ".\n";
                continue;
            }
            return x;
        } else {
            cout << "Invalid input — please enter an integer.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

char get_yesno(const string &prompt) {
    char c;
    while (true) {
        cout << prompt;
        if (cin >> c) {
            if (c == 'y' || c == 'Y' || c == 'n' || c == 'N') return c;
        }
        cout << "Please enter 'y' or 'n'.\n";
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    const string hsFile = "guess_highscore.txt";

    cout << "=== Number Guessing Deluxe ===\n";

    while (true) {
        cout << "\nChoose difficulty:\n"
             << "  1) Easy   (1-20)\n"
             << "  2) Medium (1-100)\n"
             << "  3) Hard   (1-1000)\n"
             << "  4) Custom range\n";
        int choice = get_integer_input("Enter choice (1-4): ", 1, 4);

        int maxRange = 100;
        switch (choice) {
            case 1: maxRange = 20; break;
            case 2: maxRange = 100; break;
            case 3: maxRange = 1000; break;
            case 4: {
                maxRange = get_integer_input("Enter the maximum number (>= 10): ", 10, 1000000);
                break;
            }
        }

        // Optional attempt limit
        char useLimit = get_yesno("Use attempt limit? (y/n): ");
        int attemptLimit = 0;
        if (useLimit == 'y' || useLimit == 'Y') {
            attemptLimit = get_integer_input("Enter max attempts (>=1): ", 1, 1000000);
        }

        // Build secret
        int secret = rand() % maxRange + 1;
        vector<int> guesses;
        int attempts = 0;

        cout << "\nI'm thinking of a number between 1 and " << maxRange << ". Good luck!\n";
        auto startTime = Clock::now();
        int prevDiff = -1;

        while (true) {
            int guess = get_integer_input("Enter your guess: ", 1, maxRange);
            attempts++;
            guesses.push_back(guess);
            int diff = abs(secret - guess);

            // Give relative warm/cold hint (compared to previous guess)
            if (guess == secret) {
                auto duration = chrono::duration_cast<chrono::duration<double>>(Clock::now() - startTime);
                double seconds = duration.count();
                cout << "\n🎉 You got it! The number was " << secret << ".\n";
                cout << "Attempts: " << attempts << " | Time: " << fixed << setprecision(2) << seconds << "s\n";

                // Very close message if last guess was within small range
                if (diff == 0 && guesses.size() >= 1) {
                    // If second-to-last exists, maybe praise
                    cout << "Nice finish!\n";
                }

                // Show guesses
                cout << "Your guesses: ";
                for (size_t i = 0; i < guesses.size(); ++i) {
                    cout << guesses[i] << (i + 1 < guesses.size() ? ", " : "\n");
                }

                // Load highscore and update if better (fewer attempts OR same attempts but faster)
                HighScore hs = load_highscore(hsFile);
                bool improved = false;
                if (hs.attempts == 0) {
                    improved = true;
                } else if (attempts < hs.attempts) {
                    improved = true;
                } else if (attempts == hs.attempts && seconds < hs.seconds) {
                    improved = true;
                }

                if (improved) {
                    cout << "New high score! Saving your result.\n";
                    HighScore newHs;
                    newHs.attempts = attempts;
                    newHs.seconds = seconds;
                    save_highscore(hsFile, newHs);
                } else {
                    if (hs.attempts != 0) {
                        cout << "Current high score: " << hs.attempts << " attempts in "
                             << fixed << setprecision(2) << hs.seconds << "s\n";
                    }
                }

                break;
            }

            // Not correct — provide hints
            if (diff <= max(1, maxRange / 20)) { // very close threshold proportional to range
                cout << "🔥 Very close! You're within " << diff << " of the number.\n";
            } else if (diff <= max(5, maxRange / 10)) {
                cout << "🙂 Close — keep trying.\n";
            } else {
                cout << "Not close yet.\n";
            }

            if (prevDiff != -1) {
                if (diff < prevDiff) cout << "Warmer than your previous guess.\n";
                else if (diff > prevDiff) cout << "Colder than your previous guess.\n";
                else cout << "Same distance as your previous guess.\n";
            }

            prevDiff = diff;

            // Show a quick summary of previous guesses (last 10)
            cout << "Previous guesses (" << guesses.size() << "): ";
            size_t startIdx = (guesses.size() > 10) ? guesses.size() - 10 : 0;
            for (size_t i = startIdx; i < guesses.size(); ++i) {
                cout << guesses[i] << (i + 1 < guesses.size() ? ", " : "\n");
            }

            // Attempts left if limit enabled
            if (attemptLimit > 0) {
                int left = attemptLimit - attempts;
                if (left <= 0) {
                    cout << "\n⛔ You've used all your attempts. The number was " << secret << ".\n";
                    break;
                } else {
                    cout << "Attempts left: " << left << "\n";
                }
            }
        }

        char again = get_yesno("\nPlay again? (y/n): ");
        if (again == 'n' || again == 'N') {
            cout << "Thanks for playing — bye!\n";
            break;
        }
    }

    return 0;
}
