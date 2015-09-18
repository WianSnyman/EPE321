/*!	\file Piece header
 	 File: piece.h
 	 Description: This file provides the definition for the Piece class and associated enums.
 	 Author: Noko Rammutla
 	 Created on: 18 September 2015
 	 Date Modified: 18 September 2015
 */

#ifndef PIECE_H_
#define PIECE_H_

#include <vector>;

	class Move;

	enum Piece_Type
	{
		OCEAN,
		ISLAND,
		OPPONENT_PIECE,
		OPPONENT_ADMIRAL,
		ADMIRAL,
		AIRCRAFT_CARRIER,
		HELICOPTER_CARRIER,
		CRUISER,
		DESTROYER,
		CONVOY,
		SUBMARINE,
		MINE,
		MINE_SWEEPER
	};

	enum Colour
	{
		WHITE,
		RED
	};

	class Piece
	{
	private:
		Piece_Type type;
		int x_pos;
		int y_pos;
		int value;
		Colour team;

		bool passable;
		bool jumpable;
		bool combatable;
		bool visible;

	public:
		Piece(Piece_Type type, Colour team, int x_pos, int y_pos);
		virtual ~Piece();
		virtual std::vector<Move> get_valid_moves(const Board_State & board) = 0;
		Colour get_colour();
		virtual int get_attack(Piece & other);
		virtual int get_defance(Piece & other);
	};

	class Board_State
	{
	public:
		virtual Piece * at(int x, int y) = 0;
		virtual std::vector<Piece *> operator[](int index);
		virtual ~Board_State();
	};

	class Ocean : public Piece
	{
	public:
		Ocean(int x, int y);
		std::vector<Move> get_valid_moves(const Board_State & board);
		int get_attack(Piece & other);
		int get_defance(Piece & other);
	};

	class Island : public Piece
	{
	public:
		Island(int x, int y);
		std::vector<Move> get_valid_moves(const Board_State & board);
		int get_attack(Piece & other);
		int get_defance(Piece & other);
	};

	class Opponent : public Piece
	{
	public:
		Opponent(Piece_Type type, Colour team, int x, int y);
		std::vector<Move> get_valid_moves(const Board_State & board);
		int get_attack(Piece & other);
		int get_defance(Piece & other);
	};

	class Admiral : public Piece
	{
	public:
		Admiral(Colour team, int x, int y);
		std::vector<Move> get_valid_moves(const Board_State & board);
		int get_attack(Piece & other);
		int get_defance(Piece & other);
	};

	class Mine : public Piece
	{
	public:
		Mine(Colour team, int x, int y);
		std::vector<Move> get_valid_moves(const Board_State & board);
		int get_attack(Piece & other);
		int get_defance(Piece & other);
	};

	class Mine_Sweeper : public Piece
	{
	public:
		Mine_Sweeper(Colour team, int x, int y);
		std::vector<Move> get_valid_moves(const Board_State & board);
		int get_attack(Piece & other);
		int get_defance(Piece & other);
	};

	class Aircraft_Carrier : public Piece
	{
	public:
		Aircraft_Carrier(Colour team, int x, int y) :
			Piece(AIRCRAFT_CARRIER, team, x, y) {};
	};

	class Helicopter_Carrier : public Piece
	{
	public:
		Helicopter_Carrier(Colour team, int x, int y) :
			Piece(HELICOPTER_CARRIER, team, x, y) {};
	};

	class Cruiser : public Piece
	{
	public:
		Cruiser(Colour team, int x, int y) :
			Piece(CRUISER, team, x, y) {};
	};

	class Destroyer : public Piece
	{
	public:
		Destroyer(Colour team, int x, int y) :
			Piece(DESTROYER, team, x, y) {};
	};

	class Convoy : public Piece
	{
	public:
		Convoy(Colour team, int x, int y) :
			Piece(CONVOY, team, x, y) {};
	};

	class Submarine : public Piece
	{
	public:
		Submarine(Colour team, int x, int y) :
			Piece(SUBMARINE, team, x, y) {};
	};
#endif /* PIECE_H_ */
