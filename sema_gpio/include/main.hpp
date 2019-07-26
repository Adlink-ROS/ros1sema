// Copyright 2019 ADLINK Technology Ltd. Advanced Robotic Platform Group
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef _SEMA_GPIO_MAIN_HPP_H_
#define _SEMA_GPIO_MAIN_HPP_H_

// standard headers
#include <iostream>

// roscpp headers
#include <ros/ros.h>
#include <ros/console.h>

#ifdef __cplusplus
extern "C" {
#endif
// sema headers
  #include <linux/EApiOs.h>
  #include <EApi.h>
  #include <semaeapi.h>
#ifdef __cplusplus
}
#endif

#endif /* _SEMA_GPIO_MAIN_HPP_H_ */
