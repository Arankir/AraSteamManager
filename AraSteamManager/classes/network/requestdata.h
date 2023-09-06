#ifndef IMAGEREQUEST_H
#define IMAGEREQUEST_H

#include <QNetworkAccessManager>

class RequestData : public QObject {
    Q_OBJECT
public:
    RequestData(const QString &url, bool parallel, QObject *parent = nullptr);
    RequestData(const QUrl &url, bool parallel, QObject *parent = nullptr);
    RequestData(QObject *parent = nullptr);
    ~RequestData();

    void get(const QString &url, bool parallel = false);
    void get(const QUrl &url, bool parallel = false);

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
    QUrl url_;

};

#endif // IMAGEREQUEST_H
