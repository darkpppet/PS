int solution(int n)
{
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i != 0)
            continue;
        
        int j = 2 * n / i;
        if (i % 2 == j % 2)
            continue;
        
        answer++;
    }
    return answer;
}