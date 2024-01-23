using System.Text;

List<int> preOrder = new();

try
{
    while (true)
        preOrder.Add(int.Parse(Console.ReadLine()));
}
catch (Exception _)
{
}

List<int> postOrder = new();

void TransLate(int start, int end)
{
    if (start > end)
        return;
    
    postOrder.Add(preOrder[start]);
    
    int pivot = start + 1;

    while (pivot <= end && preOrder[pivot] < preOrder[start])
        pivot++;

    TransLate(pivot, end);
    TransLate(start + 1, pivot - 1);
}

TransLate(0, preOrder.Count - 1);

postOrder.Reverse();

StringBuilder outputBuilder = new();

foreach (int node in postOrder)
    outputBuilder.AppendLine(node.ToString());

Console.Write(outputBuilder.ToString());
