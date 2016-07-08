import QtQuick 2.4

Rectangle{
    id: square
    property int currentValue
    visible: true
    border.color:"gray"
    border.width: 4

    function decideColor(value)
    {
        switch(value)
        {
        case 0:return "#cdc1b4"
        case 2:return "#eee4da"
        case 4:return "#ede0c8"
        case 8:return "#f2b179"
        case 16:return "#f59563"
        case 32:return "#f67c5f"
        case 64:return "#f65e3b"
        case 128:return "#edcf72"
        case 256:return "#edcc61"
        case 512:return "#edc850"
        case 1024:return "#edc841"
        case 2048:return "orange"
        }
    }

    color:decideColor(currentValue)

    Text{
        anchors.centerIn:square
        text: qsTr(currentValue === 0?"":currentValue.toString());
        color: currentValue < 16?"black":"white"
        font.pixelSize: parent.height/2.5
    }

}
