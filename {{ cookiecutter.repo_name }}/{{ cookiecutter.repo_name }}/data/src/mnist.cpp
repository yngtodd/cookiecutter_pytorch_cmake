#include <string>
#include <cstring>
#include <iostream>
#include <mnist.hpp>
#include <torch/torch.h>

namespace data {

  auto load_mnist(std::string& path)
  {
      std::cout << "Loading MNIST dataset!" << std::endl;
      auto dataset = torch::data::datasets::MNIST(path)
                     .map(torch::data::transforms::Normalize<>(0.5, 0.5))
                     .map(torch::data::transforms::Stack<>());

      return dataset;
  }

}
