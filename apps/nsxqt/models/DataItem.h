#pragma once

#include <nsxlib/DataTypes.h>
#include <nsxlib/InstrumentTypes.h>

#include "TreeItem.h"

class NumorItem;

class DataItem : public TreeItem
{
public:
    explicit DataItem(nsx::sptrExperiment experiment);

    NumorItem* importData(const std::string& filename);
    NumorItem *importRawData(const std::vector<std::string>& filenames,
                             double wavelength, double delta_chi, double delta_omega, double delta_phi,
                             bool rowMajor, bool swapEndian, int bpp);

    QJsonObject toJson() override;
    void fromJson(const QJsonObject& obj) override;

private:
    NumorItem *importData(nsx::sptrDataSet data);

};
