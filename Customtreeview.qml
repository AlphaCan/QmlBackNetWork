import QtQuick 2.2
import QtQuick.Controls 1.5
import QtQml.Models 2.2


TreeView {
    id: view
    anchors.left: parent.left
    anchors.right: parent.right
//    anchors.margins: 2 * 12 + row.height
    model: mytreemodel
    selection: ItemSelectionModel{
        model: mytreemodel
    }

}


