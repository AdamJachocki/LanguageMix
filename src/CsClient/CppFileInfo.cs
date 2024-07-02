using System.Runtime.InteropServices;

namespace CsClient
{
    [StructLayout(LayoutKind.Sequential, Pack = 1, CharSet = CharSet.Unicode)]
    public struct CppFileInfo
    {
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 260)]
        public string fileName;
        public long fileSize;
    }
}
