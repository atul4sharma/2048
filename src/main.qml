import QtQuick 2.4
import QtQuick.Window 2.0

Window  {
    id : mainWindow
    height : 360
    width : 360
    visible : true
    
    Rectangle   {
        id : board
        color : "lightblue"
        anchors.fill : parent
        
        focus : true
        
        Text {
            text : "Score : "
            font { pixelSize : 20;  family : "oxygon-sans" }
            anchors {top : parent.top;  topMargin : 5 }
        }
        
    }

}
