/*
 * Arcade.c
 *
 *  Created on: 19 oct 2021
 *      Author: juanm
 */

#include "Arcade.h"
#include "Inputs.h"

#define EMPTY 1
#define OCCUP 0
#define MONO 2
#define STEREO 3

//------------------------- static prototype

static int idGenerator(void);

//------------------------- end of static prototype

/*

	test function

*/

/** \brief let make a hardcoded upload for test purpose
 *
 * \param list Arcade* Pointer to array of roomList
 * \param len int the len of the array
 * \param pos int position of the array to load data
 * \param origin char the name
 * \param soundSystem int
 * \param players int
 * \param maxCoins int
 * \param idRoom int
 * \param gameName char
 * \param type int the type of the array
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
void force_arcade_add(Arcade* list, int len, int pos, char origin[], int soundSystem, int players, int maxCoins, int idRoom,char gameName[])
{
	list[pos].id=idGenerator();
	strncpy(list[pos].origin,origin,sizeof(list[pos].origin));
	list[pos].soundSystem=soundSystem;
	list[pos].players=players;
	list[pos].maxCoins=maxCoins;
	list[pos].idRoom=idRoom;
	strncpy(list[pos].gameName,gameName,sizeof(list[pos].gameName));
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
int arcade_initList(Arcade* list, int len)
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


/** \brief find an empty position on Arcade list
 *
 * \param list Arcade* Pointer to array of roomList
 * \param len int Array length
 * \param pos int pointer of the position in array Room
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int arcade_findEmpty(Arcade* list, int len, int* pos)
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
int Arcade_findArcadeById(Arcade* list, int len, int id)
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
 * \param list Arcade* Pointer to array of roomList
 * \param len int Array length
 * \param pos int pointer of the position in array Room
 * \return int Return of the number of Empty positions
 *
 */
int arcade_countEmpty(Arcade* list, int len)
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

int arcade_add(Arcade* list, int len, int idRoom)
{
	int ret=-1;
	char origin[16];
	int soundSystem;
	int players;
	int maxCoins;
	char gameName[64];

	if(list!=NULL && len>0 && list->isEmpty==EMPTY)
	{
		if(pedirTextoUsuario(origin, 16, 2, "\n\tPor favor ingrese la nacionalid: ", "\n\tSe produjo un error!\n")==0)
		{
			if(pedirIntAUsuario(&soundSystem, 0, 1, 2, "\n\tPor favor ingrese el tipo de sonido (2=MONO - 3=ESTEREO): ", "\n\tSe produjo un error!\n")==0)
			{
				if(pedirIntAUsuario(&players, 1, 8, 2, "\n\tPor favor ingrese la cantidad de jugadores que pueden jugar: ", "\n\tSe produjo un error!\n")==0)
				{
					if(pedirIntAUsuario(&maxCoins, 50, 250, 2, "\n\tPor favor ingrese la capacidad maxima de fichas del arcade(50-250): ", "\n\tSe produjo un error!\n")==0)
						{
							if(pedirTextoUsuario(gameName, 64, 2, "\n\tPor favor ingrese el nombre del juego que contiene el arcade: ", "\n\tSe produjo un error!\n")==0)
							{
								list->id=idGenerator();
								list->idRoom=idRoom;
								strncpy(list->origin,origin,sizeof(list->origin));
								list->soundSystem=soundSystem;
								list->players=players;
								list->maxCoins=maxCoins;
								strncpy(list->gameName,gameName,sizeof(list->gameName));
								list->isEmpty=OCCUP;
								ret=0;
								printf("\n\tSe cargo correctamente el arcade!\n\n");
							}
							else
							{
								printf("\n\tSe produjo un error al tratar de cargar el nombre del juego que contiene el arcade\n\n");
							}
						}
						else
						{
							printf("\n\tSe produjo un error al tratar de cargar la capacidad maxima de fichas del arcade\n\n");
						}
				}
				else
				{
					printf("\n\tSe produjo un error al tratar de cargar la cantidad de jugadores\n\n");
				}
			}
			else
			{
				printf("\n\tSe produjo un error al tratar de cargar el sistema de sonido\n\n");
			}
		}
		else
		{
			printf("\n\tSe produjo un error al tratar de cargar la nacionalidad de arcade\n\n");
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
int arcade_delete(Arcade* list, int len)
{
	int ret=-1;
	int i;
	int bufferId;
	int bufferResponse;
	char auxSoundSystemPrint[32];

		if(list->soundSystem==0)
		{
			strncpy(auxSoundSystemPrint,"Shopping",sizeof(auxSoundSystemPrint));
		}
		else
		{
			strncpy(auxSoundSystemPrint,"Local",sizeof(auxSoundSystemPrint));
		}

		if(list!=NULL && len>0)
		{
			if(pedirIntAUsuario(&bufferId, 1, len, 2, "\n\tPor favor ingrese el id del arcade que desea eliminar: ", "\n\tSe produjo un error!\n")==0)
			{
				for(i=0;i<len;i++)
				{
					if(list[i].id==bufferId)
					{
						printf("\tUsted esta por dar de baja el arcade(id): %d con sistema de sonido: %s con el juego: %s\n",list[i].id,auxSoundSystemPrint,list[i].gameName);
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

/** \brief lets modify the number of players or the contained game of a arcade
 *
 * \param list Arcade* Pointer to array of arcadeList
 * \param len int Array length
 * \param id int id to modify
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int arcade_mod(Arcade* list, int len, int id)
{
	int ret=-1;
	int i;
	int bufferResponse;
	int players;
	char gameName[64];

	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].id==id)
			{
				printf("\n\tSe esta por modificar el arcade con id: %d\n\n",id);
				if(pedirIntAUsuario(&bufferResponse, 0, 1, 2, "\n\t\tDesea continuar(0 si- 1 no)? ", "\n\tSe produjo un error!\n")==0)
				{
					if(bufferResponse==0)
					{
						printf("\n\tQuiere modificar la cantidad de jugadores? -> %d: \n\n",list[i].players);
						if(pedirIntAUsuario(&bufferResponse, 0, 1, 2, "\n\t\tDesea continuar(0 si- 1 no)? ", "\n\tSe produjo un error!\n")==0)
						{
							if(bufferResponse==0)
							{
								if(pedirIntAUsuario(&players, 1, 16, 2, "\n\t\tIngrese la nueva cantidad de jugadores: ", "\n\tSe produjo un error!\n")==0)
								{
									list[i].players=players;
									printf("\n\t\tSe modifico la cantidad de jugadores!\n\n");
									ret=0;
								}
								else
								{
									printf("\n\t\tSe produjo un error tratar de modificar la cantidad de jugadores\n\n");
								}
							}
							printf("\n\tQuiere modificar el juego que contiene el arcade? -> %s: \n\n",list[i].gameName);
							if(pedirIntAUsuario(&bufferResponse, 0, 1, 2, "\n\t\tDesea continuar(0 si- 1 no)? ", "\n\tSe produjo un error!\n")==0)
							{
								if(bufferResponse==0)
								{
									printf("\n\tJuegos disponibles:\n\n");
									arcade_printGameList(list,len);
									if(pedirTextoUsuario(gameName, 64, 2, "\n\tPor favor ingrese el nuevo juego que contiene el arcade: ", "\n\tSe produjo un error!\n")==0)
									{
										strncpy(list[i].gameName,gameName,sizeof(list[i].gameName));
										printf("\n\t\tSe modifico el juego que contiene el arcade!\n\n");
										ret=0;
									}
									else
									{
										printf("\n\tSe produjo un error al tratar de modificar el juego que contiene el arcade\n\n");
									}
								}
							}
							else
							{
								printf("\n\tNo se realizara la modificacion del juego que contiene\n\n");
							}
						}
						else
						{
							printf("\n\tNo se realizara la modificacion de cantidad de jugadores\n\n");
						}

					}
				}
				else
				{
					printf("\n\tSe produjo un error al ingresar el id\n\n");
				}
			}
		}
	}

	return ret;
}


/** \brief prints one arcade
 *
 * \param list Arcade* Pointer to array of arcadeList
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int arcade_printArcade(Arcade* list)
{
	int ret=-1;
	char auxSoundSystemPrint[32];

	if(list->soundSystem==0)
	{
		strncpy(auxSoundSystemPrint,"Mono",sizeof(auxSoundSystemPrint));
	}
	else
	{
		strncpy(auxSoundSystemPrint,"Estereo",sizeof(auxSoundSystemPrint));
	}

	if(list!=NULL && list->isEmpty==OCCUP)
	{
			printf("\n\t| Arcade:");
					printf("\n\t--------------------------\n");
					printf(
					"\tId: %d\n"
					"\n\tNacionalidad: %s\n"
					"\n\tSistema de sonido: %s\n"
					"\n\tCantidad de jugadores: %d\n"
					"\n\tCantidad maxima de fichas: %d\n"
					"\n\tNombre del juego que contiene: %s\n"
					"\n\tId del salon donde se encuentra: %d\n"
					"\t--------------------------\n\n",
					list->id,list->origin,auxSoundSystemPrint,list->players,list->maxCoins,list->gameName,list->idRoom);
				    ret=0;
	}

	return ret;
}

/** \brief makes a loop and call arcade_printArcade inside
 *
 * \param list Arcade* Pointer to array of arcadeList
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int arcade_printArcades(Arcade* list, int len)
{
	int ret=-1;
	int i;
	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			arcade_printArcade(&list[i]);
			ret=0;
		}
	}

	return ret;
}


// game functions

int arcade_printGame(Arcade* list)
{
	int ret=-1;
	if(list!=NULL && list->isEmpty==OCCUP)
	{
		printf("\n\t-: %s\n",list->gameName);
	}

	return ret;
}


int arcade_printGameList(Arcade* list, int len)
{
	int ret=-1;
	int i;

	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			arcade_printGame(&list[i]);
		}
	}

	return ret;
}


// end of game functions



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
