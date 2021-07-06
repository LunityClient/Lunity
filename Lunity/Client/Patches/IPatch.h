#ifndef LUNITY_CLIENT_PATCHES_IPATCH
#define LUNITY_CLIENT_PATCHES_IPATCH

#include <string>
#include <polyhook2/Detour/x86Detour.hpp>
#include <polyhook2/CapstoneDisassembler.hpp>

class IPatch
{
	static inline PLH::CapstoneDisassembler* dis = new PLH::CapstoneDisassembler(PLH::Mode::x86);
	std::string name;
public:
	IPatch(std::string name);
	auto GetName() -> std::string;
	auto GetDis() -> PLH::CapstoneDisassembler&;
	virtual auto Apply() -> bool;
};

#endif /* LUNITY_CLIENT_PATCHES_IPATCH */
