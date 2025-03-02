import QtQuick
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Basic Multilingual App") // We choose the app title to be language indifferent

    Component.onCompleted: Qt.uiLanguage = "en" // Set the UI language to English (so that we all start in the same place)

    Column {
        anchors.centerIn: parent
        spacing: 10

        Text {
            id: stringToTranslate
            //: Example string to translate
            text: qsTr("This string must be translated on button click")
        }

        Button {
            id: translateText
            //: Clicking this button translates the text fields
            text: qsTr("Translate text")
            onClicked: {
                Qt.uiLanguage = Qt.uiLanguage === "en" ? "de" : "en" // If UI is English translate to German. Else translate to English
                console.log(Qt.uiLanguage) // Print the UI language to console so we can monitor its changes
                translateHelper.setLanguage(Qt.uiLanguage);
            }
        }
    }
}
