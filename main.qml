import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.VirtualKeyboard 2.4
import QtQuick.Layouts 1.12
import QtQuick.Controls 1.4
import QtQuick.Controls 2.12
import QtQuick.Controls.Imagine 2.12


ApplicationWindow {
    id: window
    width: 1280
    height: 720
    minimumWidth: 1180
    minimumHeight: 663
    visible: true
    title: qsTr("EtherCAT")

    readonly property color colorGlow: "#1d6d64"
    readonly property color colorWarning: "#d5232f"
    readonly property color colorMain: "#6affcd"
    readonly property color colorBright: "#ffffff"
    readonly property color colorLightGrey: "#888"
    readonly property color colorDarkGrey: "#333"

    readonly property int fontSizeExtraSmall: Qt.application.font.pixelSize * 0.8
    readonly property int fontSizeMedium: Qt.application.font.pixelSize * 1.5
    readonly property int fontSizeLarge: Qt.application.font.pixelSize * 2
    readonly property int fontSizeExtraLarge: Qt.application.font.pixelSize * 5

    Component.onCompleted: {
        x = Screen.width / 2 - width / 2
        y = Screen.height / 2 - height / 2
    }

    menuBar: MenuBar {
        Menu {
            title:qsTr("File")
            width: 60
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }



    Frame{
        id: frame
        width: 1180
        height: 540
        anchors.fill: parent
        anchors.margins: 50

        RowLayout{
            id: mainRowLayout
            anchors.fill: parent
            anchors.margins: 24
            spacing: 36

            Container{
                id: leftTabBar

                currentIndex: 1

                Layout.fillWidth: false
                Layout.fillHeight: true

                ButtonGroup {
                    buttons: columnLayout.children
                }

                contentItem: ColumnLayout {
                    id: columnLayout
                    spacing: 3

                    Repeater {
                        model: leftTabBar.contentModel
                    }
                }
                FeatureButton{
                    id:clear_error_button
                    text: qsTr("Celar Error")
                    icon.name: qsTr("clear")
                    Layout.fillHeight: true
                }

                FeatureButton{
                    id:start_button
                    text: qsTr("Start")
                    icon.name:("start")
                    Layout.fillHeight: true
                }
                FeatureButton{
                    id:pause_button
                    text: qsTr("Pause")
                    icon.name: qsTr("pause")
                    Layout.fillHeight: true
                }
                FeatureButton{
                    id:stop_button
                    text: qsTr("Stop")
                    icon.name: qsTr("stop")
                    Layout.fillHeight: true
                }
            }
            StackLayout{
                currentIndex: leftTabBar.currentIndex

                Layout.preferredWidth: 150
                Layout.maximumWidth: 150
                Layout.fillWidth: false

                Item {

                }

                ColumnLayout{

                    spacing: 16
                    ButtonGroup{
                        id:viewButtonGroup
                        buttons: viewTypeRowLayout.children
                    }
                    RowLayout{
                        id:viewTypeRowLayout
                        spacing: 3

                        Layout.bottomMargin: 12

                        Button{
                            id:save_parameter_button
                            text: qsTr("Save")
                            font.pixelSize: fontSizeMedium
                            Layout.fillWidth: true
                        }
                        Button{
                            id:restore_default_button
                            text: qsTr("REST")
                            font.pixelSize: fontSizeMedium
                            Layout.fillWidth: true
                        }
                    }
                    Label{
                        text: qsTr("Velocity")
                        color: "black"
                        font.pixelSize: fontSizeMedium
                    }
                    Dial{
                        id:velocity_dial
                        from: 0
                        value:1
                        to:100
                        stepSize: 1
                        Layout.alignment: Qt.AlignHCenter
                        Layout.minimumWidth: 64
                        Layout.minimumHeight: 64
                        Layout.preferredWidth: 128
                        Layout.preferredHeight: 128
                        Layout.maximumWidth: 128
                        Layout.maximumHeight: 128
                        Layout.fillHeight: true

                        Label{
                            text: velocity_dial.value.toFixed(0)
                            color: "black"
                            font.pixelSize: Qt.application.font.pixelSize*3
                            anchors.centerIn: parent
                        }
                    }
                    Label{
                        text: qsTr("Position")
                        color: "black"
                        font.pixelSize: fontSizeMedium
                    }
                    Dial{
                        id:position_dial
                        from: 0
                        value:1
                        to:100
                        stepSize: 1
                        Layout.alignment: Qt.AlignHCenter
                        Layout.minimumWidth: 64
                        Layout.minimumHeight: 64
                        Layout.preferredWidth: 128
                        Layout.preferredHeight: 128
                        Layout.maximumWidth: 128
                        Layout.maximumHeight: 128
                        Layout.fillHeight: true

                        Label{
                            text: position_dial.value.toFixed(0)
                            color: "black"
                            font.pixelSize: Qt.application.font.pixelSize*3
                            anchors.centerIn: parent
                        }
                    }
                    Button{
                        id:confirm_button
                        Layout.minimumWidth: 100
                        Layout.maximumHeight: 40
                        text: qsTr("confirm")
                        Layout.alignment: Qt.AlignCenter
                        font.pixelSize: fontSizeMedium
                    }
                }

            }
            Rectangle {
                color: colorDarkGrey
                implicitWidth: 1
                Layout.fillHeight: true
            }
            ColumnLayout{
                Layout.preferredWidth: 350
                Layout.fillWidth: true
                Layout.fillHeight: true

                Frame{
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    SwipeView {
                        id: view
                        clip: true
                          currentIndex: pageIndicator.currentIndex
                          anchors.fill: parent

                          Page {
                              title: qsTr("Nic")                           

                              TreeView{
                                  id:nic_treeview
                                  anchors.left: parent.left
                                  anchors.top: parent.top
                                  anchors.right: parent.right

                                  TableViewColumn{
                                      title: "Name"
                                      role: "name"
                                  }
                                  TableViewColumn{
                                      title: "IP"
                                      role: "ip"
                                  }
                                  TableViewColumn{
                                      title: "Description"
                                      role: "description"
                                  }
                                  model:mytreeview


                                  itemDelegate: Item {
                                      Text {
                                          color: styleData.textColor
                                          elide: styleData.elideMode
                                          text: styleData.value
                                      }
                                  }
                              }

//                              ColumnLayout{
//                                  anchors.fill: parent

//                                  Button{
//                                      id:nic_scan
//                                      Layout.alignment: Qt.AlignRight

//                                      font.pixelSize: fontSizeMedium
//                                         text: qsTr("Scan")
//                                  }
//                                  Button{
//                                      id:nic_install
//                                      Layout.alignment:Qt.AlignRight
//                                      font.pixelSize: fontSizeMedium
//                                      text: qsTr("Install")
//                                  }
//                              }


                          }
                          Page {
                              title: qsTr("Setting")

                              ColumnLayout{

                                  RowLayout{

                                      Label{
                                          text: qsTr("Setting:")
                                          font.pixelSize: fontSizeMedium
                                      }
                                      RadioButton{
                                          id:all_seting
                                          text: qsTr("All Setting")
                                          font.pixelSize: fontSizeMedium
                                          checked: true
                                      }
                                      RadioButton{
                                          id:single_setting
                                          text: qsTr("Single Setting")
                                          font.pixelSize: fontSizeMedium
                                      }
                                  }
                                  RowLayout{
                                      Label{
                                          text: qsTr("Direction:")
                                          font.pixelSize: fontSizeMedium
                                      }
                                      RadioButton{
                                          id:clockwise
                                          text: qsTr("clockwise")
                                          checked: true
                                          font.pixelSize: fontSizeMedium
                                      }
                                      RadioButton{
                                          id:anticlockwise
                                          text: qsTr("anticlockwise")
                                          font.pixelSize: fontSizeMedium
                                      }
                                  }

                                  RowLayout{
                                      Label{
                                          text: qsTr("Select:")
                                          font.pixelSize: fontSizeMedium
                                      }
                                      ComboBox{
                                          id:allconfig_start_combox
                                          font.pixelSize: fontSizeMedium
                                      }
                                      Label{
                                          text: qsTr("To")
                                          font.pixelSize: fontSizeMedium
                                      }
                                      ComboBox{
                                          id:allconfig_end_combox
                                          font.pixelSize: fontSizeMedium
                                      }
                                  }

                                  RowLayout{
                                      Label{
                                          text: qsTr("Velocity")
                                          font.pixelSize: fontSizeMedium
                                      }
                                      TextField{
                                          id:velocity_textinput
                                          validator: RegExpValidator { regExp: /^[0-9\+\-\#\*\ ]{6,}$/ }
                                          inputMethodHints: Qt.ImhDialableCharactersOnly
                                          placeholderText: "<Enter>"
                                          font.pixelSize: fontSizeMedium
                                      }
                                  }

                                  RowLayout{
                                      Label{
                                          text: qsTr("Position")
                                          font.pixelSize: fontSizeMedium
                                      }
                                      TextField{
                                          id:position_textinput
                                          validator: RegExpValidator { regExp: /^[0-9\+\-\#\*\ ]{6,}$/ }
                                          inputMethodHints: Qt.ImhDialableCharactersOnly
                                          placeholderText: "<Enter>"
                                          font.pixelSize: fontSizeMedium
                                      }
                                  }
                              }
                          }

                      }

                      PageIndicator {
                          id: pageIndicator
                          interactive: true
                          count: view.count
                          currentIndex: view.currentIndex

                          anchors.bottom: parent.bottom
                          anchors.horizontalCenter: parent.horizontalCenter
                      }


                }
            }
            Rectangle {
                color: colorDarkGrey
                implicitWidth: 1
                Layout.fillHeight: true
            }
            ColumnLayout{
                RowLayout{
                    Label{
                        text: qsTr("Velocity:")
                        font.pixelSize: fontSizeMedium
                    }
                    Label{
                        id:show_velocity_lable
                        Layout.fillWidth: true
                        text: "000.0"
                        font.family: "Times New Roman"
                        font.bold: true
                        font.pixelSize: fontSizeMedium

                    }
                }
                RowLayout{
                    Label{
                        text: qsTr("Position:")
                        font.pixelSize: fontSizeMedium
                    }
                    Label{
                        id:show_position_textedit
                        Layout.fillWidth: true
                        text: "000.0"
                        font.family: "Times New Roman"
                        font.bold: true
                        font.pixelSize: fontSizeMedium
                    }
                }

                RowLayout{
                    width: 175
                    height: 25
                    Layout.fillWidth: true

                    Label{
                        text: qsTr("Info")
                        font.pixelSize: fontSizeMedium
                        height: 25
                    }
                    Button{
                        id:clear_info_button
                        text: qsTr("clear")
                        font.pixelSize: fontSizeMedium
                        height: 25
                    }
                }
                TextEdit{
                    id:info_textedit
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    readOnly: true
                }
            }
        }
    }

















    InputPanel {
        id: inputPanel
        z: 99
        x: 0
        y: window.height
        width: window.width

        states: State {
            name: "visible"
            when: inputPanel.active
            PropertyChanges {
                target: inputPanel
                y: window.height - inputPanel.height
            }
        }
        transitions: Transition {
            from: ""
            to: "visible"
            reversible: true
            ParallelAnimation {
                NumberAnimation {
                    properties: "y"
                    duration: 250
                    easing.type: Easing.InOutQuad
                }
            }
        }
    }
}

