#ifndef SLEVELS_H
#define SLEVELS_H

#include "class/steamapi/Sapi.h"

class SLevels : public Sapi
{
    Q_OBJECT
public:
    explicit SLevels(const QString &id, QObject *parent = nullptr);
    SLevels(QObject *parent = nullptr): Sapi(parent) {}
    ~SLevels() {}

    SLevels &load(const QString &steamId);
    SLevels &update();

    int getLevel() const {return _player_level;}

signals:
    void s_finished(SLevels*);
    void s_finished();

private slots:
    void onLoad() override;
    void fromJson(const QJsonValue &value) override;

private:
    QString _steamid;//"76561198065018572"
    int _player_level = 0;

};

#endif // SLEVELS_H
