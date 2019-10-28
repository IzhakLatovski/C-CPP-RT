#include "parser.h"

using namespace std;

parser_t::parser_t()
{
	tokenizer_m=new tokenizer_t;
	analyzer_m=new analyzer_t;
}

parser_t::~parser_t()
{
	delete tokenizer_m;
	delete analyzer_m;
}