using System;
using System.Text;
using System.Net;
using System.Net.Sockets;
using System.IO;

namespace SocketServer
{
    class Program
    {
        static void Main(string[] args)
        {
            // Встановлюємо для сокета локальну кінцеву точку
            IPHostEntry ipHost = Dns.GetHostEntry("localhost");
            IPAddress ipAddr = ipHost.AddressList[0];
            IPEndPoint ipEndPoint = new IPEndPoint(ipAddr, 11000);

            // Створюємо сокет Tcp / Ip
            Socket sListener = new Socket(ipAddr.AddressFamily, SocketType.Stream, ProtocolType.Tcp);

            // Призначаємо сокет локальної кінцевій точці і слухаємо вхідні сокети
            try
            {
                sListener.Bind(ipEndPoint);
                sListener.Listen(10);

                // Починаємо слухати з'єднання
                while (true)
                {
                    Console.WriteLine("Очiкуємо з'єднання через порт {0}", ipEndPoint);

                    // Програма призупиняється, очікуючи вхідне з'єднання
                    Socket handler = sListener.Accept();
                    string data = null;

                    // Ми дочекалися клієнта, що намагається з нами з'єднатися

                    byte[] bytes = new byte[1024];
                    int bytesRec = handler.Receive(bytes);

                    data += Encoding.UTF8.GetString(bytes, 0, bytesRec);

                    int k = data.IndexOf("#");
                    string fileName = "";
                    if (k > -1)
                    {
                        fileName = data.Substring(0, k);
                        data = data.Replace(fileName + "#", "");


                        // Показуємо дані на консолі
                        Console.WriteLine("\nОтриманий файл: " + fileName);
                        Console.WriteLine("============================================");
                        Console.WriteLine(data);
                        Console.WriteLine("--------------------------------------------");
                        string fullName = @"D:\_Server\" + fileName;
                        File.WriteAllText(@fullName, data, Encoding.Default);
                        Console.WriteLine("Файл збережено: " + fullName);
                        Console.WriteLine("============================================");

                        // Відправляємо відповідь клієнту
                        string reply = "Сервер отримав файл.  Довжина: " + data.Length.ToString()
                                + " символiв";
                        byte[] msg = Encoding.UTF8.GetBytes(reply);
                        handler.Send(msg);
                    }

                    if (data.IndexOf("<TheEnd>") > -1)
                    {
                        Console.WriteLine("Сервер завершив з'єднання з клiєнтом.");
                        break;
                    }

                    handler.Shutdown(SocketShutdown.Both);
                    handler.Close();
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.ToString());
            }
            finally
            {
                Console.ReadLine();
            }
        }
    }
}