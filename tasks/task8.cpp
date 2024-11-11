#include <iostream>
#include <string>
using namespace std;

const int MAX_GROUPS = 5;

class Institute {
private:
    string name;
    string address;

public:
    Institute(string name, string address)
        : name(name), address(address) {}

    string getName() const { return name; }
    string getAddress() const { return address; }
};

class Group {
private:
    string name;
    int numStudents;
    double averageScore;

public:
    Group(string name, int numStudents, double averageScore)
        : name(name), numStudents(numStudents), averageScore(averageScore) {}

    string getName() const { return name; }
    int getNumStudents() const { return numStudents; }
    double getAverageScore() const { return averageScore; }
};

class Faculty {
private:
    string fullName;
    string shortName;
    Institute institute;
    Group* groups[MAX_GROUPS];
    int groupCount;

public:
    Faculty(string fullName, string shortName, Institute institute)
        : fullName(fullName), shortName(shortName), institute(institute), groupCount(0) {}

    string getFullName() const { return fullName; }
    string getShortName() const { return shortName; }
    string getInstituteName() const { return institute.getName(); }

    bool isPartOfInstitute(const string& instName) const {
        return institute.getName() == instName;
    }

    int countAboveAverage(double averageScore) const {
        int count = 0;
        for (int i = 0; i < groupCount; i++) {
            if (groups[i]->getAverageScore() > averageScore) {
                count += groups[i]->getNumStudents();
            }
        }
        return count;
    }

    bool addGroup(Group* newGroup) {
        if (groupCount < MAX_GROUPS) {
            groups[groupCount++] = newGroup;
            return true;
        }
        return false;
    }
    bool removeGroup(const string& groupName) {
        for (int i = 0; i < groupCount; i++) {
            if (groups[i]->getName() == groupName) {
                for (int j = i; j < groupCount - 1; j++) {
                    groups[j] = groups[j + 1];
                }
                groupCount--;
                return true;
            }
        }
        return false;
    }
    int getGroupStudentCount(const string& groupName) const {
        for (int i = 0; i < groupCount; i++) {
            if (groups[i]->getName() == groupName) {
                return groups[i]->getNumStudents();
            }
        }
        return 0;
    }

    Group* getTopGroup() const {
        if (groupCount == 0) return nullptr;

        Group* topGroup = groups[0];
        for (int i = 1; i < groupCount; i++) {
            if (groups[i]->getAverageScore() > topGroup->getAverageScore()) {
                topGroup = groups[i];
            }
        }
        return topGroup;
    }
};

int main() {
    Institute inst("IT STEP University", "Zamarstynivska street 83A");
    Faculty fac("Computer Science", "CS", inst);

    Group g1("CS-21", 14, 85.4);
    Group g2("CS-22", 16, 90.1);
    Group g3("CS-23", 17, 78.5);

    fac.addGroup(&g1);
    fac.addGroup(&g2);
    fac.addGroup(&g3);

    cout << "Faculty: " << fac.getFullName() << " (" << fac.getShortName() << ")\n";
    cout << "Institute: " << fac.getInstituteName() << "\n";

    cout << "Checking if 'International relations' faculty is part of the institute " << inst.getName() << "...\n";
    cout << "Is 'International relations' part of the institute? "
        << (fac.isPartOfInstitute("International relations") ? "Yes" : "No") << "\n";

    cout << "Number of students with a score above 80: "
        << fac.countAboveAverage(80) << "\n";

    cout << "Number of students in group CS-21: "
        << fac.getGroupStudentCount("CS-21") << "\n";

    Group* topGroup = fac.getTopGroup();
    if (topGroup != nullptr) {
        cout << "Group with the highest average score: "
            << topGroup->getName() << " (" << topGroup->getAverageScore() << ")\n";
    }

    return 0;
}
