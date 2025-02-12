// Rock Paper Scissors P2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//




#include <iostream>
#include <string>
#include <random>

using namespace std;

// Function prototypes
string getPlayerChoice();
string getComputerChoice();
string determineWinner(const string& player, const string& computer);
void updateScore(const string& winner, int& playerScore, int& computerScore);
void displayTournamentWinner(int playerScore, int computerScore);

int main() {
    int playerScore = 0, computerScore = 0;
    string playerChoice, computerChoice, roundWinner;

    cout << "Welcome to Rock, Paper, Scissors Tournament!\n";

    while (true) {
        playerChoice = getPlayerChoice();

        if (playerChoice == "quit") {
            break;
        }

        computerChoice = getComputerChoice();
        cout << "Computer chose: " << computerChoice << endl;

        roundWinner = determineWinner(playerChoice, computerChoice);
        updateScore(roundWinner, playerScore, computerScore);

        cout << "Current Score - You: " << playerScore << " | Computer: " << computerScore << "\n\n";
    }

    displayTournamentWinner(playerScore, computerScore);
    return 0;
}

// Function to get player's choice with validation
string getPlayerChoice() {
    string choice;
    while (true) {
        cout << "Enter 'rock', 'paper', 'scissors', or 'quit' to end tournament: ";
        cin >> choice;

        if (choice == "rock" || choice == "paper" || choice == "scissors" || choice == "quit") {
            return choice;
        }
        cout << "Invalid choice. Please try again.\n";
    }
}

// Function to randomly generate computer's choice
string getComputerChoice() {
    random_device engine;
    uniform_int_distribution<int> dist(1, 3);

    int randChoice = dist(engine);
    if (randChoice == 1) return "rock";
    if (randChoice == 2) return "paper";
    return "scissors";
}

// Function to determine the round winner
string determineWinner(const string& player, const string& computer) {
    if (player == computer) {
        cout << "It's a draw!\n";
        return "draw";
    }
    else if ((player == "rock" && computer == "scissors") ||
        (player == "scissors" && computer == "paper") ||
        (player == "paper" && computer == "rock")) {
        cout << "You win this round!\n";
        return "player";
    }
    else {
        cout << "Computer wins this round!\n";
        return "computer";
    }
}

// Function to update scores
void updateScore(const string& winner, int& playerScore, int& computerScore) {
    if (winner == "player") {
        playerScore++;
    }
    else if (winner == "computer") {
        computerScore++;
    }
}

// Function to display the tournament winner
void displayTournamentWinner(int playerScore, int computerScore) {
    cout << "\nFinal Score - You: " << playerScore << " | Computer: " << computerScore << endl;
    if (playerScore > computerScore) {
        cout << "Congratulations! You won the tournament!\n";
    }
    else if (computerScore > playerScore) {
        cout << "Computer wins the tournament! Better luck next time.\n";
    }
    else {
        cout << "The tournament ends in a draw!\n";
    }
}
