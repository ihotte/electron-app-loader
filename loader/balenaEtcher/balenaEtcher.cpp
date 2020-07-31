#include <string>
#include <windows.h>

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "shell32.lib")

//
// cl /EHsc /Oi /Ox /Os /MACHINE x64 main.cpp
//
// http://www.cplusplus.com/reference/string/string/c_str/
// https://www.tutorialspoint.com/c_standard_library/c_function_system.htm
//

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int cmdShow)
{
	char BufferFileName[MAX_PATH];
	memset(BufferFileName, 0, MAX_PATH);
	GetModuleFileName(NULL, BufferFileName, MAX_PATH);

	std::string AppFileName = "balenaEtcher.exe";

	std::string BufferFilePath(BufferFileName);
	std::string AppDirPath = BufferFilePath.substr(0, BufferFilePath.find_last_of("\\") + 1);

	std::string AppExePath = AppDirPath + AppFileName;
	std::string Parameters = "--user-data-dir=" + AppDirPath + "userdata\\data";

	if (BufferFilePath.substr(BufferFilePath.find_last_of("\\") + 1).c_str() == AppFileName) {
		MessageBoxA(0, "Can't load itself !", 0, MB_OK | MB_ICONSTOP);
		return 1;
	}

	ShellExecute(0, "open", AppExePath.c_str(), Parameters.c_str(), NULL, SW_SHOWNORMAL);
	return 0;
}
