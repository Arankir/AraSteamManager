#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <QMainWindow>
#include <QObject>
#include <QFile>

class Language : public QObject
{
    Q_OBJECT
public:
    explicit Language(QObject *parent = nullptr);
    QStringList GetLanguage(QString form, int language);

signals:

public slots:
};

#endif // LANGUAGE_H
