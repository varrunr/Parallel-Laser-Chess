#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__

/* Size of the chess board */
#define BRD_SZ 9

/* Constants for evaluation */
#define INFTY 10000
#define KING INFTY
#define LASER 9
#define BLK 1 
#define TRMIRR 3.5
#define BMSPLTR 5

#define PLAYER1 1
#define PLAYER2 2
typedef std::vector<int> coordinate;
typedef std::vector< std::vector<int> > TwoDarray;
#endif
