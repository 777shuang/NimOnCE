#include <stdlib.h>
#include <windows.h>

/*int MessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType)
{
    size_t length = MultiByteToWideChar(CP_ACP , MB_PRECOMPOSED , lpText , -1 , NULL , 0);
    wchar_t *text = (wchar_t*)malloc(length * sizeof(wchar_t));
    MultiByteToWideChar(CP_ACP , MB_PRECOMPOSED , lpCaption , -1 , text , length);

    length = MultiByteToWideChar(CP_ACP , MB_PRECOMPOSED , lpCaption , -1 , NULL , 0);
    wchar_t *caption = (wchar_t*)malloc(length * sizeof(wchar_t));
    MultiByteToWideChar(CP_ACP , MB_PRECOMPOSED , lpCaption , -1 , caption , length);

    int status = MessageBoxW(hWnd, text, caption, uType);
    free(text);
    free(caption);
    return status;
}*/

HMODULE LoadLibraryA(LPCSTR lpLibFileName)
{
    size_t length = MultiByteToWideChar(CP_ACP , MB_PRECOMPOSED , lpLibFileName , -1 , NULL , 0);
    wchar_t *libFileName = (wchar_t*)malloc(length * sizeof(wchar_t));
    MultiByteToWideChar(CP_ACP , MB_PRECOMPOSED , lpLibFileName , -1 , libFileName , length);
    HMODULE hModule = LoadLibraryW(libFileName);
    free(libFileName);
    return hModule;
}