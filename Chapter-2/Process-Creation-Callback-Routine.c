//Here’s an example of a callback routine for process creation:

#include <ntddk.h>

VOID CreateProcessNotifyRoutineEx(
    _Inout_ PEPROCESS Process,
    _In_ HANDLE ProcessId,
    _In_opt_ PPS_CREATE_NOTIFY_INFO CreateInfo
)
{
    if (CreateInfo) {
        // Process is being created
        DbgPrint("Process created: %wZ (PID: %d)\n", CreateInfo->ImageFileName, ProcessId);
    } else {
        // Process is being deleted
        DbgPrint("Process terminated: (PID: %d)\n", ProcessId);
    }
}

NTSTATUS DriverEntry(
    _In_ PDRIVER_OBJECT DriverObject,
    _In_ PUNICODE_STRING RegistryPath
)
{
    NTSTATUS status;

    // Register the process creation callback
    status = PsSetCreateProcessNotifyRoutineEx(CreateProcessNotifyRoutineEx, FALSE);
    if (!NT_SUCCESS(status)) {
        DbgPrint("Failed to register process creation callback: 0x%X\n", status);
        return status;
    }

    DbgPrint("Driver loaded successfully\n");
    return STATUS_SUCCESS;
} 

/*
Explanation
Callback Routine Definition:
  -	The CreateProcessNotifyRoutineEx function is defined to handle process creation and termination events. It takes three parameters:
  -	Process: A pointer to the process object.
  -	ProcessId: The ID of the process being created or deleted.
  -	CreateInfo: A pointer to a PS_CREATE_NOTIFY_INFO structure that contains information about the process being created. If CreateInfo is NULL, the process is being deleted.

Callback Routine Registration:
  -	In the DriverEntry function, the PsSetCreateProcessNotifyRoutineEx function is called to register the CreateProcessNotifyRoutineEx callback routine. The second parameter is FALSE, indicating that the callback is being registered (not removed).

Callback Routine Invocation:
  -	The callback routine is invoked by the system whenever a process is created or deleted. If a process is being created, CreateInfo is not NULL, and the routine prints the process name and ID. If a process is being deleted, CreateInfo is NULL, and the routine prints the process ID.

This example demonstrates how an EDR solution can use callback routines to monitor process creation events, providing visibility into process activities on the system. By analyzing these events, the EDR can detect and respond to suspicious behavior in real-time.
*/
