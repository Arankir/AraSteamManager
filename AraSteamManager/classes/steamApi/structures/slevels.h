#ifndef SLEVELS_H
#define SLEVELS_H

#include "../sapi.h"

class SLevels : public Sapi
{
    Q_OBJECT
public:
    explicit SLevels(const QString &id, QObject *parent = nullptr);
    SLevels(QObject *parent = nullptr): Sapi(parent) {}
    ~SLevels() {}

    SLevels &load(const QString &steamId);
    SLevels &update();

    int level() const {return _playerLevel;}

signals:
    void s_finished(SLevels*);
    void s_finished();

private slots:
    void onLoad() override;
    void fromJson(const QJsonValue &value) override;

private:
    QString _steamId;//"76561198065018572"
    int _playerLevel = 0;

};

#endif // SLEVELS_H
