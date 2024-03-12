#ifndef DZ5_CLIENT_H
#define DZ5_CLIENT_H

#include <QTcpServer>
#include "QTcpSocket"


class client : public QObject
{
    Q_OBJECT

public:
     client(QWidget *parent = nullptr);
  //  ~client();

private:


    QTcpSocket * socket;
    QByteArray Data;


signals:
    void ReadyRead(QString str);



public slots :

   void slotReadyRead();
   void sendToServer(QString str);
   void connectToServer(QString host, int port);

};



#endif // DZ5_CLIENT_H
