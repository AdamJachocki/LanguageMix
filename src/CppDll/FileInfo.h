#pragma once
#include <minwindef.h>
#pragma pack(push, 1)
struct FileInfo
{
	wchar_t fileName[MAX_PATH];
	size_t fileSize;
};
#pragma pack(pop)