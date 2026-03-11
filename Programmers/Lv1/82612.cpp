using namespace std;

long long solution(int price, int money, int count)
{
    long long fee = static_cast<long long>(price) * count * (count + 1) / 2;
    long long lack = fee - money;
    
    return lack >= 0 ? lack : 0;
}