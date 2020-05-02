#pragma once
#include <cstdint>
#include <vector>
#include "block.h"

class block_chain {
public:
    block_chain();

    void add_block(block b_new);

private:
    uint32_t n_difficulty_;
    std::vector<block> v_chain_;

    block get_last_block() const;
};