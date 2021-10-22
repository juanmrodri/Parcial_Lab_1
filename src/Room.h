/*
 * Room.h
 *
 *  Created on: 16 oct 2021
 *      Author: juanm
 */

#ifndef ROOM_H_
#define ROOM_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"
#define ROOM_LOCAL 0
#define ROOM_SHOPPING 1

typedef struct
{
	int id;
	char name[32];
	char address[32];
	int type;
	int isEmpty; // 1= empty // 0=occupied

}Room;

// test function

void force_room_add(Room* list, int len, int pos, char name[], char address[], int type);

// end of test function

int room_initList(Room* list,int len);

int room_findEmpty(Room* list, int len, int* pos);

int room_findRoomById(Room* list, int len, int id);

int room_countEmpty(Room* list, int len);

int room_add(Room* list, int len);

int room_delete(Room* list, int len);

int room_printRoom(Room* list);

int room_printRooms(Room* list, int len);






#endif /* ROOM_H_ */
