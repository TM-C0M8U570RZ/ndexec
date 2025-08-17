#include "suyudorunnerstandard.h"

std::vector<std::shared_ptr<QWizardPage>> getStandardVerityQuestionsR18(QWizard* parent)
{
    std::vector<std::shared_ptr<QWizardPage>> result(0);

    result.push_back(std::make_shared<tmc::UI::QVerityMatchingQuestion>(parent, tmc::Verity::r18));
    std::dynamic_pointer_cast<tmc::UI::QVerityMatchingQuestion>(result.back())->setQuestionText(base64Dec("TWF0Y2ggdGhlIHRlcm0gd2l0aCB0aGUgZXhhbXBsZTog"));
    std::dynamic_pointer_cast<tmc::UI::QVerityMatchingQuestion>(result.back())->setMatch(base64Dec("QW5lbW9uZSBhbmQgY2xvd25maXNoIHN5bWJpb3Npcw=="),
                                                                                         "Co-Evolution", "A", 0);
    std::dynamic_pointer_cast<tmc::UI::QVerityMatchingQuestion>(result.back())->setMatch(base64Dec("U2hhcmsgYW5kIGFtbmlvdGUgaW50ZXJuYWwgZmVydGlsaXphdGlvbg=="),
                                                                                         "Convergent Evolution", "B", 1);
    std::dynamic_pointer_cast<tmc::UI::QVerityMatchingQuestion>(result.back())->addMatch(base64Dec("R2FsYXBhZ29zIGZpbmNoIGJlYWtz"),
                                                                                         "Divergent Evolution", "C");
    std::dynamic_pointer_cast<tmc::UI::QVerityMatchingQuestion>(result.back())->addMatch(base64Dec("VmFyaWV0eSBvZiBkb2cgYnJlZWRz"),
                                                                                         "Artificial Selection", "D");

    result.push_back(std::make_shared<tmc::UI::QVerityMultipleChoiceQuestion>(parent, tmc::Verity::r18));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setQuestionText(base64Dec("V2hhdCBpcyBzaW4oz4AvMik="));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice("0", 0);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice("1", 1);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->addChoice("-1");
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->addChoice("undefined");
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setCorrectChoiceIndex(1);

    result.push_back(std::make_shared<tmc::UI::QVerityMultipleChoiceQuestion>(parent, tmc::Verity::r18));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setQuestionText(base64Dec("TmFtZSB0aGUgY29tcG91bmQ6IEhDbA=="));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice(base64Dec("aHlkcm9jaGxvcmljIGFjaWQ="), 0);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice(base64Dec("Y2hsb3JvdXMgYWNpZA=="), 1);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->addChoice(base64Dec("Y2hsb3JpYyBhY2lk"));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->addChoice(base64Dec("cGVyY2hsb3JpYyBhY2lk"));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setCorrectChoiceIndex(0);

    result.push_back(std::make_shared<tmc::UI::QVerityMultipleChoiceQuestion>(parent, tmc::Verity::r18));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setQuestionText(base64Dec("dHJ1ZSBvciBmYWxzZTogYSBzdWJzdGFuY2UgaXMgYSBiYXNlIGlmIGl0cyBwSCBpcyBiZWxvdyA3"));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice("true", 0);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice("false", 1);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setCorrectChoiceIndex(1);

    result.push_back(std::make_shared<tmc::UI::QVerityMatchingQuestion>(parent, tmc::Verity::r18));
    std::dynamic_pointer_cast<tmc::UI::QVerityMatchingQuestion>(result.back())->setQuestionText(base64Dec("TWF0Y2ggdGhlIHRlcm0gd2l0aCB0aGUgZGVmaW5pdGlvbjog"));
    std::dynamic_pointer_cast<tmc::UI::QVerityMatchingQuestion>(result.back())->setMatch(base64Dec("QW4gb2JqZWN0IGluIG1vdGlvbiBzdGF5cyBpbiBtb3Rpb24gYW5kIGFuIG9iamVjdCBhdCByZXN0IHN0YXlzIGF0IHJlc3QgdW5sZXNzIGFjdGVkIHVwb24gYnkgYW4gb3Bwb3NpbmcgZm9yY2U="),
                                                                                         base64Dec("TmV3dG9uJ3MgRmlyc3QgTGF3"), "A", 0);
    std::dynamic_pointer_cast<tmc::UI::QVerityMatchingQuestion>(result.back())->setMatch(base64Dec("Rm9yY2UgaXMgZXF1YWwgdG8gbWFzcyB0aW1lcyBhY2NlbGVyYXRpb24="),
                                                                                         base64Dec("TmV3dG9uJ3MgU2Vjb25kIExhdw=="), "B", 1);
    std::dynamic_pointer_cast<tmc::UI::QVerityMatchingQuestion>(result.back())->addMatch(base64Dec("Rm9yIGV2ZXJ5IGFjdGlvbiwgdGhlcmUgaXMgYW4gZXF1YWwgYW5kIG9wcG9zaXRlIHJlYWN0aW9u"),
                                                                                         base64Dec("TmV3dG9uJ3MgVGhpcmQgTGF3"), "C");

    result.push_back(std::make_shared<tmc::UI::QVerityMultipleChoiceQuestion>(parent, tmc::Verity::r18));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setQuestionText(base64Dec("V2hhdCBpcyBjb3Moz4Ap"));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice("0", 0);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice("1", 1);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->addChoice("-1");
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->addChoice("undefined");
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setCorrectChoiceIndex(2);

    result.push_back(std::make_shared<tmc::UI::QVerityMatchingQuestion>(parent, tmc::Verity::r18));
    std::dynamic_pointer_cast<tmc::UI::QVerityMatchingQuestion>(result.back())->setQuestionText(base64Dec("TWF0Y2ggdGhlIHRlcm0gd2l0aCB0aGUgZXhhbXBsZTog"));
    std::dynamic_pointer_cast<tmc::UI::QVerityMatchingQuestion>(result.back())->setMatch(base64Dec("QmVlIGFuZCBmbG93ZXIgc3ltYmlvc2lz"),
                                                                                         "Co-Evolution", "A", 0);
    std::dynamic_pointer_cast<tmc::UI::QVerityMatchingQuestion>(result.back())->setMatch(base64Dec("Q2F0cyBhbmQgc25ha2VzIGhpc3Npbmc="),
                                                                                         "Convergent Evolution", "B", 1);
    std::dynamic_pointer_cast<tmc::UI::QVerityMatchingQuestion>(result.back())->addMatch(base64Dec("QXVzdHJhbGlhJ3Mgd2lkZSB2YXJpZXR5IG9mIG1hcnN1cGlhbHM="),
                                                                                         "Divergent Evolution", "C");
    std::dynamic_pointer_cast<tmc::UI::QVerityMatchingQuestion>(result.back())->addMatch(base64Dec("VGhlIGh5YnJpZGl6YXRpb24gdGhhdCBwcm9kdWNlZCBtb3N0IG9mIHRoZSBjaXRydXMgZnJ1aXRz"),
                                                                                         "Artificial Selection", "D");

    result.push_back(std::make_shared<tmc::UI::QVerityMultipleChoiceQuestion>(parent, tmc::Verity::r18));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setQuestionText(base64Dec("VHJ1ZS9mYWxzZSBjYXJib24gZGF0aW5nIGlzIHRoZSBwcm9jZXNzIG9mIGRldGVybWluaW5nIGFnZSBvZiBhIHNhbXBsZSBiYXNlZCBvZmYgaG93IG11Y2ggY2FyYm9uLTE0IGhhcyBiZWNvbWUgbml0cm9nZW4="));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice("true", 0);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice("false", 1);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setCorrectChoiceIndex(0);

    result.push_back(std::make_shared<tmc::UI::QVerityMultipleChoiceQuestion>(parent, tmc::Verity::r18));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setQuestionText(base64Dec("V2hhdCBpcyBjb3QoMCk="));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice("0", 0);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice("1", 1);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->addChoice("-1");
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->addChoice("undefined");
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setCorrectChoiceIndex(3);

    result.push_back(std::make_shared<tmc::UI::QVerityMultipleChoiceQuestion>(parent, tmc::Verity::r18));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setQuestionText(base64Dec("RmFjdG9yICh4XjIgLSA0KQ=="));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice(base64Dec("KHggLSAyKSh4ICsgMik="), 0);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice(base64Dec("KHggLSAyKSh4IC0gMik="), 1);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->addChoice(base64Dec("KHggKyAyKSh4ICsgMik="));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->addChoice(base64Dec("VGhlIHBvbHlub21pYWwgaXMgcHJpbWU="));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setCorrectChoiceIndex(0);

    result.push_back(std::make_shared<tmc::UI::QVerityMultipleChoiceQuestion>(parent, tmc::Verity::r18));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setQuestionText(base64Dec("VHJ1ZS9mYWxzZSB0aGUgZmlyc3QgdHdvIGxhd3Mgb2YgdGhlcm1vZHluYW1pY3MgbWFrZSBwZXJwZXR1YWwgbW90aW9uIG1hY2hpbmVzIGltcG9zc2libGUgaW4gdGhlIGtub3duIHVuaXZlcnNl"));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice("true", 0);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice("false", 1);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setCorrectChoiceIndex(0);

    result.push_back(std::make_shared<tmc::UI::QVerityMultipleChoiceQuestion>(parent, tmc::Verity::r18));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setQuestionText(base64Dec("VHJ1ZS9mYWxzZSBBY3F1aXJlZCBjaGFyYWN0ZXJpc3RpY3MgYXJlIGhlcml0YWJsZQ=="));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice("true", 0);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice("false", 1);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setCorrectChoiceIndex(1);

    result.push_back(std::make_shared<tmc::UI::QVerityMultipleChoiceQuestion>(parent, tmc::Verity::r18));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setQuestionText(base64Dec("V2hhdCBpcyB0aGUgZGVyaXZhdGl2ZSBvZiBzaW4oeCk="));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice(base64Dec("LWNvcyh4KQ=="), 0);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice(base64Dec("LXNpbih4KQ=="), 1);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->addChoice(base64Dec("Y29zKHgp"));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->addChoice(base64Dec("Y3NjKHgp"));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setCorrectChoiceIndex(2);

    result.push_back(std::make_shared<tmc::UI::QVerityMultipleChoiceQuestion>(parent, tmc::Verity::r18));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setQuestionText(base64Dec("dHJ1ZS9mYWxzZSB0aGUgZGVyaXZhdGl2ZSBvZiB4XjMgaXMgM3heMg=="));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice("true", 0);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice("false", 1);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setCorrectChoiceIndex(0);

    result.push_back(std::make_shared<tmc::UI::QVerityMultipleChoiceQuestion>(parent, tmc::Verity::r18));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setQuestionText(base64Dec("TmFtZSBDdVNPNA=="));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice(base64Dec("Q29wcGVyIHN1bGZpZGU="), 0);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice(base64Dec("Q29wcGVyIChJKSBzdWxmaXRl"), 1);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->addChoice(base64Dec("Q29wcGVyIChJKSBzdWxmYXRl"));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->addChoice(base64Dec("Q29wcGVyIChJSSkgc3VsZmF0ZQ=="));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setCorrectChoiceIndex(3);

    result.push_back(std::make_shared<tmc::UI::QVerityMultipleChoiceQuestion>(parent, tmc::Verity::r18));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setQuestionText(base64Dec("d2hhdCBpcyBsaW0geCAtPiAwICgxL3gp"));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice(base64Dec("MA=="), 0);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice(base64Dec("aW5maW5pdHk="), 1);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->addChoice(base64Dec("bmVnYXRpdmUgaW5maW5pdHk="));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->addChoice(base64Dec("RG9lcyBub3QgZXhpc3Q="));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setCorrectChoiceIndex(3);

    return result;
}

std::vector<std::shared_ptr<QWizardPage>> getStandardVerityQuestionsR13(QWizard* parent)
{
    std::vector<std::shared_ptr<QWizardPage>> result(0);

    result.push_back(std::make_shared<tmc::UI::QVerityMultipleChoiceQuestion>(parent, tmc::Verity::r13));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setQuestionText("Find the x-intercept of y = (1/2)x + 6");
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice("12", 0);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice("-12", 1);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->addChoice("6");
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->addChoice("-6");
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setCorrectChoiceIndex(1);

    result.push_back(std::make_shared<tmc::UI::QVerityMultipleChoiceQuestion>(parent, tmc::Verity::r13));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setQuestionText("Find the y-intercept of y = (1/2)x + 6");
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice("12", 0);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice("-12", 1);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->addChoice("6");
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->addChoice("-6");
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setCorrectChoiceIndex(2);

    result.push_back(std::make_shared<tmc::UI::QVerityMultipleChoiceQuestion>(parent, tmc::Verity::r13));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setQuestionText("solve 2x - 7 = 3 for x");
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice("x = -2", 0);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice("x = 5", 1);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->addChoice("x = -5");
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->addChoice("x = 2");
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setCorrectChoiceIndex(1);

    result.push_back(std::make_shared<tmc::UI::QVerityMultipleChoiceQuestion>(parent, tmc::Verity::r13));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setQuestionText("Which of the following is NOT a function:");
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice("y = 3", 0);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice("x = 3", 1);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->addChoice("y = 3x");
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->addChoice("y = 3x - 4");
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setCorrectChoiceIndex(1);

    result.push_back(std::make_shared<tmc::UI::QVerityMultipleChoiceQuestion>(parent, tmc::Verity::r13));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setQuestionText("Given a right triangle with a hypotenuse of 13 and a leg of 5, find the other leg");
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice("9", 0);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice("10", 1);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->addChoice("11");
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->addChoice("12");
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setCorrectChoiceIndex(3);

    result.push_back(std::make_shared<tmc::UI::QVerityMultipleChoiceQuestion>(parent, tmc::Verity::r13));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setQuestionText("Given a right triangle with an acute angle of 30 degrees, find the other acute angle");
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice("45 degrees", 0);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice("30 degrees", 1);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->addChoice("60 degrees");
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->addChoice("90 degrees");
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setCorrectChoiceIndex(2);

    result.push_back(std::make_shared<tmc::UI::QVerityMultipleChoiceQuestion>(parent, tmc::Verity::r13));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setQuestionText("Given a right triangle with legs of 3 and 4, find the hypotenuse");
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice("5", 0);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice("6", 1);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->addChoice("7");
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setCorrectChoiceIndex(0);

    result.push_back(std::make_shared<tmc::UI::QVerityMultipleChoiceQuestion>(parent, tmc::Verity::r13));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setQuestionText("True/false If a triangle has acute angles that are both 45 degrees, it is both an isosceles triangle and a right triangle");
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice("True", 0);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice("False", 1);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setCorrectChoiceIndex(0);

    result.push_back(std::make_shared<tmc::UI::QVerityMatchingQuestion>(parent, tmc::Verity::r13));
    std::dynamic_pointer_cast<tmc::UI::QVerityMatchingQuestion>(result.back())->setQuestionText("Match the term with the definition");
    std::dynamic_pointer_cast<tmc::UI::QVerityMatchingQuestion>(result.back())->setMatch("Angles of equal measure",
                                                                                         "Congruent Angles", "A", 0);
    std::dynamic_pointer_cast<tmc::UI::QVerityMatchingQuestion>(result.back())->setMatch("Angles that add up to 90 degrees",
                                                                                         "Complementary Angles", "B", 1);
    std::dynamic_pointer_cast<tmc::UI::QVerityMatchingQuestion>(result.back())->addMatch("Angles that add up to 180 degrees",
                                                                                         "Supplementary Angles", "C");

    result.push_back(std::make_shared<tmc::UI::QVerityMultipleChoiceQuestion>(parent, tmc::Verity::r13));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setQuestionText("solve (5/2) = (x/4) for x");
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice("x = 10", 0);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice("x = 5", 1);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->addChoice("x = 2");
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->addChoice("x = 20");
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setCorrectChoiceIndex(0);

    result.push_back(std::make_shared<tmc::UI::QVerityMultipleChoiceQuestion>(parent, tmc::Verity::r13));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setQuestionText("Multiply (x - 3)(x - 4)");
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice("x^2 - 12", 0);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice("x^2 - 7x + 12", 1);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->addChoice("x^2 + 12");
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->addChoice("x^2 + 7x - 12");
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setCorrectChoiceIndex(1);

    result.push_back(std::make_shared<tmc::UI::QVerityMultipleChoiceQuestion>(parent, tmc::Verity::r13));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setQuestionText("Rewrite the function y - 3 = 2(x - 1) in slope-intercept form");
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice("y = 2x + 2", 0);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice("y = 2x - 1", 1);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->addChoice("y = 2x + 1");
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->addChoice("y = 2x - 2");
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setCorrectChoiceIndex(2);

    result.push_back(std::make_shared<tmc::UI::QVerityMultipleChoiceQuestion>(parent, tmc::Verity::r13));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setQuestionText("True/false compounds have a completely different set of properties from the elements that make them up");
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice("True", 0);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice("False", 1);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setCorrectChoiceIndex(0);

    result.push_back(std::make_shared<tmc::UI::QVerityMatchingQuestion>(parent, tmc::Verity::r13));
    std::dynamic_pointer_cast<tmc::UI::QVerityMatchingQuestion>(result.back())->setQuestionText("Match the term with the definition");
    std::dynamic_pointer_cast<tmc::UI::QVerityMatchingQuestion>(result.back())->setMatch("A substance you can have a single atom of found on the periodic table",
                                                                                         "Element", "A", 0);
    std::dynamic_pointer_cast<tmc::UI::QVerityMatchingQuestion>(result.back())->setMatch("A combination of elements formed by chemical reactions",
                                                                                         "Compound", "B", 1);
    std::dynamic_pointer_cast<tmc::UI::QVerityMatchingQuestion>(result.back())->addMatch("A mix of elements or compounds that aren't chemically combined",
                                                                                         "Mixture", "C");

    result.push_back(std::make_shared<tmc::UI::QVerityMatchingQuestion>(parent, tmc::Verity::r13));
    std::dynamic_pointer_cast<tmc::UI::QVerityMatchingQuestion>(result.back())->setQuestionText("Match the element with the type of substance");
    std::dynamic_pointer_cast<tmc::UI::QVerityMatchingQuestion>(result.back())->setMatch("Sodium",
                                                                                         "Metal", "A", 0);
    std::dynamic_pointer_cast<tmc::UI::QVerityMatchingQuestion>(result.back())->setMatch("Silicon",
                                                                                         "Metalloid", "B", 1);
    std::dynamic_pointer_cast<tmc::UI::QVerityMatchingQuestion>(result.back())->addMatch("Helium",
                                                                                         "Nonmetal", "C");

    result.push_back(std::make_shared<tmc::UI::QVerityMultipleChoiceQuestion>(parent, tmc::Verity::r13));
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setQuestionText("What is the term for an element that is unreactive due to having a full outer shell?");
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice("Happy Gas", 0);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setChoice("Halogen", 1);
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->addChoice("Metalloid");
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->addChoice("Noble Gas");
    std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(result.back())->setCorrectChoiceIndex(3);

    return result;
}
