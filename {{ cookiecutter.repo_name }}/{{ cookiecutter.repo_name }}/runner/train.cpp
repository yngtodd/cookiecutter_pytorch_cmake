#include <iostream>
#include <torch/torch.h>
#include <mlp.hpp>
#include <mnist.hpp>

int main() {
    mlp::MLP net;

    mlp::print_parameters(net);
    std::cout << "\nNetwork output:\n" << std::endl;
    std::cout << net.forward(torch::ones({2, 784})) << std::endl;
}
