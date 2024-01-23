using System.Text;

int n = int.Parse(Console.ReadLine());

List<int> inOrder = Console.ReadLine().Split().Select(x => int.Parse(x)).ToList();
inOrder.Insert(0, 0);

List<int> postOrder = Console.ReadLine().Split().Select(x => int.Parse(x)).ToList();
postOrder.Insert(0, 0);

List<int> preOrder = new() { 0 };

void Generate(int inOrderStart, int postOrderStart, int length)
{
    if (length <= 0)
        return;
    
    preOrder.Add(postOrder[postOrderStart + n - 1]);
    
    int pivot = inOrder.IndexOf(preOrder[^1]);
    
    Generate(inOrderStart, postOrderStart, pivot - inOrderStart);
    Generate(pivot + 1, postOrderStart + pivot - inOrderStart, length - (pivot - inOrderStart) - 1);
}

Generate(1, 1, n);

StringBuilder outputBuilder = new();

foreach(int node in preOrder)
    outputBuilder.Append($"{node} ");

Console.WriteLine(outputBuilder.ToString());
