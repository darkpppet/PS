string[] input = Console.ReadLine().Split();

int n = int.Parse(input[0]);
int m = int.Parse(input[1]);
int x = int.Parse(input[2]);

Dictionary<int, Dictionary<int, long>> times = new();
Dictionary<int, Dictionary<int, long>> timesR = new();

for (int i = 1; i <= n; i++)
{
    times[i] = new();
    timesR[i] = new();
}

for (int i = 0; i < m; i++)
{
    input = Console.ReadLine().Split();
    
    int a = int.Parse(input[0]);
    int b = int.Parse(input[1]);
    long t = long.Parse(input[2]);

    times[a][b] = t;
    timesR[b][a] = t;
}

long[] distances = new long[n + 1];

for (int i = 1; i <= n; i++)
    distances[i] = 1_000_000_000_000;
distances[x] = 0;

bool[] isCheck = new bool[n + 1];

int nowTown = x;

for (int townCount = 0; townCount < n; townCount++)
{
    foreach (int nextTown in times[nowTown].Keys)
        distances[nextTown] = Math.Min(distances[nowTown] + times[nowTown][nextTown], distances[nextTown]);
    
    isCheck[nowTown] = true;
    
    long min = 1_000_000_000_001;
    
    for (int i = 1; i <= n; i++)
    {
        if (!isCheck[i] && distances[i] < min)
        {
            min = distances[i];
            nowTown = i;
        }
    }
}

long[] distancesR = new long[n + 1];

for (int i = 1; i <= n; i++)
    distancesR[i] = 1_000_000_000_000;
distancesR[x] = 0;

isCheck = new bool[n + 1];

nowTown = x;

for (int townCount = 0; townCount < n; townCount++)
{
    foreach (int nextTown in timesR[nowTown].Keys)
        distancesR[nextTown] = Math.Min(distancesR[nowTown] + timesR[nowTown][nextTown], distancesR[nextTown]);
    
    isCheck[nowTown] = true;
    
    long min = 1_000_000_000_001;
    
    for (int i = 1; i <= n; i++)
    {
        if (!isCheck[i] && distancesR[i] < min)
        {
            min = distancesR[i];
            nowTown = i;
        }
    }
}

for (int i = 1; i <= n; i++)
    distances[i] += distancesR[i];

Console.WriteLine(distances.Skip(1).Max());
