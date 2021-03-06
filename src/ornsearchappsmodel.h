#pragma once

#include "ornappsmodel.h"

class OrnSearchAppsModel : public OrnAppsModel
{
    Q_OBJECT
    Q_PROPERTY(QString searchKey READ searchKey WRITE setSearchKey NOTIFY searchKeyChanged)

public:
    explicit OrnSearchAppsModel(QObject *parent = nullptr);

    QString searchKey() const;
    void setSearchKey(const QString &searchKey);

signals:
    void searchKeyChanged();

private:
    QString    mSearchKey;
    QByteArray mPrevReplyHash;

    // OrnAbstractListModelBase interface
protected:
    void resetImpl() override;

    // QAbstractItemModel interface
public:
    void fetchMore(const QModelIndex &parent) override;
    void processReply(const QJsonDocument &jsonDoc) override;
};
