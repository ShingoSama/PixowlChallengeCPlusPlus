#include "funcPixowl.h"

//
//Exercise 2
//

int Exercise2()
{
	int secundaryOption = 1;
	while (secundaryOption != 0)
	{
		TextMenuExercise2();
		cin >> secundaryOption;
		system("CLS");
		switch (secundaryOption)
		{
		case 1:
			TextSolutionExercise2A();
			Exercise2Amain();
			system("pause");
			break;
		case 2:
			TextSolutionExercise2B();
			Exercise2Bmain();
			system("pause");
			break;
		case 3:
			TextSolutionExercise2C();
			Exercise2Cmain();
			system("pause");
			break;
		case 4:
			TextSolutionExercise2D();
			Exercise2Dmain();
			system("pause");
			break;
		case 5:
			TextSolutionExercise2E();
			Exercise2Emain();
			system("pause");
			break;
		case 6:
			TextSolutionExercise2F();
			Exercise2Fmain();
			system("pause");
			break;
		case 7:
			TextSolutionExercise2G();
			Exercise2Gmain();
			system("pause");
			break;
		case 8:
			TextSolutionExercise2H();
			Exercise2Hmain();
			system("pause");
			break;
		default:
			break;
		}
		system("CLS");
	}
	return 0;
}

void TextMenuExercise2()
{
	cout << "/-------------------\\ \n";
	cout << "|  Pixowl C++ Test  | \n";
	cout << "\\-------------------/ \n";
	cout << "\n";
	cout << "\\-----EXercise2-----/ \n";
	cout << "\n";
	cout << "Cada ejercicio tiene un comentario \n";
	cout << "1: A) \n";
	cout << "2: B) \n";
	cout << "3: C) \n";
	cout << "4: D) \n";
	cout << "5: E) \n";
	cout << "6: F) \n";
	cout << "7: G) \n";
	cout << "8: H) \n";
	cout << "0: Exit to main menu \n";
	cout << "Option: ";
}

//A)

void TextSolutionExercise2A()
{
	cout << "void func(int a) \n";
	cout << "{ \n";
	cout << "a = 1; \n";
	cout << "} \n";
	cout << "int main() \n";
	cout << "{ \n";
	cout << "int a = 0; \n";
	cout << "func(a); \n";
	cout << "cout << a ;\n";
	cout << "return 0; <- agregue el ; ya que sino daba error \n";
	cout << "} \n";
	cout << "Respuesta: el resultado es 0 ya que no se puede modificar los valores sin la referencia & \n";
	cout << "Se ejecuta la funcion Exercise2Amain() que contiene el mismo codigo: \n";
}

void Exercise2AFunc(int a)
{
	a = 1;
}

int Exercise2Amain()
{
	int a = 0;
	Exercise2AFunc(a);
	cout << a
		<< "\n";
	return 0;
}

//B)

void TextSolutionExercise2B()
{
	cout << "void func(int a) \n";
	cout << "{ \n";
	cout << "*a = 2; \n";
	cout << "} \n";
	cout << "int main() \n";
	cout << "{ \n";
	cout << "int a = 0; \n";
	cout << "func(a); \n";
	cout << "cout << a;\n";
	cout << "return 0; <- agregue el ; ya que sino daba error \n";
	cout << "} \n";
	cout << "Respuesta: el resultado es ERROR ya que no se puede modificar los valores \n";
	cout << "No se puee ejecutar el codigo ya que da dicho ERROR \n";
	cout << "Se deja copia arreglada en Exercise2Emain() y se la ejecutara\n";
}

void Exercise2BFunc(int* a)
{
	*a = 2;
}
int Exercise2Bmain()
{
	int a = 0;
	Exercise2BFunc(&a);
	cout << a
		<< "\n";
	return 0;
}

//C)

void TextSolutionExercise2C()
{
	cout << "void func(int& a) \n";
	cout << "{ \n";
	cout << "a = 3; \n";
	cout << "} \n";
	cout << "int main() \n";
	cout << "{ \n";
	cout << "int a = 0; \n";
	cout << "func(a); \n";
	cout << "cout << a; \n";
	cout << "return 0;  <- agregue el ; ya que sino daba error \n";
	cout << "} \n";
	cout << "Respuesta: Funciona correctamente, imprime un 3 ya que la funcion esta declarada con la referencia & \n";
	cout << "Se ejecuta la funcion Exercise2Cmain() que contiene el mismo codigo: \n";
}

void Exercise2CFunc(int& a)
{
	a = 3;
}
int Exercise2Cmain()
{
	int a = 0;
	Exercise2CFunc(a);
	cout << a
		<< "\n";
	return 0;
}

//D)

void TextSolutionExercise2D()
{
	cout << "void func(int& a) \n";
	cout << "{ \n";
	cout << "*a = 4; \n";
	cout << "} \n";
	cout << "int main() \n";
	cout << "{ \n";
	cout << "int a = 0; \n";
	cout << "func(a); \n";
	cout << "cout << a; \n";
	cout << "return 0; <- agregue el ; ya que sino daba error \n";
	cout << "} \n";
	cout << "Respuesta: ERROR en el codigo, deberia corregirse quitando el * en la funcion al asignar el numero 4  \n";
	cout << "Se ejecuta la funcion Exercise2Dmain() que contiene el mismo codigo solucionado: \n";
}

void Exercise2DFunc(int& a)
{
	a = 4;
}
int Exercise2Dmain()
{
	int a = 0;
	Exercise2DFunc(a);
	cout << a
		<< "\n";
	return 0;
}

//E)

void TextSolutionExercise2E()
{
	cout << "void func(int* a) \n";
	cout << "{ \n";
	cout << "*a = 5; \n";
	cout << "} \n";
	cout << "int main() \n";
	cout << "{ \n";
	cout << "int a = 0; \n";
	cout << "func(&a); \n";
	cout << "cout << a; \n";
	cout << "return 0; <- agregue el ; ya que sino daba error \n";
	cout << "} \n";
	cout << "Respuesta: el resultado es 5 se pasan correctamente los  \n";
	cout << "Se ejecuta la funcion Exercise2Emain() que contiene el mismo codigo: \n";
}

void Exercise2EFunc(int* a)
{
	*a = 5;
}
int Exercise2Emain()
{
	int a = 0;
	Exercise2EFunc(&a);
	cout << a
		<< "\n";
	return 0;
}

//F)

void TextSolutionExercise2F()
{
	cout << "void func(int* a) \n";
	cout << "{ \n";
	cout << "a = 6; \n";
	cout << "} \n";
	cout << "int main() \n";
	cout << "{ \n";
	cout << "int a = 0; \n";
	cout << "func(a); \n";
	cout << "cout << a; \n";
	cout << "return 0; <- agregue el ; ya que sino daba error  \n";
	cout << "} \n";
	cout << "Respuesta: ERROR en el codigo, la funcion func esperaba el puntero a la variable 'a' pero se enviaba solo la variable \n";
	cout << "Se ejecuta la funcion Exercise2Fmain() que contiene el mismo codigo solucionado: \n";
}

void Exercise2FFunc(int* a)
{
	*a = 6;
}
int Exercise2Fmain()
{
	int a = 0;
	Exercise2FFunc(&a);
	cout << a
		<< "\n";
	return 0;
}

//G)

void TextSolutionExercise2G()
{
	cout << "void func(int& a) \n";
	cout << "{ \n";
	cout << "a = 7; \n";
	cout << "} \n";
	cout << "int main() \n";
	cout << "{ \n";
	cout << "int a = 0; \n";
	cout << "func(&a); \n";
	cout << "cout << a; \n";
	cout << "return 0; <- agregue el ; ya que sino daba error  \n";
	cout << "} \n";
	cout << "Respuesta: ERROR en el codigo, en la llamada se pasa el &a comopuntero pero la funcion espera la variable como referencia \n";
	cout << "Se ejecuta la funcion Exercise2Gmain() que contiene el mismo codigo solucionado: \n";
}

void Exercise2GFunc(int& a)
{
	a = 7;
}
int Exercise2Gmain()
{
	int a = 0;
	Exercise2GFunc(a);
	cout << a
		<< "\n";
	return 0;
}

//H)

void TextSolutionExercise2H()
{
	cout << "void func(int* a) \n";
	cout << "{ \n";
	cout << "*a = 8; \n";
	cout << "} \n";
	cout << "int main() \n";
	cout << "{ \n";
	cout << "int a = 0; \n";
	cout << "func(a); \n";
	cout << "cout << a; \n";
	cout << "return 0; <- agregue el ; ya que sino daba error   \n";
	cout << "} \n";
	cout << "Respuesta: ERROR en el codigo, en la llamada no se pasa el &a \n";
	cout << "Se ejecuta la funcion Exercise2Hmain() que contiene el mismo codigo solucionado: \n";
}

void Exercise2HFunc(int* a)
{
	*a = 8;
}
int Exercise2Hmain()
{
	int a = 0;
	Exercise2HFunc(&a);
	cout << a
		<< "\n";
	return 0;
}