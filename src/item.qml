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
    
    }
    
}
