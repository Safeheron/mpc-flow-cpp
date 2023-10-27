#include "LazyBCValidator_V2.h"
#include "crypto-hash/sha256.h"
namespace safeheron {
namespace mpc_flow {
namespace mpc_parallel {
void LazyBCValidator_V2::CacheDigest(const std::string &party_id, const std::string &digest) {
    party_id_digest_cache_[party_id] = digest;
}

std::map<std::string, std::string> LazyBCValidator_V2::get_cached_party_id_digest() const {
    return party_id_digest_cache_;
}

int LazyBCValidator_V2::get_cache_size() const {
    return party_id_digest_cache_.size();
}

bool LazyBCValidator_V2::ValidateDigest(const std::map<std::string, std::string> &compared_party_id_digest,
                    std::string &unmatched_party_id,
                    std::string &unmatched_digest) const {
    if (compared_party_id_digest.size() != party_id_digest_cache_.size()) return false;

    uint32_t count = 0;
    for (auto iter = compared_party_id_digest.begin(); iter != compared_party_id_digest.end(); iter++) {
        bool is_party_found = false;
        std::map<std::string, std::string>::const_iterator found = party_id_digest_cache_.find(iter->first);
        if (found != party_id_digest_cache_.end()) {
            is_party_found = true;
            if(found->second == iter->second) {
                count++;
            } else {
                unmatched_party_id = iter->first;
                unmatched_digest = iter->second;
                return false;
            }
        }
        if(!is_party_found){
            unmatched_party_id = iter->first;
            unmatched_digest.clear();
            return false;
        }
    }

    return count == party_id_digest_cache_.size();
}

}
}
}