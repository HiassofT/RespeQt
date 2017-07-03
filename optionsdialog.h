/*
 * optionsdialog.h
 *
 * Copyright 2016 TheMontezuma
 *
 * This file is copyrighted by either Fatih Aygun, Ray Ataergin, or both.
 * However, the years for these copyrights are unfortunately unknown. If you
 * know the specific year(s) please let the current maintainer know.
 */

#ifndef OPTIONSDIALOG_H
#define OPTIONSDIALOG_H

#include <QtWidgets/QDialog>
#include <QTreeWidget>
#include <QtDebug>

#include "serialport.h"

namespace Ui {
    class OptionsDialog;
}

class OptionsDialog : public QDialog {
    Q_OBJECT

public:
    OptionsDialog(QWidget *parent = 0);
    ~OptionsDialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::OptionsDialog *m_ui;
    QTreeWidgetItem *itemStandard, *itemAtariSio, *itemEmulation, *itemI18n;
    QTreeWidgetItem *itemTestSerialPort, *itemAtari1020, *itemAtari1027;

private slots:
    void on_serialPortComboBox_currentIndexChanged(int index);
    void on_serialPortHandshakeCombo_currentIndexChanged(int index);
    void on_serialPortUseDivisorsBox_toggled(bool checked);
    void on_treeWidget_itemClicked(QTreeWidgetItem* item, int column);
    void on_treeWidget_currentItemChanged(QTreeWidgetItem* current, QTreeWidgetItem* previous);
    void OptionsDialog_accepted();
    void on_useEmulationCustomCasBaudBox_toggled(bool checked);
    void on_testFileButton_clicked();
    void on_button_1027font_clicked();
};

#endif // OPTIONSDIALOG_H
