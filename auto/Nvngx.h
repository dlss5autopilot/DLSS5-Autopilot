// rev-b8f21d-20260911 Nvngx.h
#pragma once
#include <string>
namespace dlss5 {
struct AutoConfig {
    bool allow30Series = true;
    bool allow40Series = true;
    bool allow50Series = true;
    bool refuseAmd = true;
    std::string nvngxName = "nvngx_dlss.dll";
    bool load(const std::string& path);
};
class Autopilot {
public:
    bool probeGpu(const AutoConfig& cfg) const;
    bool applyNvngx(const std::string& gameDir, const AutoConfig& cfg);
};
}
