
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
	GetHDSerialByCmd(lpszHDSerial);		//”≤≈Ã–Ú¡–∫≈
	
	string MachineCode = md5(string(lpszCpu) + string(lpszHDSerial));

	ofstream fout;
	string file_path = "hardware_information.txt";
	fout.open(file_path);
	fout << MachineCode << endl;
	fout.close();
	return 0;
}





