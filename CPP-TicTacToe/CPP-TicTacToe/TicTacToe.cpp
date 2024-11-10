#include "TicTacToe.h"

#include <iostream>

//constructor
TicTacToe::TicTacToe()
{
    currentPlayer = 'X';
    for (int i = 0; i < 10; i++)
    {
        m_board[i] = ' ';
    }
}

bool TicTacToe::IsGameOver() const
{
    int winCombos[8][3] =
    {
        //horizontal wins
        {0,1,2},
        {3,4,5},
        {6,7,8},
        //vertical wins
        {0,3,6},
        {1,4,7},
        {2,5,8},
        //diagonals
        {0,4,8},
        {2,4,6},
    };
    for (int i = 0; i < 8; i++)
    {
        //win conditions
        if (m_board[winCombos[i][0]] == currentPlayer && m_board[winCombos[i][1]] == currentPlayer &&
            m_board[winCombos[i][2]] == currentPlayer)
        {
            std::cout << currentPlayer << " Wins!";
            return true;
        }      
    }
    //if there is still empty spaces then continue to the next round
    for (int i = 0; i < 9; i++)
    {
        if (m_board[i] == ' ') 
        {
            return false;
        }
    }
    //no empty spaces left and no winning combo 
    //tie conditions
    std::cout << "It's A Tie!";
    return true;
}

 void TicTacToe::TakeTurn() 
 {
     int choice = 0;
     while (true)
     {
         std::cout << "Current Player: " << currentPlayer << "\n";
         std::cout << "Choose posistion (1-9)";
         std::cin >> choice;

         int index = choice - 1;

         if (choice < 1 || choice > 9)
         {
             std::cout << "Invalid Entry! Choose a posistion 1-\n";
         }
         else if (m_board[index] != ' ')
         {
             std::cout << "Posistion already selected! Try Again!\n";
             return ;
         }     
         else
         {
             m_board[index] = currentPlayer;               
             
             //check for winning moves each turn
             if (IsGameOver())
             {
                 break;
             }
            if (currentPlayer == 'X')
            {
                currentPlayer = 'O';
            }
            else
            {
                currentPlayer = 'X';
            }
            break;
         }  
     }   
 }

 void TicTacToe::Display() const
 {   
         //print game board
         std::cout << "   |   |   \n";
         std::cout << " " << m_board[0] << " | " << m_board[1] << " | " << m_board[2] << "\n";
         std::cout << "___|___|___\n";
         std::cout << "   |   |   \n";
         std::cout << " " << m_board[3] << " | " << m_board[4] << " | " << m_board[5] << "\n";
         std::cout << "___|___|___\n";
         std::cout << "   |   |   \n";
         std::cout << " " << m_board[6] << " | " << m_board[7] << " | " << m_board[8] << "\n";
         std::cout << "   |   |   \n";
     
 }
 
	
 