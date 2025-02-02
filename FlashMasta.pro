#-------------------------------------------------
#
# Project created by QtCreator 2015-07-14T10:24:19
#
#-------------------------------------------------

QT       += core gui svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FlashMasta
TEMPLATE = app

CONFIG +=\
    c++11

SOURCES +=\
    src/ui/qt/main.cpp \
    src/cartridge/ngp_cartridge.cpp \
    src/cartridge/cartridge_descriptor.cpp \
    src/cartridge/ngp_chip.cpp \
    src/linkmasta/ngp_linkmasta_device.cpp \
    src/linkmasta/ngp_linkmasta_messages.cpp \
    src/task/forwarding_task_controller.cpp \
    src/task/task_controller.cpp \
    src/usb/exception/busy_exception.cpp \
    src/usb/exception/disconnected_exception.cpp \
    src/usb/exception/exception.cpp \
    src/usb/exception/interrupted_exception.cpp \
    src/usb/exception/not_found_exception.cpp \
    src/usb/exception/timeout_exception.cpp \
    src/usb/exception/unconfigured_exception.cpp \
    src/usb/exception/uninitialized_exception.cpp \
    src/usb/exception/unopen_exception.cpp \
    src/usb/libusb_usb_device.cpp \
    src/usb/usb_device.cpp \
    src/ui/qt/main_window.cpp \
    src/linkmasta/ws_linkmasta_device.cpp \
    src/linkmasta/ws_linkmasta_messages.cpp \
    src/cartridge/ws_cartridge.cpp \
    src/cartridge/ws_rom_chip.cpp \
    src/cartridge/ws_sram_chip.cpp \
    src/linkmasta/linkmasta_device.cpp \
    src/ui/qt/task/ngp_cartridge_backup_save_task.cpp \
    src/ui/qt/task/ngp_cartridge_backup_task.cpp \
    src/ui/qt/task/ngp_cartridge_flash_task.cpp \
    src/ui/qt/task/ngp_cartridge_restore_save_task.cpp \
    src/ui/qt/task/ngp_cartridge_task.cpp \
    src/ui/qt/task/ngp_cartridge_verify_task.cpp \
    src/ui/qt/task/ws_cartridge_backup_save_task.cpp \
    src/ui/qt/task/ws_cartridge_backup_task.cpp \
    src/ui/qt/task/ws_cartridge_flash_task.cpp \
    src/ui/qt/task/ws_cartridge_restore_save_task.cpp \
    src/ui/qt/task/ws_cartridge_task.cpp \
    src/ui/qt/task/ws_cartridge_verify_task.cpp \
    src/linkmasta/device_manager.cpp \
    src/linkmasta/libusb_device_manager.cpp \
    src/ui/qt/detail/fm_cartridge_slot_widget.cpp \
    src/ui/qt/flash_masta_app.cpp \
    src/ui/qt/detail/cartridge_widget.cpp \
    src/ui/qt/worker/lm_cartridge_fetching_worker.cpp \
    src/ui/qt/worker/lm_cartridge_polling_worker.cpp \
    src/ui/qt/detail/lm_detail_widget.cpp \
    src/ui/qt/detail/cartridge_info_widget.cpp \
    src/game/game_descriptor.cpp \
    src/sqlite/sqlite3.c \
    src/game/ws_game_catalog.cpp \
    src/game/ngp_game_catalog.cpp \
    src/ui/qt/task/ngp_cartridge_verify_save_task.cpp \
    src/ui/qt/task/ws_cartridge_verify_save_task.cpp \
    src/common/log.cpp

HEADERS  +=\
    src/cartridge/cartridge.h \
    src/cartridge/ngp_cartridge.h \
    src/common/types.h \
    src/cartridge/cartridge_descriptor.h \
    src/cartridge/ngp_chip.h \
    src/linkmasta/linkmasta_device.h \
    src/linkmasta/ngp_linkmasta_device.h \
    src/linkmasta/ngp_linkmasta_messages.h \
    src/task/forwarding_task_controller.h \
    src/task/task_controller.h \
    src/usb/exception/busy_exception.h \
    src/usb/exception/disconnected_exception.h \
    src/usb/exception/exception.h \
    src/usb/exception/interrupted_exception.h \
    src/usb/exception/not_found_exception.h \
    src/usb/exception/timeout_exception.h \
    src/usb/exception/unconfigured_exception.h \
    src/usb/exception/uninitialized_exception.h \
    src/usb/exception/unopen_exception.h \
    src/usb/libusb_usb_device.h \
    src/usb/usb.h \
    src/usb/usb_device.h \
    src/usb/usbfwd.h \
    src/ui/qt/main_window.h \
    src/linkmasta/ws_linkmasta_device.h \
    src/linkmasta/ws_linkmasta_messages.h \
    src/cartridge/ws_cartridge.h \
    src/cartridge/ws_rom_chip.h \
    src/cartridge/ws_sram_chip.h \
    src/ui/qt/task/ngp_cartridge_backup_save_task.h \
    src/ui/qt/task/ngp_cartridge_backup_task.h \
    src/ui/qt/task/ngp_cartridge_flash_task.h \
    src/ui/qt/task/ngp_cartridge_restore_save_task.h \
    src/ui/qt/task/ngp_cartridge_task.h \
    src/ui/qt/task/ngp_cartridge_verify_task.h \
    src/ui/qt/task/ws_cartridge_backup_save_task.h \
    src/ui/qt/task/ws_cartridge_backup_task.h \
    src/ui/qt/task/ws_cartridge_flash_task.h \
    src/ui/qt/task/ws_cartridge_restore_save_task.h \
    src/ui/qt/task/ws_cartridge_task.h \
    src/ui/qt/task/ws_cartridge_verify_task.h \
    src/linkmasta/device_manager.h \
    src/linkmasta/libusb_device_manager.h \
    src/ui/qt/detail/fm_cartridge_slot_widget.h \
    src/ui/qt/flash_masta_app.h \
    src/ui/qt/detail/cartridge_widget.h \
    src/ui/qt/worker/lm_cartridge_fetching_worker.h \
    src/ui/qt/worker/lm_cartridge_polling_worker.h \
    src/ui/qt/detail/lm_detail_widget.h \
    src/ui/qt/detail/cartridge_info_widget.h \
    src/game/game_catalog.h \
    src/game/game_descriptor.h \
    src/sqlite/sqlite3.h \
    src/sqlite/sqlite3ext.h \
    src/game/ws_game_catalog.h \
    src/game/ngp_game_catalog.h \
    src/ui/qt/task/ngp_cartridge_verify_save_task.h \
    src/ui/qt/task/ws_cartridge_verify_save_task.h \
    src/common/log.h

FORMS    +=\
    src/ui/qt/main_window.ui \
    src/ui/qt/detail/fm_cartridge_slot_widget.ui \
    src/ui/qt/detail/lm_detail_widget.ui \
    src/ui/qt/detail/cartridge_info_widget.ui \
    src/ui/qt/detail/cartridge_widget.ui

DISTFILES += \
    README.md

INCLUDEPATH +=\
    src \
    src/common

macx {
    INCLUDEPATH +=\
        includes/osx
    
    QMAKE_MAC_SDK = macosx10.11
    
    QMAKE_LFLAGS +=\
        -L"$$PWD/libs/osx"\
        -lobjc

    LIBS     +=\
        -framework IOKit \
        -framework CoreFoundation \
        "$$PWD/libs/osx/libusb-1.0.a"
    
    QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.10
    
    DEFINES  +=\
        OS_MACOSX

    APP_QML_FILES.files = $$PWD/resources.qrc
    APP_QML_FILES.path = Contents/Resources
    QMAKE_BUNDLE_DATA += APP_QML_FILES
}
win32 {
    INCLUDEPATH +=\
        includes/win

    CONFIG(64bit) {
        LIBS += -L"$$PWD/libs/win64" -l"libusb-1.0"
    }
    CONFIG(32bit) {
        LIBS += -L"$$PWD/libs/win32" -l"libusb-1.0"
    }
	
    DEFINES  +=\
        OS_WINDOWS
}
unix {
    LIBS += -ldl -lusb-1.0
}

RESOURCES += \
    resources.qrc
