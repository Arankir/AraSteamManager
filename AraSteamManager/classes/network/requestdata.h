#ifndef IMAGEREQUEST_H
#define IMAGEREQUEST_H

#include <QNetworkAccessManager>

class RequestData : public QObject {
    Q_OBJECT
public:
    RequestData(const QString &url, const bool &parallel, QObject *parent = nullptr);
    RequestData(QObject *parent = nullptr);
    ~RequestData();

    void get(const QString &url, const bool &parallel = false);
    void get(const QUrl &url, const bool &parallel = false);

    QByteArray reply() const;
    QString error() const;

signals:
    void s_finished(RequestData *imgr);

private slots:
    void onResultGet(QNetworkReply *reply);

private:
    QNetworkAccessManager *manager_;
    QByteArray reply_;
    QString error_;
    QString url_;

};

#endif // IMAGEREQUEST_H
