# Edit the rsyslog configuration to allow remote devices to send logs:

sudo nano /etc/rsyslog.conf
Uncomment or add the following lines:
module(load="imudp")
input(type="imudp" port="514")

module(load="imtcp")
input(type="imtcp" port="514")
Then restart rsyslog:
sudo systemctl restart rsyslog
