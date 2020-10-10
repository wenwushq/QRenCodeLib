#include "QtRenCode.h"
#include "GenCode.h"

QtRenCode::QtRenCode(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
	connect(ui.btnGen, SIGNAL(pressed()), this, SLOT(BtnGenClicked()));
}


void QtRenCode::BtnGenClicked()
{
	QPixmap pixmapShow;
	GenQRCode(ui.editCont->toPlainText(), pixmapShow, ui.labelCode->size());
	ui.labelCode->setPixmap(pixmapShow);
}