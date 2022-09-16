#ifndef SPROFILECUSTOMIZATION_H
#define SPROFILECUSTOMIZATION_H

#include "../sapi.h"

class SProfileCustomization : public Sapi {
    enum class Customization_type {
        unknown = 0,
        rarest_achievements = 1,
        game_collector = 2,
        items_showcase = 3,
        items_to_exchange = 4,
        badge_collector = 5,
        favorite_game = 6,
        screenshot = 7,
        your_text = 8,
        favorite_band = 9,
        review = 10,
        workshop = 11,
        your_workshop = 12,
        illustration = 13,
        video = 14,
        guide = 15,
        my_guides = 16,
        achievements = 17,
        community_awards = 21,
        selected_illustrations = 22,
        perfectionist = 23
    };

public:
    SProfileCustomization(const SProfileCustomization &customization);
    SProfileCustomization(const QJsonObject &object = QJsonObject(), QObject *parent = nullptr);

    SProfileCustomization &operator=(const SProfileCustomization &customization);
    SProfileCustomization &operator=(SProfileCustomization &&customization);
    bool    operator<(const SProfileCustomization &customization) const;
    bool    operator>(const SProfileCustomization &customization) const;
    bool    operator==(const SProfileCustomization &customization) const;
    bool    operator!=(const SProfileCustomization &customization) const;

    QString title() const;
    int level() const;
    int count() const;
    bool isUpgradable() const;
    bool isPurchase() const;

    QJsonObject toJson() const;
    void fromJson(const QJsonObject &object);

    static QList<SProfileCustomization> load(const ProfileID &profileId, std::function<void (QList<SProfileCustomization>)> callback = nullptr);
private:
    Customization_type type_ = Customization_type::unknown;
    int count_ = 0;
    int level_ = 0;
};

using SProfileCustomizations = QList<SProfileCustomization>;

#endif // SPROFILECUSTOMIZATION_H
