/************************************************************************/
/*
win7 x32 �Խ�������ϵ

0��3�����ÿ��ʹ��IDT��������35
*/
/************************************************************************/

#include <ntddk.h>

#include "kernel.h"
#include "IDT.h"
#include "SSDT.h"

PKSYSTEM_SERVICE_TABLE pSystemServiceTable;

ULONG demo(IN ULONG a, IN ULONG b)
{
	DbgPrint("%d \n", a + b);

	return a + b;
}

VOID DriverUnload(PDRIVER_OBJECT pDriverObj)
{
	UNREFERENCED_PARAMETER(pDriverObj);

	FreeSystemServiceTable(pSystemServiceTable);

	DbgPrint("������ж�� \n");
}

NTSTATUS DriverEntry(PDRIVER_OBJECT pDriverObj, PUNICODE_STRING pRegistryString)
{
	NTSTATUS status = STATUS_SUCCESS;

	UNREFERENCED_PARAMETER(pRegistryString);

	status = CreateSystemServiceTable(&pSystemServiceTable);
	if (!NT_SUCCESS(status)) {
		DbgPrint("%s(%d): CreateSystemServiceTable failed.", __FILE__, __LINE__);

		return status;
	} else {
		DbgPrint("SystemServiceTable��ַ��%X \n", pSystemServiceTable);
	}

	// ��IDT�������Ӻ���
	AddFun2SystemServiceTable(pSystemServiceTable, (ULONG)demo, 2);								//0

	SetIDTEntry(35, (ULONG)YKiSystemService);


	pDriverObj->DriverUnload = DriverUnload;

	return status;
}