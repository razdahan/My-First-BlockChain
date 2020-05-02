#pragma once
#include <cstdint>
#include <iostream>
#include "string"
class block
{
public:
	std::string s_prev_hash;

	block(std::uint32_t n_index_in, const std::string& s_data_in);
	std::string get_hash();
	void mine_block(const std::uint32_t n_difficulty);

private:
	std::uint32_t n_index_;
	std::int64_t n_nonce_;
	std::string s_data_;
	std::string s_hash_;
	time_t t_time_;
	std::string calculate_hash() const;
};