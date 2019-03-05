#ifndef _MLP_HPP_
#define _MLP_HPP_

#include <torch/torch.h>

namespace mlp {

  // Define a new Module.
  struct MLP : torch::nn::Module {
    MLP() {
      // Construct and register three Linear submodules.
      fc1 = register_module("fc1", torch::nn::Linear(784, 64));
      fc2 = register_module("fc2", torch::nn::Linear(64, 32));
      fc3 = register_module("fc3", torch::nn::Linear(32, 10));
    }

    // Implement the Net's algorithm.
    torch::Tensor forward(torch::Tensor x) {
      // Use one of many tensor manipulation functions.
      x = torch::relu(fc1->forward(x.reshape({x.size(0), 784})));
      x = torch::dropout(x, /*p=*/0.5, /*train=*/is_training());
      x = torch::relu(fc2->forward(x));
      x = torch::log_softmax(fc3->forward(x), /*dim=*/1);
      return x;
    }

    // Use one of many "standard library" modules.
    torch::nn::Linear fc1{nullptr}, fc2{nullptr}, fc3{nullptr};
  };

  void print_parameters(mlp::MLP net);

}

#endif // _MLP_HPP_
