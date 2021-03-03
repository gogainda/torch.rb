#include <torch/torch.h>

#include <rice/rice.hpp>

#include "utils.h"

void init_device(Rice::Module& m) {
  Rice::define_class_under<torch::Device>(m, "Device")
    .add_handler<torch::Error>(handle_error)
    .define_constructor(Rice::Constructor<torch::Device, std::string>())
    .define_method("index", &torch::Device::index)
    .define_method("index?", &torch::Device::has_index)
    .define_method(
      "type",
      [](torch::Device& self) {
        std::stringstream s;
        s << self.type();
        return s.str();
      });
}
