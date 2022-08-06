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
		case 2:
			Exercise2();
			system("pause");
			break;
		case 3:
			Exercise3();
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