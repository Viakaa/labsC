#include <iostream>
#include <string>
using namespace std;

struct Student {
	std::string name;
	std::string lastName;
	std::string subject;
	int retakes;
};

int main() {
    const int student_number = 5;
    Student students[student_number] = {
        {"Olena","Danyliuk", "Mathematics", 3},
        {"Anna", "Sydorenko", "Physics", 1},
        {"Roman","Sukhai", "Chemistry", 2},
        {"Dmytro","Honcharuk", "History", 5},
        {"Iryna","Melnyk", "Informatics", 4}
    };

    for (int k = 0; k < student_number - 1; ++k)
        for (int i = 0; i < student_number - 1 - k; ++i)
        {
            if (students[i].retakes > students[i + 1].retakes) {
                Student temp = students[i + 1];
                students[i + 1] = students[i];
                students[i] = temp;
            }
        } 
        cout << "List of students sorted by the number of retakes:\n";
        for (int i = 0; i < student_number; ++i) {
            cout << students[i].name  <<" " << students[i].lastName << ", " << students[i].subject << ": " << students[i].retakes << " retakes\n";
        }

        return 0;
}