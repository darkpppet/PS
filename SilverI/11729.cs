using System;
using System.Text;
using System.Linq;

StringBuilder outputBuilder = new();
int moveCount = 0;

void MoveHanoiTower(int n, int start, int end)
{
    if (n == 1)
    {
        moveCount++;
        outputBuilder.AppendLine($"{start} {end}");
        return;
    }
    
    int not = (new int[] { 1, 2, 3 }).Except(new int[] { start, end }).ToArray()[0];
    
    MoveHanoiTower(n - 1, start, not);
    moveCount++;
    outputBuilder.AppendLine($"{start} {end}");
    MoveHanoiTower(n - 1, not, end);
}

int n = int.Parse(Console.ReadLine());

MoveHanoiTower(n, 1, 3);

Console.WriteLine(moveCount);
Console.Write(outputBuilder.ToString());
