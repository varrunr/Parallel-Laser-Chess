#ifndef __MOVE_H__
#define __MOVE_H__

class Move
{
	private:

		int src_loc[2];
		int dst_loc[2];
		char type;
		int angle;
		
		bool is_valid_angle();
		bool is_valid_type();
		bool is_valid_loc(int *);
		
		Move();
		Move( char, int, int, int , int , int);
	public:

		bool is_valid();
		bool set_move(int *);
};

#endif
