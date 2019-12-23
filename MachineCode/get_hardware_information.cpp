
//#pragma warning(disable:4996)
#include "get_hardware_information.h"
#include "base64.h"
#include "md5.h"
#include <iostream>
#include <fstream>

using namespace std;


int get_hardware_information()
{
	char lpszCpu[128] = "";
	char lpszHDSerial[128] = "";
	GetCpuSerialByCmd(lpszCpu, 128);	//CPU–Ú¡–∫≈

	int out = 0, i = 10;
	MasterHardDiskSerial a;
	char SerialNumber[1024] = { "" };
	std::cout << "i" << i-- << std::endl;
	memset(&SerialNumber, 0, sizeof(SerialNumber));//”≤≈ÃID

	out = a.GetSerialNo(SerialNumber);
	string MachineCode = md5(string(lpszCpu) + string(SerialNumber));

	ofstream fout;
	string file_path = "hardware_information.txt";
	fout.open(file_path);
	fout << MachineCode << endl;
	fout.close();
	return 0;
}





