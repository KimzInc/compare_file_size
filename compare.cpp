// Written by Felix @kimzaf (Twitter handle)
//

#include <iostream>
#include<fstream>

bool allFilesEqual(std::fstream*, std::fstream*);

int sizeOfFile(std::fstream*);

int main()
{
	/*
	read(where to read, how many bits to read)

	*/
	std::fstream myFile1, myFile2;

	myFile1.open("text1.txt", std::ios::in | std::ios::ate | std::ios::ate);
	myFile2.open("text2.txt", std::ios::in | std::ios::ate | std::ios::ate);

	if (myFile1.is_open() && myFile2.is_open())
	{
		if(allFilesEqual(&myFile1, &myFile2)){
			std::cout << "Files are equal" << std::endl;
		}
		else
		{
			std::cout << "Files are not equal" << std::endl;
		}
		
	}
	else
	{
		std::cout << "Error reading the file!!!!" << std::endl;
	}

}


bool allFilesEqual(std::fstream* file1, std::fstream* file2) {

	int filesSize1 = sizeOfFile(file1);

	int filesSize2 = sizeOfFile(file2);

	if (filesSize1 == filesSize2)
	{
		//std::cout << "Files are Equal\n";
		return true;
	}
	else {
		//std::cout << "Files are not equal\n";
		return false;
	}

}

int sizeOfFile(std::fstream* file) {
	file->seekg(0, std::ios::end);

	int fileSize = file->tellg();
	file->seekg(0, std::ios::beg);  //set at the beginning so that it does not give problems up there

	return fileSize;
}
