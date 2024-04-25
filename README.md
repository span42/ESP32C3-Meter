
# ESP32C3电流表

基于[硬创社一款ESP32C3方案](https://x.jlc.com/platform/detail/4d6a2bda7be04d82ac1198d2ee54cad1?type=1)的修改版项目

#### 方案

（1）输入电压：5~30V
（2）输入电流：8A
（3）板子四层，阻容器件全部 >= 0603，方便人肉贴片
（4）1.14寸分辨率135*240  ST7789 IPS彩屏
（5）电压测量精度：±0.01V
（6）电流测量精度：±0.01A
（7）type-c接口，方便调试下载，同时也预留了UART下载口
（8）lvgl界面
（9）wifi联网
（10）双按键
（11）web server


#### 开发环境

  VSCode platformio ESP32C3 arduino
  [idf-5.1.2下载地址](https://dl.espressif.cn/dl/idf-installer/espressif-ide-setup-2.12.0-with-esp-idf-5.1.2.exe)

#### 依赖库

|-- lvgl @ 8.4.0
|-- EEPROM @ 2.0.0
|-- WiFi @ 2.0.0
|-- LittleFS @ 2.0.0
|-- WebServer @ 2.0.0
|-- PubSubClient @ 2.8.0
|-- ArduinoJson @ 7.0.4
|-- HTTPClient @ 2.0.0
|-- OneButton @ 2.5.0
|-- TFT_eSPI @ 2.5.43
|-- INA226 @ 0.5.2
|-- Wire @ 2.0.0

#### 资源占用

RAM:   [===       ]  31.1% (used 101844 bytes from 327680 bytes)
Flash: [=======   ]  72.6% (used 1713410 bytes from 2359296 bytes)
Building .pio\build\esp32-c3-devkitm-1\firmware.bin

#### 功能即特点：
    ESP32C3主频160MHz，RAM 300KB，Flash 4MB，支持wifi及蓝牙
    可外部供电，也可type-c供电
    支持反方向供电，但我一般用不到
    双按键，靠近typc-c口按键短按时为屏幕显示方向切换，长按2s释放后为系统重启，如果此键在系统重启时长按下，系统将进入AP配置模式；另一个键用于界面循环切换
    freertos多任务
    基本的mAh，mWh累计；平均值，最大最小值统计
    实时系统时间，wifi联网后自动获取，断电不保存
    实时天气，来源openweatherMap API，需用户申请 apikey 并在wifi配置页面填入，城市选择只简单列了几项，可在 config.html文件随时追加
    引入mqtt，随时可将数据上发到平台

lvgl 界面设计
![](/4.Image/lvgl.png)

板子背面，flash可不焊
![](/4.Image/背.jpg)

实时电压电流功率
![](/4.Image/ui1.jpg)

平均，最大，最小电压电流功率
![](/4.Image/ui2.jpg)

信息系统
![](/4.Image/ui3.jpg)

集成openweatherMap天气
![](/4.Image/ui4.jpg)

左图数值是板子功耗
![](/4.Image/功耗.jpg)

AP设置模式：长按屏幕翻转键2秒，释放后设备重启，马上接着长按 即进入AP模式
![](/4.Image/ap.jpg)

手机连上板子热点后，扫码进入配置界面，界面还没来得及美化
![](/4.Image/设置AP.png)