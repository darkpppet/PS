using System;

int antenna = int.Parse(Console.ReadLine());
int eyes = int.Parse(Console.ReadLine());

if (antenna >= 3 && eyes <= 4)
	Console.WriteLine("TroyMartian");

if (antenna <= 6 && eyes >= 2)
	Console.WriteLine("VladSaturnian");

if (antenna <= 2 && eyes <= 3)
	Console.WriteLine("GraemeMercurian");
