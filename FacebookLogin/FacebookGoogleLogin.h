#ifndef FACEBOOKGOOGLELOGIN_H
#define FACEBOOKGOOGLELOGIN_H

#include <QNetworkAccessManager>
#include <QNetworkReply>
class FacebookGoogleLogin: public QNetworkAccessManager {
    Q_OBJECT

signals:
    void dataGot();
public:
    FacebookGoogleLogin();
    virtual QNetworkReply * createRequest(Operation op,
                                          const QNetworkRequest & request, QIODevice * outgoingData);
private:
    QNetworkReply * reply;
    QNetworkAccessManager * manager;
    void getAccessToken(QString code);
private slots:
    void finished(QNetworkReply * reply);
};

#endif // FACEBOOKGOOGLELOGIN_H
