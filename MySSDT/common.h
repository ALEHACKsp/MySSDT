#ifndef __COMMON_H_
#define __COMMON_H_

#include <ntddk.h>

#ifdef __cplusplus
extern "C" {
#endif

	/*
	�ر�ҳ����
	*/
	VOID PageProtectOff();

	/*
	����ҳ����
	*/
	void PageProtectOn();

	/*
	һ�����޸�8�ֽ��ڴ�
	*/
	VOID Hook8b(IN ULONG hookAddr, IN PUCHAR hookBytesArr, OUT PUCHAR oldCode);

	VOID Int3();

#ifdef __cplusplus
}
#endif

#endif
