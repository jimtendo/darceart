import QtQuick 2.0

Rectangle {
    id: root
    color: "black"

    function addEffect(layerNumber, code) {
        var component = Qt.createComponent("qrc:///QML/Effect.qml");
        if (component.status === Component.Ready)
            component.createObject(root, {"id": "layer1"});
        else
            console.log("component not created")
    }

    function addVideo(layerNumber, filename) {
        var component = Qt.createComponent("qrc:///QML/Video.qml");
        if (component.status === Component.Ready) {
            component.createObject(root, {"id": "layer1", "mediaSource": filename});
        }

        else
            console.log("component not created")
    }

    function removeLayer(layerName) {
        layerName.destroy();
    }
}


