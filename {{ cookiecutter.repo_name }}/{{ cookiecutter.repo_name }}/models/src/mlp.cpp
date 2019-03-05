#include <mlp.hpp>

namespace mlp {

    void print_parameters(mlp::MLP net)
    {
        for (const auto& pair : net.named_parameters())
        {
            std::cout << pair.key() << ": " << pair.value() << std::endl;
        }
    }

}
