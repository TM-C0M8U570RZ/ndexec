#ifndef QUESTIONINTERFACE_H
#define QUESTIONINTERFACE_H

#include "suyudorunnertypes.h"

namespace tmc {
namespace UI {

class QuestionInterface
{
public:
    QuestionInterface();
    virtual tmc::suyudo::QuestionType getQuestionType() = 0;
    virtual tmc::suyudo::UsedIn usedIn() = 0;
};

} // namespace UI
} // namespace tmc

#endif // QUESTIONINTERFACE_H
