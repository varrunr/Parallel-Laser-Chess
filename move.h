#ifndef __MOVE_H__
#define __MOVE_H__

class Move
{
	private:

		char src_loc[2];
		char dst_loc[2];
		char type;
		int angle;
		
		bool is_valid_angle();
		bool is_valid_type();
		bool is_valid_loc(char *);

	public:

		bool is_valid();
		bool set_move(char *);
};

#endif