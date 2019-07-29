# ros1sema

SEMA is a Board Management Controller (BMC) software for supporting ADLINK Technology industrial computers.

[SEMA websute](https://www.adlinktech.com/Products/Industrial_IoT_and_Cloud_solutions/SEMA_Smart_Embedded_Management_Agent/SEMA?lang=en)

This repository is for those who want to use SEMA functions on their ROS application.

# Note first

This package only support SEMA 3.6, which has not released official yet. If you are ADLINK's customers who want to use SEMA on your ROS application. Please contact your agent.

Reason: SEMA 3.5 statically link to it's own liblog4cpp.so which is conflict with roscpp. (rosconsole use log4cxx which has the same API with log4cpp but inconsist functions).

If you use this packages within a SEMA 3.5 library, you will get an exception.

# Quick start

```bash
$> mkdir -p ~/ros_ws/src
$> cd ~/ros_ws/src/
$> git clone  https://github.com/Adlink-ROS/ros1sema -b release
$> cd ~/ros_ws/
$> catkin_make
```

# How to use this repository to link SEMA ?

There's a cmake module for finding sema library: `sema_vendor` which located at this repository. Please add this package to your ROS package dependency.

You can follow the example `sema_gpio` to see how to use `sema_vendor` to link SEMA.

Briefly, there are 4 steps.

## Add dependency in your package.xml

[add dependency](https://github.com/Adlink-ROS/ros1sema/blob/1df3b170932971b1e6c566675773ea11e022873e/sema_gpio/package.xml#L18)

## Link `libsema` in your CMakeLists.txt

1. [search sema_vendor](https://github.com/Adlink-ROS/ros1sema/blob/1df3b170932971b1e6c566675773ea11e022873e/sema_gpio/CMakeLists.txt#L19)
2. [find_package libsema](https://github.com/Adlink-ROS/ros1sema/blob/1df3b170932971b1e6c566675773ea11e022873e/sema_gpio/CMakeLists.txt#L21)

## include libsema headers

[include libsema headers](https://github.com/Adlink-ROS/ros1sema/blob/1df3b170932971b1e6c566675773ea11e022873e/sema_gpio/CMakeLists.txt#L23)

## Link `semaeapi` to your target

[link libsema to your target](https://github.com/Adlink-ROS/ros1sema/blob/1df3b170932971b1e6c566675773ea11e022873e/sema_gpio/CMakeLists.txt#L38)

## Search environment SEMA_BSP_PATH

export SEMA_BSP_PATH= "where you put sema library"

## Override your target's  runpath (this step is optional)

[override rpath for your targets](https://github.com/Adlink-ROS/ros1sema/blob/1df3b170932971b1e6c566675773ea11e022873e/sema_gpio/CMakeLists.txt#L41)
