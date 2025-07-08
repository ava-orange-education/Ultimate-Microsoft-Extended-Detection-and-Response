# Use the following PowerShell cmdlet to determine whether Large Send Offload (LSO) is enabled:
Get-NetAdapterAdvancedProperty | Where-Object DisplayName -Match "^Large

# If LSO is enabled, use the following powershell command to disable it:
Disable-NetAdapterLso -Name {name of adapter}  
