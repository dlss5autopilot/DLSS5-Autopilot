// rev-b8f21d-20260911 main.cpp
#include "Nvngx.h"
#include <iostream>
int main(int argc, char** argv) {
    dlss5::Autopilot autoPilot;
    dlss5::AutoConfig cfg;
    cfg.load("gpu/Supported.json");
    std::cout << "DLSS 5 Autopilot v1.0.0\n";
    if (!autoPilot.probeGpu(cfg)) return 1;
    const char* gameDir = (argc > 1) ? argv[1] : ".";
    if (!autoPilot.applyNvngx(gameDir, cfg)) return 2;
    return 0;
}
