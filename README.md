이 폴더에는 2025년 1학기에 진행하는 IOT과목의 수업내용을 올립니다 



### InfluxDB 설치

InfluxDB download key using wget
```
  wget -q https://repos.influxdata.com/influxdata-archive_compat.key
  echo '393e8779c89ac8d958f81f942f9ad7fb82a25e133faddaf92e15b16e6ac9ce4c influxdata-archive_compat.key' | sha256sum -c && cat   influxdata-archive_compat.key | gpg --dearmor | sudo tee /etc/apt/trusted.gpg.d/influxdata-archive_compat.gpg > /dev/null
  echo 'deb [signed-by=/etc/apt/trusted.gpg.d/influxdata-archive_compat.gpg] https://repos.influxdata.com/debian stable main' | sudo tee /etc/apt/sources.list.d/influxdata.list
```

Packages are up to date && install Influxdb
 ```
 sudo apt-get update && sudo apt-get install influxdb -y
```
InfluxDB as a background service on startup
```
  sudo service influxdb start
```
InfluxDB is status (service)
```
  sudo service influxdb status
```
