#include "statefsproperty.h"
#include <QDebug>

StatefsProperty::StatefsProperty(QObject *parent) :
    QObject(parent)
{
}

QString StatefsProperty::key() const
{
    if (property.isNull()) {
        return QString();
    }
    else {
        return property->key();
    }
}

void StatefsProperty::setKey(const QString &newKey)
{
    if (property.isNull() || property->key() != newKey) {
        qDebug() << "new key:" << newKey;
        property.reset(new ContextProperty(newKey, this));
        property->subscribe();
        QObject::connect(property.data(), SIGNAL(valueChanged()), this, SLOT(onValueChanged()));
        Q_EMIT keyChanged();
    }
}

QVariant StatefsProperty::value() const
{
    if (property.isNull()) {
        return QVariant();
    }
    else {
        return property->value();
    }
}

void StatefsProperty::onValueChanged()
{
    qDebug() << property->key() << property->value();
    Q_EMIT valueChanged();
}
