using System.Text;

PriorityQueue<int, int> priotyQueue = new();

int n = int.Parse(Console.ReadLine());

StringBuilder outputBuilder = new();

for (int i = 0; i < n; i++)
{
    int x = int.Parse(Console.ReadLine());
    
    if (x == 0)
    {
        priotyQueue.TryDequeue(out int num, out _);
        outputBuilder.AppendLine(num.ToString());
    }
    else
    {
        priotyQueue.Enqueue(x, -x);
    }
}

Console.Write(outputBuilder.ToString());
