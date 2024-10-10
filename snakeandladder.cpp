#include <iostream>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()
#include <map>
using namespace std;

// Function to roll a dice (returns a number between 1 and 6)
int rollDice() {
    return (rand() % 6) + 1;
}

// Function to initialize the board with snakes and ladders
void initializeBoard(map<int, int> &snakes, map<int, int> &ladders) {
    // Define snakes: key = start position, value = end position
    snakes[16] = 6;
    snakes[47] = 26;
    snakes[49] = 11;
    snakes[56] = 53;
    snakes[62] = 19;
    snakes[64] = 60;
    snakes[87] = 24;
    snakes[93] = 73;
    snakes[95] = 75;
    snakes[98] = 78;

    // Define ladders: key = start position, value = end position
    ladders[1] = 38;
    ladders[4] = 14;
    ladders[9] = 31;
    ladders[21] = 42;
    ladders[28] = 84;
    ladders[36] = 44;
    ladders[51] = 67;
    ladders[71] = 91;
    ladders[80] = 100;
}

int main() {
    srand(time(0));  // Seed random number generator

    // Create board maps for snakes and ladders
    map<int, int> snakes;
    map<int, int> ladders;
    initializeBoard(snakes, ladders);

    int playerPosition = 0;

    cout << "====== Welcome to Snake and Ladder Game ======\n";
    cout << "Start at position 0 and reach position 100 to win!\n";
    cout << "Ladders help you climb up, and snakes bring you down.\n";
    cout << "==============================================\n";

    while (playerPosition < 100) {
        cout << "\nPress 'r' to roll the dice: ";
        char roll;
        cin >> roll;
        
        if (roll != 'r' && roll != 'R') {
            cout << "Invalid input! Please press 'r' to roll the dice.\n";
            continue;
        }

        int diceRoll = rollDice();
        cout << "You rolled a " << diceRoll << "!\n";
        
        // Move the player
        int newPosition = playerPosition + diceRoll;
        
        // Check if the new position is within bounds
        if (newPosition > 100) {
            cout << "Roll exceeded the final position 100. Stay at position " << playerPosition << ".\n";
            continue;
        }

        // Check for snakes or ladders
        if (snakes.find(newPosition) != snakes.end()) {
            cout << "Oh no! You landed on a snake at " << newPosition << ". Slipping down to " << snakes[newPosition] << ".\n";
            newPosition = snakes[newPosition];
        } else if (ladders.find(newPosition) != ladders.end()) {
            cout << "Great! You landed on a ladder at " << newPosition << ". Climbing up to " << ladders[newPosition] << ".\n";
            newPosition = ladders[newPosition];
        } else {
            cout << "You moved to position " << newPosition << ".\n";
        }

        playerPosition = newPosition;
    }

    cout << "\nCongratulations! You've reached position 100 and won the game!\n";
    return 0;
}
