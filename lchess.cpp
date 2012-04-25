#include<vector>
#include<iostream>
#include "constants.h"
#include "piece.h"
#include "board.h"
#include "lchess.h"
//std::vector< coordinate > get_next_move ( Board & , Piece& );

void fire( Piece &laser , Board &board , int angle)
{
	bool x_dir , y_dir; 
	Piece pc;
	if( angle == 90 || angle == 270 )
	{
		// Iterate in x direction
		// pc = first non null entry
        x_dir = true;
	}
	else
	{
		// Iterate in y direction
		// pc = first non null entry
		y_dir = true;
	}	
	if(x_dir == false && y_dir == false)
    {
		// Out of bounds 
        return;
	}

    int face_angle = pc.get_angle();
    int new_angle = 0;
	
	switch (pc.type)
	{
		case Piece::DiaMirror:
	    {		
			if(x_dir)
			{
				if(face_angle  == 0 || face_angle == 180)
				{
					if(angle == 270) new_angle = 0;      // +y 
					if(angle == 90)  new_angle = 180;    // -y
				}
				if(face_angle == 90 || face_angle == 270)
				{
					if(angle == 270) new_angle = 180;   // -y
					if(angle == 90)  new_angle = 0 ;    // +y
				}
			}
			if(y_dir)
			{
				if(face_angle == 0 || face_angle == 180)
				{
					if(angle == 0)   new_angle = 90 ;   // -x
					if(angle == 180) new_angle = 270;   // +x
				}
				if(face_angle == 90 || face_angle == 270)
				{
					if(angle == 0)   new_angle = 270;   // +x
					if(angle == 180) new_angle = 90;    //  -x
				}
			}
			fire(pc , board, new_angle);
			break;
    	}
        case Piece::StrMirror:
        {
			if( angle == 90 || angle == 270)
		    {
			    new_angle = 360 - face_angle;
		    }
		    else 
            {
                new_angle = 180 - face_angle;
		    }
		    fire( pc, board, new_angle);
	        break;
        }
        case Piece::TriMirror:
        {
			if(x_dir)
			{
				if(face_angle == 0)
				{
					if(angle == 270) new_angle = 0; // +y 
					if(angle == 90) 
                    {
                        board.destroy(pc);
                        return;
                    }
				}

				if(face_angle == 180 )
				{
					if(angle == 270) 
                    {
                        board.destroy(pc);
                        return;
                    }
					if(angle == 90) new_angle = 180; // -y
				}

				if( face_angle == 90)
				{
					if(angle == 270) new_angle = 180;
					if(angle == 90 ) 
                    {
                        board.destroy(pc);
                        return;
                    }
                }
				
				if(face_angle == 270)
				{
					if(angle == 270)
                    {
                        board.destroy(pc);
                        return;
                    }
					if(angle == 90) new_angle = 0;
				}
				fire(pc , board , new_angle);

			}

			if(y_dir)
			{
				if(face_angle == 0)
				{
					if(angle == 0) new_angle = 90; // -x 
					if(angle == 180)
                    {
                        board.destroy(pc);
                        return;
                    }
				}

				if(face_angle == 180 )
				{
					if(angle == 0)
                    {
                        board.destroy(pc);
                        return;
                    }
					if(angle == 180) new_angle = 270; // +x
				}

				if(face_angle == 90)
				{
					if(angle == 180) new_angle = 90;
					if(angle == 0 )
                    {
                        board.destroy(pc);
                        return;
                    }
				}

				if(face_angle == 270)
				{
					if(angle == 180)
                    {
                        board.destroy(pc);
                        return;
                    }
					if(angle == 0) new_angle = 270;
				}
				fire(pc , board , new_angle);
			}
            break;
		}
        case Piece::Block:
		{
			if( (angle - face_angle) == 180) 
                new_angle = face_angle;
			else
            {
                board.destroy(pc);
                return;
            }
			fire(pc , board , new_angle);
            break;
		}
        case Piece::King:
		{
			board.destroy(pc);
            return;
		}
        case Piece::Hcube:
		{
			break;
		}
        case Piece::Hhole:
        {
            break;
        }
        case Piece::Bsplitter:
		{
			if(face_angle == angle) 
            {
                board.destroy(pc);
            }
			if(face_angle == 0 || face_angle == 180)
			{
				new_angle = face_angle;
				fire(pc , board , new_angle);
			}
			else
			{
				int new_angle1 = (angle - 90) % 360;
				int new_angle2 = (angle + 90) % 360;
				fire(pc , board , new_angle1);
				fire(pc , board , new_angle2);
			}
            break;
		}
	}
}
					
int main(int argc, char *argv[])
{
	return 0;
}
