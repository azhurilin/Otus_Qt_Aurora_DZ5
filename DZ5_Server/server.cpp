#include <server.h>
#include <QDebug>
#include <QDataStream>
#include <QIODevice>
//=====================*******=====================
Server::Server()
{
  if (this->listen(QHostAddress::Any, 1234))
  {
    qDebug() << "server start";
  }
  else
  {
    qDebug() << "server error";
  }

}
//=====================*******=====================
void Server::incomingConnection(qintptr SDescriptor)
{
    socket = new QTcpSocket;
    socket->setSocketDescriptor(SDescriptor);

    connect(socket, &QTcpSocket::readyRead, this, &Server::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);

    Sockets.push_back(socket);

    qDebug() << "new connection" << SDescriptor;

}
//=====================*******=====================
void Server::slotReadyRead()
{
   socket = (QTcpSocket *)sender();
   QDataStream   in(socket);
   in.setVersion(QDataStream::Qt_5_12);
   //in.setVersion(QDataStream::Qt_6_2);

  if(in.status() == QDataStream::Ok)
    {
      int ClientNumber = 0;
      for (int i=0;i<Sockets.size();i++)
      {
       if (Sockets[i] == socket) ClientNumber = i + 1;
     }


      qDebug()  << "read data client"  << ClientNumber;
      QString str;
      in >> str;
      qDebug()  << str;
      SendToClient(QString::number(ClientNumber) + "->" + str);
    }
  else
    {
      qDebug()  << "DataStream error";
    }

}
//=====================*******=====================
void Server::SendToClient(QString str)
{
   Data.clear();
   QDataStream out(&Data, QIODevice::WriteOnly);
   out.setVersion(QDataStream::Qt_5_12);

   out << str;


   for (int i=0;i<Sockets.size();i++)
     {
        Sockets[i]->write(Data);
     }


}
//=====================*******=====================
























