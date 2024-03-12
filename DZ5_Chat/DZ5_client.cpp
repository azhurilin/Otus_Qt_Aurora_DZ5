#include "DZ5_client.h"
#include <QDataStream>
#include <QAbstractSocket>

//=====================*******=====================
client::client(QWidget *parent)
{
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::readyRead, this, &client::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);

    //connectToServer("127.0.0.1", 1234);

}

//=====================*******=====================
//=====================*******=====================
void client::slotReadyRead()
{
   socket = (QTcpSocket *)sender();
   QDataStream   in(socket);
   in.setVersion(QDataStream::Qt_5_12);

  if(in.status() == QDataStream::Ok)
    {
      qDebug()  << "read data";
      QString str;
      in >> str;
      qDebug()  << str;

      emit ReadyRead(str);

    }
  else
    {
      qDebug()  << "DataStream error";
    }




}
//=====================*******=====================
void client::sendToServer(QString str)
{
   Data.clear();
   QDataStream out(&Data, QIODevice::WriteOnly);
   out.setVersion(QDataStream::Qt_5_12);

   out << str;

   socket->write(Data);


}
//=====================*******=====================
void client::connectToServer(QString host, int port)
{

   if(socket->state() == QAbstractSocket::ConnectedState)
     {
       sendToServer("Disconnect");
       socket->disconnect();
     }

    socket->connectToHost(host, port);
    sendToServer("Hello server " + host);

}
//=====================*******=====================

