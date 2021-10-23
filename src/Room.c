/*
 * Room.c
 *
 *  Created on: 16 oct 2021
 *      Author: juanm
 */

#include "Room.h"

#define EMPTY 1
#define OCCUP 0

//------------------------- static prototype

static int idGenerator(void);

//------------------------- end of static prototype

/*

	test function

*/

/** \brief let make a hardcoded upload for test purpose
 *
 * \param list Room* Pointer to array of roomList
 * \param len int the len of the array
 * \param pos int position of the array to load data
 * \param name char the name
 * \param address the address
 * \param type int the type of the array
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
void force_room_add(Room* list, int len, int pos, char name[], char address[], int type)
{
	list[pos].id=idGenerator();
	strncpy(list[pos].name,name,sizeof(list[pos].name));
	strncpy(list[pos].address,address,sizeof(list[pos].address));
	list[pos].type=type;
	list[pos].isEmpty= OCCUP;
}

// --------------------------------------------------------------- end of test function

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Room* Pointer to array of roomList
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int room_initList(Room* list, int len)
{
	int ret=-1;
	int i;

	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			list[i].isEmpty=EMPTY;
			ret=0;
		}
	}
	return ret;
}

/** \brief find an empty position on room list
 *
 * \param list Room* Pointer to array of roomList
 * \param len int Array length
 * \param pos int pointer of the position in array Room
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int room_findEmpty(Room* list, int len, int* pos)
{
	int ret=-1;
	int i;

	if(list!=NULL && len>0 && pos >=0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==EMPTY)
			{
				*pos=i;
				ret=0;
				break;
			}
		}
	}
	else
	{
		printf("\n\tAlgun valor contenia un error\n\n");
	}

	return ret;
}

/** \brief checks if the selected id exist
	 *
	 * \param list Room* Pointer to array of roomList
	 * \param len int Array length
	 * \param id int pointer of the selected id
	 * \return int Return the index of the selected id
	 *
	 */
int room_findRoomById(Room* list, int len, int id)
{
	int index=0;
	int i;

	if(list!=NULL && len>0 && id!=0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].id==id)
			{
				index=i;
				break;
			}
		}
	}

	return index;
}

/** \brief count the number of empty positions
 *
 * \param list Room* Pointer to array of roomList
 * \param len int Array length
 * \param pos int pointer of the position in array Room
 * \return int Return of the number of Empty positions
 *
 */
int room_countEmpty(Room* list, int len)
{
	int count=0;
	int i;

	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==EMPTY)
			{
				count++;
			}
		}
	}

	return count;
}

/** \brief let user add all elements of Room* list position
 *
 * \param list Room* Pointer to array of roomList
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int room_add(Room* list, int len)
{
	int ret=-1;
	char name[32];
	char address[32];
	int type;

	if(list!=NULL && len>0 && list->isEmpty==EMPTY)
	{
		if(pedirTextoUsuario(name, 32, 2, "\n\tPor favor ingrese el nombre de lo salon: ", "\n\tSe produjo un error!\n")==0)
		{
			if(pedirTextoUsuario(address, 32, 2, "\n\tPor favor ingrese la direccion del salon: ", "\n\tSe produjo un error!\n")==0)
			{
				if(pedirIntAUsuario(&type, 0, 1, 2, "\n\tPor favor ingrese el tipo de salon (0=SHOPPING - 1=LOCAL): ", "\n\tSe produjo un error!\n")==0)
				{
					list->id=idGenerator();
					strncpy(list->name,name,sizeof(list->name));
					strncpy(list->address,address,sizeof(list->address));
					list->type=type;
					list->isEmpty=OCCUP;
					ret=0;
					printf("\n\tSe cargo correctamente el salon!\n\n");
				}
				else
				{
					printf("\n\tSe produjo un error al tratar de cargar el tipo de salon\n\n");
				}
			}
			else
			{
				printf("\n\tSe produjo un error al tratar de cargar la direccion\n\n");
			}
		}
		else
		{
			printf("\n\tSe produjo un error al tratar de cargar el nombre\n\n");
		}
	}

	return ret;
}

/** \brief change the value of isEmpty to empty
 *
 * \param list Room* Pointer to array of roomList
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int room_delete(Room* list, int len, int res)
{
	int ret=-1;
	int i;
	int bufferId = res;
	int bufferResponse;
	char auxTypePrint[32];

		if(list->type==0)
		{
			strncpy(auxTypePrint,"Shopping",sizeof(auxTypePrint));
		}
		else
		{
			strncpy(auxTypePrint,"Local",sizeof(auxTypePrint));
		}

		if(list!=NULL && len>0)
		{
			if(bufferId>0)
			{
				for(i=0;i<len;i++)
				{
					if(list[i].id==bufferId)
					{
						printf("\n\tUsted esta por dar de baja el salon\n\n\t| %s: %s | localizado en %s\n",auxTypePrint,list[i].name,list[i].address);
						if(pedirIntAUsuario(&bufferResponse, 0, 1, 2, "\n\t\tDesea continuar(0 si- 1 no)? ", "\n\tSe produjo un error!\n")==0)
						{
							if(bufferResponse==0)
							{
								list[i].isEmpty=EMPTY;
								ret=0;
								printf("\n\tSe elimino correctamente!\n\n");
							}
							else
							{
								printf("\n\tNo se procedera con la baja\n\n");
								break;
							}
						}
						else
						{
							printf("\n\tSe produjo un error al leer la respuesta\n\n");
						}
					}
				}
			}
			else
			{
				printf("\n\tSe produjo un error, o el Id no existe\n\n");
			}
		}

	return ret;
}

/** \brief prints one room
 *
 * \param list Room* Pointer to array of roomList
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int room_printRoom(Room* list)
{
	int ret=-1;
	char auxTypePrint[32];

	if(list->type==0)
	{
		strncpy(auxTypePrint,"Shopping",sizeof(auxTypePrint));
	}
	else
	{
		strncpy(auxTypePrint,"Local",sizeof(auxTypePrint));
	}

	if(list!=NULL && list->isEmpty==OCCUP)
	{
			printf("\n\t| Salon:");
					printf("\n\t--------------------------\n");
					printf(
					"\tNombre: %s\n"
					"\tId: %d\n"
					"\n\tDireccion: %s"
					"\n\tTipo: %s\n"
					"\t--------------------------\n\n",
					list->name,list->id,list->address,auxTypePrint);
				    ret=0;
	}

	return ret;
}

/** \brief makes a loop and call room_printRoom inside
 *
 * \param list Room* Pointer to array of roomList
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int room_printRooms(Room* list, int len)
{
	int ret=-1;
	int i;
	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			room_printRoom(&list[i]);
			ret=0;
		}
	}

	return ret;
}

/** \brief generates new id number
 *
 * \return int
 *
 */
static int idGenerator(void)
{
	static int count=1;
	return count++;
}
