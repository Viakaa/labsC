#include <iostream>
#include <string>
using namespace std;

template <typename T>
class BaseArray {
protected:
    T* array;      
    int size;       
    int capacity;   

public:
    BaseArray(int capacity = 10) : size(0), capacity(capacity) {
        array = new T[capacity];
    }

    virtual ~BaseArray() {
        delete[] array;
    }

    void add(const T& element) {
        if (size == capacity) {
            resize();
        }
        array[size++] = element;
    }

    T& get(int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        return array[index];
    }

    int getSize() const {
        return size;
    }

    virtual void input() = 0;
    virtual void output() const = 0;

protected:
    void resize() {
        capacity *= 2;
        T* newArray = new T[capacity];
        for (int i = 0; i < size; ++i) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
    }
};

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

public:
    Faculty(const string& fullName = "", const string& shortName = "", const Institute& institute = {})
        : fullName(fullName), shortName(shortName), institute(institute) {}

    string getFullName() const { return fullName; }
    string getShortName() const { return shortName; }
    Institute getInstitute() const { return institute; }

    friend ostream& operator<<(ostream& os, const Faculty& faculty) {
        os << "Faculty: " << faculty.fullName << " (" << faculty.shortName << ")\n"
            << faculty.institute;
        return os;
    }
};

class FacultyArray : public BaseArray<Faculty> {
public:
    FacultyArray(int capacity = 10) : BaseArray<Faculty>(capacity) {}
    void input() override {
        string fullName, shortName, instituteName, instituteAddress;

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

        cout << "Enter faculty full name: ";
        getline(cin, fullName);

        cout << "Enter faculty short name: ";
        getline(cin, shortName);

        cout << "Enter institute name: ";
        getline(cin, instituteName);

        cout << "Enter institute address: ";
        getline(cin, instituteAddress);

        add(Faculty(fullName, shortName, Institute(instituteName, instituteAddress)));
    }



    void output() const override {
        for (int i = 0; i < size; ++i) {
            cout << array[i] << endl;
        }
    }
};

int main() {
    FacultyArray facultyArray;

    facultyArray.input();  
    facultyArray.input(); 

    cout << "\nFaculties:\n";
    facultyArray.output();

    return 0;
}
