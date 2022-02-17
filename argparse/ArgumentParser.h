#ifndef ARGPARSE_H
#define ARGPARSE_H

#include <string>
#include <vector>
#include "Argument.h"

using std::string, std::vector;

namespace argparse {

	class ArgumentParser {
	public:
		ArgumentParser();
		~ArgumentParser();
	private:
		string* prog;
		string* usage;
		string* description;
		string* epilog;

		vector<ArgumentParser*> parents;

		string* prefixChars;
		string* argumentDefault;
		bool addHelp;
		bool allowAbbreviation;	
	};
}

#endif
