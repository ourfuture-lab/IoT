1、使用新的8266的库，连接wifi后，作tcp server
   pc连接同一个wifi，再通过telnet ip 端口，例如telnet 10.0.1.2 8090
   示例中的ssid与password改成等连接的wifi名字和密码
   
2、硬件连线
Arduino端          ESP8266
   GND     <--->   GND
   3.3V    <--->   VCC         #必须得连3.3V，连5V会导致温度过高
   3.3V    <--->   CH_PD       #必须得连3.3V，连5V会导致温度过高，如果开机8266蓝灯亮，说明电压还高，需要加大电阻
   URXD    <--->   TX（D2）    #根据程序设定的确定具体的端口
   UTXD    <--->   RX（D3）    #根据程序设定的确定具体的端口
