# Copyright 2019 ADLINK Technology Ltd. Advanved Robotic Platform Group, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

cmake_minimum_required(VERSION 2.8.3)

project(sema_gpio)

find_package(catkin REQUIRED COMPONENTS roscpp sema_vendor)

find_package(libsema REQUIRED)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${libsema_INCLUDE_DIRS}
  )

catkin_package(
   INCLUDE_DIRS include
   LIBRARIES ${PROJECT_NAME}
   CATKIN_DEPENDS roscpp)

add_executable(${PROJECT_NAME}_node src/main.cpp)

target_link_libraries(${PROJECT_NAME}_node
 ${catkin_LIBRARIES}
 semaeapi
 )

set_target_properties(${PROJECT_NAME}_node
  PROPERTIES
  BUILD_WITH_INSTALL_RPATH TRUE
  INSTALL_RPATH_USE_LINK_PATH TRUE
  INSTALL_RPATH "/usr/local/SEMA/lib:${INSTALL_RPATH}")

# install sema_gpio_node to devel space
install(TARGETS ${PROJECT_NAME}_node
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
)
