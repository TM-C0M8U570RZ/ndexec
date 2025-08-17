#include "veritywizard.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <iostream>
#include <tmc_application.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::filesystem::path exefsDir = std::filesystem::path(argv[0]).parent_path().parent_path();
    std::filesystem::path romfsDir = exefsDir / "org.TMC0M8U570RZ.suyudorunner_romfs";
    tmc::Application* app = tmc::Application::getGlobalInstance(argc, argv, exefsDir, romfsDir, "org.TMC0M8U570RZ.suyudorunner");
    if (app->hasArg('h') || app->hasArg("help"))
    {
        std::cout << "Usage:" << std::endl <<
            "    ndexec [OPTIONS]" << std::endl <<
            "    ndexec -- <PROCESS_ARGV>" << std::endl <<
            "    ndexec [OPTIONS] -- <PROCESS_ARGV>" << std::endl <<
            "    ndexec" << std::endl << std::endl <<

            "Chainloading is skipped when no process argv is provided." << std::endl <<
            "Programs run afterward will still have the cache intact" << std::endl <<
            "if -o is at the default or a custom dir supported by the" << std::endl <<
            "program." << std::endl << std::endl <<

            "The default config runs `ndexec -so" << std::endl <<
            "~/.local/share/org.TMC0M8U570RZ.suyudo`" << std::endl << std::endl <<

            "-h|--help           Print this message" << std::endl << std::endl <<

            "-r|--honoo-rocket   Give the mascot a canine penis" << std::endl << std::endl <<

            "-m|--honoo-mushroom Give the mascot a human penis" << std::endl << std::endl <<

            "-s|--honoo-safe     Keep the mascot SFW" << std::endl << std::endl <<

            "-f|--soft           Keep Honoo's penis flaccid for -r" << std::endl <<
            "                    or -m (Prevent automod flagging" << std::endl <<
            "                    pornographic content)" << std::endl << std::endl <<

            "-o|--output [DIR]   Directory to save .mspcache" << std::endl <<
            "                    file (Defaults to" << std::endl <<
            "                    ~/.local/share/org.TMC0M8U570RZ.suyudo on Linux" << std::endl <<
            "                    and %APPDATA%\\org.TMC0M8U570RZ.suyudo on Windows)" << std::endl;
        return 0;
    }
    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "ndexec_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    tmc::suyudo::VerityWizard vw;
    vw.show();
    return a.exec();
}
