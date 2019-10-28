#include "analyzer.h"
#include <string>
#include <string.h>
#include <iostream>

using namespace std;

analyzer_t::analyzer_t()
{
	lineNumber_m=0;
	predefined_m=0;
	plus_m=0;
	minus_m=0;
    roundBraces_m=0;
    squareBraces_m=0;
    curlyBraces_m=0;
    ifElse_m=0;

    string predefinedString[]={"char","short","int","long","float","double","void",};
    string operatorsString[]={"++","--","==","->","=","+","-","*","&","<<",">>"};
    string keywordsString[]={"if","else","for","while","class","private","public","protected","main","const","virtual",};

	predefinedSet_m.insert(predefinedString);
	operatorsSet_m.insert(operatorsString);
	keywordsSet_m.insert(keywordsString);

	delimitersString_m="()[]{};<>=+-*&";
}

void analyzer_t::analyze(queue<string>& tokens, size_t lineNumber)
{
	if(!strcmp(str.c_str(),"main"))
	{

	}
	else
	{
			cout<<"Error! main is not at the begining"<<endl;		
	}
}

void analyzer_t::checkOpeningBraces()
{
	if(roundBraces_m>0 || squareBraces_m>0 || curlyBraces_m>0)
	{
			cout<<"Error! Too much ( opening braces"<<endl;		
	}
	else if(squareBraces_m>0)
	{
			cout<<"Error! Too much [] opening braces"<<endl;		
	}
	else if(curlyBraces_m>0)
	{
			cout<<"Error! Too much {} opening braces"<<endl;		
	}
}

void analyzer_t::checkClosingBraces(const string& str)
{
	if(!strcmp(str.c_str(),"("))
	{
		roundBraces_m++;
	}
	else if(!strcmp(str.c_str(),")"))
	{
		if(roundBraces_m!=0)
		{
			roundBraces_m--;
		}
		else
		{
			cout<<"Error in line "<<lineNumber_m<<" . Round braces () weren't open"<<endl;
		}
	}
	else if(!strcmp(str.c_str(),"["))
	{
		squareBraces_m++;
	}
	else if(!strcmp(str.c_str(),"]"))
	{
		if(squareBraces_m!=0)
		{
			squareBraces_m--;
		}
		else
		{
			cout<<"Error in line "<<lineNumber_m<<" . Square braces [] weren't open"<<endl;
		}
	}
	else if(!strcmp(str.c_str(),"{"))
	{
		curlyBraces_m++;
	}
	else if(!strcmp(str.c_str(),"}"))
	{
		if(curlyBraces_m!=0)
		{
			curlyBraces_m--;
		}
		else
		{
			cout<<"Error in line "<<lineNumber_m<<" . Curly braces {} weren't open"<<endl;
		}
	}
}

void analyzer_t::checkWords(const string& str)
{
	if(str[0]=='_' || (str[0]>='a' && str[0]<='z') || (str[0]>='A' && str[0]<='Z'))
	{

	}
	else
	{
		cout<<"Error in line "<<lineNumber_m<<" . Bad name"<<endl;
	}
}

void analyzer_t::checkPredefined()
{
	if(predefined_m)
	{
		cout<<"Error in line "<<lineNumber_m<<" . Predefined"<<endl;
		predefined_m=false;
	}
	else
	{
		predefined_m=true;
	}
}

void analyzer_t::checkPlusMinus(const string& str)
{
	if(!strcmp(str.c_str(),"+"))
	{
		if(plus_m<=1)
		{
			plus_m++;
		}
		else
		{
			plus_m=0;
			cout<<"+++ is not allowed"<<endl;
		}
	}
	else if(!strcmp(str.c_str(),"-"))
	{
		if(minus_m<=1)
		{
			minus_m++;
		}
		else
		{
			minus_m=0;
			cout<<"--- is not allowed"<<endl;
		}
	}
}

void analyzer_t::checkIfElse(const string& str)
{
	if(!strcmp(str.c_str(),"if"))
	{
		ifElse_m++;
	}
	else if(!strcmp(str.c_str(),"else"))
	{
		if(ifElse_m!=0)
		{
			ifElse_m--;
		}
		else
		{
			cout<<"Error in line "<<lineNumber_m<<" . No if to do else"<<endl;
		}
	}
}