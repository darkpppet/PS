string[] input = Console.ReadLine().Split();

int a = int.Parse(input[0]);
int b = int.Parse(input[1]);
int x = int.Parse(input[2]);
int y = int.Parse(input[3]);

int path1 = Math.Abs(b - a);
int path2 = Math.Abs(x - a) + Math.Abs(b - y);
int path3 = Math.Abs(y - a) + Math.Abs(b - x);

Console.WriteLine(Math.Min(Math.Min(path1, path2), path3));
