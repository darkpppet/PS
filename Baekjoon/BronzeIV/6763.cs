using System;

int limit = int.Parse(Console.ReadLine());
int speed = int.Parse(Console.ReadLine());

int over = speed - limit;

Console.WriteLine(over <= 0 ? "Congratulations, you are within the speed limit!" : "You are speeding and your fine is ${0}.", over switch
				  {
					  >= 1 and <= 20 => 100,
					  >= 21 and <= 30 => 270,
					  _ => 500
				  });
