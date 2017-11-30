#include <QObject>
#include <QString>

#include "src/utils/request.h"

class FirebaseEvent {
  public:
    QString type;
    QString data;
};

class Firebase : public QObject {
    Q_OBJECT

  public:
    Firebase(QString firebaseUrl);

    QString getValue(QString endpoint);

    void setValue(QString endpoint, QString data) {
    }

    void listenForEvents();

  signals:
    void newEvent(FirebaseEvent e);

  public slots:
    void newEventCaptured();

  private:
    QString m_firebaseUrl;
};
