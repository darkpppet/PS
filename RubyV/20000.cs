using System.Text;

StringBuilder outputBuilder = new();

switch (Console.ReadLine())
{
	case "0":
		outputBuilder.Append(@"BOJ 20000");
		break;
		
	case "1":
		outputBuilder.AppendLine(@"#include <cstdio>");
		outputBuilder.AppendLine(@"int main(){");
		outputBuilder.AppendLine(@"    int N;");
		outputBuilder.AppendLine(@"    scanf(""%d"",&N);");
		outputBuilder.AppendLine(@"    if(N==1){");
		outputBuilder.AppendLine(@"        puts(""4"");");
		outputBuilder.AppendLine(@"    };");
		
		for (int i = 2; i <= 20000; i++)
		{
			outputBuilder.AppendLine($@"    else if(N=={i}){{");
			outputBuilder.AppendLine($@"        puts(""{i * 4}"");");
			outputBuilder.AppendLine(@"    }");
		}
		
		outputBuilder.AppendLine(@"    else{");
		outputBuilder.AppendLine(@"        puts(""Still working on it..."");");
		outputBuilder.AppendLine(@"    }");
		outputBuilder.AppendLine(@"    return 0;");
		outputBuilder.AppendLine(@"}");
		
		break;
		
	case "2":
		
	case "3":
		
	case "4":
		
	case "5":
		
	case "6":
		
	case "7":
		
	case "8":
		
	case "9":
}

Console.WriteLine(outputBuilder.ToString());
