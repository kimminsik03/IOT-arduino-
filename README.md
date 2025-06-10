이 폴더에는 2025년 1학기에 진행하는 IOT과목의 수업내용을 올립니다 

# InfluxDB 설치

### InfluxDB download key using wget
```
  wget -q https://repos.influxdata.com/influxdata-archive_compat.key
  echo '393e8779c89ac8d958f81f942f9ad7fb82a25e133faddaf92e15b16e6ac9ce4c influxdata-archive_compat.key' | sha256sum -c && cat   influxdata-archive_compat.key | gpg --dearmor | sudo tee /etc/apt/trusted.gpg.d/influxdata-archive_compat.gpg > /dev/null
  echo 'deb [signed-by=/etc/apt/trusted.gpg.d/influxdata-archive_compat.gpg] https://repos.influxdata.com/debian stable main' | sudo tee /etc/apt/sources.list.d/influxdata.list
```

### Packages are up to date && install Influxdb
 ```
 sudo apt-get update && sudo apt-get install influxdb -y
```
### InfluxDB as a background service on startup
```
  sudo service influxdb start
```
### InfluxDB is status (service)
```
  sudo service influxdb status
```
# InfluxDB 데이터베이스 만들기
```
$ influx

>create database (DBname)
show databases(How to check the database I created)
```

### influxdb import with python
```
pip install influxdb
```

### hint: See PEP 668 for the detailed specification 
```
  //위에서 pip install influxdb 명령어가 에러가 났을 때 
  sudo rm /usr/lib/python3.11/EXTERNALLY-MANAGED
```

# Grafana Installation
### 1. Install the prerequisite packages
```
sudo apt-get install -y apt-transport-https software-properties-common wget
```
### 2. Import the GPG key:
```
sudo mkdir -p /etc/apt/keyrings/
wget -q -O - https://apt.grafana.com/gpg.key | gpg --dearmor | sudo tee /etc/apt/keyrings/grafana.gpg > /dev/null
```
### 3. To add a repository for stable releases, run the following command:
```
echo "deb [signed-by=/etc/apt/keyrings/grafana.gpg] https://apt.grafana.com stable main" | sudo tee -a /etc/apt/sources.list.d/grafana.list
```
### 4. Run the following command to update the list of available packages:
```
sudo apt-get update && sudo apt-get install grafana -y
```
### 5. Run the following command to server start
```
sudo systemctl start grafana-server
```
#====================================================================================================================

#라즈베리파이5 TinyOS , NesC , Oscilloscope.py(미들웨어) 설치
###사전 설치
```
sudo apt-get install emacs gperf bison flex git build-essential automake avarice avr-libc avrdude binutils-avr gcc-avr gdb-avr subversion graphviz checkinstall openjdk-17-jdk git
```
###사전 설정
#1
```
$ vim ~/tinyos.env

export TOSROOT=/opt/tinyos-2.x
export TOSDIR=$TOSROOT/tos
export CLASSPATH=$TOSROOT/support/sdk/java/tinyos.jar:$CLASSPATH
export CLASSPATH=$TOSROOT/support/sdk/java:$CLASSPATH
export CLASSPATH=.:$CLASSPATH
export MAKERULES=$TOSROOT/support/make/Makerules
export PYTHONPATH=$PYTHONPATH:$TOSROOT/support/sdk/python

echo "setting up TinyOS on source path $TOSROOT"
```
#2
```
$ vim ~/.bashrc
  끝줄에 추가
  source ~/tinyos.env
```
#3 실행
```
$ source ~/.bashrc
```
#JNI 파일 복사
```
$ git clone https://github.com/sonnonet/jni.git
$ cd jni/tinyos/
$ sudo mv libtoscomm.so /usr/lib
$ sudo mv libgetenv.so /usr/lib
```
#NesC 설치
```
$ mv ~/sonnonet/jni/tinyos/nesc-1.3.4.tar.gz ~/
$ tar –xvzf nesc-1.3.4.tar.gz
$ cd nesc-1.3.4
$ ./configure --build=aarch64-unknown-linux-gnu
$ make
$ sudo make install
```
#TinyOS-Tools 설치
```
$ cd /home/pi
$ git clone --branch release_tinyos_2_1_2 https://github.com/tinyos/tinyos-release.git
$ mv tinyos-release tinyos-2.x && sudo mv tinyos-2.x /opt/
$ cd /opt/tinyos-2.x/tools/
$ ./Bootstrap
$ ./configure --build=aarch64-unknown-linux-gnu
$ make
$ sudo make install
```
#테스트
```
$ motelist
```

#기본 미들웨어 소스코드 다운
```
$ git clone https://github.com/sonnonet/2024_inhatc
$ cd 2024_inhatc/Zigbee/Oscilloscope/
```
#실행방법 (mote 연결후)
```
python oscilloscope.py serial@/dev/ttyUSB0:115200
```
#tos.py 복사
```
$ mv ./tos.py /opt/tinyos-2.x/support/sdk/python/tos.py
```
#Error
```
attributeerror 'Serial' object has no attribute 'setbaudrate'
-> sudo vim /usr/local/bin/tos-bsl
-> :1345 줄로 이동
-> self.serialport.setBaudrate(baudrate) -> self.serialport.setBaudrate = baudrate (수정)
```

```
attributeerror 'serial' object has no attribute 'Serial'
-> pip uninstall serial
-> pip install pyserial
```










