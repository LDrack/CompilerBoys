//#include "SymbolTable.h"

#include "Parser.h"
#include "Scanner.h"
#include <sys/timeb.h>
#include <wchar.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 5) {
		cout << "argc: " << argc << endl;
		cout << "Usage: MIECCompiler.exe -in <infile.miec> -out <file.iex>" << endl;
	}
	else if (strcmp(argv[1], "-in") || strcmp(argv[3], "-out")) {
		cout << "argc: " << argc << endl;
		cout << "argv[1]: " << argv[1] << endl;
		cout << "argv[3]: " << argv[3] << endl;
		cout << "Usage: MIECCompiler.exe -in <infile.miec> -out <file.iex>" << endl;
	}
	else {
		wchar_t* fileName = coco_string_create(argv[2]);
		MIEC::Scanner* scanner = new MIEC::Scanner(fileName);
		MIEC::Parser* parser = new MIEC::Parser(scanner);

		//parser->tab = new MIEC::SymbolTable(parser);
		//parser->gen = new MIEC::CodeGenerator();

		parser->Parse();
		if (parser->errors->count == 0) {
			//parser->gen->Decode();
			//parser->gen->Interpret("MIEC.IN");
			cout << "No errors" << endl;
		}

		coco_string_delete(fileName);
		//delete parser->gen;
		//delete parser->tab;
		delete parser;
		delete scanner;
	}

   return 0;
}