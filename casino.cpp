#include <iostream>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()
using namespace std;

void rules() {
    cout << "\n====== Casino Game Rules ======\n";
    cout << "1. Choose a number between 1 and 10.\n";
    cout << "2. If you win, you will receive 10 times the amount of your bet.\n";
    cout << "3. If you lose, you lose the bet amount.\n";
    cout << "4. You can quit anytime by entering 0 as your bet.\n";
    cout << "================================\n";
}

int main() {
    string playerName;
    int balance;          // Player's starting balance
    int betAmount;
    int guess;
    int dice;             // Casino-generated number

    // Set up random number generator
    srand(time(0));

    cout << "====== Welcome to the Casino Game ======\n";
    cout << "Enter your name: ";
    getline(cin, playerName);
    cout << "Enter your starting balance: $";
    cin >> balance;

    // Show game rules
    rules();

    while (true) {
        cout << "\nYour current balance is $" << balance << "\n";
        
        // Get the player's bet amount
        do {
            cout << "Hey, " << playerName << ", enter bet amount (or 0 to quit): $";
            cin >> betAmount;
            
            if (betAmount > balance) {
                cout << "You cannot bet more than your current balance!\n";
            }
        } while (betAmount > balance);

        if (betAmount == 0) {
            cout << "Thank you for playing! You leave with $" << balance << ".\n";
            break;
        }

        // Player's guess
        cout << "Guess a number between 1 and 10: ";
        cin >> guess;
        if (guess < 1 || guess > 10) {
            cout << "Invalid guess! Please choose a number between 1 and 10.\n";
            continue;
        }

        // Casino rolls the dice
        dice = rand() % 10 + 1;

        // Check if the player won
        if (guess == dice) {
            cout << "Congratulations! You guessed correctly. You win $" << betAmount * 10 << "!\n";
            balance += betAmount * 10;
        } else {
            cout << "Bad luck! The winning number was " << dice << ". You lose $" << betAmount << ".\n";
            balance -= betAmount;
        }

        // Check if the player has run out of money
        if (balance <= 0) {
            cout << "You've run out of money! Game over.\n";
            break;
        }
    }

    cout << "Goodbye, " << playerName << "! You leave with $" << balance << ".\n";
    return 0;
}
