#include <iostream>
#include <string>

struct Student {
    std::string name;
    std::string subject;
    int retakes;
};

int main() {
    const int student_number = 5; 
    Student students[student_number] = {
        {"Danyliuk Olena", "Mathematics", 3},
        {"Sydorenko Anna", "Physics", 1},
        {"Sukhai Roman", "Chemistry", 2},
        {"Honcharuk Dmytro", "History", 5},
        {"Melnyk Iryna", "Informatics", 4}
    };

    for (int i = 0; i < student_number - 1; i++) {
        for (int j = 0; j < student_number - i - 1; j++) {
            if (students[j].retakes > students[j + 1].retakes) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    std::cout << "List of students sorted by the number of retakes:\n";
    for (int i = 0; i < student_number; i++) {
        std::cout << students[i].name << ", " << students[i].subject << ": " << students[i].retakes << " retakes\n";
    }

    return 0;
}
