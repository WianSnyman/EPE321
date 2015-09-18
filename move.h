/*!	\file Move header
 	 File: piece.h
 	 Description: This file provides the definition for the Move class and associated enums.
 	 Author: Noko Rammutla
 	 Created on: 18 September 2015
 	 Date Modified: 18 September 2015
 */

#ifndef MOVE_H_
#define MOVE_H_

	enum Move_Type
	{
		SAIL,
		COMBAT,
		JUMP
	};

	class Move
	{
	private:
		int x_start;
		int y_start;
		int x_end;
		int y_end;
		Move_Type type;
	public:
		Move(int x_start, int y_start, int x_end, int y_end, Move_Type type) {
			this->x_start = x_start;
			this->y_start = y_start;
			this->x_end = x_end;
			this->y_end = y_end;
			this->type = type;
		}

		int get_x_start() {
			return x_start;
		}

		int get_y_start() {
			return y_start;
		}

		int get_x_end() {
			return x_end;
		}

		int get_y_end() {
			return y_end;
		}

		Move_Type get_type() {
			return type;
		}
	};

	class Invalid_Move_Exception
	{
	private:
		std::string message;
	public:
		Invalid_Move_Exception()
		{
			message = "Invalid Move";
		};

		Invalid_Move_Exception(std::string message)
		{
			this->message = message;
		};

		std::string what()
		{
			return this->message;
		};
	};

#endif /* MOVE_H_ */
