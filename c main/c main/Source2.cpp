#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

//std::string paths;
int ver();

int main()
{
	int x;
	char* docdir = getenv("USERPROFILE");
	if (!docdir)
	{
		std::cout << "Cannot get user profile...\n";
		//std::cin >> x;
		return 1;
	}
	std::string path(docdir);
	path += "\\Desktop\\CUSA00552_patch\\eboot.bin";
	//std::cout << path << "\n";

	std::time_t result = std::time(nullptr);	//Get time in result var
	//std::cout << std::ctime(&result); Not
	char dateTime[24];
	std::cout << "Current time: ";
	std::strncpy(dateTime, ctime(&result), 24); //Convert ctime to char array

	for (int i = 0; i < 24; i++)
	{
		std::cout << dateTime[i];
	}

	//std::cin >> x;
	std::cout << "\n" << "Reading File...\n";
	//std::cout << path << "\n";
	std::fstream eboot(path, std::ios::in | std::ios::out);	//Open file for read and write 
	if (!eboot)
	{
		std::cout << "Cannot open file to read...\n";
		//std::cin >> x;
		return 1;
	}
	std::cout << "Writing to chars...\n\n";
	eboot.seekg(16928724, eboot.beg);	//Month starting char posision in eboot.bin, taking next 48 chars to get date and build into array
	auto chars_pos = eboot.tellg();		//Add 48 chars to chars_pos

	char chars[48] = { 0 };	//Create char array for data mainpulation
	eboot.read(chars, 48);	//Write 48 chars into created array
	std::cout << "Time in file: ";
	for (int i = 0; i < 48; i++)
	{
		std::cout << chars[i];
	}
	std::cout << "\n";
	chars[0] = dateTime[4];	//Write date and time posistions from char array to the char array holding data from the file
	chars[1] = dateTime[5];
	chars[2] = dateTime[6];
	chars[4] = dateTime[8];
	chars[5] = dateTime[9];
	chars[12] = dateTime[11];
	chars[13] = dateTime[12];
	chars[15] = dateTime[14];
	chars[16] = dateTime[15];
	chars[18] = dateTime[17];
	chars[19] = dateTime[18];

	if (chars[47] == '9') //Check first digit in version
	{
		if (chars[46] == '9')	//Check second digit in version
		{
			if (chars[45] == '9')	//Check third digit in version
			{
				chars[44]++;
				chars[45] = '0';
				chars[46] = '0';
				chars[47] = '0';
				std::cout << "In-Game Build Version: ";
				std::cout << chars[44];
				std::cout << chars[45];
				std::cout << chars[46];
				std::cout << chars[47] << "\n";
			}
			else
			{
				chars[45]++;
				chars[46] = '0';
				chars[47] = '0';
				std::cout << "In-Game Build Version: ";
				std::cout << chars[44];
				std::cout << chars[45];
				std::cout << chars[46];
				std::cout << chars[47] << "\n";
			}

		}
		else
		{
			chars[46]++;
			chars[47] = '0';
			std::cout << "In-Game Build Version: ";
			std::cout << chars[44];
			std::cout << chars[45];
			std::cout << chars[46];
			std::cout << chars[47] << "\n";
		}
	}
	else
	{
		chars[47]++;
		std::cout << "In-Game Build Version: ";
		std::cout << chars[44];
		std::cout << chars[45];
		std::cout << chars[46];
		std::cout << chars[47] << "\n";
	}
	std::cout << "Time in chars[] memory: ";
	for (int i = 0; i < 21; i++)
	{
		std::cout << chars[i];
	}
	std::cout << "\n";
	//std::cout << dateTime[8];
	//chars[0]++;
	eboot.seekg(chars_pos, eboot.beg);
	eboot.write(chars, 48);	//Write to eboot with updated 48 chars
	eboot.close();
	ver();	//This function increments the pkg and game tile version by 1
}

int ver()
{
	char* docdir = getenv("USERPROFILE");
	std::string path(docdir);
	path += "\\Desktop\\CUSA00552_patch\\sce_sys\\param.sfo";
	int x;
	std::fstream version(path, std::ios_base::in | std::ios_base::out);
	if (!version)
	{
		std::cout << "Cannot open output file to read...\n";
		std::cin >> x;
		return 1;
	}
	version.seekg(757, version.beg);
	auto chars_pos = version.tellg();

	char chars[4] = { 0 };
	version.read(chars, 4);

	if (chars[3] == '9')
	{

		if (chars[2] == '9')
		{
			chars[0]++;
			chars[2] = '0';
			chars[3] = '0';
			std::cout << "Param Build Version: ";
			std::cout << chars[0];
			std::cout << chars[1];
			std::cout << chars[2];
			std::cout << chars[3] << "\n";
		}
		else
		{
			chars[2]++;
			chars[3] = '0';
			std::cout << "Param Build Version: ";
			std::cout << chars[0];
			std::cout << chars[1];
			std::cout << chars[2];
			std::cout << chars[3] << "\n";
		}
	}
	else
	{
		chars[3]++;
		std::cout << "Param Build Version: ";
		std::cout << chars[0];
		std::cout << chars[1];
		std::cout << chars[2];
		std::cout << chars[3] << "\n";
	}


	version.seekg(chars_pos, version.beg);
	version.write(chars, 4);
	//file.close();

	///////////////////////////////////////////////////////////////////
	// Part 1 was for file version, part 2 is for game title version //
	///////////////////////////////////////////////////////////////////

	version.seekg(1526, version.beg);
	auto chars_pos2 = version.tellg();

	std::cout << "Game Title Version: ";
	std::cout << chars[0];
	std::cout << chars[1];
	std::cout << chars[2];
	std::cout << chars[3] << "\n";

	version.seekg(chars_pos2, version.beg);
	version.write(chars, 4);
	version.close();
	//std::cout << "Enter a key to close";
	//std::cin >> x;
	return 0;
}