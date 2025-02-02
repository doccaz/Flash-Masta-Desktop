#include "flash_masta_app.h"

#include "common/log.h"
#include "linkmasta/libusb_device_manager.h"
#include "game/ws_game_catalog.h"
#include "game/ngp_game_catalog.h"
#include "main_window.h"
#include <iostream>

FlashMastaApp* FlashMastaApp::instance = nullptr;
const int FlashMastaApp::NO_DEVICE = -1;
const int FlashMastaApp::NO_SLOT = -1;

FlashMastaApp::FlashMastaApp(int argc, char **argv, int flags)
  : QApplication(argc, argv, flags),
    m_main_window(nullptr), m_device_manager(nullptr),
    m_ws_game_catalog(nullptr), m_ngp_game_catalog(nullptr),
    m_game_backup_enabled(false), m_game_flash_enabled(false),
    m_game_verify_enabled(false), m_save_backup_enabled(false),
    m_save_restore_enabled(false), m_save_verify_enabled(false),
    m_selected_device(NO_DEVICE), m_selected_slot(NO_SLOT)
{
  if (FlashMastaApp::instance == nullptr)
  {
    FlashMastaApp::instance = this;
  }
  
  m_device_manager = new libusb_device_manager();

try
{
  m_ws_game_catalog = new ws_game_catalog((QString("/usr/share/FlashMasta/wsgames.db")).toStdString().c_str());
  m_ngp_game_catalog = new ngp_game_catalog((QString("/usr/share/FlashMasta/ngpgames.db")).toStdString().c_str());
}
catch(const std::runtime_error& e)
{
  std::cerr << e.what() << '\n';
  std::cerr << "trying alternate location for games database..." << '\n';
  m_ws_game_catalog = new ws_game_catalog((QCoreApplication::applicationDirPath() + QString("/wsgames.db")).toStdString().c_str());
  m_ngp_game_catalog = new ngp_game_catalog((QCoreApplication::applicationDirPath() + QString("/ngpgames.db")).toStdString().c_str());
  std::cout << "games database loaded." << '\n';
}

  m_main_window = new MainWindow();
  
  qRegisterMetaType<std::string>("std::string");
  qRegisterMetaType<cartridge*>("cartridge::cartridge");
  
  connect(m_main_window, SIGNAL(destroyed(QObject*)), this, SLOT(mainWindowDestroyed(QObject*)));
  m_main_window->show();
}

FlashMastaApp::~FlashMastaApp()
{
  log_start(log_level::DEBUG, "deleting FlashMastaApp...");
  delete m_device_manager;
  delete m_ws_game_catalog;
  delete m_ngp_game_catalog;
  log_end("done");
}

device_manager* FlashMastaApp::getDeviceManager() const
{
  return m_device_manager;
}

MainWindow* FlashMastaApp::getMainWindow() const
{
  return m_main_window;
}

game_catalog* FlashMastaApp::getWonderswanGameCatalog() const
{
  return m_ws_game_catalog;
}

game_catalog* FlashMastaApp::getNeoGeoGameCatalog() const
{
  return m_ngp_game_catalog;
}

int FlashMastaApp::getSelectedDevice() const
{
  return m_selected_device;
}

int FlashMastaApp::getSelectedSlot() const
{
  return m_selected_slot;
}



// public slots:

void FlashMastaApp::setGameBackupEnabled(bool enabled)
{
  emit gameBackupEnabledChanged(enabled);
}

void FlashMastaApp::setGameFlashEnabled(bool enabled)
{
  emit gameFlashEnabledChanged(enabled);
}

void FlashMastaApp::setGameVerifyEnabled(bool enabled)
{
  emit gameVerifyEnabledChanged(enabled);
}

void FlashMastaApp::setSaveBackupEnabled(bool enabled)
{
  emit saveBackupEnabledChanged(enabled);
}

void FlashMastaApp::setSaveRestoreEnabled(bool enabled)
{
  emit saveRestoreEnabledChanged(enabled);
}

void FlashMastaApp::setSaveVerifyEnabled(bool enabled)
{
  emit saveVerifyEnabledChanged(enabled);
}

void FlashMastaApp::setSelectedDevice(int device_id)
{
  int old_id = m_selected_device;
  m_selected_device = device_id;
  emit selectedDeviceChanged(old_id, device_id);
  
  if (m_selected_device == -1)
  {
    setGameBackupEnabled(false);
    setGameFlashEnabled(false);
    setGameVerifyEnabled(false);
    setSaveBackupEnabled(false);
    setSaveRestoreEnabled(false);
    setSaveVerifyEnabled(false);
  }
}

void FlashMastaApp::setSelectedSlot(int slot_id)
{
  int old_id = m_selected_slot;
  m_selected_slot = slot_id;
  emit selectedSlotChanged(old_id, slot_id);
  
  if (m_selected_device == -1)
  {
    setGameBackupEnabled(false);
    setGameFlashEnabled(false);
    setGameVerifyEnabled(false);
    setSaveBackupEnabled(false);
    setSaveRestoreEnabled(false);
    setSaveVerifyEnabled(false);
  }
}



// private slots:

void FlashMastaApp::mainWindowDestroyed(QObject* object)
{
  if (object == m_main_window)
  {
    m_main_window = nullptr;
  }
}



FlashMastaApp* FlashMastaApp::getInstance()
{
  return FlashMastaApp::instance;
}



