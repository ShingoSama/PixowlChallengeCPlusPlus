#include "funcPixowl.h"

//
//Exercise 5
//

int Exercise5()
{
	cout << "/-------------------\\ \n";
	cout << "|  Pixowl C++ Test  | \n";
	cout << "\\-------------------/ \n";
	cout << "\n";
	cout << "\\-----EXercise5-----/ \n";
	cout << "\n";

	Utils util;

	cout << "Se crea una Clase Util con el metodo check para poder probar funcionalidad\n";
	cout << "Recomiendo dejar un txt en la siguiente ruta con el siguiente nombre: C:\\temp\\Newtext.txt\n";

	bool utilcheck = util.check("C:\\temp\\Newtext.txt");

	cout << "Se comentaron lineas y se modificaron para que el programa ejecute, de otra forma el programa da error." << "\n";
	cout << "Revisarlas puntual mente desde el codigo fuente." << "\n" << "\n";
	cout << "Los siguientes comentarios son review del codigo original" << "\n";
	cout << "////Falta documentacion del metodo check y un nombre mas descriptivo" << "\n";
	cout << "//bool Utils::check(std::string arg)//El string arg deberia llamarse filePath. Tambien enviaria una lista de valores a comparar" << "\n";
	cout << "//{" << "\n";
	cout << "//	auto foo = fopen(arg, \"rb\");//El codigo no funciona, hay que convertir string arg a char*" << "\n";
	cout << "//	if (foo != nullptr)//La variable foo se deberia llamar file" << "\n";
	cout << "//	{" << "\n";
	cout << "//		fseek(foo, 0, SEEK_END);" << "\n";
	cout << "//		size_t baz = ftell(foo);// baz deberia llamarse length" << "\n";
	cout << "//		rewind(foo);" << "\n";
	cout << "//" << "\n";
	cout << "//		std::string bar;// Nombraria a la variable como contentFile" << "\n";
	cout << "//		bar.resize(baz);" << "\n";
	cout << "//		fread(&bar[0], baz, 1, foo);" << "\n";
	cout << "//" << "\n";
	cout << "//		if (bar.find(\"nick\") != std::string::npos)// Se puede anidar con un OR los dos IF" << "\n";
	cout << "//		{" << "\n";
	cout << "//			return true; // crear una variable para guardar el true" << "\n";
	cout << "//		}" << "\n";
	cout << "//		else if (bar.find(\"mail\") != std::string::npos);//No debveria llevar ; al final del if" << "\n";
	cout << "//		{" << "\n";
	cout << "//			return true;" << "\n";
	cout << "//		}" << "\n";
	cout << "//	}" << "\n";
	cout << "//	fclose(foo); //El fclose deberia ir antes de salir del if, si esta fuera y el archivo no se encuentra da error" << "\n";
	cout << "//Falta el return del result inicializada en false al final de la funcion" << "\n";
	cout << "//Seteada en los if de \"nick\" y \"mail\" \n";
	cout << "//}" << "\n";

	return 0;
}



bool Utils::check(std::string arg)
{
	bool result = false;
	char* caracter;

	caracter = (char*)malloc(sizeof(arg));

	strcpy_s(caracter, (sizeof(arg)), arg.c_str());
	cout << "Se intentara abrir el archivo : " << caracter << "\n";
#pragma warning(suppress : 4996)
	auto foo = fopen(caracter, "rb");
	if (foo != nullptr)
	{
		cout << "fopen funciona correctamente \n";
		fseek(foo, 0, SEEK_END);
		size_t baz = ftell(foo);
		rewind(foo);

		std::string bar;
		bar.resize(baz);
		fread(&bar[0], baz, 1, foo);

		std::size_t found = bar.find("nick");
		std::size_t found2 = bar.find("mail");

		if ((bar.find("nick") != std::string::npos) || (bar.find("mail") != std::string::npos))
		{
			result = true;
		}
		fclose(foo);
	}
	else
	{
		cout << "Problema al abrir el archivo. \n";
	}
	return result;
}