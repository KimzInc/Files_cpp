// intro_files.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>

int main()
{
	/*
		NOTE 
		DEFAULT MODE (FLAGS)
		fstream - ios::out | ios::in
		ifstream - ios::in
		ofstream - ios::out

		
		ios::in	    Open for input operations.
		ios::out    Open for output operations.
		ios::binary	Open in binary mode.
		ios::ate	Set the initial position at the end of the file.
						
		ios::app	All output operations are performed at the end of the file, 
					appending the content to the current content of the file.
		ios::trunc	If the file is opened for output operations and it already existed,
					its previous content is deleted and replaced by the new one.'

		Checking state flags
		bad() -badbit(1)- Returns true if a reading or writing operation fails. For example, 
			    in the case that we try to write to a file that is not open for writing 
				or if the device where we try to write has no space left.
		fail() -failbit(4)- Returns true in the same cases as bad()

		eof() -eofbit(2)- Returns true if a file open for reading has reached the end.

		good() -goodbit(0) - It is the most generic state flag: it returns false in the same cases in 
				which calling any of the previous functions would return true.


				1 - 001
				2 - 010
				4 - 100

				bitwise operators: & | ^


		FOR INPUT
		tellg - tell get  - tell where is the reading pointer
		seekg - seek get - set reading pointer as specific position 


		seekg(how_many_bytes_from_the_flag_place, flag);

		possible flags:
		ios::beg - (begin) set from the begin (default)
		ios::end - set from the end
		ios::cur  - (current) set from current place


	
	*/
	std::fstream file;

	file.open("test.txt", std::ios::in | std::ios::binary);

	

	if (file.is_open()) {
		std::string buffer;

		file.seekg(0, std::ios::end);

		std::streampos sizeofFile = file.tellg();


		file.seekg(0);

		std::cout << "The size of the file is " << sizeofFile << " bytes" << std::endl;

		do
		{
			file >> buffer;
			std::cout << buffer << std::endl;

		} while (!file.eof());

		std::cout << (file.rdstate() ^ std::ifstream::eofbit) << std::endl;

		if ((file.rdstate() ^ std::ifstream::eofbit) == 0) {
			file.clear();

			std::cout << file.tellg() << std::endl;
			file >> buffer;
			std::cout << buffer << std::endl;
		}

	
		file.close();
	}
	else {
		std::cout << "This file is not working " << std::endl;
	}



	return 0;

}
