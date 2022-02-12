#include "Parser.h"
#include "Scanner.h"
#include <sys/timeb.h>
#include <wchar.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>

using namespace std;


#define PRINT_DAC_STDOUT 0


// Singletons:
// set mInstance
std::unique_ptr<MIEC::SymbolTable> MIEC::SymbolTable::mInstance{nullptr};
MIEC::SymbolFactory* MIEC::SymbolTable::mFac{nullptr};
std::unique_ptr<MIEC::SymbolFactory> MIEC::SymbolFactory::mInstance{nullptr};






// -in ..\Testbench_fuer_Studierende\testfiles\ok\if.miec -out .\out.miex

const char* get_filename_ext(const char* filename) {
	const char* dot = strrchr(filename, '.');
	if (!dot || dot == filename) return "";
	return dot + 1;
}

void writeReport(const char* filename, const int errorcount) {
	ofstream o("MIECCompiler.report", ios::app);
	if (!o.good()) {
		o.close();
		return;
	}

	time_t rawtime;
	time(&rawtime);
	struct tm* timeinfo = localtime(&rawtime);

	o << put_time(timeinfo, "%c") << " => ";
	o << filename << ": ";

	if (errorcount == 0) {
		o << "OK" << endl;
	}
	else {
		o << "FAILED: " << errorcount << " error(s) detected" << endl;
	}

	o.close();
}

void printCoutMessage(char* filename, const int errorcount) {
	cout << filename << ": ";

	if (errorcount == 0) {
		cout << "OK" << endl;
	}
	else {
		cout << "FAILED: " << errorcount << " error(s) detected" << endl;
	}
}

int main(int argc, char* argv[])
{
	if (argc != 5) {
		cout << "argc: " << argc << endl;
		cout << "Usage: MIECCompiler.exe -in <infile.miec> -out <file.iex>" << endl;
	}
	else if (strcmp(argv[1], "-in") || strcmp(argv[3], "-out")) {
		cout << "Arguments -in and -out must be provided exactly." << endl;
		cout << "Usage: MIECCompiler.exe -in <infile.miec> -out <file.iex>" << endl;
	}
	else if (strcmp(get_filename_ext(argv[2]), "miec") || strcmp(get_filename_ext(argv[4]), "iex")) {
		cout << "Check file extensions. Only .miec and .iex are allowed." << endl;
		cout << "Usage: MIECCompiler.exe -in <infile.miec> -out <file.iex>" << endl;
	}
	else {
		wchar_t* fileName = coco_string_create(argv[2]);
		//wchar_t* fileName = MIEC::coco_string_create(argv[2]);
		MIEC::Scanner* scanner = new MIEC::Scanner(fileName);
		MIEC::Parser* parser = new MIEC::Parser(scanner);

		try {
			parser->Parse();
			printCoutMessage(argv[2], parser->errors->count);

			if (PRINT_DAC_STDOUT)
				parser->tab->Print(std::wcout);
			if (parser->errors->count == 0) {
				if (PRINT_DAC_STDOUT)
					parser->dac.Print(wcout);
				cout << "No errors" << endl;
			}
		} catch (const std::exception& e) {
			if (PRINT_DAC_STDOUT)
				std::cerr << e.what() << std::endl;
			delete parser;
			delete scanner;
			return -1;
		}

		writeReport(argv[2], parser->errors->count);

		//MIEC::coco_string_delete(fileName);
		coco_string_delete(fileName);
		delete parser;
		delete scanner;
	}

   return 0;
}
