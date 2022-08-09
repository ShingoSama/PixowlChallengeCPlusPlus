//
// Programa principal
//

#include "funcPixowl.h"

int main()
{
	int mainOption = 1;
	while (mainOption != 0)
	{
		TextMenuMain();
		cin >> mainOption;
		system("CLS");
		switch (mainOption)
		{
		case 1:
			Exercise1();
			system("pause");
			break;
		case 2:
			Exercise2();
			system("pause");
			break;
		case 3:
			Exercise3();
			system("pause");
			break;
		case 4:
			Exercise4();
			system("pause");
			break;
		case 5:
			Exercise5();
			system("pause");
			break;
		case 6:
			Exercise6();
			system("pause");
			break;
		case 7:
			Exercise7();
			system("pause");
			break;
		default:
			break;
		}
		system("CLS");
	}
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