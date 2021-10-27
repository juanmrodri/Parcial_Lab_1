/*
 * Menu.c
 *
 *  Created on: 17 oct 2021
 *      Author: juanm
 */

#include "Menu.h"
#include "Room.h"
#include "Arcade.h"
#include "Inputs.h"
#include "Report.h"
#define ROOM_LEN 15
#define ARCADE_LEN 15

/** \brief prints out the menu on the main function
 *
 * \param list res* Pointer to response value
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

int menu(int* res)
{
	int ret=-1;
	int bufferResponse;
	if(res!=NULL)
	{
		if(pedirIntAUsuario(&bufferResponse, 0, 9, 2, "Que desea realizar:\n-------------------\n\n"
											"\t1).Alta de Salon\n\n"
											"\t2).Eliminar Salon\n\n"
											"\t3).Imprimir salones\n\n"
											"\t4).Incorporar arcade\n\n"
											"\t5).Modificar arcade\n\n"
											"\t6).Eliminar arcade\n\n"
											"\t7).Imprimir arcades\n\n"
											"\t8).Imprimir juegos\n\n"
											"\t9).Informes\n\n"
											"\t0).Salir\n\n--------------> ","Error!")==0)
		{
			if(bufferResponse>=0 && bufferResponse<10)
			{
				*res=bufferResponse;
			}
		}
		else
		{
			printf("\n\tNo se pudo leer el dato\n\n");
		}
	}
	else
	{
		printf("\n\tNo se pudo leer el dato\n\n");
	}
	return ret;
}

int menu_resolve(int* res, Room* roomList, int lenRoom, Arcade* arcadeList, int lenArcade)
{
	int ret=-1;
	int findIdPos;
	int bufferResponse;
	int bufferIdResponse;
	char bufferReportResponse;
	int auxPosIdRoomSelected;
	if(res!=NULL)
	{
		switch(*res)
					{
					case 1:
						// alta de salon
						if(room_findEmpty(roomList, lenRoom, &findIdPos)==0)
						{
							printf("\n\tIngresar salon\n\n");
							room_add(&roomList[findIdPos],lenRoom);
							room_printRoom(&roomList[findIdPos]);
						}
						else
						{
							printf("\n\tNo existe mas lugar para ingresar valores\n\n");
						}
						break;
					case 2:
						// eliminar salon
						if(room_countEmpty(roomList,lenRoom)==lenRoom)
						{
							printf("\n\tNo existe ningun salon ingresado hasta el momento\n\n");
						}
						else
						{
							printf("\n\tEliminar salon\n\n");
							room_printRooms(roomList,lenRoom);
							menu_askForId(&bufferIdResponse, 0);
							if(arcade_searchRoomId(arcadeList,lenArcade,bufferIdResponse)!=0)
							{
								printf("\n\tEl salon que eligio tiene: %d arcade(s)\n\n",arcade_searchRoomId(arcadeList,lenArcade,bufferIdResponse));
								if(pedirIntAUsuario(&bufferResponse, 0, 1, 2, "\n\t\tDesea continuar(0 si- 1 no)? ", "\n\tSe produjo un error!\n")==0)
								{
									if(bufferResponse==0)
									{
										room_delete(roomList,lenRoom,bufferIdResponse);
									}
									else
									{
										printf("\n\tNo se ha eliminado el salon\n\n");
									}
								}
								else
								{
									printf("\n\tNo se ha eliminado el salon, se produjo un error al leer la respuesta\n\n");
								}
							}
							else
							{
								room_delete(roomList,lenRoom,bufferIdResponse);
							}
						}
						break;
					case 3:
						// imprimir salones
						if(room_countEmpty(roomList,lenRoom)==lenRoom)
						{
							printf("\n\tNo existe ningun salon ingresado hasta el momento\n\n");
						}
						else
						{
							printf("\n\tSalones ingresados\n\n");
							room_printRooms(roomList,lenRoom);
						}
						break;
					case 4:
						// incorporar arcade
						if(room_countEmpty(roomList,lenRoom)==lenRoom)
						{
							printf("\n\tNo existe ningun salon ingresado hasta el momento, debe ingresar alguno, para poder cargarle un arcade\n\n");
						}
						else
						{
							if(arcade_findEmpty(arcadeList, lenArcade,&findIdPos)==0)
							{
								room_printRooms(roomList,lenRoom);
								printf("\n\tIngresar Arcade:\n\n");
								menu_askForId(&bufferIdResponse,0);
								if(room_findRoomById(roomList,lenRoom,bufferIdResponse)!=0)
								{
									auxPosIdRoomSelected = room_findRoomById(roomList,lenRoom,bufferIdResponse);
									if(auxPosIdRoomSelected!=0)
									{
										arcade_add(&arcadeList[findIdPos], lenArcade, bufferIdResponse);
									}
									else
									{
										printf("\n\tSe produjo un error al buscar la posicion!\n\n");
									}

								}
								else
								{
									printf("\n\tEl id no existe o ya no se encuentra disponible\n\n");
								}
							}
							else
							{
								printf("\n\tNo se pueden ingresar mas arcades!\n\n");
							}
						}
						break;
					case 5:
						// modificar arcade
						if(room_countEmpty(roomList,lenRoom)==lenRoom)
						{
							printf("\n\tNo existe ningun salon ingresado hasta el momento, deberia existir por lo menos un salor y este tener arcades\n\n");
						}
						else
						{
							if(arcade_countEmpty(arcadeList,lenArcade)==lenRoom)
								{
									printf("\n\tNo existe ningun arcade ingresado por el momento\n\n");
								}
								else
								{
									arcade_printArcades(arcadeList,lenArcade);
									printf("\n\tModificar Arcade:\n\n");
									menu_askForId(&bufferIdResponse,1);
									if(Arcade_findArcadeById(arcadeList, lenArcade, bufferIdResponse)!=0)
									{
										arcade_mod(arcadeList, lenArcade, bufferIdResponse);
									}
									else
									{
										printf("\n\tSe produjo un error al buscar el arcade!\n\n");
									}

								}
						}
						break;
					case 6:
						// eliminar arcade
						if(room_countEmpty(roomList,lenRoom)==lenRoom)
						{
							printf("\n\tNo existe ningun salon ingresado hasta el momento, deberia existir por lo menos un salor y este tener arcades\n\n");
						}
						else
						{
							if(arcade_countEmpty(arcadeList,lenArcade)==lenRoom)
							{
								printf("\n\tNo existe ningun arcade ingresado por el momento\n\n");
							}
							else
							{
								printf("\n\tEliminar arcade\n\n");
								arcade_printArcades(arcadeList,lenArcade);
								arcade_delete(arcadeList,lenArcade);
							}
						}

						break;
					case 7:
						// imprimir arcades
						if(room_countEmpty(roomList,lenRoom)==lenRoom)
						{
							printf("\n\tNo existe ningun salon ingresado hasta el momento, deberia existir por lo menos un salor y este tener arcades\n\n");
						}
						else
						{
							if(arcade_countEmpty(arcadeList,lenArcade)==lenRoom)
							{
								printf("\n\tNo existe ningun arcade ingresado por el momento\n\n");
							}
							else
							{
								printf("\n\tArcades ingresados\n\n");
								arcade_printArcades(arcadeList,lenArcade);
							}
						}
						break;
					case 8:
						// imprimir juegos
						if(room_countEmpty(roomList,lenRoom)==lenRoom)
						{
							printf("\n\tNo existe ningun salon ingresado hasta el momento, deberia existir por lo menos un salor y este tener arcades\n\n");
						}
						else
						{
							if(arcade_countEmpty(arcadeList,lenArcade)==lenRoom)
							{
								printf("\n\tNo existe ningun arcade ingresado por el momento\n\n");
							}
							else
							{
								printf("\n\tJuegos que contienen los arcades ingresados\n\n");
								arcade_printGameList(arcadeList,lenArcade);
							}
						}
						break;
					case 9:
						// informes
						if(room_countEmpty(roomList,lenRoom)==lenRoom)
						{
							printf("\n\tNo existe ningun salon ingresado hasta el momento, deberia existir por lo menos un salor y este tener arcades\n\n");
						}
						else
							{
								if(arcade_countEmpty(arcadeList,lenArcade)==lenRoom)
								{
									printf("\n\tNo existe ningun arcade ingresado por el momento\n\n");
								}
								else
								{
									do
									{
									if(pedirCharUsuario(&bufferReportResponse, 97, 104, 2, "\n\t\tInformes:\n-------------------\n\n"
										"\t\ta).Salones con mas de 4 arcades\n\n"
										"\t\tb).Arcades con mas de 2 jugadores\n\n"
										"\t\tc).Info de salon\n\n"
										"\t\td).Lista de arcades en salon (id)\n\n"
										"\t\te).Salon con mas arcades\n\n"
										"\t\tf).Recaudacion maxima de un salon (id)\n\n"
										"\t\tg).Ingresar nombre de juego para ver cuantos arcades lo contienen\n\n"
										"\t\th).Salir\n\n--------------> ","Error!")==0)
										{
											if(bufferReportResponse>=97 && bufferReportResponse<=104)
											{
												switch(bufferReportResponse)
												{
												case 'a':
													printf("\n\t\tSalones con mas de 4 arcades:\n\n");
													report_roomMoreThanFourArcades(roomList, lenRoom, arcadeList, lenArcade);
													break;
												case 'b':
													printf("\n\tArcades para mas de 2 jugadores: b\n\n");
													break;
												case 'c':
													printf("\n\tOpcion c\n\n");
													break;
												case 'd':
													printf("\n\tOpcion d\n\n");
													break;
												case 'e':
													printf("\n\tOpcion e\n\n");
													break;
												case 'f':
													printf("\n\tOpcion f\n\n");
													break;
												case 'g':
													printf("\n\tOpcion g\n\n");
													break;
												}
											}
										}
									}while(bufferReportResponse!=104);
								}
							}
						break;
					}
	}
	return ret;
}

/** \brief ask the user for the
	 *
	 * \param res int pointer of the selected id
	 * \param idEval int value indicates which id will be asked for
	 * \return int 0 ok -1 error
	 *
	 */
int menu_askForId(int* res, int idEval)
{
	int ret=-1;
	int bufferRes;

	if(res!=0 && idEval>=0)
	{
		if(idEval==0)
		{
			if(pedirIntAUsuario(&bufferRes, 1, ROOM_LEN, 2, "\n\tElija el Id del salon: ", "\n\tError!!!\n")==0)
					{
						ret=0;
						*res=bufferRes;
					}
		}
		else
		{
			if(idEval==1)
			{
				if(pedirIntAUsuario(&bufferRes, 1, ARCADE_LEN, 2, "\n\tElija el Id del arcade: ", "\n\tError!!!\n")==0)
					{
						ret=0;
						*res=bufferRes;
					}
			}
		}
	}

	return ret;
}
