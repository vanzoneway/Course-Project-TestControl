//aspectratiopixmaplabel_h
#ifndef ASPECTRATIOPIXMAPLABEL_H
#define ASPECTRATIOPIXMAPLABEL_H

#include <QLabel>
#include <QPixmap>
#include <QResizeEvent>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QDropEvent>
#include <QList>
#include <QUrl>
#include <QMouseEvent>

class AspectRatioPixmapLabel : public QLabel
{
    Q_OBJECT
public:
    explicit AspectRatioPixmapLabel(QWidget *parent = 0);
    virtual int heightForWidth( int width ) const;
    virtual QSize sizeHint() const;
    QPixmap scaledPixmap() const;
    bool is_changed = false;
public slots:
    void setPixmap ( const QPixmap & );
    void resizeEvent(QResizeEvent *);
    void setClicable(bool x);
    void clearImage();
    QString getPath_to_IMG();
    void setCurrentIMG(QString path_to_IMG);



private slots:

    void dragEnterEvent(QDragEnterEvent *event);

    void dropEvent(QDropEvent *event);

    void mousePressEvent(QMouseEvent* e);

private:
    bool is_clicable = false;

    QPixmap pix;
    QString path_to_IMG = "NONE";


};

#endif // ASPECTRATIOPIXMAPLABEL_H
