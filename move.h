#ifndef __MOVE_H__
#define __MOVE_H__

class Move
{
	private:

		char src_loc[2];
		char dst_loc[2];
		char type;
		int angle;
	
	public:

		bool is_valid_move();
		bool set_move(char *);
};

#endif


