using System.Buffers;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Text;

namespace CsClient
{
    internal class LibraryClient
    {
        [DllImport("CppDll.dll", CallingConvention = CallingConvention.StdCall)]
        private static extern int add(int a, int b);

        [DllImport("CppDll.dll", CallingConvention = CallingConvention.StdCall, CharSet = CharSet.Unicode)]
        private static extern int getStrLen(string str);

        [DllImport("CppDll.dll", CallingConvention = CallingConvention.StdCall, CharSet = CharSet.Ansi)]
        private static extern int getStrLenA([MarshalAs(UnmanagedType.LPStr)] ref string str);


        [DllImport("CppDll.dll", CallingConvention = CallingConvention.StdCall, CharSet = CharSet.Unicode)]
        //heap corruption
        //private static extern string getInfo();
        //[return: MarshalAs(UnmanagedType.LPWStr)]

        private static extern IntPtr getInfo();

        [DllImport("CppDll.dll", CallingConvention = CallingConvention.StdCall)]
        private static extern void freeInfo(IntPtr pData);

        [DllImport("CppDll.dll", CallingConvention = CallingConvention.StdCall, CharSet = CharSet.Unicode)]
        private static extern string getInfoWithCom();

        [DllImport("CppDll.dll", CallingConvention = CallingConvention.StdCall, EntryPoint = "getInfo2", CharSet = CharSet.Unicode)]
        private static extern void getInfo(StringBuilder data, int length);

        [DllImport("CppDll.dll", CallingConvention = CallingConvention.StdCall, EntryPoint = "getInfo3", CharSet = CharSet.Unicode)]
        private static extern int getInfoWithLen(StringBuilder data, int length);

        [DllImport("CppDll.dll", CallingConvention = CallingConvention.StdCall, EntryPoint = "getInfo3", CharSet = CharSet.Unicode)]
        private static extern int getInfoWithArray([Out] char[] data, int length);

        [DllImport("CppDll.dll", CallingConvention=CallingConvention.StdCall, CharSet = CharSet.Unicode)]
        [return:MarshalAs(UnmanagedType.BStr)]
        private static extern string getInfoWithBstr();

        [DllImport("CppDll.dll", CallingConvention = CallingConvention.StdCall, CharSet = CharSet.Unicode, EntryPoint = "getInfo4")]
        private static extern void getInfo([MarshalAs(UnmanagedType.BStr)] ref string data);

        [DllImport("CppDll.dll", CallingConvention = CallingConvention.StdCall)]
        private static extern Point3d getPoint3d();

        [DllImport("CppDll.dll", CallingConvention = CallingConvention.StdCall)]
        private static extern void updatePoint3d(ref Point3d pt);

        [DllImport("CppDll.dll", CallingConvention = CallingConvention.StdCall, CharSet = CharSet.Unicode)]
        private static extern CppFileInfo getFileInfo(string filename);

        public int Add(int a, int b)
        {
            return add(a, b);
        }

        public int GetStrLen(string str) 
        {
            return getStrLen(str);
        }

        public int GetStrLenA(string str)
        {
            return getStrLenA(ref str);
        }

        public string GetInfo()
        {
            var ptr = getInfo();
            var result = Marshal.PtrToStringUni(ptr);
            freeInfo(ptr);
            return result;
        }

        public string GetInfoWithCom()
        {
            return getInfoWithCom();
        }

        public string GetInfoWithStrBuilder()
        {
            var sb = new StringBuilder(255);
            getInfo(sb, sb.Capacity);

            return sb.ToString();
        }

        public string GetInfoWithLen()
        {
            int len = getInfoWithLen(null, 0);
            var sb = new StringBuilder(len + 2);
            getInfoWithLen(sb, sb.Capacity);

            return sb.ToString();
        }

        public string GetInfoWithBstr()
        {
            return getInfoWithBstr();
        }

        public string GetInfoFromBstr()
        {
            string result = "";
            getInfo(ref result);

            return result;
        }

        public string GetInfoWithArray()
        {
            int len = getInfoWithArray(null, 0);
            char[] buffer = ArrayPool<char>.Shared.Rent(len + 1);
            getInfoWithArray(buffer, buffer.Length);

            return new string(buffer);
        }

        public Point3d GetPoint()
        {
            return getPoint3d();
        }

        public void UpdatePoint(ref Point3d pt)
        {
            updatePoint3d(ref pt);
        }

        public CppFileInfo GetAssemblyFileInfo()
        {
            var location = Assembly.GetExecutingAssembly().Location;
            return getFileInfo(location);
        }
    }
}
