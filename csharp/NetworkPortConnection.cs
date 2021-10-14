using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Sockets;

public class Program
{
  public static void Main()
  {
    PortConnect("192.168.0.1", 100);
  }

  private static void PortConnect(string Ip, int port)
  {
   using(TcpClient tcpClient = new TcpClient())
    {
        try {
            tcpClient.Connect("127.0.0.1", 9081);
            Console.WriteLine("Port open");
        } catch (Exception) {
            Console.WriteLine("Port closed");
        }
    }

    using (var udp = new UdpClient())
    {
        try
        {
        udp.Connect("120.0.0.1", 243);
        }
        catch (Exception) {
            Console.WriteLine("not able to connect");
        }

    }
  }
}
