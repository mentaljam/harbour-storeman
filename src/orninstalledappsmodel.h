#pragma once

#include <QAbstractListModel>

#include "orninstalledpackage.h"

class OrnInstalledAppsModel : public QAbstractListModel
{
    Q_OBJECT

public:

    enum Roles
    {
        NameRole = Qt::UserRole + 1,
        TitleRole,
        TitleUnlocalizedRole,
        VersionRole,
        IconRole,
        SortRole,
        SectionRole,
        UpdateAvailableRole,
        UpdateVersionRole,
        IdRole
    };
    Q_ENUM(Roles)

    explicit OrnInstalledAppsModel(QObject *parent = nullptr);

public slots:
    void reset();

private slots:
    void onInstalledPackages(const OrnInstalledPackageList &packages);
    void onPackageInstalled(const QString &packageName);
    void onPackageRemoved(const QString &packageName);
    void onUpdatablePackagesChanged();

private:
    bool mResetting{false};
    OrnInstalledPackageList mData;

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;
};
