#ifndef __WS_CARTRIDGE_VERIFY_SAVE_TASK_H__
#define __WS_CARTRIDGE_VERIFY_SAVE_TASK_H__

#include "ws_cartridge_task.h"
#include <iosfwd>

class WsCartridgeVerifySaveTask : public WsCartridgeTask
{
public:
  explicit WsCartridgeVerifySaveTask(QWidget* parent, cartridge* cart, int slot = -1);
  ~WsCartridgeVerifySaveTask();
  
protected:
  void run_task();
  
private:
  std::ifstream* m_fin;
};

#endif // __WS_CARTRIDGE_VERIFY_SAVE_TASK_H__
