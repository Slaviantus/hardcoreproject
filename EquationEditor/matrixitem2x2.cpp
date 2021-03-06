#include "matrixitem2x2.h"
#include "place.h"
#include "iostream"
#include "QFontMetrics"
#include "QPen"
#include "QPainter"
#include "QSize"


Matrixitem2x2::Matrixitem2x2(const QFont &font, QObject *parent) : CommonItem(font, MATRIX_PARTS, parent)
{
    for (int i(0); i<m_iNum; ++i) {                           // создание и настройка типа дочерних элементов - зависит от типа родительского элемента
        items[i] = new Place(font);                                     // создание
        items[i]->setParentItem(this);                                  // данный объект задается дочерним в качестве родителя
        items[i]->enableEditable(true);
    }
    setChildPos();
}

void Matrixitem2x2::setChildPos()
{
    items[0]->setPos(2.0, -16.0);
    items[1]->setPos(items[0]->boundingRect().width() + 4.0, -16.0);
    items[2]->setPos(2.0, items[0]->boundingRect().bottom());
    items[3]->setPos(items[2]->boundingRect().width() + 4.0, items[0]->boundingRect().bottom());
}

void Matrixitem2x2::updateSize()
{
    CommonItem::updateSize();
    m_topLeft += QPointF(-3.0, 0.0);
    m_sz += QSizeF(2*10.0, 4.0);
    items[0]->setY(-16.0);
    items[1]->setY(-16.0);
    items[2]->setY(items[0]->boundingRect().bottom() + 1.0);
    items[3]->setY(items[0]->boundingRect().bottom() + 1.0);
    max_windth = items[0]->boundingRect().width();
    for(int i = 0; i < m_iNum; i = 2 + i)
    {
        if(items[i]->boundingRect().width() >= max_windth)
        {
            max_windth = items[i]->boundingRect().width();
            max_index_1 = i;
        }
    }
    for(int i = 1; i < m_iNum; i = 2 + i)
    {
        items[i]->setX(items[max_index_1]->boundingRect().width() + 4.0);
    }
    for(int i = 1; i < m_iNum; i = 2 + i)
    {
        if(items[i]->boundingRect().width() >= max_windth)
        {
            max_windth = items[i]->boundingRect().width();
            max_index_2 = i;
        }
    }
    m_sz.setWidth(items[max_index_1]->boundingRect().width() + items[max_index_2]->boundingRect().width() + 6.0);

}

void Matrixitem2x2::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QFontMetrics fm(font);

    QPen pen;

    qreal pw = 5.0;

    pen.setWidthF(fm.size(Qt::TextSingleLine, "0").height()*0.05);
    painter->setPen(pen);

    painter->drawLine(QPointF(-2.0, boundingRect().top()),
                      QPointF(-2.0, boundingRect().bottom()));

    painter->drawLine(QPointF(boundingRect().width()-2.0, boundingRect().top()),
                      QPointF(boundingRect().width()-2.0, boundingRect().bottom()));

    pen.setWidthF(pen.widthF() / 2.0);
    painter->setPen(pen);
    painter->drawLine(QPointF(-2.0, boundingRect().top()),
                      QPointF(-2.0 + pw, boundingRect().top()));
    painter->drawLine(QPointF(0.0, boundingRect().bottom()),
                      QPointF(0.0 + pw, boundingRect().bottom()));
    painter->drawLine(QPointF(boundingRect().width()-2.0, boundingRect().top()),
                      QPointF(boundingRect().width()-(2.0 + pw), boundingRect().top()));
    painter->drawLine(QPointF(boundingRect().width()-2.0, boundingRect().bottom()),
                      QPointF(boundingRect().width()-(2.0 + pw), boundingRect().bottom()));

}
