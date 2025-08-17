cmake_minimum_required(VERSION 3.19)
project(ndexec LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets LinguistTools)

qt_standard_project_setup()

qt_add_executable(ndexec
    WIN32 MACOSX_BUNDLE
    main.cpp



    tegami.h tegami.cpp tegami.ui
    qveritymatchingquestion.h qveritymatchingquestion.cpp qveritymatchingquestion.ui
    questioninterface.h questioninterface.cpp
    suyudorunnertypes.h
    veritywizard.h veritywizard.cpp veritywizard.ui
    debugview.h debugview.cpp debugview.ui
    qveritymultiplechoicequestion.h qveritymultiplechoicequestion.cpp qveritymultiplechoicequestion.ui
    suyudorunnerstandard.h
    suyudorunnerstandard.cpp
    qcachepasswordpage.h qcachepasswordpage.cpp qcachepasswordpage.ui
    r13veritypasspage.h r13veritypasspage.cpp r13veritypasspage.ui
    r13verityfailpage.h r13verityfailpage.cpp r13verityfailpage.ui
    r18veritypasspage.h r18veritypasspage.cpp r18veritypasspage.ui
    r18verityfailpage.h r18verityfailpage.cpp r18verityfailpage.ui
    suyudorunnerhelpers.h
    suyudorunnerhelpers.cpp

)

qt_add_translations(
    TARGETS ndexec
    TS_FILES ndexec_en_US.ts
)

target_include_directories(ndexec
    PUBLIC
        $ENV{TMC_SDK_PATH}/current/helpers/include
        $ENV{TMC_SDK_PATH}/current/src/third-party/tiny-AES-c
        $ENV{TMC_SDK_PATH}/current/libTmcNdbTagging/include
        $ENV{TMC_SDK_PATH}/current/libTmcMesprit/include
        $ENV{TMC_SDK_PATH}/current/include
)

target_link_directories(ndexec
    PUBLIC
        $ENV{TMC_SDK_PATH}/current/lib/${CMAKE_SYSTEM_PROCESSOR}
        $ENV{TMC_SDK_PATH}/current/lib/${CMAKE_SYSTEM_PROCESSOR}/third-party)

target_link_libraries(ndexec
    PRIVATE
        Qt::Core
        Qt::Widgets
)

target_link_libraries(ndexec
    PUBLIC
        -laes
        -lTmcMesprit
        -lTmcHelpers
        -lTmcNdbTagging
        -lTmcSdkCore
)

include(GNUInstallDirs)

install(TARGETS ndexec
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET ndexec
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
