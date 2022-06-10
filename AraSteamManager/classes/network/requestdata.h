#ifndef IMAGEREQUEST_H
#define IMAGEREQUEST_H

//#include <QMainWindow>
#include <QNetworkAccessManager>
//#include <QNetworkRequest>
//#include <QNetworkReply>
//#include <QJsonDocument>
//#include <QJsonObject>
//#include <QJsonArray>
////#include <QTextCodec>
//#include <QTcpSocket>

class RequestData : public QObject {
    Q_OBJECT
public:
    RequestData(const QString &url, const bool &parallel, QObject *parent = nullptr);
    RequestData(QObject *parent = nullptr);
    ~RequestData();

    void get(const QString &url, const bool &parallel = false);
    void get(const QUrl &url, const bool &parallel = false);

    QByteArray reply() const {return reply_;}
    QString error() const {return error_;}

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
