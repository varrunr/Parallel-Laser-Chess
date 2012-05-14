#ifndef __MOVE_H__
#define __MOVE_H__

namespace mv
{
	class Move
	{
		public:

			int src_x , src_y;
			int dst_x , dst_y;
			char type;
			int angle;
			
			bool is_valid_angle();
			bool is_valid_type();
			bool loc_is_valid();
			
			Move();
			Move( char, int, int, int , int , int);
			
			Move& operator = (const Move&);		
			bool is_valid();
			bool set_move(int *);
	};
}
#endif
