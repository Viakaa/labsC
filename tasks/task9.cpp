#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

template <typename T>
class DynamicArray {
protected:
    vector<T> array;

public:
    DynamicArray() = default;
    virtual ~DynamicArray() = default;

    void add(const T& element) {
        array.push_back(element);
    }

    T get(size_t index) const {
        if (index < array.size()) {
            return array[index];
        } else {
            throw out_of_range("Index out of range");
        }
    }

    size_t size() const {
        return array.size();
    }

    virtual void input() = 0; 
    virtual void output() const = 0; 
};

struct Group {
    string name;
    int studentCount;
    double averageScore;

    Group(const string& name = "", int studentCount = 0, double averageScore = 0.0)
        : name(name), studentCount(studentCount), averageScore(averageScore) {}

    friend ostream& operator<<(ostream& os, const Group& group) {
        os << "Group: " << group.name
           << ", Students: " << group.studentCount
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
};

class GroupArray : public DynamicArray<Group> {
public:
    void input() override {
        int n;
        cout << "Enter the number of groups: ";
        cin >> n;
        cin.ignore();

        for (int i = 0; i < n; ++i) {
            Group group;
            cin >> group;
            add(group);
        }
    }

    void output() const override {
        cout << "Groups in the array:\n";
        for (const auto& group : array) {
            cout << group << endl;
        }
    }
};

int main() {
    try {
        GroupArray groupArray;

        groupArray.input();

        groupArray.output();

        groupArray.add(Group("NewGroup", 20, 88.5));
        cout << "\nAfter adding a new group:\n";
        groupArray.output();

        cout << "\nGroup at index 0: " << groupArray.get(0) << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
