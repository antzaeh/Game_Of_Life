/***************************************************************************
 *   Copyright (C) 2022 by ak   *
 *   antti.kruuti@gmail.com   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

/*********************************************************************

 1.  NAME


 2.  DESCRIPTION


 3.  VERSIONS
       Original:
         21.4.2022 / AK
         28.4.200 / AK

       Version history:

**********************************************************************/

/*-------------------------------------------------------------------*
 *    HEADER FILES                                                    *
 *--------------------------------------------------------------------*/
#include <stdio.h>
//#include <ncurses.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

/*-------------------------------------------------------------------*
 *    GLOBAL VARIABLES AND CONSTANTS                                  *
 *--------------------------------------------------------------------*/
/* Control flags */

/* Global constants */
#define row 9
#define col 9

/* Global variables */

/* Global structures */
struct cell
{
    int current; /* current situation, which is visible on screen */
    int future;  /* temporary calculation area for next round calculation */
};

/*-------------------------------------------------------------------*
 *    FUNCTION PROTOTYPES                                             *
 *--------------------------------------------------------------------*/
void print_board(struct cell board[col][row], int i, int j);
void init_game(struct cell board[col][row], int i, int j);
int count_naap(struct cell board[col][row], int i, int j);
void calc_game(struct cell board[col][row], int i, int j);