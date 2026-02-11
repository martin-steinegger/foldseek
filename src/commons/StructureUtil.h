#ifndef STRUCTURE_UTIL_H
#define STRUCTURE_UTIL_H

#include "Util.h"
#include "PrefilteringIndexReader.h"
#include "LocalParameters.h"

class StructureUtil {
public:
    static bool is3Di12StDb(int dbtype) {
        return (DBReader<unsigned int>::getExtendedDbtype(dbtype)
                & LocalParameters::DBTYPE_EXTENDED_3DI_12ST) != 0;
    }

    static std::string getIndexWithSuffix(std::string db, const std::string &suffix) {
        if (Util::endsWith(".idx", db)) {
            db = db.substr(0, db.length() - 4);
        } else {
            return db + suffix;
        }
        db.append(suffix);
        std::string index = PrefilteringIndexReader::searchForIndex(db);
        if (index != "") {
            return index;
        }
        return db;
    }
};

#endif
