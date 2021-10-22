/*
 * Inputs.c
 *
 *  Created on: 2 oct 2021
 *      Author: juanm
 */

#include "Inputs.h"



// prototipos privados ----------------------

static int myGets(char pResultado[], int len);

static int esNumerica(char cadenaNumeros[]);

//-------------------------------------------

/// @brief static int esNumerica(char[])
///
/// @param cadenaNumeros
/// @return : -1 Error: NO es numerica. 0 Es numerica
///

static int esNumerica(char cadenaNumeros[])
{
	int i=0;
	int estado=-1; // doy por sentado que esta todo mal

	if(cadenaNumeros!=NULL)
	{
		estado=0; // esto habria que cambiarlo, ya que si la cadena viene pero vacia estariamos devolviendo que esta todo bien
		while(cadenaNumeros[i]!='\0')
			{
				if(cadenaNumeros[i]<'0' || cadenaNumeros[i]>'9')
				{
					// si esta mal!
					estado=-1;
					break;
				}
				i++;
			}
	}

	return estado;
}

int pedirFloatAUsuario(float* pResultado, float min, float max, int reintentos, char* variableTexto, char* textoError)
{
	int retorno=-1;
	float aux;
	int i;
	char bufferFloat[30];

	if(pResultado != NULL && min<max && reintentos >=0 && variableTexto != NULL && textoError != NULL)
	{
		for (i=0; i<=reintentos; i++)
		{
				printf("%s",variableTexto);
				if(myGets(bufferFloat,sizeof(bufferFloat))==0)
					{
							if(esNumerica(bufferFloat)==0)
								{
									aux = atof(bufferFloat); // tener en cuenta que en float es atof

										if (aux>=min && aux<=max)
											{
												retorno = 0; // OK
												*pResultado=aux;
												break;
											}
											else
												{
													retorno = -2;
													printf("%s\n", textoError);
												}
								}
									else
										{
											printf("%s\n", textoError);
										}
					}
					else
						{
							retorno = -2;
							printf("%s\n", textoError);
						}
		}
	}
	return retorno;
}

int pedirIntAUsuario(int* pResultado, int min, int max, int reintentos, char* variableTexto, char* textoError)
{
		int retorno=-1;
		int aux;
		int i;
		char bufferCadenaAux[16]; // que sea mas grande no tiene sentido

		if(pResultado != NULL && min<max && reintentos >=0 && variableTexto != NULL && textoError != NULL)
		{
			for (i=0; i<=reintentos; i++)
			{
				printf("%s",variableTexto);
				//fflush(stdin);
				//r = scanf("%d", &aux);
				if(myGets(bufferCadenaAux,sizeof(bufferCadenaAux))==0)
				{
				// el usuario ingreso algo
				// ahora lo valido para ver si los simbolos son numericos

					if(esNumerica(bufferCadenaAux)==0)
					{
							// si son numericos, convierto la cadena a INT, ahora ya convertimos la cadena a entero, de ser posible claro
							aux = atoi(bufferCadenaAux);

								if (aux>=min && aux<=max)
								{
									retorno = 0; // OK
									*pResultado=aux;
									break;
								}
								else
									{
										retorno = -2;
										printf("%s\n", textoError);
									}
					}
					else
						{
							printf("%s\n", textoError);
						}
				}
				else
				{
					retorno = -2;
					printf("%s\n", textoError);
				}
			}
		}

	return retorno;
}

int pedirCharUsuario(char* pResultado, char min, char max, int reintentos, char* variableTexto, char* textoError) // el min y el max puede ser int tambien
{
		int retorno=-1;
		char aux;
		int i;
		if(pResultado != NULL && min<max && reintentos >=0 && variableTexto != NULL && textoError != NULL)
		{
			for (i=0; i<=reintentos; i++)
			{
							printf("%s",variableTexto);
							fflush(stdin);
							scanf("%c", &aux);

							if (aux>=min && aux<=max)
							{
								retorno = 0; // OK
								*pResultado=aux;
								break;
							}
							else
							{
								retorno = -2; // ahora -2 significa que hay un error
								printf("%s", textoError);
							}
			}
		}
		return retorno;
}

/// @brief static int char (pResultado[], int len)
///
/// @param pResultado
/// @param len
/// @return : -1 Error: NO es numerica. 0 Es valido
///

static int myGets(char pResultado[], int len) // tener en cuenta que tiene un prototipo privado! es decir va en este archivo
{
	int retorno=-1;
	int indexFinal;
	fflush(stdin);

	if(fgets(pResultado,len,stdin)!=NULL)
		{
		indexFinal = strlen(pResultado)-1;
		if(pResultado[indexFinal]=='\n')
			{
				pResultado[indexFinal]='\0';
			}
			retorno=0;
		}
	return retorno;
}

/// @brief pedirTextoUsuario(char pResultado[], int len, int reintentos, char* variableTexto, char* textoError)
///
/// @param pResultado
/// @param len
/// @param len
/// @param reintentos
/// @param len
/// @return : -1 Error: NO es numerica. 0 Es valido
///
int pedirTextoUsuario(char pResultado[], int len, int reintentos, char* variableTexto, char* textoError) // el primer parametro, lo cambiamos por la primera posicion en memoria de la cadena
{
		int retorno=-1;
		int i;

		if(pResultado != NULL && reintentos >=0 && variableTexto != NULL && textoError != NULL)
		{
				for (i=0; i<=reintentos; i++)
				{

						printf("%s",variableTexto);
						//if((scanf("%s", pResultado))==1) // si fue una cadena de caracteres, el %s significa leeme una palabra, en el scanf el %s, corta en los espacios!
						// nos despedimos del scanf 23/09/21
						if(myGets(pResultado,len)==0) // con esto ya puedo leer de manera segura, con esto podemos leer de la consola de manera segura, esto solo va a leer texto
						{
							if(isdigit(*pResultado)==0) // 1 significa que no es un digito
							{
								retorno=0;
								break;
							}
							else
							{
								printf("%s", textoError);
							}

						}
						else
						{
							printf("%s", textoError);
						}
				}
		}
		return retorno;
}

