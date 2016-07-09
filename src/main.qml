import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1

ApplicationWindow{
    id:window
    visible: true
    title: "2048"
    height: 355
    width:  355
    minimumHeight: 355
    minimumWidth: 355
    
    toolBar: ToolBar{
        Text {
            id: text
            color: "black"
            text: qsTr("Score : "+game.score)
            font{
                pixelSize:window.height/10
            }
        }
    }

    TableView{
        id:tableView
        visible:true
        anchors.fill: parent
        headerVisible: false
        focus : !(game.gameOver)

        Keys.onUpPressed: game.moveUp()
        Keys.onDownPressed: game.moveDown()
        Keys.onLeftPressed: game.moveLeft()
        Keys.onRightPressed: game.moveRight()

        Layout.preferredHeight: window.height - window.height/10
        Layout.preferredWidth: window.width

        TableViewColumn{
            role:"firstColumn"
            resizable: false
            movable: false
            width:tableView.width/4 - 1
            delegate:Square{
                currentValue: styleData.value
                anchors.fill: parent
            }
        }
        
        TableViewColumn{
            role:"secondColumn"
            resizable: false
            movable: false
            width:tableView.width/4 - 1
            delegate:Square{
                currentValue: styleData.value
                anchors.fill: parent
            }
        }
        
        TableViewColumn{
            role:"thirdColumn"
            resizable: false
            movable: false
            width:tableView.width/4 -1
            delegate:Square{
                currentValue: styleData.value
                anchors.fill: parent
            }
        }
        
        TableViewColumn{
            role:"fourthColumn"
            resizable: false
            movable: false
            width:tableView.width/4 - 1
            delegate: Square{
                currentValue: styleData.value
                anchors.fill: parent
            }
        }

        rowDelegate:Rectangle{
            height: tableView.height/4 - 1
            color:"#232629"
        }
        model:game
    }
    
    Rectangle{
        visible:game.gameOver
        width: window.width
        height: window.height
        color: "white"
        opacity: 0.7
        Text{
            y:parent.height/4
            x:y/4
            text:qsTr("Game Over ")
            font.pixelSize:parent.height/6
        }
        focus:game.gameOver
        MouseArea{
            anchors.fill:parent
            onClicked:{game.basicDeletion() }
        }
    }
}
