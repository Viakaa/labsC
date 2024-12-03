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

    Institute(const Institute& other) : name(other.name), address(other.address) {}

    Institute& operator=(const Institute& other) {
        if (this != &other) {
            name = other.name;
            address = other.address;
        }
        return *this;
    }

    ~Institute() {}

    string getName() const { return name; }
    string getAddress() const { return address; }

    friend ostream& operator<<(ostream& os, const Institute& institute) {
        os << "Institute: " << institute.name << ", Address: " << institute.address;
        return os;
    }

    friend istream& operator>>(istream& is, Institute& institute) {
        cout << "Enter institute name: ";
        getline(is, institute.name);
        cout << "Enter institute address: ";
        getline(is, institute.address);
        return is;
    }

    bool operator==(const Institute& other) const {
        return name == other.name && address == other.address;
    }

    bool operator!=(const Institute& other) const {
        return !(*this == other);
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

    Group(const Group& other)
        : name(other.name), studentCount(other.studentCount), averageScore(other.averageScore) {}

    Group& operator=(const Group& other) {
        if (this != &other) {
            name = other.name;
            studentCount = other.studentCount;
            averageScore = other.averageScore;
        }
        return *this;
    }

    ~Group() {}

    string getName() const { return name; }
    int getStudentCount() const { return studentCount; }
    double getAverageScore() const { return averageScore; }

    friend ostream& operator<<(ostream& os, const Group& group) {
        os << "Group: " << group.name << ", Students: " << group.studentCount
           << ", Average Score: " << group.averageScore;
        return os;
    }

    friend istream& operator>>(istream& is, Group& group) {
        cout << "Enter group name: ";
        getline(is, group.name);
        cout << "Enter student count: ";
        is >> group.studentCount;
        cout << "Enter average score: ";
        is >> group.averageScore;
        is.ignore();
        return is;
    }

    Group operator+(const Group& other) const {
        return Group(name + " & " + other.name,
                     studentCount + other.studentCount,
                     (averageScore + other.averageScore) / 2);
    }

    bool operator>(const Group& other) const {
        return averageScore > other.averageScore;
    }

    operator double() const {
        return averageScore;
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

    Faculty(const Faculty& other)
        : fullName(other.fullName), shortName(other.shortName), institute(other.institute), groupCount(other.groupCount) {
        for (int i = 0; i < groupCount; ++i) {
            groups[i] = other.groups[i];
        }
    }

    Faculty& operator=(const Faculty& other) {
        if (this != &other) {
            fullName = other.fullName;
            shortName = other.shortName;
            institute = other.institute;
            groupCount = other.groupCount;
            for (int i = 0; i < groupCount; ++i) {
                groups[i] = other.groups[i];
            }
        }
        return *this;
    }

    ~Faculty() {}

    string getFullName() const { return fullName; }
    string getShortName() const { return shortName; }
    Institute getInstitute() const { return institute; }

    bool belongsToInstitute(const string& instituteName) const {
        return institute.getName() == instituteName;
    }

    void addGroup(const Group& group) {
        if (groupCount < 100) {
            groups[groupCount++] = group;
        } else {
            cout << "Cannot add more groups. Maximum capacity reached.\n";
        }
    }

    Group getTopGroup() const {
        if (groupCount == 0) {
            cout << "No groups available.\n";
            return {};
        }

        Group topGroup = groups[0];
        for (int i = 1; i < groupCount; ++i) {
            if (groups[i] > topGroup) {
                topGroup = groups[i];
            }
        }
        return topGroup;
    }

    friend ostream& operator<<(ostream& os, const Faculty& faculty) {
        os << "Faculty: " << faculty.fullName << " (" << faculty.shortName << ")\n"
           << faculty.institute << "\nGroups:\n";
        for (int i = 0; i < faculty.groupCount; ++i) {
            os << faculty.groups[i] << "\n";
        }
        return os;
    }

    friend istream& operator>>(istream& is, Faculty& faculty) {
        cout << "Enter faculty full name: ";
        getline(is, faculty.fullName);
        cout << "Enter faculty short name: ";
        getline(is, faculty.shortName);
        cout << "Enter institute details:\n";
        is >> faculty.institute;
        faculty.groupCount = 0;
        return is;
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

    return 0;
}