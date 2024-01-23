int n = int.Parse(Console.ReadLine());

List<int> array = Console.ReadLine().Split().Select(x => int.Parse(x)).ToList();
int[] length = new int[n];
length[0] = 1;
List<int> end = new();
end.Add(array[0]);

for (int i = 1; i < n; i++)
{
    if (array[i] > end[^1])
    {
        end.Add(array[i]);
        length[i] = end.Count;
    }
    else
    {
        int index = ~end.BinarySearch(array[i]);

        if (index >= 0)
        {
            end[index] = array[i];
            length[i] = index + 1;
        }
        else
        {
            length[i] = ~index + 1;
        }
    }
}

array.Reverse();
end.Clear();
end.Add(array[0]);

for (int i = 1; i < n; i++)
{
    if (array[i] > end[^1])
    {
        end.Add(array[i]);
        length[^(i + 1)] += end.Count - 1;
    }
    else
    {
        int index = ~end.BinarySearch(array[i]);

        if (index >= 0)
        {
            end[index] = array[i];
            length[^(i + 1)] += index;
        }
        else
        {
            length[^(i + 1)] += ~index;
        }
    }
}

Console.WriteLine(length.Max());
