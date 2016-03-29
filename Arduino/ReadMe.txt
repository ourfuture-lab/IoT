1、硬件连线
Arduino的GND有多个，可以任意接
电压5V和3.3V，根据传感器的要求来选择
数字口D0-D13和模拟口A0-A5，根据传感器来选择数字还是模拟的。例如，超声波传感器测距示例程序连接的D2和D3口，可以换成其他D口，当然硬件连线有变化，程序也需要设置对应的输入输出端口

2、调试
需要注意的是，在Arduino IDE的工具菜单选择正确的Arduino的型号、几号com口、串口的波特率

Arduino内置的Serial.print函数可打印输出，通过打开Arduino IDE的串口工具，可观察到print打印做简单调试，特别要注意的PC端波特率的设置，大部程序的波特率是9600，有的38400，这个具体根据程序中设定值来设置PC端的com的波特率。

3、编译
在window系统，如果使用第三方库，需要将库文件放Arduino IDE对应的目录下，在windows用户的我的文档Arduino下。
例如，使用了HMC5883L的库，需要放在C:\Users\Administrator\Documents\Arduino\libraries\HMC5883L这个目录下。

