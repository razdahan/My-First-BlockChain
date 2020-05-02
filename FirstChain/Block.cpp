#include "Block.h"
#include "sha256.h"
#include <time.h>
#include "vector"
#include <string>
#include <sstream>

block::block(std::uint32_t n_index_in, const std::string& s_data_in)
{
	this->n_nonce_ = 0;
	this->t_time_ = time(nullptr);
}

std::string block::get_hash()
{
	return this->s_hash_;
}

void block::mine_block(const std::uint32_t n_difficulty)
{

    std::vector<char> cstr;
    for (uint32_t i = 0; i < n_difficulty; ++i) {
        cstr.push_back('0');
    }
    cstr.insert(cstr.end(),'\0');

    const std::string str(cstr.begin(),cstr.end());
    std::cout << "the str is " << str << std::endl;
 
	
    auto counter = 0;
    do {
        this->n_nonce_++;
        this->s_hash_ = calculate_hash();
    	if(counter%1000==0)
			std::cout << "\r tried "<<counter<<" hashes";
        counter += 1;
    } while (this->s_hash_.substr(0, n_difficulty) != str);

    std::cout << std::endl;
    std::cout << "Block mined: " << this->s_hash_ << std::endl;
}

inline std::string block::calculate_hash() const
{
	std::stringstream ss;
    ss << this->n_index_ << this->t_time_ << this->s_data_<< this->n_nonce_ << this->s_prev_hash;

    return sha256(ss.str());
}
