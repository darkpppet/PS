string[] input = Console.ReadLine().Split();

int n = int.Parse(input[0]);
int m = int.Parse(input[1]);

char[,] map = new char[n, m];

for (int i = 0; i < n; i++)
{
    char[] row = Console.ReadLine().ToCharArray();
    
    for (int j = 0; j < m; j++)
        map[i, j] = row[j];
}

HashSet<(int I, int J, bool IsBreak)> before = new() { (0, 0, false) };
int length = 1;
bool isFind = false;

void Check(HashSet<(int I, int J, bool IsBreak)> beforeList, int i, int j, bool isBreak)
{
    if (i >= 0 && i < n && j >= 0 && j < m)
    {
        if (i == n - 1 && j == m - 1)
            isFind = true;
        else if (map[i, j] == '0')
            beforeList.Add((i, j, isBreak));
        else if (map[i, j] == '1' && !isBreak)
            beforeList.Add((i, j, true));
    }
}

do
{
    HashSet<(int I, int J, bool IsBreak)> tempBefore = new();
    
    foreach (var tuple in before)
    {
        Check(tempBefore, tuple.I - 1, tuple.J, tuple.IsBreak);
        Check(tempBefore, tuple.I, tuple.J - 1, tuple.IsBreak);
        Check(tempBefore, tuple.I, tuple.J + 1, tuple.IsBreak);
        Check(tempBefore, tuple.I + 1, tuple.J, tuple.IsBreak);
    }
    
    length++;
    before = new(tempBefore);
    
} while (!isFind && before.Count > 0);

Console.WriteLine(isFind ? length : -1);
