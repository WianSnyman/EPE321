/*!	\file Piece implementation
 	 File: piece.cpp
 	 Description: This file provides the implementation for the Piece class and subclasses.
 	 Author: Noko Rammutla
 	 Created on: 18 September 2015
 	 Date Modified: 18 September 2015
 */

#include "piece.h"
#include "move.h"
#include <vector>

using namespace std;

Piece::Piece(Piece_Type type, Colour team, int x_pos, int y_pos)
{
	this->type = type;
	this->team = team;
	this->x_pos = x_pos;
	this->y_pos = y_pos;

	this->passable = false;
	this->jumpable = false;
	this->combatable = false;
	this->visible = false;
	this->value = 0;
}

Piece::~Piece()
{

}

std::vector<Move> Piece::get_valid_moves(const Board_State & board)
{
	vector<Move> moves;

	return moves;
}

Colour Piece::get_colour()
{
	return this->team;
}

int Piece::get_attack(Piece & other)
{
	return this->value;
}

int Piece::get_defance(Piece & other)
{
	return this->value;
}

Ocean::Ocean(int x, int y)
{

}

std::vector<Move> Ocean::get_valid_moves(const Board_State & board)
{

}

int Ocean::get_attack(Piece & other)
{

}

int Ocean::get_defance(Piece & other)
{

}

Island::Island(int x, int y)
{

}
std::vector<Move> Island::get_valid_moves(const Board_State & board)
{

}

int Island::get_attack(Piece & other)
{

}

int Island::get_defance(Piece & other)
{

}

Opponent::Opponent(Piece_Type type, Colour team, int x, int y)
{

}

std::vector<Move> Opponent::get_valid_moves(const Board_State & board)
{

}

int Opponent::get_attack(Piece & other)
{

}

int Opponent::get_defance(Piece & other)
{

}

Admiral::Admiral(Colour team, int x, int y)
{

}

std::vector<Move> Admiral::get_valid_moves(const Board_State & board)
{

}

int Admiral::get_attack(Piece & other)
{

}

int Admiral::get_defance(Piece & other)
{

}

Mine::Mine(Colour team, int x, int y)
{

}

std::vector<Move> Mine::get_valid_moves(const Board_State & board)
{

}

int Mine::get_attack(Piece & other)
{

}

int Mine::get_defance(Piece & other)
{

}

Mine_Sweeper::Mine_Sweeper(Colour team, int x, int y)
{

}

std::vector<Move> Mine_Sweeper::get_valid_moves(const Board_State & board)
{

}

int Mine_Sweeper::get_attack(Piece & other)
{

}

int Mine_Sweeper::get_defance(Piece & other)
{

}
