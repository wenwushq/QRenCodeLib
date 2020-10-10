#include "GenCode.h"
#include "..\QRenCodeLib\qrencode.h"
#include <QPainter>

//根据内容生成二维码
bool GenQRCode(const QString &strCont, QPixmap &pixmapGen, QSize &sizeQRCode)
{
	if (strCont.isEmpty())
		return false;

	//版本参数是2，实际上二维码生成的，版本是根据二维码内容来决定的，最后一个参数设为1为大小写敏感
	QRcode *pqrCode = QRcode_encodeString(strCont.toStdString().c_str(), 2, QR_ECLEVEL_Q, QR_MODE_8, 1);
	if (pqrCode == nullptr)
		return false;

	const int nQRCodeWidth = pqrCode->width > 0 ? pqrCode->width : 1;
	const double dScaleX = sizeQRCode.width() / (double)nQRCodeWidth;
	const double dScaleY = sizeQRCode.height() / (double)nQRCodeWidth;

	QImage imgQRCode(sizeQRCode, QImage::Format_ARGB32_Premultiplied);

	QPainter painter(&imgQRCode);
	QColor colorBk(Qt::white);//背景色
	painter.setBrush(colorBk);
	painter.setPen(Qt::NoPen);
	painter.drawRect(0, 0, sizeQRCode.width(), sizeQRCode.height());//填充背景色

	QColor colorForeground(Qt::black);//前景色
	for (int nY = 0; nY < nQRCodeWidth; nY++)
	{
		for (int nX = 0; nX < nQRCodeWidth; nX++)
		{
			unsigned char charCont = pqrCode->data[nY * nQRCodeWidth + nX];
			if (charCont & 0x01)
			{
				QRectF rcDraw(nX * dScaleX, nY * dScaleY, dScaleX, dScaleY);
				painter.fillRect(rcDraw, QBrush(colorForeground));
			}
		}
	}

	pixmapGen = QPixmap::fromImage(imgQRCode);

	QRcode_free(pqrCode);//释放内存

	return true;
}