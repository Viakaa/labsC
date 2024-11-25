#include <iostream>
#include <string>
using namespace std;

class Institute {
private:
    string name;
    string address;

public:
    Institute(const string& name = "", const string& address = "")
        : name(name), address(address) {}

    string getName() const { return name; }
    string getAddress() const { return address; }

    friend ostream& operator<<(ostream& os, const Institute& institute) {
        os << "Institute: " << institute.name << ", Address: " << institute.address;
        return os;
    }
};

class Group {
private:
    string name;
    int studentCount;
    double averageScore;

public:
    Group(const string& name = "", int studentCount = 0, double averageScore = 0.0)
        : name(name), studentCount(studentCount), averageScore(averageScore) {}

    string getName() const { return name; }
    int getStudentCount() const { return studentCount; }
    double getAverageScore() const { return averageScore; }

    friend ostream& operator<<(ostream& os, const Group& group) {
        os << "Group: " << group.name << ", Students: " << group.studentCount
            << ", Average Score: " << group.averageScore;
        return os;
    }
};

class Faculty {
private:
    string fullName;
    string shortName;
    Institute institute;
    Group groups[100];
    int groupCount;

public:
    Faculty(const string& fullName = "", const string& shortName = "", const Institute& institute = {})
        : fullName(fullName), shortName(shortName), institute(institute), groupCount(0) {}

    string getFullName() const { return fullName; }
    string getShortName() const { return shortName; }
    Institute getInstitute() const { return institute; }

    bool belongsToInstitute(const string& instituteName) const {
        return institute.getName() == instituteName;
    }

    void addGroup(const Group& group) {
        if (groupCount < 100) {
            groups[groupCount++] = group;
        }
        else {
            cout << "Cannot add more groups. Maximum capacity reached.\n";
        }
    }

    void removeGroup(const string& groupName) {
        for (int i = 0; i < groupCount; ++i) {
            if (groups[i].getName() == groupName) {
                for (int j = i; j < groupCount - 1; ++j) {
                    groups[j] = groups[j + 1];
                }
                --groupCount;
                return;
            }
        }
        cout << "Group not found.\n";
    }

    int getStudentCountInGroup(const string& groupName) const {
        for (int i = 0; i < groupCount; ++i) {
            if (groups[i].getName() == groupName) {
                return groups[i].getStudentCount();
            }
        }
        cout << "Group not found.\n";
        return 0;
    }

    Group getTopGroup() const {
        if (groupCount == 0) {
            cout << "No groups available.\n";
            return {};
        }

        Group topGroup = groups[0];
        for (int i = 1; i < groupCount; ++i) {
            if (groups[i].getAverageScore() > topGroup.getAverageScore()) {
                topGroup = groups[i];
            }
        }
        return topGroup;
    }

    int countAboveAverageStudents(double averageScore) const {
        int count = 0;
        for (int i = 0; i < groupCount; ++i) {
            if (groups[i].getAverageScore() > averageScore) {
                count += groups[i].getStudentCount();
            }
        }
        return count;
    }

    friend ostream& operator<<(ostream& os, const Faculty& faculty) {
        os << "Faculty: " << faculty.fullName << " (" << faculty.shortName << ")\n"
            << faculty.institute << "\nGroups:\n";
        for (int i = 0; i < faculty.groupCount; ++i) {
            os << faculty.groups[i] << "\n";
        }
        return os;
    }
};

int main() {
       Institute inst("IT STEP University", "Zamarstynivska street 83A");
       Faculty faculty("Computer Science", "CS", inst);
   
       faculty.addGroup(Group("CS-21", 14, 85.4));
       faculty.addGroup(Group("CS-22", 16, 90.1));
       faculty.addGroup(Group("CS-23", 17, 78.5));
   
 
    cout << faculty << endl;
    cout << "Top group: " << faculty.getTopGroup() << endl;
    cout << "Students with scores above 78: " << faculty.countAboveAverageStudents(78) << endl;

    return 0;
}
