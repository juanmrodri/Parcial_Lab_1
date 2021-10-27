/*
 * Report.c
 *
 *  Created on: 23 oct 2021
 *      Author: juanm
 */

#include "Report.h"
#include "Inputs.h"

#define EMPTY 1
#define OCCUP 0


/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Room* Pointer to array of roomList
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int report_roomMoreThanFourArcades(Room* roomList, int lenRoom, Arcade* arcadeList, int lenArcade)
{
	int ret=-1;
	int i;
	int j;
	int count=0;
	char auxTypePrint[32];

	if(roomList!=NULL && lenRoom>0 && arcadeList!=NULL && lenArcade>0)
	{
		for(i=0;i<lenRoom;i++)
			{
				if(roomList[i].isEmpty==OCCUP)
				{
						for(j=0;j<lenArcade;j++)
						{
							if(arcadeList[j].isEmpty==OCCUP)
							{
								if(arcadeList[j].idRoom==roomList[i].id)
								{
									count=count+1;
									ret=0;
								}
							}
						}
						if(count>4)
						{
							if(roomList[i].type==0)
							{
								strncpy(auxTypePrint,"Shopping",sizeof(auxTypePrint));
							}
							else
							{
								strncpy(auxTypePrint,"Local",sizeof(auxTypePrint));
							}
							printf("\n\t\tId: %d\n\t\tNombre: %s\n\t\tDireccion: %s\t\tTipo de salon: %s\n\n",roomList[i].id,roomList[i].name,roomList[i].address,auxTypePrint);
							count=0;
						}
						else
						{
							count=0;
						}
				}
			}
	}

	return ret;
}

int report_arcadeMoreThanTwoPlayers(Arcade* arcadeList, int lenArcade, Room* roomList, int lenRoom)
{
	int ret=-1;

	return ret;
}
