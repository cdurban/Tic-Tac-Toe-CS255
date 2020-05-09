/*
 * Project:     Project 8
 * File:        TicTacToe.hpp
 * Author:      Chase Urban
 * Due:         Monday, April 27th 2020
 * Description: Header file for TicTacToe, which derives Game
 */

#include <cstdlib>

#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#include "Game.hpp"

class TicTacToe:public Game{
public:
    /*
     * Constructor, constructs dynamic array
     */
    TicTacToe(){  
        for(int i = 0; i < 3; i++)
            board[i] = new int[3];
    }
    
    /*
     * Displays the start message
     */
    virtual void displayMessage()const{
    Game::displayMessage();
    std::cout << "Tic Tac Toe!\n"
            << "Your goal is to create a line of three cells\n"
            << "in a row. Choose a cell by entering the values\n"
            << "of the column and the row of the cell you want\n"
            << "to select.\n\n";
    }
    
    /*
     * Makes a move for the computer
     */
    virtual void computerMove();
    
    /*
     * Prompts the user to make a move
     */
    virtual void makeMove();
    
    /*
     * Checks to see if the game is over
     */
    virtual bool isGameOver()const;
    
    /*
     * Checks to see if the game is in a win state
     */
    bool isWon()const;
    
    /*
     * Checks to see if the game is in a tie state
     */
    bool isTied()const;
    
    /*
     * Prints the board out 
     */
    void printBoard()const;
    
    /*
     * Destructor
     */
    virtual ~TicTacToe(){
        for(int i = 0; i < 3; i++)
            delete[] board[i];
        delete[] board;
    }
    
private:
    int** board = new int*[3]; //Game board
};

#endif /* TICTACTOE_HPP */

