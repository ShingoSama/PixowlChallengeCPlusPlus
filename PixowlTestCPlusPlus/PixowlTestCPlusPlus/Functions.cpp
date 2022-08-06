#include "funcPixowl.h"

void Add(struct node** head_ref, int new_value)
{
    //Declare new node
    struct node* new_node = new node;

    //Copy value in the new node value
    new_node->value = new_value;

    //Link the old list to the new node
    new_node->next = (*head_ref);

    //Move the head to point to the new node */
    (*head_ref) = new_node;
}

void SumNodes(struct node* head, int* sum)
{
    //Validate head is not null
    if (!head)
        return;

    // recursively traverse the remaining nodes
    SumNodes(head->next, sum);

	//Sum
    *sum = *sum + head->value;
}

int SumNodesUtil(struct node* head)
{

    int sum = 0;

    // find the sum of  nodes
    SumNodes(head, &sum);

    // required sum
    return sum;
}

int Exercise1()
{
    struct node* head = NULL;

    Add(&head, 5);
    Add(&head, 6);
    Add(&head, 7);
    Add(&head, 8);
    Add(&head, 9);

    cout << "Sum of nodes = "
         << SumNodesUtil(head)
		 <<"\n"
		 << "\n";
    return 0;
}


void TextMenuMain()
{
	cout << "/-------------------\\ \n";
	cout << "|  Pixowl C++ Test  | \n";
	cout << "\\-------------------/ \n";
	cout << "\n";
	cout << "Exercise 1) \n";
	cout << "Exercise 2) \n";
	cout << "Exercise 3) \n";
	cout << "Exercise 4) \n";
	cout << "Exercise 5) \n";
	cout << "Exercise 6) \n";
	cout << "Exercise 7) \n";
	cout << "Option: ";
}

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

void Exercise2BFunc(int *a)
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

//Exercise 3

int Exercise3()
{
	//char* str;
	//char* str2;
	//char* str3;
	//char* str4;
	//int* a;

	//str = malloc( sizeof ( char ) * 32);
	//strcpy(str, "brown fox jumps over the lazy");

	//str2 = &str[4];
	//str3 = str + 3;
	//str++;

	//a = (int*)(str + 4);
	//a += 2;

	//str4 = (char*)a;
	//printf("str4: %s", str4);

	//cout << "D1: " << str;
	//cout << "D2: " << str2;
	//cout << "D3: " << str3;

	//free(str);
	//free(str2);
	//free(str3);

	return 0;
}

int Exercise4()
{
	//int32_t* dst = GetScreenARGB();
	//int offset = SCR_W * SCR_H + 1;
	//while (‐‐offset)
	//{
	//	int32_t s = ((*dst & 0xff0000) >> 16) * 0.33f;
	//	s += ((*dst & 0xff00) >> 8) * 0.59f;
	//	s += (*dst & 0xff) * 0.11f;
	//	*dst = (*dst & 0xff000000) | (s << 16) | (s << 8) | s;
	//	dst++;
	//}
	return 0;
}

int Exercise5()
{
	return 0;
}

//bool Utils::check(std::string arg)
//{
//	auto foo = fopen(arg, "rb");
//	if (foo != nullptr)
//	{
//		fseek(foo, 0, SEEK_END);
//		size_t baz = ftell(foo);
//		rewind(foo);
//
//		std::string bar;
//		bar.resize(baz);
//		fread(&bar[0], baz, 1, foo);
//
//		if (bar.find("nick") != std::string::npos)
//		{
//			return true;
//		}
//		else if (bar.find("mail") != std::string::npos);
//		{
//			return true;
//
//		}
//	}
//	fclose(foo);
//}

//Exercise 6

int Exercise6()
{
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
	FillList(values2, sizeArray2);
	//Borro un numero random de la lista 2
	DeleteRandomNumber(values2, sizeArray);
	//lleno la lista 1, contrenda 999 valores diferentes
	FillRandomNumber(values, values2, sizeArray2);
	//desordenamos la lista
	DisorderList(values, sizeArray);
	
	//cout << "Size Array: " << sizeArray << "\n";

	//muestro la lista desordenada

	//for (int i = 0; i < sizeArray; i++)
	//{
	//	cout << values[i] << " ";
	//}

	//Busco el numero que falta
	int missingNumber = FindMissing(values, sizeArray);

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

//Exercise 7

void Exercise7()
{
	string text;
	string delimiter = " ";
	vector<string> strings;
	cout << "Ingrese un texto: ";
	cin.ignore();
	std::getline(std::cin, text);


	std::cout << text << "\n";

	size_t pos = 0;
	std::string token;
	while ((pos = text.find(delimiter)) != std::string::npos) {
		token = text.substr(0, pos);
		std::cout << token << std::endl;
		text.erase(0, pos + delimiter.length());
	}
	std::cout << text << std::endl;
}