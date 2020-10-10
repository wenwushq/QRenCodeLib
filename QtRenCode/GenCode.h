#pragma once
#include <QString>
#include <QPixmap>

//根据内容生成二维码
bool GenQRCode(const QString &strCont, QPixmap &pixmapGen, QSize &sizeQRCode);