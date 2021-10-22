/*
 * Inputs.h
 *
 *  Created on: 2 oct 2021
 *      Author: juanm
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef INPUTS_H_
#define INPUTS_H_

int pedirFloatAUsuario(float* pResultado, float min, float max, int reintentos, char* variableTexto, char* textoError);

int pedirIntAUsuario(int* pResultado, int min, int max, int reintentos, char* variableTexto, char* textoError);

int pedirCharUsuario(char* pResultado, char min, char max, int reintentos, char* variableTexto, char* textoError);

int pedirTextoUsuario(char pResultado[], int len, int reintentos, char* variableTexto, char* textoError);

#endif /* INPUTS_H_ */
