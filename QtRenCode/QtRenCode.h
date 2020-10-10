#pragma once

#include <QtWidgets/QWidget>
#include "ui_QtRenCode.h"

class QtRenCode : public QWidget
{
    Q_OBJECT

public:
    QtRenCode(QWidget *parent = Q_NULLPTR);

private slots:
	void BtnGenClicked();

private:
    Ui::QtRenCodeClass ui;
};
