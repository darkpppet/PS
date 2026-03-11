using namespace std;

long long solution(int n)
{
    if (n == 1)
        return 1;
    
    if (n == 2)
        return 2;
    
    int before2 = 1, before1 = 2;
    
    for (int i = 3; i <= n; i++)
    {
        int now = (before2 + before1) % 1234567;
        before2 = before1;
        before1 = now;
    }
    
    return before1;
}