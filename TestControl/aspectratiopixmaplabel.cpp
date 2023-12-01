//aspectratiopixmaplabel.h
#include "aspectratiopixmaplabel.h"
//#include <QDebug>

AspectRatioPixmapLabel::AspectRatioPixmapLabel(QWidget *parent) :
    QLabel(parent)
{
    setAcceptDrops(true);
    this->setMinimumSize(1,1);
    setScaledContents(false);
}

void AspectRatioPixmapLabel::setPixmap ( const QPixmap & p)
{
    pix = p;
    if(!pix.isNull()){
        QLabel::setPixmap(scaledPixmap());
    }else{
        QLabel::setText("NONE");
    }
}


int AspectRatioPixmapLabel::heightForWidth( int width ) const
{
    return pix.isNull() ? this->height() : ((qreal)pix.height()*width)/pix.width();
}


QSize AspectRatioPixmapLabel::sizeHint() const
{
    int w = this->width();
    return QSize( w, heightForWidth(w) );
}


QPixmap AspectRatioPixmapLabel::scaledPixmap() const
{
    return pix.scaled(this->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
}


void AspectRatioPixmapLabel::resizeEvent(QResizeEvent * e)
{
    if(!pix.isNull())
        QLabel::setPixmap(scaledPixmap());
}


void AspectRatioPixmapLabel::setClicable(bool x)
{
    is_clicable = x;
}


void AspectRatioPixmapLabel::clearImage()
{
    QLabel::clear();
    QLabel::setText("NONE");
    pix = QPixmap();
}


QString AspectRatioPixmapLabel::getPath_to_IMG()
{
    return path_to_IMG;
}


void AspectRatioPixmapLabel::setCurrentIMG(QString path_to_IMG)
{
    QPixmap pix(path_to_IMG);
    this->path_to_IMG = path_to_IMG;
    this->setPixmap(pix);
}


void AspectRatioPixmapLabel::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasUrls() && is_clicable)
        event->acceptProposedAction();
}


void AspectRatioPixmapLabel::dropEvent(QDropEvent *event)
{
    const QMimeData* mimeData = event->mimeData();

    if(mimeData->hasUrls() && is_clicable)
    {
        QList<QUrl> urlList = mimeData->urls();

        if(!urlList.isEmpty())
        {
            QUrl url = urlList.first();
            QString filePath = url.toLocalFile();
            QPixmap pix(filePath);
            this->setPixmap(pix);
            path_to_IMG = filePath;
            is_changed = true;


        }
    }
}


void AspectRatioPixmapLabel::mousePressEvent(QMouseEvent *e)
{

    if(e->button() == Qt::RightButton && is_clicable)
    {
        QLabel::clear();
        QLabel::setText("NONE");
        pix = QPixmap();
        path_to_IMG = "NONE";
        is_changed = true;

    }
}


