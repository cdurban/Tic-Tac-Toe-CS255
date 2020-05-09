/*
 * Project:     Project 8
 * File:        Game.hpp
 * Author:      Chase Urban
 * Due:         Monday, April 27th 2020
 * Description: Header file for Game
 * 
 * A base class for all computer games
 */

#include <cstdlib>
#include <iostream>

#ifndef GAME_HPP
#define GAME_HPP

class Game {
public:
    enum who{HUMAN, COMPUTER, NEUTRAL};
    Game(){numberMoves = 0;};
    /*
     * The human and the machine take turns to play this game
     * Postcondition: A player is returned depending on who is the last player 
     * when the game is over.
     */
    who play();
    
    /*
     * Used to check if the game is over
     */
    virtual bool isGameOver()const=0;
    
    /*
     * Postcondition: Boolean wether the game is tied or not. Should only be 
     * implemented when there is a tie state.
     */
    bool isTied()const{
        return false;
    }
    
    /*
     * Postcondition: A message that describes the game has been displayed at the
     * beginning of the game
     */
    virtual void displayMessage()const=0;
    
    //Displays a message when the game is over.
    void displayMessage2(){
        std::cout << "The game has ended at move number " << numberMoves << ".\n";
    }
    
    /*
     * Postcondition: The computer has made its move
     */
    virtual void computerMove()=0;
    
    /*
     * Postcondition: The human has made its move
     */
    virtual void makeMove()=0;
    
    //Returns the number of moves.
    int getNumberMoves(){return numberMoves;}
    
    /*
     * Destructor
     */
    virtual ~Game(){};
    
     
private:
    int turn; //Decides whose turn it is, also allows for winner to be passed back
protected:
    int numberMoves; //Number of moves made so far.
};

#endif /* GAME_HPP */

