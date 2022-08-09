#include "funcPixowl.h"

//
//Exercise 4
//

int Exercise4()
{
	cout << "/-------------------\\ \n";
	cout << "|  Pixowl C++ Test  | \n";
	cout << "\\-------------------/ \n";
	cout << "\n";
	cout << "\\-----EXercise4-----/ \n";
	cout << "\n";
	cout << "int32_t* dst = GetScreenARGB();    //Obtiene los valores de pantalla \n";
	cout << "int offset = SCR_W * SCR_H + 1;    //Tamaño de la pantalla + 1 \n";
	cout << "while (‐‐offset)                   //Recorro la pantalla teniendo en cuenta que el primer valor se resta ultimo recorrido 1 \n";
	cout << "{                                  //En cada linea empieza a pintar / dar color al pixel \n";
	cout << "int32_t s = ((*dst & 0xff0000) >> 16) * 0.33f;         //Color Red \n";
	cout << "s += ((*dst & 0xff00) >> 8) * 0.59f;                   //Color Green \n";
	cout << "s += (*dst & 0xff) * 0.11f;                            //Color Blue \n";
	cout << "*dst = (*dst & 0xff000000) | (s << 16) | (s << 8) | s; //Apha \n";
	cout << "dst++;                            //Se mueve un espacio \n";
	cout << "} \n";
	cout << "Este es el ejercicio mas dificil, ya que nunca realice algo similar, entiendo que va asignando colores a la pantalla \n";
	return 0;
}