/*
 * Project:     Project 8
 * File:        Game.cpp
 * Author:      Chase Urban
 * Due:         Monday, April 27th 2020
 * Description: Implementation file for Game
 */

#include "Game.hpp"

void Game::displayMessage()const{
    std::cout << "Welcome to our great game: ";
}

Game::who Game::play(){
    //Determine who starts first
    srand((unsigned)time(NULL));
    turn = (int)(0.5 + rand()/(double)RAND_MAX);
    displayMessage();
    std::cout << ((turn == 0)?"Computer goes":"You go") << " first:\n";
    
    while(true){
        numberMoves++;
        if(turn == 0)
            computerMove();
        else
            makeMove();
        
        if(isGameOver()){
            if(isTied()){
                displayMessage2();
                return NEUTRAL;
            }
            else if(turn == 0){
                displayMessage2();
                return COMPUTER;
            }   
            else if(turn == 1){
                displayMessage2();
                return HUMAN;
            } 
        }
        turn = (1 + turn) % 2;
    }
}