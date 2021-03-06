
#ifndef TABLEMIMEDATA_H
#define TABLEMIMEDATA_H

#include <vector>

#include <QtCore/QMimeData>
#include <QStringList>

#include "universalid.hpp"
#include "columnbase.hpp"

namespace CSMDoc
{
    class Document;
}

namespace CSMWorld
{

/// \brief Subclass of QmimeData, augmented to contain and transport UniversalIds.
///
/// This class provides way to construct mimedata object holding the universalid copy
/// Universalid is used in the majority of the tables to store type, id, argument types.
/// This way universalid grants a way to retrive record from the concrete table.
/// Please note, that tablemimedata object can hold multiple universalIds in the vector.

    class TableMimeData : public QMimeData
    {
        public:
            TableMimeData(UniversalId id, const CSMDoc::Document& document);

            TableMimeData(std::vector<UniversalId>& id, const CSMDoc::Document& document);

            ~TableMimeData();

            virtual QStringList formats() const;

            std::string getIcon() const;

            std::vector<UniversalId> getData() const;

            bool holdsType(UniversalId::Type type) const;

            bool holdsType(CSMWorld::ColumnBase::Display type) const;

            bool fromDocument(const CSMDoc::Document& document) const;

            UniversalId returnMatching(UniversalId::Type type) const;

            UniversalId returnMatching(CSMWorld::ColumnBase::Display type) const;

            static CSMWorld::UniversalId::Type convertEnums(CSMWorld::ColumnBase::Display type);
            static CSMWorld::ColumnBase::Display convertEnums(CSMWorld::UniversalId::Type type);

        private:
            std::vector<UniversalId> mUniversalId;
            QStringList mObjectsFormats;
            const CSMDoc::Document& mDocument;

    };
}
#endif // TABLEMIMEDATA_H