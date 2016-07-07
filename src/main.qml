import QtQuick 2.5
import QtQuick.Window 2.2

Window{
    id: mainWindow
    height: Screen.height/2
    width: Screen.width/3
    x: Screen.width/3
    y:Screen.height/4
    visible: true
    
    Rectangle{
        id: root
        color: "grey"
        height: mainWindow.height
        width: mainWindow.width
        anchors.fill: mainWindow
        focus: true
        
        Text{
            id: scoreText
            text: "Score : "
            font.pixelSize: root.height/15
        }
        
        Grid {
                rows: 4
                columns: 4
                spacing: 4
                anchors.verticalCenter: root.verticalCenter
                anchors.horizontalCenter: root.horizontalCenter

                Repeater {
                    id: boardRepeater
                    model: 16
                    delegate: Square {
                        squareWidth: root.width/5
                        squareHeight: root.height/5
                        currentValue: 8
                    }
                }
            }
    
    }
    
}
