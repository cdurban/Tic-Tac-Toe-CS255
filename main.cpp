/*
 * Project:     Project 8
 * File:        main.cpp
 * Author:      Chase Urban
 * Due:         Monday, April 27th 2020
 * Description: main class for project 8
 */

#include <cstdlib>
#include "TicTacToe.hpp"

using namespace std;

int main(int argc, char** argv) {

    Game* g = new TicTacToe();
    Game::who w = g->play();
    if(w == Game::COMPUTER)
        cout << "Sorry! The computer wins the game!\n";
    else if(w == Game::HUMAN)
        cout << "Congratulations! You win the game!\n";
    else if(w == Game::NEUTRAL)
        cout << "Uh oh! The game has ended in a tie!\n";
    
    return 0;
}

