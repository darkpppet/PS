int count = int.Parse(Console.ReadLine());

List<int> list = new();
Dictionary<int, int> mode = new();

for (int i = 0; i < count; i++)
{
    int input = int.Parse(Console.ReadLine());
    
    list.Add(input);
    
    if (mode.ContainsKey(input))
        mode[input]++;
    else
        mode[input] = 1;
}

int maxCount = mode.Values.Max();
List<int> modes = mode.Keys.Where(x => mode[x] == maxCount).ToList();

list.Sort();
modes.Sort();

Console.WriteLine((int)Math.Round(list.Average(), MidpointRounding.AwayFromZero));
Console.WriteLine(list[list.Count / 2]);
Console.WriteLine(modes.Count == 1 ? modes[0] : modes[1]);
Console.WriteLine(list.Max() - list.Min());
