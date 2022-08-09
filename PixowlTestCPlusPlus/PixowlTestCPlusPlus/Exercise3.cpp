#include "funcPixowl.h"

//
//Exercise 3
//

int Exercise3()
{
	cout << "/-------------------\\ \n";
	cout << "|  Pixowl C++ Test  | \n";
	cout << "\\-------------------/ \n";
	cout << "\n";
	cout << "\\-----EXercise3-----/ \n";
	cout << "\n";

	char* str;
	char* str2;
	char* str3;
	char* str4;
	int* a;

	str = (char*)malloc(sizeof(char) * 32);
#pragma warning(suppress : 4996)
	strcpy(str, "brown fox jumps over the lazy");

	str2 = &str[4];
	str3 = str + 3;
	str++;

	a = (int*)(str + 4);
	a += 2;

	str4 = (char*)a;
	printf("str4: %s", str4);

	cout << "\n";
	cout << "D1: str " << str << "\n";
	cout << "D1: str " << str << "\n";
	cout << "POSITION 1 \n";
	cout << "D2: str2 " << str2 << "\n";
	cout << "POSITION 4 \n";
	cout << "D3: str3 " << str3 << "\n";
	cout << "POSITION 3 \n";
	cout << "D4: str4 " << str4 << "\n";
	cout << "POSITION 13 \n";

	str--;
	free(str);
	//free(str2);
	//free(str3);
	// Solo deberian limpiar str ya que los demas apuntan al mismo bloque de memoria
	cout << "Se comentaron lineas y se modificaron para que el programa ejecute." << "\n";
	cout << "Solo se debera liberar la variable str primero volviendola a la posicion 0." << "\n";
	cout << "De otra forma el programa da error." << "\n";
	return 0;
}

//int main()
//{
//	char* str;
//	char* str2;
//	char* str3;
//	char* str4;
//	int* a;
//
//	str = malloc(sizeof(char) * 32);//Este codigo da error, ver linea 22 posible solucion
//	strcpy(str, "brown fox jumps over the lazy");
//
//	str2 = &str[4];
//	str3 = str + 3;
//	str++;
//
//	a = (int*)(str + 4);
//	a += 2;
//
//	str4 = (char*)a;
//	printf("str4: %s", str4);
//
//	free(str);//los free apuntan al bloque str, no se pueden liverar, volver str a la posicion 0 para poder liverar como se ve en la linea 46/47
//	free(str2);
//	free(str3);
//
//	return 0;
//}