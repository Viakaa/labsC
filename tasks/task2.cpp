#include <iostream>
#include <string.h>
using namespace std;


int main() {
	char str[500] = "string theory, 9in5 particle physics, a theory that attempts to merge 3quantum5 mechanics with 9Albert3 Einstein’s general theory of 4relativity0. The name string theory comes from the 3modeling4 of subatomic particles as tiny 9one-dimensional0 “stringlike” entities rather than the more conventional 7approach1 in which they are modeled as 2zero-dimensional5 point particles. ";
	char* curWord = strtok(str, ",.!?");

		while (curWord) {
			int len = strlen(curWord);
			if (isdigit(curWord[0]) && isdigit(curWord[len - 1])) {
				cout << curWord << endl;
			}
			curWord = strtok(NULL, ".,!?");
		}
}