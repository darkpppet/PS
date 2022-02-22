string[] input = Console.ReadLine().Split();

int n = int.Parse(input[0]);
int m = int.Parse(input[1]);

List<int> trueKnowers = Console.ReadLine().Split().Skip(1).Select(x => int.Parse(x)).ToList();

List<HashSet<int>> parties = new();

for (int i = 0; i < m; i++)
    parties.Add(Console.ReadLine().Split().Skip(1).Select(x => int.Parse(x)).ToList());


bool[] isListenTrue = new bool[n + 1];

foreach (int knower in trueKnowers)
{
    isListenTrue[knower] = true;
    
    
    
}

