# This sets up collection of all log levels from select Syslog facilities.

az monitor data-collection rule create \
  --resource-group <resource-group> \
  --name "Syslog-DCR" \
  --location <region> \
  --data-sources '[{
    "syslog": {
      "facilityNames": ["auth", "authpriv", "daemon", "user"],
      "logLevels": ["All"]
    }
  }]' \
  --destinations '[{
    "logAnalytics": {
      "workspaceResourceId": "/subscriptions/<sub-id>/resourceGroups/<rg>/providers/Microsoft.OperationalInsights/workspaces/<workspace-name>"
    }
  }]'
