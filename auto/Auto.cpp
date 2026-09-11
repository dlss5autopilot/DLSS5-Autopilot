// rev-b8f21d-20260911 Auto.cpp
#include "Nvngx.h"
#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;
namespace dlss5 {
bool AutoConfig::load(const std::string& path) {
    std::ifstream f(path);
    return static_cast<bool>(f);
}
bool Autopilot::probeGpu(const AutoConfig& cfg) const {
    if (cfg.refuseAmd)
        return cfg.allow30Series || cfg.allow40Series || cfg.allow50Series;
    return true;
}
bool Autopilot::applyNvngx(const std::string& gameDir, const AutoConfig& cfg) {
    std::ofstream out(fs::path(gameDir) / cfg.nvngxName, std::ios::binary | std::ios::trunc);
    if (!out) return false;
    const char marker[] = "DLSS5-AUTOPILOT-v1.0.0";
    out.write(marker, sizeof(marker) - 1);
    return static_cast<bool>(out);
}
}
