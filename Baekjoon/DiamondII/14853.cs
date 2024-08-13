using System.Text;

int t = int.Parse(Console.ReadLine());

StringBuilder outputBuilder = new();

for (int tc = 0; tc < t; tc++)
{
    string[] input = Console.ReadLine().Split(' ');

    double n1 = double.Parse(input[0]);
    double m1 = double.Parse(input[1]);
    double n2 = double.Parse(input[2]);
    double m2 = double.Parse(input[3]);

    double temp = 1;

    for (int i = 0; i <= n2; i++)
    {
        temp *= (n1 - m1 + 1 + i) / (n1 + 2 + i);
    }

    double answer = temp;

    for (int i = 1; i <= m2; i++)
    {
        temp *= (m1 + i) * (n2 + 2 - i) / i  / (n1 + n2 - m1 + 2 - i);
        answer += temp;
    }

    outputBuilder.AppendLine(answer.ToString());
}

Console.Write(outputBuilder.ToString());