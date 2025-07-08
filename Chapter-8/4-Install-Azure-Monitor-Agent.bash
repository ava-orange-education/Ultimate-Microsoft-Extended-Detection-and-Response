az vm extension set \
  --name AzureMonitorLinuxAgent \
  --publisher Microsoft.Azure.Monitor \
  --vm-name <vm-name> \
  --resource-group <resource-group-name>

# Alternatively, install manually using the onboarding script:
wget https://aka.ms/InstallAzureMonitorAgentLinux
chmod +x InstallAzureMonitorAgentLinux
sudo ./InstallAzureMonitorAgentLinux
