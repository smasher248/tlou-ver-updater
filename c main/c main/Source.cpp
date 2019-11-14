#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <Windows.h>

int main()
{
	std::string lineOne = " PSF  „  ð                 	                              $ %   0      /       D   B       H   I       L   X Ž      P   d       P  o       T  †       X  Ÿ       l  ¸       €  Ñ       ”  ê       ¨        ¼        Ð  5      ä  @#   €   è  F\n";
	//std::string s2 = "The Last of Us - Custom Build";
	int lineNo = 0;
	std::fstream paramr("C:\\Users\\smasher248\\Desktop\\CUSA00552\\ff.txt");
	std::string line;
	while (std::getline(paramr, line))
	{
		lineNo++;
	}
	char* tab2 = &line[0];

	// 1181 - 2.02 start 
	// 412 2.02 ver start 
	if (tab2[415] == '9')
	{

		if (tab2[414] == '9')
		{
			tab2[412]++;
			tab2[414] = '0';
			tab2[415] = '0';
			std::cout << tab2[412];
			std::cout << tab2[413];
			std::cout << tab2[414];
			std::cout << tab2[415];
		}
		else
		{
			tab2[414]++;
			tab2[415] = '0';
			std::cout << tab2[414];
			std::cout << tab2[415];
		}
	}
	else
	{
		std::cout << tab2[412];
		std::cout << tab2[413];
		std::cout << tab2[414];
		std::cout << tab2[415];
		tab2[415]++;

	}
	
	if (tab2[1184] == '9')
	{

		if (tab2[1183] == '9')
		{
			tab2[1181]++;
			tab2[1183] = '0';
			tab2[1184] = '0';
			std::cout << tab2[1181];
			std::cout << tab2[1182];
			std::cout << tab2[1183];
			std::cout << tab2[1184];
		}
		else
		{
			tab2[414]++;
			tab2[415] = '0';
			std::cout << tab2[1183];
			std::cout << tab2[1184];
		}
	}
	else
	{
		std::cout << tab2[1181];
		std::cout << tab2[1182];
		std::cout << tab2[1183];
		std::cout << tab2[1184];
		tab2[1184]++;

	}
	
	paramr.close();
	std::ofstream paramw("C:\\Users\\smasher248\\Desktop\\CUSA00552\\ff.txt" /*std::ofstream::app*/);
	if (!paramw)
	{
		std::cout << "Cannot open output file\n";
		return 1;
	}
	paramw << lineOne;
	for (int i = 0; i < 1303; i++)
	{
		line = tab2[i];
		paramw << line;
	}
	paramw.close();
}