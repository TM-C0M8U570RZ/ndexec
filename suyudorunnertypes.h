#ifndef SUYUDORUNNERTYPES_H
#define SUYUDORUNNERTYPES_H
#include <tmc_global_types.h>

namespace tmc {
namespace suyudo {

enum QuestionType : u8 {
    MATCHING = 0,
    MULTIPLE_CHOICE
};

enum UsedIn : u8 {
    VERITY = 0,
    SUYUDO
};

}
}

#endif // SUYUDORUNNERTYPES_H
