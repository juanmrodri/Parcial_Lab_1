/*
 * Menu.h
 *
 *  Created on: 17 oct 2021
 *      Author: juanm
 */

#ifndef MENU_H_
#define MENU_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"
#include "Room.h"
#include "Arcade.h"

int menu(int* res);

int menu_resolve(int* res, Room* roomList, int lenRoom, Arcade* arcadeList, int lenArcade);

int menu_askForId(int* res, int idEval);

#endif /* MENU_H_ */
