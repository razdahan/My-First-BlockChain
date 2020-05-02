#include "Blockchain.h"
#include "Block.h"
block_chain::block_chain()
{
	this->v_chain_.emplace_back(block(0, "Genesis Block"));
	this->n_difficulty_ = 6;
}

void block_chain::add_block(block b_new)
{
	b_new.s_prev_hash = get_last_block().get_hash();
	b_new.mine_block(n_difficulty_);
	v_chain_.push_back(b_new);
}

block block_chain::get_last_block() const
{
	return this->v_chain_.back();
}
