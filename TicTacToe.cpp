/*
 * Project:     Project 8
 * File:        TicTacToe.cpp
 * Author:      Chase Urban
 * Due:         Monday, April 27th 2020
 * Description: Implementation file for TicTacToe, which derives Game
 */

#include <cstdlib>

#include "TicTacToe.hpp"

void TicTacToe::computerMove(){
    int r, c;
    r = (int)(rand()/(double)RAND_MAX * 3);
    c = (int)(rand()/(double)RAND_MAX * 3);
    while(board[r][c] != 0){
        r = (int)(rand()/(double)RAND_MAX * 3);
        c = (int)(rand()/(double)RAND_MAX * 3);
    }
    board[r][c] = 2;
    std::cout << "The computer has taken cell [" << r << ", " << c << "]\n\n";
}

void TicTacToe::makeMove(){
    printBoard();
    std::cout << "\n\nSelect a row and column to take: ";
    int r, c;
    std::cin >> r >> c;
    while(board[r][c] != 0){
        std::cout << "ERROR: Cell Already Taken!\n";
        std::cout << "Select a row and column to take:\n";
        std::cin >> r >> c;
    }
    board[r][c] = 1;
    std::cout << "\nYou have taken cell [" << r << ", " << c << "]\n\n\n";
}

bool TicTacToe::isGameOver()const{
    if(isWon() || isTied())
        return true;
    else
        return false;
}

bool TicTacToe::isWon()const{
    if((0 != board[0][0] && board[0][0] == board[0][1] && board[0][1] == board[0][2]) ||
            (0 != board[1][0] && board[1][0] == board[1][1] && board[1][1] == board[1][2]) ||
            (0 != board[2][0] && board[2][0] == board[2][1] && board[2][1] == board[2][2]) ||
            
            (0 != board[0][0] && board[0][0] == board[1][0] && board[1][0] == board[2][0]) ||
            (0 != board[0][1] && board[0][1] == board[1][1] && board[1][1] == board[2][1]) ||
            (0 != board[0][2] && board[0][2] == board[1][2] && board[1][2] == board[2][2]) ||
            
            (0 != board[0][0] && board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
            (0 != board[2][0] && board[2][0] == board[1][1] && board[1][1] == board[0][2])){
        printBoard();
        return true;
    }
}

bool TicTacToe::isTied()const{
    if(isWon())
        return false;
    if(Game::numberMoves >= 9){
        if(isWon())
            return false;
        else{
            std::cout << "tie??";
            return true;
        }
    }
    else
        return false;
}

void TicTacToe::printBoard()const{
    std::cout << "    0     1     2  \n";
    for(int i = 0; i < 3; i++){
        std::cout << "       |     |     \n";
        std::cout << (i) << "   ";
        for(int j = 0; j < 3; j++){
            switch(board[i][j]){
                case 0: 
                    std::cout << " ";
                    break;
                case 1:
                    std::cout << "x";
                    break;
                case 2:
                    std::cout << "o";
                    break;
            }
            if(j < 2)
                std::cout << "  |  ";
            else
                std::cout << "\n";
        }
        std::cout << "       |     |     \n";
        if(i < 2)
            std::cout << "  -----+-----+-----\n";
    }
}
