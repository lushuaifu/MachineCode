#include<fstream>
#include <iostream> 
#include <string> 
#include "AESEncryptor.h"


int main(int argc, char *argv[]){
	unsigned char src[4] = { 0x28, 0x7e, 0x88, 0x16 };
	AesEncryptor aesE(src);

	std::string strInfor = "";
	std::string file_path = "hardware_information.txt";
	std::ifstream fin;
	fin.open(file_path);
	getline(fin, strInfor);

	std::string encryptS = aesE.EncryptString(strInfor);

	std::string decryptS = aesE.DecryptString(encryptS);
	std::ofstream fout;
	std::string path = "register_code.txt";
	fout.open(path);
	fout << encryptS << std::endl;
	return 0;
}