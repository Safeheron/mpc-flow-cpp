#ifndef MPC_FLOW_CPP_MPC_FLOW_MPC_PARALLEL_LAZYBCVALIDATOR_V2_H
#define MPC_FLOW_CPP_MPC_FLOW_MPC_PARALLEL_LAZYBCVALIDATOR_V2_H
#include <map>
#include <string>

namespace safeheron {
namespace mpc_flow {
namespace mpc_parallel {
class LazyBCValidator_V2 {
public:
    void CacheDigest(const std::string &party_id, const std::string &digest);
    std::map<std::string, std::string> get_cached_party_id_digest() const;
    int get_cache_size() const;
    bool ValidateDigest(const std::map<std::string, std::string> &compared_party_id_digest,
                        std::string &unmatched_party_id,
                        std::string &unmatched_digest) const;
private:
    std::map<std::string, std::string> party_id_digest_cache_;
};
}
}
}


#endif //MPC_FLOW_CPP_MPC_FLOW_MPC_PARALLEL_LAZYBCVALIDATOR_V2_H
