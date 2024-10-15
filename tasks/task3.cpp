#include <iostream>
#include <string.h>
#include <cctype>
using namespace std;


int main() {
	char str[500] = "string theory, 9in5 particle physics, a theory that attempts to merge 3quantum5 mechanics with 9Albert3 Einstein�s general theory of 4relativity0. The name string theory comes from the 3modeling4 of subatomic particles as tiny 9one-dimensional0 �stringlike� entities rather than the more conventional 7approach1 in which they are modeled as 2zero-dimensional5 point particles. ";
	char* context = nullptr;
	char* curWord = strtok_s(str, " ,.", &context);
	cout << "Words that have numbers at the start and at the ends of them:" << endl;
	while (curWord) {
		size_t len = strlen(curWord);
		if ((curWord[0] >= '0' && curWord[0] <= '9') &&
			(curWord[len - 1] >= '0' && curWord[len - 1] <= '9')) {
			cout << curWord << endl;
		}
		curWord = strtok_s(NULL, " .,", &context);
	}

	return 0;
}