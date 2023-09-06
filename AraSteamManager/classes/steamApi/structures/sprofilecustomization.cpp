#include "sprofilecustomization.h"
#include <QJsonDocument>
#include <QJsonArray>

SProfileCustomization::SProfileCustomization(const SProfileCustomization &aCopy): Sapi{aCopy.parent()}, type_(aCopy.type_), count_(aCopy.count_), level_(aCopy.level_) {

}

SProfileCustomization::SProfileCustomization(const QJsonObject &aObject, QObject *aParent): Sapi{aParent} {
    fromJson(aObject);
}

SProfileCustomization &SProfileCustomization::operator=(const SProfileCustomization &aCustomization) {
    type_ = aCustomization.type_;
    count_ = aCustomization.count_;
    level_ = aCustomization.level_;
    return *this;
}

SProfileCustomization &SProfileCustomization::operator=(SProfileCustomization &&aCustomization) {
    type_ = std::move(aCustomization.type_);
    count_ = std::move(aCustomization.count_);
    level_ = std::move(aCustomization.level_);
    return *this;
}

bool SProfileCustomization::operator<(const SProfileCustomization &aCustomization) const {
    return type_ < aCustomization.type_;
}

bool SProfileCustomization::operator>(const SProfileCustomization &aCustomization) const {
    return type_ > aCustomization.type_;
}

bool SProfileCustomization::operator==(const SProfileCustomization &aCustomization) const {
    return type_ == aCustomization.type_ &&
           count_ == aCustomization.count_ &&
           level_ == aCustomization.level_;
}

bool SProfileCustomization::operator!=(const SProfileCustomization &aCustomization) const {
    return type_ != aCustomization.type_ ||
           count_ != aCustomization.count_ ||
           level_ != aCustomization.level_;
}

QString SProfileCustomization::title() const {
    switch (type_) {
    case Customization_type::rarest_achievements: {
        return tr("Редчайшие достижения");
    }
    case Customization_type::game_collector: {
        return tr("Коллекционер игр");
    }
    case Customization_type::items_showcase: {
        return tr("Витрина предметов");
    }
    case Customization_type::items_to_exchange: {
        return tr("Предметы на обмен");
    }
    case Customization_type::badge_collector: {
        return tr("Коллекционер значков");
    }
    case Customization_type::favorite_game: {
        return tr("Любимая игра");
    }
    case Customization_type::screenshot: {
        return tr("Скриншот");
    }
    case Customization_type::your_text: {
        return tr("Свой текст");
    }
    case Customization_type::favorite_band: {
        return tr("Любимая группа");
    }
    case Customization_type::review: {
        return tr("Обзор");
    }
    case Customization_type::workshop: {
        return tr("Мастерская");
    }
    case Customization_type::your_workshop: {
        return tr("Ваша мастерская");
    }
    case Customization_type::illustration: {
        return tr("Иллюстрация");
    }
    case Customization_type::video: {
        return tr("Видео");
    }
    case Customization_type::guide: {
        return tr("Руководство");
    }
    case Customization_type::my_guides: {
        return tr("Мои руководства");
    }
    case Customization_type::achievements: {
        return tr("Достижения");
    }
    case Customization_type::community_awards: {
        return tr("Награды сообщества");
    }
    case Customization_type::selected_illustrations: {
        return tr("Избранные иллюстрации");
    }
    case Customization_type::perfectionist: {
        return tr("Перфекционист");
    }
    default : {
        return tr("");
    }
    }
}

int SProfileCustomization::level() const {
    return level_;
}

int SProfileCustomization::count() const {
    return count_;
}

bool SProfileCustomization::isUpgradable() const {
    int type = static_cast<int>(type_);
    return (type == 1) || (type == 2) || (type == 3) || (type == 5) || (type == 12) || (type == 16) || (type == 17) || (type == 21) || (type == 23);
}

bool SProfileCustomization::isPurchase() const {
    int type = static_cast<int>(type_);
    return (type == 2) || (type == 3) || (type == 4) || (type == 5) || (type == 6) || (type == 7) || (type == 8) || (type == 9) || (type == 10) ||
            (type == 11) || (type == 12) || (type == 13) || (type == 14) || (type == 15) || (type == 16) || (type == 17) || (type == 22) || (type == 23);
}

QJsonObject SProfileCustomization::toJson() const {
    QJsonObject object;
    object["customization_type"] = static_cast<int>(type_);
    object["count"] = count_;
    object["level"] = level_;
    return object;
}

void SProfileCustomization::fromJson(const QJsonObject &aObject) {
    type_ = static_cast<Customization_type>(aObject.value("customization_type").toInt());
    count_ = aObject.value("count").toInt();
    level_ = aObject.value("level").toInt();
}

SProfileCustomizations onLoadCustomizations(const QByteArray &aByteArray) {
    SProfileCustomizations list;
    for(const QJsonValue &customization: QJsonDocument::fromJson(aByteArray).object().value("response").toObject().value("purchased_customizations").toArray()) {
        list.append(SProfileCustomization(customization.toObject()));
    }
    for(const QJsonValue &customization: QJsonDocument::fromJson(aByteArray).object().value("response").toObject().value("upgraded_customizations").toArray()) {
        list.append(SProfileCustomization(customization.toObject()));
    }
    return list;
}

SProfileCustomizations SProfileCustomization::load(const ProfileID &aProfileId, std::function<void (SProfileCustomizations)> aCallback) {
    return Sapi::load<SProfileCustomization>(Sapi::Url::profileCustomizations(aProfileId), onLoadCustomizations, aCallback);
}
