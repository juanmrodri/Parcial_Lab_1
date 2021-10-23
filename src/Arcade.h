/*
 * Arcade.h
 *
 *  Created on: 19 oct 2021
 *      Author: juanm
 */

#ifndef ARCADE_H_
#define ARCADE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"
#include "Room.h"

typedef struct
{
	int id;
	char origin[16];
	int soundSystem;
	int players;
	int maxCoins;
	int idRoom;
	char gameName[64];
	int isEmpty;

}Arcade;

// test function

void force_arcade_add(Arcade* list, int len, int pos, char origin[], int soundSystem, int players, int maxCoins, int idRoom,char gameName[]);

// end of test function

int arcade_initList(Arcade* list,int len);

int arcade_findEmpty(Arcade* list, int len, int* pos);

int Arcade_findArcadeById(Arcade* list, int len, int id);

int arcade_countEmpty(Arcade* list, int len);

int arcade_add(Arcade* list, int len, int idRoom);

int arcade_searchRoomId(Arcade* list, int len, int res);

int arcade_delete(Arcade* list, int len);

int arcade_mod(Arcade* list, int len, int id);

int arcade_printArcade(Arcade* list);

int arcade_printArcades(Arcade* list, int len);

// game functions

int arcade_printGame(Arcade* list);

int arcade_printGameList(Arcade* list, int len);

// end game functions

#endif /* ARCADE_H_ */
