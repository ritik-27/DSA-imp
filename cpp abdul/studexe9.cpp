#include <iostream>
using namespace std;
class Student
{
private:
    int rollno;
    string name;
    int phyMarks;
    int chemMarks;
    int mathMarks;

public:
    Student(int r, string n, int ph, int ch, int ma)
    {
        this->rollno = r;
        name = n;
        phyMarks = ph;
        chemMarks = ch;
        mathMarks = ma;
    }
    int total()
    {
        return (phyMarks + chemMarks + mathMarks);
    }
    char grade()
    {
        float average = total() / 3;
        if (average > 75)
            return 'A';
        else if (average >= 40 && average < 75)
            return 'B';
        else
            return 'C';
    }
};
int main()
{
    int roll;
    string name;
    int m, p, c;
    cout << "Enter Roll number of a Student: ";
    cin >> roll;
    cout << "Enter Name of a Student: ";
    cin >> name;
    cout << "Enter marks in 3 subjects: ";
    cin >> m >> p >> c;
    Student s1(roll, name, p, c, m);
    cout << "Total Marks:" << s1.total() << endl;
    cout << "Grade of Student:" << s1.grade() << endl;
    return 0;
}