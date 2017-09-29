#ifndef DIALOG_CONTROLLER
#define DIALOG_CONTROLLER

#include <QObject>

#include "UserController.h"
#include "src/structs/Dialog.h"
#include "src/utils/cipherhelper.h"
#include "src/utils/messageworker.h"
#include "src/utils/request.h"

class DialogController : public QObject {
    Q_OBJECT
    Q_PROPERTY(int dialogID READ getDialogID WRITE setDialogID)
  public:
    explicit DialogController(int dialogId);
    DialogController();
    ~DialogController() override;

    int getDialogID();
    void setDialogID(int dialogID);

    Q_INVOKABLE void startUpdating();
    void stopUpdating();

    Q_INVOKABLE MessageList *getMessageList();
    Q_INVOKABLE void sendMessage(const QString &messageText);

  public slots:
    void updateFinished();

  private:
    Dialog *m_dialog = nullptr;
    QThread *m_workerThread = nullptr;
    MessageWorker *m_messageWorker = nullptr;
};

#endif //DIALOG_CONTROLLER
