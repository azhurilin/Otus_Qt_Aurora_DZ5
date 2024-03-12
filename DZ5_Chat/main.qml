import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Styles 1.4
import QtQuick.Dialogs 1.2


Window {
    id: root

    width: 480
    height: 640
    visible: true
    title: qsTr("OtusQtChat")
    color: "linen"


//=====================*******=====================
    function  onReadyRead(str)
    {
      textEdit.append(str)
    }


    Component.onCompleted:
    {
     textEdit.append("start");

     ReadyRead.connect(onReadyRead);


    }


//=====================*******=====================

        Rectangle {
         id: hostInput
          width: parent.width*0.2
          height: parent.height * 0.1
          color: "grey"
          anchors.left: parent.left
          anchors.top:  parent.top

          TextInput {
           id: host
           anchors.centerIn: parent
           text: "127.0.0.1"
           font.family: "Ubuntu"
           font.pixelSize: 20
          }
         }

//=====================*******=====================

        Rectangle {
         id: hostText
          width: parent.width*0.2
          height: parent.height * 0.1
          color: root.color
          anchors.left:    hostInput.right
          anchors.top:     parent.top

          Text {
            //color: "white"
            text: "host"
           anchors.centerIn: parent

            font.family: "Ubuntu"
            font.pixelSize: 28
          }
        }

//=====================*******=====================

       Rectangle {
         id: portInput
          width: parent.width*0.2
          height: parent.height * 0.1
          color: "grey"
          anchors.left: hostText.right
          anchors.top:  parent.top

          TextInput {
           id: port
           anchors.centerIn: parent
           text: "1234"
           font.family: "Ubuntu"
           font.pixelSize: 20
          }
         }

//=====================*******=====================

        Rectangle {
         id: portText
          width: parent.width*0.2
          height: parent.height * 0.1
          color: root.color
          anchors.left:    portInput.right
          anchors.top:     parent.top

          Text {
            //color: "white"
            text: "port"
           anchors.centerIn: parent

            font.family: "Ubuntu"
            font.pixelSize: 28
          }
        }

//=====================*******=====================

        Rectangle {
         id:connectBtn
          width: parent.width*0.2
          height: parent.height * 0.1
          color: "blue"
          border.color: "black"
          border.width: 4


          anchors.top: parent.top
          anchors.right: parent.right


          Text {
              id: textConnect
              text: qsTr("connect")
              anchors.centerIn: parent
              font.pixelSize: 20

          }


           MouseArea {
             anchors.fill: parent
             onClicked: {

                connectToServer(host.text, parseInt(port.text))

             }
            }

         }

//=====================*******==========================================*******=====================

        Rectangle {
         id:sendBtn
          width: parent.width*0.2
          height: parent.height * 0.1
          color: "green"
          border.color: "black"
          border.width: 4

          anchors.top: connectBtn.bottom
          anchors.right: parent.right




          Text {
              id: textSend
              text: qsTr("send")
              anchors.centerIn: parent
              font.pixelSize: 20

          }


           MouseArea {
             anchors.fill: parent
             onClicked: {

               sendToServer(sendMessage.text);
              // sendMessage.text=""


             }
            }

         }

//=====================*******=====================
      Rectangle {
         id: messgeInput
          width: parent.width*0.8
          height: parent.height * 0.1
          color: "lightgrey"
          anchors.right:  sendBtn.left
          anchors.top:  sendBtn.top

          TextInput {
           id:sendMessage
           anchors.centerIn: parent
           text: "message"
           font.family: "Ubuntu"
           font.pixelSize: 20
          }
         }

//=====================*******==========================================*******=====================

          TextEdit {
            id:  textEdit
            anchors.left:   parent.left
            anchors.right:  parent.right
            anchors.bottom: parent.bottom
            anchors.top:    messgeInput.bottom

            color: "lightsteelblue"


            text: ""
            font.family: "Ubuntu"
            font.pixelSize: 20
          }








//=====================*******=====================




}
