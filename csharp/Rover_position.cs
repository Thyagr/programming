using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
  public static void Main()
  {
    Random rnd = new Random();
    int n = 20; // rnd.Next(1, 20);
    var commandsList = new List<string> {"RIGHT", "DOWN", "LEFT", "UP" };
    int cmdCount = 15; // rnd.Next(1, 10);
    var commands = new List<string>();
    for (int i = 0; i < cmdCount; i++)
    {
      var rcmd = rnd.Next(0, 4);
      commands.Add(commandsList[rcmd]);
    }
    
    Console.WriteLine($"n = {n}, cmds = {cmdCount}");

    // int n = 4;
    // var commands = new List<string> {"RIGHT", "DOWN", "LEFT", "LEFT", "DOWN" };
    int final = Rover_Position(n, commands);
    Console.WriteLine($"Final position = {final}");
  }

  private static int Rover_Position(int n, List<string> commands)
  {
    int pos = 0;

    // bounds
    if (n < 2 || n > 20) return pos;
    if (commands.Count < 1 || commands.Count > 20) return pos; 

    var up_boundary = new HashSet<int>();
    var down_boundary = new HashSet<int>();
    var left_boundary = new HashSet<int>();
    var right_boundary = new HashSet<int>();

    // 0 	1 	2  3
    // 4 	5  	6  7 
    // 8 	9  10  11 
    // 12  13  14  15 
    for (int i = 0; i < n; i++) up_boundary.Add(i);
    for (int i = 0; i < n; i++ ) left_boundary.Add(i * n);
    for (int i = 0; i < n; i++) right_boundary.Add(i*n + (n-1));
    for (int i = 0; i < n; i++) down_boundary.Add(n*(n-1) + i);

    foreach (var commmand in commands)
    {
      switch (commmand)
      {
        case "DOWN":
          if (!down_boundary.Contains(pos))
            pos += n;
          break;
        case "UP":
          if (!up_boundary.Contains(pos))
            pos -= n;
          break;
        case "LEFT":
          if (!left_boundary.Contains(pos))
            pos -= 1;
            break;
        case "RIGHT":
          if (!right_boundary.Contains(pos))
            pos += 1;
          break;
        }
      Console.WriteLine($"Command = {commmand}, Position = {pos}");
    }

    return pos;
  }
}