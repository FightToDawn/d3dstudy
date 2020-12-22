#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <WinInet.h>
#include <ShlObj.h>
#include <iostream>

int main() {
	//int n = 3;
	//n = n + 5;
	//std::cout << n << std::endl;

	CoInitialize(nullptr);

	IActiveDesktop* pDeskTop = nullptr;  //ipVtbl ָ����麯����
	wchar_t wszWallpaper[MAX_PATH];

	CoCreateInstance(CLSID_ActiveDesktop,
		nullptr,
		CLSCTX_INPROC_SERVER,
		__uuidof(IActiveDesktop),
		reinterpret_cast<void**>(&pDeskTop));

	pDeskTop->GetWallpaper(wszWallpaper, MAX_PATH, 0);
	pDeskTop->Release();
	std::wcout << wszWallpaper;

	IShellLink* pLink = nullptr;
	CoCreateInstance(
		CLSID_ShellLink,
		nullptr,
		CLSCTX_INPROC_SERVER,
		__uuidof(IShellLink),
		reinterpret_cast<void**>(&pLink)
	);

	char path[2000];
	wcstombs(path, wszWallpaper, 2000);

	pLink->SetPath(wszWallpaper);

	//IPersistFileҲ��CLSID_ShellLink�������Ľӿ� ����ֱ��ʹ��QueryInterface����
	IPersistFile* pPersist = nullptr;
	pLink->QueryInterface(__uuidof(IPersistFile), reinterpret_cast<void**>(&pPersist));
	pPersist->Save(L"C:\\wallpaper.lnk", FALSE);
	pPersist->Release();

	pLink->Release();

	CoUninitialize();

	std::cin.get();

	return 0;
}