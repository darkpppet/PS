using System;

string d1 = Console.ReadLine();
string d2 = Console.ReadLine();
string d3 = Console.ReadLine();
string d4 = Console.ReadLine();

Console.WriteLine((d1 == "8" || d1 == "9") && (d4 == "8" || d4 == "9") && d2 == d3 ? "ignore" : "answer");
