#ifndef __FLASH_MASTA_APP_H__
#define __FLASH_MASTA_APP_H__

#include <QApplication>
#include <QMetaType>

class device_manager;
class MainWindow;
class game_catalog;

class FlashMastaApp: public QApplication
{
  Q_OBJECT
public:
  FlashMastaApp(int argc, char** argv, int flags = ApplicationFlags);
  ~FlashMastaApp();
  
  device_manager* getDeviceManager() const;
  MainWindow* getMainWindow() const;
  game_catalog* getWonderswanGameCatalog() const;
  game_catalog* getNeoGeoGameCatalog() const;
  int getSelectedDevice() const;
  int getSelectedSlot() const;
  
public slots:
  void setGameBackupEnabled(bool enabled);
  void setGameFlashEnabled(bool enabled);
  void setGameVerifyEnabled(bool enabled);
  void setSaveBackupEnabled(bool enabled);
  void setSaveRestoreEnabled(bool enabled);
  void setSaveVerifyEnabled(bool enabled);
  void setSelectedDevice(int device_id);
  void setSelectedSlot(int slot_id);
  
private slots:
  void mainWindowDestroyed(QObject*);
  
signals:
  void gameBackupEnabledChanged(bool);
  void gameFlashEnabledChanged(bool);
  void gameVerifyEnabledChanged(bool);
  void saveBackupEnabledChanged(bool);
  void saveRestoreEnabledChanged(bool);
  void saveVerifyEnabledChanged(bool);
  void selectedDeviceChanged(int, int);
  void selectedSlotChanged(int, int);
  
public:
  static FlashMastaApp* getInstance();
  
private:
  Q_DISABLE_COPY(FlashMastaApp)
  
  MainWindow* m_main_window;
  device_manager* m_device_manager;
  game_catalog* m_ws_game_catalog;
  game_catalog* m_ngp_game_catalog;
  bool m_game_backup_enabled;
  bool m_game_flash_enabled;
  bool m_game_verify_enabled;
  bool m_save_backup_enabled;
  bool m_save_restore_enabled;
  bool m_save_verify_enabled;
  int m_selected_device;
  int m_selected_slot;
  
  static FlashMastaApp* instance;
  static const int NO_DEVICE;
  static const int NO_SLOT;
};

#endif // __FLASH_MASTA_APP_H__
