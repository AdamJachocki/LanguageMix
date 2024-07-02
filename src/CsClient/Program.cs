using System.Runtime.InteropServices;

namespace CsClient
{
    internal class Program
    {
        static void Main(string[] args)
        {          
            var ch = "𠝹";


            var client = new LibraryClient();
            int result = client.Add(2, 5);
            Console.WriteLine("Add: " + result);

            var strLen = client.GetStrLen("𠝹");
            Console.WriteLine("StrLen: " + strLen);

            strLen = client.GetStrLenA("Hello!");
            Console.WriteLine("StrLenA: " + strLen);

            var info = client.GetInfo();
            Console.WriteLine("Info: " + info);

            info = client.GetInfoWithCom();
            Console.WriteLine("Info with COM: " + info);

            info = client.GetInfoWithStrBuilder();
            Console.WriteLine("Info, SB: " + info);

            info = client.GetInfoWithLen();
            Console.WriteLine("Info len: " + info);

            info = client.GetInfoWithBstr();
            Console.WriteLine("Info BSTR: " + info);

            info = client.GetInfoFromBstr();
            Console.WriteLine("Info from BSTR: " + info);

            info = client.GetInfoWithArray();
            Console.WriteLine("Info with buffer: " + info);

            var point = client.GetPoint();
            Console.WriteLine($"Point1: {point}");

            client.UpdatePoint(ref point);
            Console.WriteLine($"Point after update: {point}");

            CppFileInfo fileInfo = client.GetAssemblyFileInfo();
        }
    }
}