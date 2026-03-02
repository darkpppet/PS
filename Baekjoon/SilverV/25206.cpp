#include <iostream>
#include <unordered_map>

using namespace std;

const unordered_map<string, double> gradeTable
{
    {"A+", 4.5},
    {"A0", 4.0},
    {"B+", 3.5},
    {"B0", 3.0},
    {"C+", 2.5},
    {"C0", 2.0},
    {"D+", 1.5},
    {"D0", 1.0},
    {"F", 0.0}
};

int main()
{
    double totalGrade = 0, totalCredit = 0;

    for (int i = 0; i < 20; i++)
    {
        string course, grade;
        double credit;

        cin >> course >> credit >> grade;

        if (grade == "P")
            continue;

        totalGrade += credit * gradeTable.at(grade);
        totalCredit += credit;
    }

    cout << totalGrade / totalCredit;
    return 0;
}