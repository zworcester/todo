#include "Argument.h"

argparse::Argument::Argument(string value, argparse::ARGUMENT_TYPE type)
	:	value{value},
		type{type}
{}

argparse::Argument::Argument(string value, string type)
	:	value{value}
{
	this->type = STRINGS_AS_TYPES.at(type);
}

int argparse::Argument::getType() {
	return static_cast<int>(this->type);
}

string argparse::Argument::getTypeString() {
	switch(this->type) {
	case argparse::ARGUMENT_TYPE::NONE:
		return "none";
	case argparse::ARGUMENT_TYPE::INTEGER:
		return "int";
	case argparse::ARGUMENT_TYPE::REAL_NUMBER:
		return "real";
	case argparse::ARGUMENT_TYPE::BOOLEAN:
		return "bool";
	case argparse::ARGUMENT_TYPE::CHARACTER:
		return "char";
	case argparse::ARGUMENT_TYPE::STRING:
		return "string";
	default:
		return "none";
	};
}

string argparse::Argument::asString() {
	return this->value;
}

char argparse::Argument::asChar() {
	if (this->type != argparse::ARGUMENT_TYPE::CHARACTER) {
		throw "REPLACE_ME_WITH_INVALID_CONVERSION_EXCEPTION";
	}
	else {
		return this->value[0];
	}
}
