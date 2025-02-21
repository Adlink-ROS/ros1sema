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

#include "main.hpp"

int main(int argc, char* argv[]) {

  uint32_t ret;
  uint32_t handler;

  // Initial sema
  ret = SemaEApiLibInitialize(false,
      IP_V4,
      "127.0.0.1",
      0,
      (char *)"",
      &handler);

  if (ret != EAPI_STATUS_SUCCESS) {
    std::cout << "Initial sema failed" << std::endl;
    return 0;
  }

  std::cout << "Initial sema success" << std::endl;

  ros::init(argc, argv, "talker");

  ros::NodeHandle n;

  return 0;
}
