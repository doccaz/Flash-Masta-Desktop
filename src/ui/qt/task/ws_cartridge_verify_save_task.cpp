#include "ws_cartridge_verify_save_task.h"
#include <QFileDialog>
#include <QMessageBox>
#include <fstream>
#include "cartridge/cartridge.h"

WsCartridgeVerifySaveTask::WsCartridgeVerifySaveTask(QWidget* parent, cartridge* cart, int slot)
  : WsCartridgeTask(parent, cart, slot)
{
  // Nothing else to do
}

WsCartridgeVerifySaveTask::~WsCartridgeVerifySaveTask()
{
  // Nothing else to do
}

void WsCartridgeVerifySaveTask::run_task()
{
  // Get source file from user
  QString filename = QFileDialog::getOpenFileName(
    (QWidget*) this->parent(), tr("Open File"), QString(),
    tr("WonderSwan Color (*.wsf);;All Files (*)"));
  if (filename.isNull())
  {
    // Quietly fail
    return;
  }
  
  // Initialize inputfile
  m_fin = new std::ifstream(filename.toStdString().c_str(), std::ios::binary);
  if (!m_fin->is_open())
  {
    delete m_fin;
    QMessageBox msgBox;
    msgBox.setText("Unable to open file");
    msgBox.exec();
    return;
  }
  
  set_progress_label("Verifying cartridge");
  
  // Begin task
  try
  {
    if (m_cartridge->compare_cartridge_save_data(*m_fin, m_slot, this) && !is_task_cancelled())
    {
      QMessageBox msgBox;
      msgBox.setText("Cartridge and file match.");
      msgBox.exec();
    }
    else if(!is_task_cancelled())
    {
      QMessageBox msgBox;
      msgBox.setText("Cartridge data does not match the chosen file.");
      msgBox.exec();
    }
  }
  catch (std::exception& ex)
  {
    (void) ex;
    m_fin->close();
    delete m_fin;
    throw;
  }
  
  // Cleanup
  m_fin->close();
  delete m_fin;
}
