#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Functions
string getUserChoice();
string getComputerChoice();
string findWinner(string user, string comp);
void showFinal(int human, int comp);

int main() {
    srand(time(0)); // seed random once
    int humanScore = 0, compScore = 0;
    string user, comp, winner;

    cout << "Rock, Paper, Scissors Game\n";

    while (true) {
        user = getUserChoice();
        if (user == "quit") break;

        comp = getComputerChoice();
        cout << "Computer chose: " << comp << endl;

        winner = findWinner(user, comp);

        if (winner == "human") {
            humanScore++;
            cout << "You win this round!\n";
        } else if (winner == "computer") {
            compScore++;
            cout << "Computer wins this round!\n";
        } else {
            cout << "Draw round.\n";
        }

        cout << "Score -> You: " << humanScore << "  Computer: " << compScore << "\n\n";
    }

    showFinal(humanScore, compScore);
    return 0;
}

string getUserChoice() {
    string choice;
    while (true) {
        cout << "Enter rock, paper, scissors, or quit: ";
        cin >> choice;
        if (choice == "rock" || choice == "paper" || choice == "scissors" || choice == "quit")
            return choice;
        cout << "Invalid input.\n";
    }
}

string getComputerChoice() {
    int r = rand() % 3; // 0,1,2
    if (r == 0) return "rock";
    if (r == 1) return "paper";
    return "scissors";
}

string findWinner(string user, string comp) {
    if (user == comp) return "draw";
    if ((user == "rock" && comp == "scissors") ||
        (user == "scissors" && comp == "paper") ||
        (user == "paper" && comp == "rock")) {
        return "human";
    }
    return "computer";
}

void showFinal(int human, int comp) {
    cout << "\nFinal Score -> You: " << human << "  Computer: " << comp << endl;
    if (human > comp) cout << "You win the tournament!\n";
    else if (comp > human) cout << "Computer wins the tournament!\n";
    else cout << "Tournament ends in a draw!\n";
}
