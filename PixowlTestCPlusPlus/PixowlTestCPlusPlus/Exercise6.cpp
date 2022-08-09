#include "funcPixowl.h"

//
//Exercise 6
//

int Exercise6()
{
	cout << "/-------------------\\ \n";
	cout << "|  Pixowl C++ Test  | \n";
	cout << "\\-------------------/ \n";
	cout << "\n";
	cout << "\\-----EXercise2-----/ \n";
	cout << "\n";
	
	Exercise6Main();
	return 0;
}
int Exercise6Main()
{
	int values[999];
	int values2[1000];

	int sizeArray = sizeof(values) / sizeof(values[0]);
	int sizeArray2 = sizeof(values2) / sizeof(values2[0]);

	//lleno la lista 2, contendra numeros del 1 al 1000
	cout << "Se llena una lista del 1 al 1000 y luego se borra un numero random. \n";
	FillList(values2, sizeArray2);
	//Borro un numero random de la lista 2
	DeleteRandomNumber(values2, sizeArray);
	cout << "Se completa la lista de 999 elementos. \n";
	//lleno la lista 1, contiene 999 valores diferentes
	FillRandomNumber(values, values2, sizeArray2);
	cout << "Se desordena la lista. \n";
	//desordenamos la lista
	DisorderList(values, sizeArray);

	//cout << "Size Array: " << sizeArray << "\n";

	//muestro la lista desordenada

	//for (int i = 0; i < sizeArray; i++)
	//{
	//	cout << values[i] << " ";
	//}
	cout << "Luego se calcula el faltante. \n";
	//Busco el numero que falta
	int missingNumber = FindMissing(values, sizeArray);

	cout << "Por ultimo se muestra el numero faltante. \n";
	cout << "\n" << "Missing No: " << missingNumber << "\n";

	return 0;
}

int FindMissing(int values[], int amountTimes)
{
	int N = amountTimes + 1;
	int total = (N) * (N + 1) / 2;

	for (size_t i = 0; i < amountTimes; i++)
	{
		total -= values[i];
	}

	return total;
}

void FillList(int values[], int amountTimes)
{
	for (int i = 0; i < amountTimes; i++)
	{
		values[i] = i + 1;
	}
}

void DeleteRandomNumber(int values[], int amountTimes)
{
	// Providing a seed value
	srand((unsigned)time(NULL));

	// Get a random number
	int random = rand() % amountTimes;

	// Print the random number
	//cout << "Random" << random << endl;

	values[random] = 0;
}

void FillRandomNumber(int values[], int values2[], int amountTimes)
{
	int counter = 0;
	for (int i = 0; i < amountTimes; i++)
	{
		if (values2[i] != 0)
		{
			values[counter] = values2[i];
			counter++;
		}
	}
}

void DisorderList(int values[], int amountTimes)
{
	int isFree[999];
	int disorderValues[999];
	int i, pos;
	time_t t;

	//semilla para el rand
	srand((unsigned)time(&t));

	//inicializacion del array para ver si esta libre o no
	for (i = 0; i < amountTimes; i++) {
		isFree[i] = 1;//1 -> libre, 0 -> ocupado
	}

	for (i = 0; i < amountTimes; i++)
	{
		pos = rand() % amountTimes;
		//este while evita que dos elementos sean guardados en la misma posicion
		while (isFree[pos] == 0)pos = rand() % amountTimes;
		disorderValues[pos] = values[i];
		isFree[pos] = 0;
	}
	for (int i = 0; i < amountTimes; i++)
	{
		values[i] = disorderValues[i];
	}
}