#pragma once

#include "Game.h"

class TicTacToe : public Game
{
private:
	char m_board[10] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };		
	char currentPlayer;
	char marker; //x and o

public:
	//constructor
	TicTacToe();
	//destructor
	virtual ~TicTacToe() {}

	//Overrides
	virtual bool IsGameOver() const ;

	virtual void TakeTurn(); 

	virtual void Display() const ;

};