#include <set>

#include <QIcon>

#include <nsxlib/CrystalTypes.h>
#include <nsxlib/Peak3D.h>

#include "ExperimentItem.h"
#include "PeaksItem.h"
#include "UnitCellItem.h"
#include "UnitCellsItem.h"

UnitCellsItem::UnitCellsItem() : TreeItem()
{
    setText("Unit cells");

    QIcon icon(":/resources/unitCellsIcon.png");
    setIcon(icon);

    setEditable(false);

    setDragEnabled(true);
    setDropEnabled(true);

    setSelectable(false);

    setCheckable(false);
}

nsx::UnitCellList UnitCellsItem::unitCells()
{
    nsx::UnitCellList unitCells;
    unitCells.reserve(rowCount());

    for (int i = 0; i < rowCount(); ++i)
    {
        UnitCellItem* ucItem = dynamic_cast<UnitCellItem*>(child(i));
        if (ucItem) {
            unitCells.push_back(ucItem->unitCell());
        }
    }

    return unitCells;
}

void UnitCellsItem::removeUnusedUnitCells()
{
    auto peaks_item = experimentItem()->peaksItem();

    auto&& all_peaks = peaks_item->allPeaks();

    std::set<nsx::sptrUnitCell> unit_cells;

    for (auto peak : all_peaks) {
        auto unit_cell = peak->unitCell();
        if (!unit_cell) {
            continue;
        }
        auto it = unit_cells.find(unit_cell);
        if (it == unit_cells.end()) {
            unit_cells.insert(unit_cell);
        }
    }

    for (int i = rowCount()-1; i >= 0; --i)
    {
        UnitCellItem* unit_cell_item = dynamic_cast<UnitCellItem*>(child(i));
        if (unit_cell_item) {
            auto it = unit_cells.find(unit_cell_item->unitCell());
            if (it == unit_cells.end()) {
                removeRow(i);
            }
        }
    }
}
