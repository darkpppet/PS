using System;
using System.Text;

class SkiJump
{
	public readonly double g = 9.81;
	
	public double J { get; init; }
	public double P { get; init; }
	public double H { get; init; }
	public double L { get; init; }
	public double V0 { get => Math.Sqrt(2 * g * J); }
	
	public double CalcH(double l) => l switch
	{
			< 0 => H,
			double when l >= 0 && l < L / 2 => H * (1 - (2 * l * l) / (L *  L)),
			double when l >= L / 2 && l < L => 2 * H * (l / L - 1) * (l / L - 1),
			_ => 0
	};
	
	public double CalcdH(double l) => l switch
	{
			double when l >= 0 && l < L / 2 => -(4 * H * l) / (L * L),
			double when l >= L / 2 && l < L => 4 * H * (l / L - 1) / L,
			_ => 0
	};
	
	public double CalcF(double l) => -(l * l) / (4 * J) + H + P;
	public double CalcdF(double l) => -l / (2 * J);
}

class Program
{
	public static void Main(string[] args)
	{
		int n = int.Parse(Console.ReadLine());
		
		StringBuilder outputBuilder = new();
		
		for (int t = 0; t < n; t++)
		{
			string[] input = Console.ReadLine().Split(' ');
			
			SkiJump skiJump = new()
			{
				J = double.Parse(input[0]),
				P = double.Parse(input[1]),
				H = double.Parse(input[2]),
				L = double.Parse(input[3])
			};
			
			double left = 0;
			double right = 2 * Math.Sqrt(skiJump.J * (skiJump.H + skiJump.P));
			double middle;
			
			do
			{
				middle = (left + right) / 2;
				
				double diff = skiJump.CalcF(middle) - skiJump.CalcH(middle);
				
				if (diff == 0)
					break;
				else if (diff > 0)
					left = middle;
				else
					right = middle;
			} while (Math.Abs(right - left) > 0.00000000001);
			
			double v = Math.Sqrt(skiJump.V0 * skiJump.V0 + 2 * skiJump.g * (skiJump.P + skiJump.H - skiJump.CalcH(middle)));
			
			double alpha = Math.Abs(Math.Atan(skiJump.CalcdF(middle)) - Math.Atan(skiJump.CalcdH(middle))) * 180 / Math.PI;
			
			outputBuilder.AppendLine($"{middle} {v} {alpha}");
		}
		
		Console.Write(outputBuilder.ToString());
	}
}
