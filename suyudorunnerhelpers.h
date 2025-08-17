#ifndef SUYUDORUNNERHELPERS_H
#define SUYUDORUNNERHELPERS_H

#include <veritycallback.h>
#include <tmc_global_1to1_algos.h>

namespace tmc {
namespace suyudo {

class VerityWizard;

std::vector<u8> buildMspcache(bool r13Pass, bool r18Pass, VerityWizard* vw, const std::string& password);

}
}

#endif // SUYUDORUNNERHELPERS_H
