# Use the following PowerShell cmdlet to determine whether Large Send Offload (LSO) is enabled:
Get-NetAdapterAdvancedProperty | Where-Object DisplayName -Match "^Large
