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
		bad() - Returns true if a reading or writing operation fails. For example, 
			    in the case that we try to write to a file that is not open for writing 
				or if the device where we try to write has no space left.
		fail() - Returns true in the same cases as bad()

		eof() - Returns true if a file open for reading has reached the end.

		good() - It is the most generic state flag: it returns false in the same cases in 
				which calling any of the previous functions would return true.
	
	*/
	std::fstream file;

	file.open("test.txt", std::ios::out | std::ios::ate | std::ios::in);

	if (file.is_open())
	{
		file << "Good morning!\n";
		file << "How are you\n";
		file << "I am fine\n";
		file << "How was your night!!";
		file.close();
	}
	else {
		std::cout<<"This file is not working "<<std::endl;
	}


	


}
