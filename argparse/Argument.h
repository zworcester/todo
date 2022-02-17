#pragma once

#include <string>
#include <sstream>
#include <map>
using std::string, std::stringstream, std::map;

namespace argparse {

	enum ARGUMENT_TYPE {
		NONE = -1,
		INTEGER = 0,
		REAL_NUMBER = 1,
		BOOLEAN = 2,
		CHARACTER = 3,
		STRING = 4
	};

	const map<string, ARGUMENT_TYPE> STRINGS_AS_TYPES = 
	{
		{"none", ARGUMENT_TYPE::NONE},
		{"int", ARGUMENT_TYPE::INTEGER},
		{"real", ARGUMENT_TYPE::REAL_NUMBER},
		{"bool", ARGUMENT_TYPE::BOOLEAN},
		{"char", ARGUMENT_TYPE::CHARACTER},
		{"string", ARGUMENT_TYPE::STRING}
	};

	class Argument {
	public:
		Argument(string value="", ARGUMENT_TYPE type=ARGUMENT_TYPE::NONE);
		Argument(string value, string type="none");
		~Argument() {}
		
		//long long asLongLong();
		//unsigned long long asULongLong();
		//long asLong();
		//unsigned long asULong();
		//int asInt();
		//unsigned asUInt();
		//short asShort();
		//unsigned short asUShort();

		char asChar();
		
		//float asFloat();
		//double asDouble();
		//long double asLongDouble();

		int getType();
		string getTypeString();
		string asString();
	private:
		ARGUMENT_TYPE type;
		string value;
	};
}
