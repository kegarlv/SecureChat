#ifndef DIALOG_CONTROLLER
#define DIALOG_CONTROLLER

#include <QObject>

#include "UserController.h"
#include "src/structs/Dialog.h"
#include "src/utils/cipherhelper.h"
#include "src/utils/messageworker.h"
#include "src/utils/request.h"

#include "src/utils/Firebase.h"

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

    Q_INVOKABLE MessageList *getMessageList();
    Q_INVOKABLE void sendMessage(const QString &messageText);

  public slots:
    void newEvent(FirebaseEvent e);

  private:
    Dialog *m_dialog = nullptr;
    QThread *m_workerThread = nullptr;
    Firebase *fb;
};

#endif //DIALOG_CONTROLLER
