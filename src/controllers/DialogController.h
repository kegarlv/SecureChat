#ifndef DIALOG_CONTROLLER
#define DIALOG_CONTROLLER

#include <QObject>

#include "src/structs/Dialog.h"
#include "src/utils/messageworker.h"
#include "src/utils/request.h"
#include "src/utils/cipherhelper.h"

class DialogController : public QObject {
    Q_OBJECT
  public:
    DialogController(int dialogId);
    DialogController();
    ~DialogController();

   Q_INVOKABLE void startUpdating();
    void stopUpdating();

    Q_INVOKABLE MessageList *getMessageList();
    void sendMessage(const Message &msg);

public slots:
    void updateFinished();


  private:
    Dialog *m_dialog = nullptr;
    QThread *m_workerThread = nullptr;
    MessageWorker *m_messageWorker = nullptr;
};

#endif //DIALOG_CONTROLLER
