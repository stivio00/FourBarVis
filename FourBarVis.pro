#-------------------------------------------------
#
# Project created by QtCreator 2019-06-15T18:33:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FourBarVis
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        about.cpp \
        fourbarlinkage.cpp \
        main.cpp \
        mainwindow.cpp \
        settings.cpp

HEADERS += \
        about.h \
        fourbarlinkage.h \
        mainwindow.h \
        settings.h

FORMS += \
        about.ui \
        mainwindow.ui \
        settings.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources/QBE-Faenza.qrc \
    resources/QBE-GNOME.qrc \
    resources/QBE-Oxygen.qrc \
    resources/QBE-Tango.qrc \
    resources/application.qrc

#TODO: TANGO ICON or Oxigen ICON SET
DISTFILES += \
    resources/icons/QBE-Faenza/README \
    resources/icons/QBE-Faenza/applications-fonts.svg \
    resources/icons/QBE-Faenza/document-import.png \
    resources/icons/QBE-Faenza/document-open.png \
    resources/icons/QBE-Faenza/document-save-as.png \
    resources/icons/QBE-Faenza/document-save.png \
    resources/icons/QBE-Faenza/edit-find.svg \
    resources/icons/QBE-Faenza/edit-redo.png \
    resources/icons/QBE-Faenza/edit-undo.png \
    resources/icons/QBE-Faenza/exit.png \
    resources/icons/QBE-Faenza/format-text-bold.png \
    resources/icons/QBE-Faenza/format-text-italic.png \
    resources/icons/QBE-Faenza/format-text-underline.png \
    resources/icons/QBE-Faenza/go-jump.png \
    resources/icons/QBE-Faenza/go-next.png \
    resources/icons/QBE-Faenza/go-previous.png \
    resources/icons/QBE-Faenza/help-about.svg \
    resources/icons/QBE-Faenza/index.theme \
    resources/icons/QBE-Faenza/key_bindings.svg \
    resources/icons/QBE-Faenza/software-properties.svg \
    resources/icons/QBE-Faenza/zoom-fit.png \
    resources/icons/QBE-Faenza/zoom-height.png \
    resources/icons/QBE-Faenza/zoom-in.png \
    resources/icons/QBE-Faenza/zoom-original.png \
    resources/icons/QBE-Faenza/zoom-out.png \
    resources/icons/QBE-Faenza/zoom-selection.png \
    resources/icons/QBE-Faenza/zoom-width.png \
    resources/icons/QBE-GNOME/README \
    resources/icons/QBE-GNOME/application-exit.png \
    resources/icons/QBE-GNOME/document-open.png \
    resources/icons/QBE-GNOME/document-save-as.png \
    resources/icons/QBE-GNOME/document-save.png \
    resources/icons/QBE-GNOME/edit-find.png \
    resources/icons/QBE-GNOME/edit-redo.png \
    resources/icons/QBE-GNOME/edit-undo.png \
    resources/icons/QBE-GNOME/format-text-bold.png \
    resources/icons/QBE-GNOME/format-text-italic.png \
    resources/icons/QBE-GNOME/format-text-underline.png \
    resources/icons/QBE-GNOME/go-down.png \
    resources/icons/QBE-GNOME/go-jump.png \
    resources/icons/QBE-GNOME/go-next.png \
    resources/icons/QBE-GNOME/go-previous.png \
    resources/icons/QBE-GNOME/go-up.png \
    resources/icons/QBE-GNOME/help-about.png \
    resources/icons/QBE-GNOME/index.theme \
    resources/icons/QBE-GNOME/list-add.png \
    resources/icons/QBE-GNOME/list-remove.png \
    resources/icons/QBE-GNOME/preferences-desktop-font.png \
    resources/icons/QBE-GNOME/preferences-desktop-keyboard-shortcuts.png \
    resources/icons/QBE-GNOME/preferences-system.png \
    resources/icons/QBE-GNOME/zoom-fit-best.png \
    resources/icons/QBE-GNOME/zoom-in.png \
    resources/icons/QBE-GNOME/zoom-original.png \
    resources/icons/QBE-GNOME/zoom-out.png \
    resources/icons/QBE-Misc/Document-import.svg \
    resources/icons/QBE-Misc/README \
    resources/icons/QBE-Misc/gnome-edit-find.svg \
    resources/icons/QBE-Misc/joinRow.svg \
    resources/icons/QBE-Misc/moveTo.svg \
    resources/icons/QBE-Misc/splitRow.svg \
    resources/icons/QBE-Oxygen/application-exit.png \
    resources/icons/QBE-Oxygen/application-x-font-ttf.png \
    resources/icons/QBE-Oxygen/document-import.png \
    resources/icons/QBE-Oxygen/document-open.png \
    resources/icons/QBE-Oxygen/document-save-as.png \
    resources/icons/QBE-Oxygen/document-save.png \
    resources/icons/QBE-Oxygen/draw-rectangle.png \
    resources/icons/QBE-Oxygen/edit-find.png \
    resources/icons/QBE-Oxygen/edit-redo.png \
    resources/icons/QBE-Oxygen/edit-table-delete-row.png \
    resources/icons/QBE-Oxygen/edit-table-insert-row-under.png \
    resources/icons/QBE-Oxygen/edit-undo.png \
    resources/icons/QBE-Oxygen/format-text-bold.png \
    resources/icons/QBE-Oxygen/format-text-italic.png \
    resources/icons/QBE-Oxygen/format-text-underline.png \
    resources/icons/QBE-Oxygen/go-down.png \
    resources/icons/QBE-Oxygen/go-jump.png \
    resources/icons/QBE-Oxygen/go-next.png \
    resources/icons/QBE-Oxygen/go-previous.png \
    resources/icons/QBE-Oxygen/go-up.png \
    resources/icons/QBE-Oxygen/help-about.png \
    resources/icons/QBE-Oxygen/index.theme \
    resources/icons/QBE-Oxygen/list-add.png \
    resources/icons/QBE-Oxygen/list-remove.png \
    resources/icons/QBE-Oxygen/preferences-desktop-keyboard.png \
    resources/icons/QBE-Oxygen/preferences-system.png \
    resources/icons/QBE-Oxygen/zoom-fit-best.png \
    resources/icons/QBE-Oxygen/zoom-fit-height.png \
    resources/icons/QBE-Oxygen/zoom-fit-width.png \
    resources/icons/QBE-Oxygen/zoom-in.png \
    resources/icons/QBE-Oxygen/zoom-original.png \
    resources/icons/QBE-Oxygen/zoom-out.png \
    resources/icons/QBE-Oxygen/zoom-select.png \
    resources/icons/QBE-Tango/README \
    resources/icons/QBE-Tango/View-zoom-0.svg \
    resources/icons/QBE-Tango/View-zoom-fit.svg \
    resources/icons/QBE-Tango/View-zoom-in.svg \
    resources/icons/QBE-Tango/View-zoom-out.svg \
    resources/icons/QBE-Tango/View-zoom-target.svg \
    resources/icons/QBE-Tango/document-open.svg \
    resources/icons/QBE-Tango/document-save-as.svg \
    resources/icons/QBE-Tango/document-save.svg \
    resources/icons/QBE-Tango/edit-find.svg \
    resources/icons/QBE-Tango/edit-redo.svg \
    resources/icons/QBE-Tango/edit-undo.svg \
    resources/icons/QBE-Tango/font-x-generic.svg \
    resources/icons/QBE-Tango/format-text-bold.svg \
    resources/icons/QBE-Tango/format-text-italic.svg \
    resources/icons/QBE-Tango/format-text-underline.svg \
    resources/icons/QBE-Tango/go-down.svg \
    resources/icons/QBE-Tango/go-jump.svg \
    resources/icons/QBE-Tango/go-next.svg \
    resources/icons/QBE-Tango/go-previous.svg \
    resources/icons/QBE-Tango/go-top.svg \
    resources/icons/QBE-Tango/go-up.svg \
    resources/icons/QBE-Tango/help-browser.svg \
    resources/icons/QBE-Tango/index.theme \
    resources/icons/QBE-Tango/list-add.svg \
    resources/icons/QBE-Tango/list-remove.svg \
    resources/icons/QBE-Tango/system-log-out.svg \
    resources/icons/qbe.ico \
    resources/icons/qbe.png \
    resources/icons/qbe.svg \
    resources/icons/qbe/README \
    resources/icons/qbe/deleteRow.png \
    resources/icons/qbe/deleteRow.svg \
    resources/icons/qbe/down.svg \
    resources/icons/qbe/drawRect.png \
    resources/icons/qbe/insertRow.svg \
    resources/icons/qbe/rectangle.svg \
    resources/icons/qbe/showSymbol.png \
    resources/icons/qbe/up.svg \
    resources/win.rc

OTHER_FILES += README.MD
