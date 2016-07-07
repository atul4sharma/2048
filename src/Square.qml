import QtQuick 2.4

Rectangle{
    id: square
    property int squareHeight
    property int squareWidth
    property int currentValue
    
    height: squareHeight
    width: squareWidth
    visible: true
    color: "orange"
    radius: 7
    
    Text{
        anchors.centerIn:square
        text: currentValue
        font.pointSize: squareHeight/3
        
    }
    
}
