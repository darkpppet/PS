#include <iostream>
#include <cmath>

using namespace std;

void generateCantor(string& cantorSet, int begin, int end)
{
    if (end - begin <= 1)
        return;

    const int sectionSize = (end - begin) / 3;
    const int point1 = begin + sectionSize;
    const int point2 = begin + sectionSize * 2;

    generateCantor(cantorSet, begin, point1);
    fill(cantorSet.begin() + point1, cantorSet.begin() + point2, ' ');
    generateCantor(cantorSet, point2, end);
}

int main()
{
    int n;
    while (cin >> n)
    {
        string cantorSet(pow(3, n), '-');
        generateCantor(cantorSet, 0, cantorSet.size());

        cout << cantorSet << '\n';
    }
    return 0;
}