#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

template <typename T>
class AbstractArray {
protected:
    T* array;
    int size;
    int capacity;

    void resize() {
        capacity *= 2;
        T* newArray = new T[capacity];
        for (int i = 0; i < size; i++) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
    }

public:
    AbstractArray(int initialCapacity = 5)
        : size(0), capacity(initialCapacity) {
        array = new T[capacity];
    }

    virtual ~AbstractArray() {
        delete[] array;
    }

    virtual void add(const T& item) = 0;
    virtual void remove(const string& name) = 0;
    virtual void print() const = 0;
};

class Group {
private:
    string name;
    int numStudents;
    double averageScore;

public:
    Group() : name(""), numStudents(0), averageScore(0.0) {}

    Group(string name, int numStudents, double averageScore)
        : name(name), numStudents(numStudents), averageScore(averageScore) {}

    string getName() const { return name; }
    int getNumStudents() const { return numStudents; }
    double getAverageScore() const { return averageScore; }

    void print() const {
        cout << "Group: " << name << ", Students: " << numStudents
             << ", Avg. Score: " << averageScore << "\n";
    }
};

class FacultyGroups : public AbstractArray<Group> {
private:
    string facultyName;

public:
    FacultyGroups(string facultyName, int initialCapacity = 5)
        : AbstractArray<Group>(initialCapacity), facultyName(facultyName) {}

    void add(const Group& group) override {
        if (size == capacity) {
            resize();
        }
        array[size++] = group;
    }

    void remove(const string& groupName) override {
        for (int i = 0; i < size; i++) {
            if (array[i].getName() == groupName) {
                for (int j = i; j < size - 1; j++) {
                    array[j] = array[j + 1];
                }
                size--;
                return;
            }
        }
        cout << "Group not found: " << groupName << "\n";
    }

    void print() const override {
        cout << "Faculty: " << facultyName << "\n";
        for (int i = 0; i < size; i++) {
            array[i].print();
        }
    }

    Group getTopGroup() const {
        if (size == 0) {
            throw runtime_error("No groups in the list.");
        }
        Group topGroup = array[0];
        for (int i = 1; i < size; i++) {
            if (array[i].getAverageScore() > topGroup.getAverageScore()) {
                topGroup = array[i];
            }
        }
        return topGroup;
    }
};

int main() {
    FacultyGroups csFaculty("Computer Science");

    Group g1("CS-21", 14, 85.4);
    Group g2("CS-22", 16, 90.1);
    Group g3("CS-23", 17, 78.5);

    csFaculty.add(g1);
    csFaculty.add(g2);
    csFaculty.add(g3);

    cout << "All groups:\n";
    csFaculty.print();

    cout << "\nRemoving group CS-23...\n";
    csFaculty.remove("CS-23");

    cout << "All groups after removal:\n";
    csFaculty.print();

    try {
        Group topGroup = csFaculty.getTopGroup();
        cout << "\nTop group:\n";
        topGroup.print();
    }
    catch (const runtime_error& e) {
        cout << e.what() << "\n";
    }

    return 0;
}
