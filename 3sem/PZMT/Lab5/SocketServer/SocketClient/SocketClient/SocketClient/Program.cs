using System;
using System.IO;
using System.Text;
using System.Net;
using System.Net.Sockets;

namespace SocketClient
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                SendMessageFromSocket(11000);
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.ToString());
                Console.ReadLine();
            }
        }

        static void SendMessageFromSocket(int port)
        {
            // Буфер для вхідних даних
            byte[] bytes = new byte[1024];


            // Встановлюємо віддалену точку для сокета
            IPHostEntry ipHost = Dns.GetHostEntry("localhost");
            IPAddress ipAddr = ipHost.AddressList[0];
            IPEndPoint ipEndPoint = new IPEndPoint(ipAddr, port);

            Socket sender = new Socket(ipAddr.AddressFamily, SocketType.Stream, ProtocolType.Tcp);

            // З'єднуємо сокет з віддаленою точкою
            sender.Connect(ipEndPoint);

            int index = 0;
            DirectoryInfo dir = new DirectoryInfo(@"D:\_Client");
            Console.WriteLine("\n===================================================\nКаталог: D:\\_Client\n");

            foreach (var item in dir.GetFiles())
                Console.WriteLine("     " + index++ + ": " + item.Name);
            
            Console.Write("\nВведiть номер файлу (-1 - вихiд): ");
            index = Convert.ToInt32(Console.ReadLine());
            if (index < 0 || index > dir.GetFiles().GetUpperBound(0))
            {
                sender.Send(Encoding.UTF8.GetBytes("<TheEnd>"));
                //звільняємо сокет
                sender.Shutdown(SocketShutdown.Both);
                sender.Close();

                return;
            }


            string message = System.IO.File.ReadAllText(@dir.GetFiles()[index].FullName);
            message = dir.GetFiles()[index].Name + '#' + message;
            
            Console.Clear();
            Console.WriteLine("Сокет з'єднується з {0} ", sender.RemoteEndPoint.ToString());
            byte[] msg = Encoding.UTF8.GetBytes(message);

            // Відправляємо дані через сокет
            int bytesSent = sender.Send(msg);

            // Отримуємо відповідь від сервера
            int bytesRec = sender.Receive(bytes);

            Console.WriteLine("\nВiдповiдь з сервера: {0}\n\n", Encoding.UTF8.GetString(bytes, 0, bytesRec));

            // Використовуємо рекурсію для неодноразового виклику SendMessageFromSocket()
            SendMessageFromSocket(port);
        }
    }
}
