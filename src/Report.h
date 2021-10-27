/*
 * Report.h
 *
 *  Created on: 23 oct 2021
 *      Author: juanm
 */

#ifndef REPORT_H_
#define REPORT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Room.h"
#include "Arcade.h"
#include "Inputs.h"

int report_roomMoreThanFourArcades(Room* roomList, int lenRoom, Arcade* arcadeList, int lenArcade);

int report_arcadeMoreThanTwoPlayers(Arcade* arcadeList, int lenArcade, Room* roomList, int lenRoom);

#endif /* REPORT_H_ */
