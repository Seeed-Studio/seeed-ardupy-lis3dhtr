# Seeed ArduPy LIS3DHTR [![Build Status](https://api.travis-ci.com/Seeed-Studio/seeed-ardupy-lis3dhtr.svg?branch=master)](https://travis-ci.com/github/Seeed-Studio/seeed-ardupy-lis3dhtr)

## Introduction

An ArduPy library for 3-Axis Digital Accelerometer ±2g to 16g (LIS3DHTR).Acceleration data can be obtained using IIC interface.

## How to binding with ArduPy
- Install [AIP](https://github.com/Seeed-Studio/ardupy-aip)
```shell
pip3 install aip
```
- Build firmware with Seeed ArduPy LIS3DHTR
```shell
aip install https://github.com/Seeed-Studio/seeed-ardupy-lis3dhtr
aip build
```
- Flash new firmware to you ArduPy board
```shell
aip flash [Ardupy Bin PATH]
```
For more examples of using AIP, please refer to [AIP](https://github.com/Seeed-Studio/ardupy-aip).
## Usage
```python
from arduino import grove_lis3dhtr
lis = grove_lis3dhtr()

while True:
    if lis.avaiable():
        print("X: ", lis.x)
        print("Y: ", lis.y)
        print("Z: ", lis.z)

```
## API Reference
- **available(*void*) : bool** - available
```python
if lis.available():
    print("X: " + lis.x)
```

- **setPoweMode(*mode\<uint8_t\>*) : void** - set power mode
```python
# Set power mode
lis.setPoweMode(0) #POWER_MODE_NORMAL 
lis.setPoweMode(1) #POWER_MODE_LOW 
```
- **setFullScaleRange(*range\<uint8_t\>*) : void** - set full scale range
```python
lis.setFullScaleRange(0) # LIS3DHTR_RANGE_2G 
lis.setFullScaleRange(1) # LIS3DHTR_RANGE_4G
lis.setFullScaleRange(2) # IS3DHTR_RANGE_8G
lis.setFullScaleRange(3) # LIS3DHTR_RANGE_16G
```
- **setOutputDataRate(*rate\<uint8_t\>*) : void** - set output data rate
```python
lis.setOutputDataRate(0) # LIS3DHTR_DATARATE_POWERDOWN 
lis.setOutputDataRate(2) # LIS3DHTR_DATARATE_10HZ
lis.setOutputDataRate(3) # LIS3DHTR_DATARATE_25HZ
lis.setOutputDataRate(4) # LIS3DHTR_DATARATE_50HZ
lis.setOutputDataRate(5) # LIS3DHTR_DATARATE_100HZ
lis.setOutputDataRate(6) # LIS3DHTR_DATARATE_400HZ
lis.setOutputDataRate(7) # LIS3DHTR_DATARATE_400HZ
lis.setOutputDataRate(8) # LIS3DHTR_DATARATE_1_6KH
lis.setOutputDataRate(9) # LIS3DHTR_DATARATE_5KHZ
```
- **setHighSolution(*rate\<bool\>*) : void** set high solution
```python
lis.setHighSolution(True) # HighSolution enable
lis.setHighSolution(False) # HighSolution disable
```
- **openTemp(*void*) : void** - open temperature enable
```python
lis.openTemp()
```
- **closeTemp(*void*) : void** - close temperature enable
```python
lis.closeTemp()
```
- **x : float** - get acceleration z
```python
x = lis.x
```
- **y : float** - get acceleration y
```python
y = lis.y
```
- **z : float** - get acceleration z
```python
z = lis.z
```
- **adc1 : uint16_t** - get adc channle 1
```python
adc1 = lis.adc1
```
- **adc2 : uint16_t** - get adc channle 2
```python
adc2 = lis.adc2
```
- **adc3 : uint16_t** - get adc channle 3
```python
adc3 = lis.adc3
```

- **temperature : uint16_t** - get temperature
```python
temperature = lis.temperature
```

----
## License
This software is written by seeed studio<br>
and is licensed under [The MIT License](http://opensource.org/licenses/mit-license.php). Check License.txt for more information.<br>

Contributing to this software is warmly welcomed. You can do this basically by<br>
[forking](https://help.github.com/articles/fork-a-repo), committing modifications and then [pulling requests](https://help.github.com/articles/using-pull-requests) (follow the links above<br>
for operating guide). Adding change log and your contact into file header is encouraged.<br>
Thanks for your contribution.

Seeed Studio is an open hardware facilitation company based in Shenzhen, China. <br>
Benefiting from local manufacture power and convenient global logistic system, <br>
we integrate resources to serve new era of innovation. Seeed also works with <br>
global distributors and partners to push open hardware movement.<br>
