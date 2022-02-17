#include "ArgumentParser.h"

argparse::ArgumentParser::ArgumentParser() {
	this.prog = new string("program");
	this.addHelp = true;
	this.allowAbbreviation = false;

	this.usage = new string("Usage: " + this->prog + (this.addHelp ? "[-h]" : "") + "\n\nOptions:" + (this.addHelp ? " -h,--help\tprint this message, then quit" : ""))
	this.argumentDefault = nullptr;
	this.description = nullptr;
	this.epilog = nullptr;
	this.prefixChars = new string("-");

}

argparse::ArgumentParser::~ArgumentParser() {
	delete this.prog;
	delete this.usage;
	delete this.description;
	delete this.epilog;
	delete this.prefixChars;
	delete this.argumentDefault;
}
