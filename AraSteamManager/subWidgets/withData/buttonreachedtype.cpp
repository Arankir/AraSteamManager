#include "buttonreachedtype.h"
#include "classes/common/images.h"

const int c_frameNumberAll = 0;
const int c_frameNumberNotReached = 29;
const int c_frameNumberReached = 59;

const QSize c_iconSize = QSize(24, 24);

ButtonReachedType::ButtonReachedType(QWidget *aParent): QPushButton(aParent), movie_(new QMovie()) {
    updateIcons();
    connect(movie_, &QMovie::frameChanged, this, [=, this] {
        setIcon(movie_->currentPixmap());
        switch (type_) {
        case ReachedType::reached: {
            if (movie_->currentFrameNumber() == c_frameNumberReached) {
                movie_->setPaused(true);
            }
            break;
        }
        case ReachedType::all: {
            if (movie_->currentFrameNumber() == c_frameNumberAll) {
                movie_->setPaused(true);
            }
            break;
        }
        case ReachedType::notReached: {
            if (movie_->currentFrameNumber() == c_frameNumberNotReached) {
                movie_->setPaused(true);
            }
            break;
        }
        default: {

        }
        }
    });
    setIconSize(c_iconSize);
    stateChanged(ReachedType::all);
    connect(this, &QPushButton::pressed, this, &ButtonReachedType::onButtonClick);
}

ButtonReachedType::~ButtonReachedType() {
    if (movie_) {
        delete movie_;
    }
}

void ButtonReachedType::updateIcons() {
    if (movie_ != nullptr) {
        int frame = movie_->currentFrameNumber();
        movie_->setFileName(Images::reachedGif());
        movie_->setScaledSize(c_iconSize);
        movie_->jumpToFrame(frame);
    } else {
        qWarning() << "error missing movie";
    }
}

void ButtonReachedType::updateSettings(QFlags<changedSettings> aSettings) {
    if (aSettings.testFlag(changedSettings::theme)) {
        updateIcons();
    }
}

void ButtonReachedType::onButtonClick() {
    switch (type_) {
    case ReachedType::reached: {
        stateChanged(ReachedType::all);
        emit s_radioButtonChange(ReachedType::all);;
        break;
    }
    case ReachedType::all: {
        stateChanged(ReachedType::notReached);
        emit s_radioButtonChange(ReachedType::notReached);
        break;
    }
    case ReachedType::notReached: {
        stateChanged(ReachedType::reached);
        emit s_radioButtonChange(ReachedType::reached);
        break;
    }
    default: {

    }
    }
}

void ButtonReachedType::stateChanged(const ReachedType &aNewType) {
    type_ = aNewType;
    movie_->start();
}

ReachedType ButtonReachedType::type() const {
    return type_;
}

void ButtonReachedType::setType(const ReachedType &aType) {
    stateChanged(aType);
}
