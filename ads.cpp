#include <windows.h>
#include <stdio.h>
#include<string.h>

int main()
{
    const char* filepath = "D:\\dfir.txt:myads";
    HANDLE hfile = CreateFileA(
        filepath,
        GENERIC_READ | GENERIC_WRITE,
        0,
        NULL,
        CREATE_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        NULL);
    if (hfile == INVALID_HANDLE_VALUE)
    {
        printf("ADS Creation Failed");
        return 1;
    }

    const char* adsdata = "This consists of ads data";
    DWORD byteswritten;

    if (!WriteFile(hfile, adsdata, strlen(adsdata), &byteswritten, NULL))
    {
        printf("error writing to the ADS");
    }

    const wchar_t* filename = L"D:\\dfir.txt:myads";
    WIN32_FIND_STREAM_DATA streamData;
    HANDLE hfilestream = FindFirstStreamW(
        filename,
        FindStreamInfoStandard,
        &streamData,
        0);

    do {
        wprintf(L"The stream name is:%s\n", streamData.cStreamName);
    } while (FindNextStreamW(hfilestream, &streamData));

    FindClose(hfilestream);
    return 0;

}

