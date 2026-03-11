#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

string solution(string my_string) {
    transform(my_string.begin(), my_string.end(), my_string.begin(), static_cast<int(*)(int)>(tolower));
    sort(my_string.begin(), my_string.end());
    return my_string;
}