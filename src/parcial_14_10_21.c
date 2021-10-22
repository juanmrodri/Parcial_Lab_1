/*
 ============================================================================
 Name        : parcial_14_10_21.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Inputs.h"
#include "Room.h"
#include "Arcade.h"
#include "Menu.h"
#define ROOM_LEN 15 // cambiar a 100
#define ARCADE_LEN 15

int main(void) {
	setbuf(stdout, NULL);

	int response;

	Room roomList[ROOM_LEN];

	Arcade arcadeList[ARCADE_LEN];

	room_initList(roomList, ROOM_LEN);

	arcade_initList(arcadeList,ARCADE_LEN);

	force_room_add(roomList, ROOM_LEN, 0, "Sacoa", "Av. Lavalle y Florida\n", 0);
	force_room_add(roomList, ROOM_LEN, 1, "Neverland", "Abasto\n", 1);
	force_room_add(roomList, ROOM_LEN, 2, "Playland", "Unicenter\n", 1);
	force_room_add(roomList, ROOM_LEN, 3, "Sacoa", "Av. Livertador y Juan b. Justo\n", 0);
	force_room_add(roomList, ROOM_LEN, 4, "Italpark", "Av. Figueroa Alcorta\n", 0);
	force_room_add(roomList, ROOM_LEN, 5, "Sacoa", "Av. Lavalle y Florida\n", 0);
	force_room_add(roomList, ROOM_LEN, 6, "BondiolaLand", "Abasto\n", 1);
	force_room_add(roomList, ROOM_LEN, 7, "SaNlorenzolandia", "Unicenter\n", 1);
	force_room_add(roomList, ROOM_LEN, 8, "Sacoa", "Av. Livertador y Juan b. Justo\n", 0);
	force_room_add(roomList, ROOM_LEN, 9, "Parque de la costa", "Av. Figueroa Alcorta\n", 0);

	force_arcade_add(arcadeList, ARCADE_LEN, 0, "Japan",0, 4, 120, 1, "Sunset Riders");
	force_arcade_add(arcadeList, ARCADE_LEN, 1, "USA",0, 8, 250, 2, "Daytona USA");
	force_arcade_add(arcadeList, ARCADE_LEN, 2, "USA",1, 2, 100, 8, "Mortal Kombat");
	force_arcade_add(arcadeList, ARCADE_LEN, 3, "Japan",1, 4, 90, 9, "Pacman");

	/*
	  for(int i=0;i<ARCADE_LEN;i++)
	{
		if(arcadeList[i].isEmpty==0)
		{
			printf("\nJuego: %s\n"
					"\nOrigen: %s\n"
					"\nCantidad de jugadores: %d\n"
					"\nCantidad maxima de fichas que contiene el arcade: %d\n",arcadeList[i].gameName,arcadeList[i].origin,arcadeList[i].players,arcadeList[i].maxCoins);
		}
	}
	 */

	// menu starts
	do
	{
		menu(&response); // llama a todo el menu aca

		menu_resolve(&response,roomList,ROOM_LEN,arcadeList,ARCADE_LEN);

	}while(response!=0);

	return EXIT_SUCCESS;
}
