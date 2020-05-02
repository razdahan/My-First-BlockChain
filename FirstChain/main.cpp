#include "Blockchain.h"
#include <iostream>

int main(){
block_chain bChain = block_chain();

std::cout << "Mining block 1..." << std::endl;
bChain.add_block(block(1, "Block 1"));

std::cout << "Mining block 2..." << std::endl;
bChain.add_block(block(2, "Block 2"));

std::cout << "Mining block 3..." << std::endl;
bChain.add_block(block(3, "Block 3"));

return 0;
}