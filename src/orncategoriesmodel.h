#pragma once

#include "ornabstractlistmodel.h"
#include "orncategorylistitem.h"

/**
 * @brief The categories model class
 * This will work properly only if api response contains sorted categories
 */
class OrnCategoriesModel : public OrnAbstractListModel<OrnCategoryListItem>
{
    Q_OBJECT
public:
    enum Role
    {
        CategoryIdRole = Qt::UserRole,
        AppsCountRole,
        DepthRole,
        NameRole,
        VisibilityRole,
        ChildrenRole,
    };
    Q_ENUM(Role)

    explicit OrnCategoriesModel(QObject *parent = nullptr);

    // QAbstractItemModel interface
public:
    QVariant data(const QModelIndex &index, int role) const override;
    void fetchMore(const QModelIndex &parent) override;
    QHash<int, QByteArray> roleNames() const override;

    // OrnAbstractListModel interface
protected:
    void processReply(const QJsonDocument &jsonDoc) override;
};
