string[] input = Console.ReadLine().Split(' ');

int n = int.Parse(input[0]);
int m = int.Parse(input[1]);

int[,] relationships = new int[n + 1, n + 1];

for (int i = 1; i <= n; i++)
{
    for (int j = 1; j <= n; j++)
    {
        relationships[i, j] = int.MaxValue / 2;
    }
}

for (int i = 0; i < m; i++)
{
    input = Console.ReadLine().Split(' ');
	
    int a = int.Parse(input[0]);
    int b = int.Parse(input[1]);
	
    relationships[a, b] = 1;
    relationships[b, a] = 1;
}

for (int mid = 1; mid <= n; mid++)
{
    for (int start = 1; start <= n; start++)
    {
        for (int end = 1; end <= n; end++)
        {
            if (relationships[start, end] > relationships[start, mid] + relationships[mid, end])
            {
                relationships[start, end] = relationships[start, mid] + relationships[mid, end];
            }
        }
    }
}

int[] nums = new int[n + 1];

int min = int.MaxValue;
int minIndex = 0;

for (int i = 1; i <= n; i++)
{
    nums[i] = 0;
    for (int j = 1; j <= n; j++)
    {
        if (i != j)
        {
            nums[i] += relationships[i, j];
        }
    }
    
    if (nums[i] < min)
    {
        min = nums[i];
        minIndex = i;
    }
    
}

Console.WriteLine(minIndex);
