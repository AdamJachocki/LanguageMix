namespace CsClient
{
    internal class Program
    {
        static void Main(string[] args)
        {            
            var client = new LibraryClient();
            int result = client.Add(2, 5);
            Console.WriteLine("Add: " + result);

            var strLen = client.GetStrLen("Hello!");
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
        }
    }
}