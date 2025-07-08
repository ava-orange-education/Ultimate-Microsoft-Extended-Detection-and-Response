az monitor data-collection rule association create \
  --resource-id /subscriptions/<sub-id>/resourceGroups/<rg>/providers/Microsoft.Compute/virtualMachines/<vm-name> \
  --rule-id /subscriptions/<sub-id>/resourceGroups/<rg>/providers/Microsoft.Insights/dataCollectionRules/Syslog-DCR \
  --name "Syslog-DCR-Association"
