#ifndef ANALYZER_H
#define ANALYZER_H

#include <set>
#include <string>
#include <queue>

using namespace std;

class analyzer_t
{
	public:
		virtual ~analyzer_t();
		analyzer_t();

		void analyze(queue<string>& tokens, size_t lineNumber);

		void checkClosingBraces(const string& str);
		void checkOpeningBraces();
		void checkWords(const string& str);
		void checkPlusMinus(const string& str);
		void checkIfElse(const string& str);
		void checkPredefined();

	private:
		analyzer_t(const analyzer_t& temp);
		analyzer_t& operator=(const analyzer_t& temp);

		set<string> predefinedSet_m;
		set<string> operatorsSet_m;
		set<string> keywordsSet_m;
		string delimitersString_m;

		size_t lineNumber_m;

		bool predefined_m;

        size_t plus_m;
        size_t minus_m;
        size_t roundBraces_m;
        size_t squareBraces_m;
        size_t curlyBraces_m;
        size_t ifElse_m;

};

#endif