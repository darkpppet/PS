using System.Text;

PriorityQueue<int, int> priorityQueue = new();

int n = int.Parse(Console.ReadLine());

StringBuilder outputBuilder = new();

for (int i = 0; i < n; i++)
{
    int x = int.Parse(Console.ReadLine());
    
    if (x == 0)
    {
        priorityQueue.TryDequeue(out int num, out _);
        outputBuilder.AppendLine($"{num}");
    }
    else
    {
        priorityQueue.Enqueue(x, x);
    }
}

Console.Write(outputBuilder.ToString());
