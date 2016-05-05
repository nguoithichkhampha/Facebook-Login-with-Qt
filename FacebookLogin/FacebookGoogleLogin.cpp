#include <QDebug>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "FacebookGoogleLogin.h"

using boost::property_tree::ptree;
using boost::property_tree::read_json;

FacebookGoogleLogin::FacebookGoogleLogin()
    : QNetworkAccessManager()
{
    manager = new QNetworkAccessManager();
    connect(manager, SIGNAL(finished(QNetworkReply *)), this,
            SLOT(finished(QNetworkReply *)));
}

QNetworkReply * FacebookGoogleLogin::createRequest(Operation op,
        const QNetworkRequest & request, QIODevice * outgoingData)
{
    QString cancel_url =
        "https://your_link_redirect_to_website/?error=access_denied&error_code=200&error_description=Permissions+error&error_reason=user_denied#_=_";
    reply = QNetworkAccessManager::createRequest(op, request, outgoingData);
    QString url_request = request.url().toString();
    //qDebug() << "url " << url_request;
    if(url_request.compare(cancel_url) == 0) {
        // user click cancel
        emit dataGot();
    }
    if(url_request.contains("?code=")) {
        emit dataGot();
        int index = url_request.indexOf("?code=");
        QString code = url_request.mid(index + 6);
        getAccessToken(code);
    }
    return reply;
}

void FacebookGoogleLogin::getAccessToken(QString code)
{
    QString client_id = "your_app_id";
    QString client_secret = "your_app_secret";
    QString redirect_uri =
        "your_link_redirect_to_website";
    QString url = QString("https://graph.facebook.com/v2.5/oauth/access_token?"
                          "client_id=%1&redirect_uri=%2&client_secret=%3&code=%4").arg(client_id,
                                  redirect_uri, client_secret, code);
    QNetworkRequest request = QNetworkRequest(QUrl(url));
    manager->get(request);
}

void FacebookGoogleLogin::finished(QNetworkReply * reply)
{
    try {
        ptree pt2;
        QString strReply = (QString)reply->readAll();
        std::string report_string = strReply.toStdString();
        std::istringstream is (report_string);
        read_json (is, pt2);
        std::string value = pt2.get<std::string>("access_token");
        QString access_token = QString::fromStdString(value);
        if(!access_token.isEmpty())
            qDebug() << "get access token " << access_token;
    }
    catch (std::exception & e) {
        qDebug() << "Exception " << e.what();
    }
}
