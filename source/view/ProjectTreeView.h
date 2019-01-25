//
// Created by jansorg on 16.01.19.
//

#ifndef TOM_UI_PROJECTTREEVIEW_H
#define TOM_UI_PROJECTTREEVIEW_H

#include <QtWidgets/QAction>
#include <QtWidgets/QTreeView>

#include "model/ProjectTreeItem.h"
#include "model/ProjectTreeModel.h"
#include "gotime/TomControl.h"

class ProjectTreeView : public QTreeView {
Q_OBJECT

signals:

    void projectSelected(const Project &project);

public:
    explicit ProjectTreeView(QWidget *parent);

    void setup(TomControl *control, ProjectStatusManager *statusManager);

public slots:

    void refresh();

private slots:

    void onCustomContextMenuRequested(const QPoint &pos);

    void onCurrentChanged(const QModelIndex &index, const QModelIndex &prev);

    void projectUpdated(const Project &project);

    void projectsStatusChanged(const QStringList &projectIDs);

private:
    void createNewProject(const Project &parentProject);

    void showContextMenu(ProjectTreeItem *item, const QPoint &globalPos);

private:

    TomControl *_control;
    ProjectStatusManager *_statusManager;

    ProjectTreeModel *_sourceModel;
    QSortFilterProxyModel *_sortModel;
};


#endif //TOM_UI_PROJECTTREEVIEW_H
