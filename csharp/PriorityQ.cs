using System;
using System.Collections.Generic;
using System.Linq;

public class MyQueue
{
    LinkedList<int> queue;

    public MyQueue()
    {
        queue = new LinkedList<int>();
    }

    public int Size => queue.Count;

    public void AddItem(int item)
    {
        if (Size == 0 || item <= queue.First.Value)
        {
            queue.AddFirst(item);
        }
        else if (item >= queue.Last.Value)
        {
            queue.AddLast(item);
        }
        else
        {
            var node = queue.First;
            while (node.Value < item)
            {
                node = node.Next;
            }
            queue.AddBefore(node, item);
        }
    }

    public int? GetItem()
    {
        if (Size == 0) return null;

        int item = queue.First.Value;
        queue.RemoveFirst();
        return item;
    }

    public int? GetItemLast()
    {
        if (Size == 0) return null;
        int item = queue.Last.Value;
        queue.RemoveLast();
        return item;
    }
}

public class Program
{
  public static void Main()
  {
    Console.WriteLine("Priority Queue");

    var myQueue = new MyQueue();
    var random = new Random();
            
    for(int i = 0; i < random.Next(5, 15); i++)
    {
        var item = random.Next(1, 100);
        Console.Write($"{item} ");
        myQueue.AddItem(item);
    }
    Console.WriteLine();
    while (myQueue.Size > 0)
    {
        Console.Write($"{myQueue.GetItem()} ");
    }
    Console.WriteLine();
  }
}
