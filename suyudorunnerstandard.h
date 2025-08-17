#ifndef SUYUDORUNNERSTANDARD_H
#define SUYUDORUNNERSTANDARD_H

#include <tmc_global_1to1_algos.h>
#include "qveritymultiplechoicequestion.h"
#include "qveritymatchingquestion.h"
#include <QWizard>

std::vector<std::shared_ptr<QWizardPage>> getStandardVerityQuestionsR13(QWizard* parent);
std::vector<std::shared_ptr<QWizardPage>> getStandardVerityQuestionsR18(QWizard* parent);

#endif // SUYUDORUNNERSTANDARD_H
